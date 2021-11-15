#include "Snake.h"

ostream& operator<<(ostream& os, const Snake& s) {
	os << "Game Over";
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

void Snake::MoveUp(int BdX[500], int BdY[500]) {
	if (Down == false) {
		if (Move < 500)
			Move++;
		else
			Move = 1;

		BdX[Move] = x;
		BdY[Move] = y;

		y = y - 1;

		Up = true;
		Down = false;
		Left = false;
		Right = false;
	}
}

void Snake::MoveDown(int BdX[500], int BdY[500]) {
	if (Up == false) {
		if (Move < 500)
			Move++;
		else
			Move = 1;

		BdX[Move] = x;
		BdY[Move] = y;

		y = y + 1;

		Up = false;
		Down = true;
		Left = false;
		Right = false;
	}

}

void Snake::MoveLeft(int BdX[500], int BdY[500]) {
	if (Right == false) {
		if (Move < 500)
			Move++;
		else
			Move = 1;

		BdX[Move] = x;
		BdY[Move] = y;

		x = x - 1;

		Up = false;
		Down = false;
		Left = true;
		Right = false;
	}

}

void Snake::MoveRight(int BdX[500], int BdY[500]) {
	if (Left == false) {
		if (Move < 500)
			Move++;
		else
			Move = 1;
		
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