/*
 *File: Lab2-1
 *Author: Jesse Montel
 *date: 9/5/2019
 *Description: Makes hal
 */
#include <iostream>;
#include <string>;
using namespace std;
int main(void) {
	cout << "Hello, my name is Hal!"<<endl;
	cout << "What would you like me to do?"<<endl;
	string user_input;
	getline(cin, user_input);
	cout << "Im sorry I cannot do that";
	return 0;

}
