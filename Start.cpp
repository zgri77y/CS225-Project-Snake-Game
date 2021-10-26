// Class:	CS225
// Author:	Zachery Griswold & Natalie Yarbrough
// Group	Project: Snake Game
// Date:	2021

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int x = 6;
int y = 6;
int nmin = 0;
int apple_x = 10;
int apple_y = 10; 

void appleLocation() {
	apple_x = rand() % 13 + 1;
	apple_y = rand() % 18 + 1;

};

void board();

int main() {
	bool Game_Runnning;
	char input;

	cout << "Press any button to start!";
	cin.ignore();
	Game_Runnning = true;
	system("CLS");

	srand(time(NULL));
	appleLocation(); 

	board();

	while (Game_Runnning == true) {
		cin >> input;

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

		board();

	}
	return 0;
}

void board() {
	system("CLS");
	
	cout << "||||||||||||||||||||||" << endl;
	for (int i = 0; i < 15; i++) {
		cout << '|';
		for (int j = 0; j < 20; j++) {
			if (i == y && j == x) {
				cout << 'S';
			}
			else if (i == apple_x && j == apple_y) {
				cout << "O";

			}

			else {
				cout << ' ';
			}

		}
		cout << '|' << endl;
	}
	cout << "||||||||||||||||||||||" << endl;
	if ((apple_x == y) && (apple_y == x)) {
		cout << "You ate the apple" << endl;
		appleLocation();
	}
}
