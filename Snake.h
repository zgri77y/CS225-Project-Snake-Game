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
	Snake();
	void MoveUp(int BdX[500], int BdY[500]);
	void MoveDown(int BdX[500], int BdY[500]);
	void MoveLeft(int BdX[500], int BdY[500]);
	void MoveRight(int BdX[500], int BdY[500]);
	int GetX() { return x; }
	int GetY() { return y; }
	int GetMove() { return Move; }
	int GetDirect();
	friend ostream& operator<<(ostream& os, const Snake&);
};