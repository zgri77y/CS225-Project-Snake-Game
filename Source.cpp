// Class:	CS225
// Author:	Zachery Griswold & Natalie Yarbrough
// Group	Project: Snake Game
// Date:	2021

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include "Snake.h"
#include "Apple.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

bool board(Apple& a1, Snake& CPPSnake);

int main() {
	bool Game_Runnning;
	bool hitBody = false;

	int input;
	int score;
	int Direct;
	int BdX[500];
	int BdY[500];

	Apple a1;
	Snake CPPSnake;

	cout << "Press any button to start!";
	_getch();
	Game_Runnning = true;
	system("CLS");

	srand(time(NULL));

	board(a1, CPPSnake);

	while (Game_Runnning == true) {
		Sleep(300);
		
		try {
			Direct = CPPSnake.GetDirect();
			if (Direct == 0)
				throw (Direct);
		}
		catch (int NewDirect) {
			cout << "Direction Error" << endl;
			Direct = 1;
		}

		if (_kbhit()) {
			input = _getch();

			switch (input) {
			case 'w':
				CPPSnake.MoveUp(BdX[500], BdY[500]);
				break;
			case 'a':
				CPPSnake.MoveLeft(BdX[500], BdY[500]);
				break;
			case 's':
				CPPSnake.MoveDown(BdX[500], BdY[500]);
				break;
			case 'd':
				CPPSnake.MoveRight(BdX[500], BdY[500]);
				break;
			}
		}
		else if(Direct == 1)
			CPPSnake.MoveUp(BdX[500], BdY[500]);
		else if (Direct == 2)
			CPPSnake.MoveLeft(BdX[500], BdY[500]);
		else if (Direct == 3)
			CPPSnake.MoveDown(BdX[500], BdY[500]);
		else if (Direct == 4)
			CPPSnake.MoveRight(BdX[500], BdY[500]);


		hitBody = board(a1, CPPSnake);
		ofstream fout("Results.txt");
		score = a1.GetScore();
		fout << "Your score is: " << score << endl;
		fout.close();

		if (BdX[0] < 0 || BdX[0] > 19 || BdY[0] < 0 || BdY[0] > 14 || hitBody == true) { Game_Runnning = false; }
	}
	system("CLS");

	cout << CPPSnake;

	ofstream fout("Results.txt");
	score = a1.GetScore();
	fout << "Your score is: " << score << endl;
	fout.close();

	return 0;

}

bool board(Apple& a1, Snake& CPPSnake) {
	system("CLS");

	int x = CPPSnake.GetX();
	int y = CPPSnake.GetY();
	int Move = CPPSnake.GetMove();

	bool hitBody = false;
	bool prB = false;

	int score = a1.GetScore();
	cout << "Score: " << score << endl;

	BdX[0] = x;
	BdY[0] = y;

	cout << "||||||||||||||||||||||" << endl;
	for (int i = 0; i < 15; i++) {
		cout << '|';
		for (int j = 0; j < 20; j++) {

			for (int l = Move; l > (Move - score); l--) {
				if (i == BdY[l] && j == BdX[l]) {
					cout << 'o';
					prB = true;
				}
			}

			if (i == BdY[0] && j == BdX[0] && prB == false) {
				cout << 'S';
			}
			else if (i == a1.getApple_X() && j == a1.getApple_Y() && prB == false) {
				cout << "A";
			}
			else if (prB == false) {
				cout << ' ';
			}
			else if (i == BdY[0] && j == BdX[0] && prB == true) {
				hitBody = true;
			}

			prB = false;

		}
		cout << '|' << endl;
	}

	cout << "||||||||||||||||||||||" << endl;

	if ((a1.getApple_X() == y) && (a1.getApple_Y() == x)) {
		cout << "You ate the apple" << endl;
		a1.AddScore();
		a1.appleLocation();
	}

	return hitBody;
}

