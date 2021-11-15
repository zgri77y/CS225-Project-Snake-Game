#pragma once
#include <iostream>
using namespace std;



class Snake {
private:
	int Move = 0;
	bool Up, Down, Left, Right;
	int x = 6;
	int y = 6;
public:
	int BdX[500];
	int BdY[500];
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