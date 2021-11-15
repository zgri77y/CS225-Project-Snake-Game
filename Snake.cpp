#include "Snake.h"

ostream& operator<<(ostream& os, const Snake& s) {
	os << "Game Over"<< endl;
	return os;
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

int Snake::GetDirect() {
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