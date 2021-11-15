#pragma once
#include <iostream>
using namespace std;

int BdX[256];
int BdY[256];

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
	int GetDirect();
	friend ostream& operator<<(ostream& os, const Snake&);
};