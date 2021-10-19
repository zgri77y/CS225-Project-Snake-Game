// Class:	CS225
// Author:	Zachery Griswold & Natalie Yarbrough
// Group	Project: Snake Game
// Date:	2021

#include <iostream>
#include <string>
#include <cctype>
#include <climits>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	bool Game_Runnning;

	cout << "Press any button to start!";
	cin.ignore();
	Game_Runnning = true;
	system("CLS");

	while (Game_Runnning == true) {
		cout << "||||||||||||||||||||||||||" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "|                        |" << endl;
		cout << "||||||||||||||||||||||||||" << endl;
		Sleep(2000);
		system("CLS");
	}
	
	
	return 0;
}