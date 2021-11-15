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


bool board(Apple& a1, Bonus& b1, Snake& CPPSnake);

int main() {
	bool Game_Runnning;
	bool hitBody = false;

	int input;
	int score;
	int Direct;

	Apple a1;
	Bonus b1;
	Snake CPPSnake;

	cout << "Press any button to start!";
	_getch();
	Game_Runnning = true;
	system("CLS");

	srand(time(NULL));

	board(a1, b1, CPPSnake);

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
				CPPSnake.MoveUp();
				break;
			case 'a':
				CPPSnake.MoveLeft();
				break;
			case 's':
				CPPSnake.MoveDown();
				break;
			case 'd':
				CPPSnake.MoveRight();
				break;
			default:
				if (Direct == 1)
					CPPSnake.MoveUp();
				else if (Direct == 2)
					CPPSnake.MoveLeft();
				else if (Direct == 3)
					CPPSnake.MoveDown();
				else if (Direct == 4)
					CPPSnake.MoveRight();
			}
		}
		else if (Direct == 1)
			CPPSnake.MoveUp();
		else if (Direct == 2)
			CPPSnake.MoveLeft();
		else if (Direct == 3)
			CPPSnake.MoveDown();
		else if (Direct == 4)
			CPPSnake.MoveRight();


		hitBody = board(a1, b1, CPPSnake);
		ofstream fout("Results.txt");
		score = b1.GetScore();
		fout << "Your score is: " << score << endl;
		fout.close();

		if (CPPSnake.BdX[0] < 0 || CPPSnake.BdX[0] > 19 || CPPSnake.BdY[0] < 0 || CPPSnake.BdY[0] > 14 || hitBody == true) { Game_Runnning = false; }
	}
	system("CLS");

	ofstream fout("Results.txt");
	score = b1.GetScore();
	fout << "Your score is: " << score << endl;
	fout.close();

	cout << "Your score is: " << score << endl;

	cout << CPPSnake;

	return 0;

}

bool board(Apple& a1, Bonus& b1, Snake& CPPSnake) {
	system("CLS");

	int x = CPPSnake.GetX();
	int y = CPPSnake.GetY();
	int Move = CPPSnake.GetMove();

	bool hitBody = false;
	bool prB = false;

	int score = b1.GetScore();
	int scoreSnake = a1.GetScore();
	cout << "Score: " << score << endl;

	CPPSnake.BdX[0] = x;
	CPPSnake.BdY[0] = y;

	cout << "||||||||||||||||||||||" << endl;
	for (int i = 0; i < 15; i++) {
		cout << '|';
		for (int j = 0; j < 20; j++) {

			for (int l = Move; l > (Move - scoreSnake); l--) {
				if (i == CPPSnake.BdY[l] && j == CPPSnake.BdX[l]) {
					cout << 'o';
					prB = true;
				}
			}

			if (i == CPPSnake.BdY[0] && j == CPPSnake.BdX[0] && prB == false) {
				cout << 'S';
			}
			else if (i == a1.getApple_X() && j == a1.getApple_Y() && prB == false) {
				cout << "A";
			}
			else if (prB == false) {
				cout << ' ';
			}
			else if (i == CPPSnake.BdY[0] && j == CPPSnake.BdX[0] && prB == true) {
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
		b1.AddScore();
		a1.appleLocation();

		if (rand() % 10 == 9) {
			b1.bonusPoints();
		}
		
	}

	return hitBody;
}