#pragma once
#include <iostream>
using namespace std;

class Apple {

protected:
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
		apple_x = rand() % 14 + 1;
		apple_y = rand() % 19 + 1;

	};

	void AddScore() {
		score++;
	}

	int GetScore() {
		return score;
	}
};


class Bonus :public Apple {
public:
	int bonusPoints() {
		int oldScore = score;
		do {
			score = score + 5;
		} while (oldScore == score);
		cout << "Bonus Apple!!" << endl;
		GetScore();
		return score;
	};

};
