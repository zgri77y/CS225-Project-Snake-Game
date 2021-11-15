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
	int GetDirect() {
		if (Up == true) {
			return 1;
		}
		else if (Left == true) {
			return 2;
		}
		else if (Down == true) {
			return 3;
		}
		else if (Right == true) {
			return 4;
		}
		else {
			return 0;
		}
	}
	friend ostream& operator<<(ostream& os, const Snake&);
};

ostream& operator<<(ostream& os, const Snake& s) {
	os << "Game Over";
	return os;
}

int BdX[256];
int BdY[256];
void board(Apple& a1, Snake& CPPSnake);
bool hitBody = false;

int main() {
	bool Game_Runnning;
	int input;
	Apple a1;
	Snake CPPSnake;
	int score;
	int Direct;

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
		}
		else if(Direct == 1)
			CPPSnake.MoveUp();
		else if (Direct == 2)
			CPPSnake.MoveLeft();
		else if (Direct == 3)
			CPPSnake.MoveDown();
		else if (Direct == 4)
			CPPSnake.MoveRight();


		board(a1, CPPSnake);
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

void board(Apple& a1, Snake& CPPSnake) {
	system("CLS");

	int x = CPPSnake.GetX();
	int y = CPPSnake.GetY();
	int Move = CPPSnake.GetMove();

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
	if (Down == false) {
		Move++;
		BdX[Move] = x;
		BdY[Move] = y;

		y = y - 1;

		Up = true;
		Down = false;
		Left = false;
		Right = false;
	}
}

void Snake::MoveDown() {
	if (Up == false) {
		Move++;
		BdX[Move] = x;
		BdY[Move] = y;

		y = y + 1;

		Up = false;
		Down = true;
		Left = false;
		Right = false;
	}

}

void Snake::MoveLeft() {
	if (Right == false) {
		Move++;
		BdX[Move] = x;
		BdY[Move] = y;

		x = x - 1;

		Up = false;
		Down = false;
		Left = true;
		Right = false;
	}

}

void Snake::MoveRight() {
	if (Left == false) {
		Move++;
		BdX[Move] = x;
		BdY[Move] = y;

		x = x + 1;

		Up = false;
		Down = false;
		Left = false;
		Right = true;
	}

}
