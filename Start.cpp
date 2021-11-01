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

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;



class Apple {

private:
	int apple_x = 10;
	int apple_y = 10;

public:

	int getApple_X() {
		return apple_x;
	}

	int getApple_Y() {
		return apple_y;
	}

	Apple() {
		apple_x = rand() % 13 + 1;
		apple_y = rand() % 18 + 1;
	};

	void appleLocation() {
		apple_x = rand() % 13 + 1;
		apple_y = rand() % 18 + 1;

	};
};



int x = 6;
int y = 6;
int nmin = 0;
int score = 0;

void board(Apple& a1);

int main() {
	bool Game_Runnning;
	int input;
	Apple a1;

	cout << "Press any button to start!";
	cin.ignore();
	Game_Runnning = true;
	system("CLS");

	srand(time(NULL));

	board(a1);

	while (Game_Runnning == true) {
		input = _getch();

		switch (input) {
		case 'w':
			if (y == nmin) {
				break;
			}
			else {
				y = y - 1;
				break;
			}
		case 'a':
			if (x == nmin) {
				break;
			}
			else {
				x = x - 1;
				break;
			}
		case 's':
			if (y == 14) {
				break;
			}
			else {
				y = y + 1;
				break;
			}
		case 'd':
			if (x == 19) {
				break;
			}
			else {
				x = x + 1;
				break;
			}
		}

		board(a1);
		ofstream fout("Results.txt");
		fout << "Your score is: " << score << endl;
		fout.close();

	}

}

void board(Apple& a1) {
	system("CLS");

	cout << "Score: " << score << endl;

	cout << "||||||||||||||||||||||" << endl;
	for (int i = 0; i < 15; i++) {
		cout << '|';
		for (int j = 0; j < 20; j++) {
			if (i == y && j == x) {
				cout << 'S';
			}
			else if (i == a1.getApple_X() && j == a1.getApple_Y()) {
				cout << "O";

			}

			else {
				cout << ' ';
			}

		}
		cout << '|' << endl;
	}
	cout << "||||||||||||||||||||||" << endl;
	if ((a1.getApple_X() == y) && (a1.getApple_Y() == x)) {
		cout << "You ate the apple" << endl;
		score++;
		a1.appleLocation();
	}

}
