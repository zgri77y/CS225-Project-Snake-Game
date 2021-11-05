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
	int score = 0;
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

	void AddScore() {
		score++;
	}

	int GetScore() {
		return score;
	}
};

class Snake {
private:
	int Move = 0;
	bool Up, Down, Left, Right;
	int x = 6;
	int y = 6;
public:
	Snake();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	int GetX() { return x; }
	int GetY() { return y; }
	int GetMove() { return Move; }
};

char Direction[256];
void board(Apple& a1, Snake& CPPSnake);


int main() {
	bool Game_Runnning;
	int input;
	Apple a1;
	Snake CPPSnake;
	int score;

	cout << "Press any button to start!";
	_getch();
	Game_Runnning = true;
	system("CLS");

	srand(time(NULL));

	board(a1, CPPSnake);

	while (Game_Runnning == true) {
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
		}

		board(a1, CPPSnake);
		ofstream fout("Results.txt");
		score = a1.GetScore();
		fout << "Your score is: " << score << endl;
		fout.close();

	}

}

void board(Apple& a1, Snake& CPPSnake) {
	system("CLS");

	int x = CPPSnake.GetX();
	int y = CPPSnake.GetY();
	int Move = CPPSnake.GetMove();

	bool prB = false;

	int score = a1.GetScore();
	cout << "Score: " << score << endl;

	int BdX[100];
	int BdY[100];

	BdX[0] = x;
	BdY[0] = y;

	for (int k = 1; k < score+1; k++) {
		switch (Direction[Move - k]) {
		case 'U':
			BdY[k] = BdY[k - 1] + 1;
			BdX[k] = BdX[k - 1];
			break;
		case 'D':
			BdY[k] = BdY[k - 1] - 1;
			BdX[k] = BdX[k - 1];
			break;
		case 'L':
			BdX[k] = BdX[k - 1] + 1;
			BdY[k] = BdY[k - 1];
			break;
		case 'R':
			BdX[k] = BdX[k - 1] - 1;
			BdY[k] = BdY[k - 1];
			break;
		}
	}

	cout << "||||||||||||||||||||||" << endl;
	for (int i = 0; i < 15; i++) {
		cout << '|';
		for (int j = 0; j < 20; j++) {

			for (int l = 1; l < score + 1; l++) {
				if (i == BdY[l] && j == BdX[l]) {
					cout << 'B';
					prB = true;
				}
			}

			if (i == BdY[0] && j == BdX[0] && prB == false) {
				cout << 'S';
			}
			else if (i == a1.getApple_X() && j == a1.getApple_Y() && prB == false) {
				cout << "O";

			}
			else if (prB == false) {
				cout << ' ';
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

}

Snake::Snake() {
	Up = false;
	Down = true;
	Left = false;
	Right = false;

	x = 6;
	y = 6;
}

void Snake::MoveUp() {
	if (y > 0 && Down == false) {
		y = y - 1;
		Move++;
		Direction[Move] = 'U';

		Up = true;
		Down = false;
		Left = false;
		Right = false;
	}
}

void Snake::MoveDown() {
	if (y < 14 && Up == false) {
		y = y + 1;
		Move++;
		Direction[Move] = 'D';

		Up = false;
		Down = true;
		Left = false;
		Right = false;
	}

}

void Snake::MoveLeft() {
	if (x > 0 && Right == false) {
		x = x - 1;
		Move++;
		Direction[Move] = 'L';

		Up = false;
		Down = false;
		Left = true;
		Right = false;
	}

}

void Snake::MoveRight() {
	if (x < 19 && Left == false) {
		x = x + 1;
		Move++;
		Direction[Move] = 'R';

		Up = false;
		Down = false;
		Left = false;
		Right = true;
	}

}
