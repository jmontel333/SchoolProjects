/*
 *File: Lab2-1
 *Author: Jesse Montel
 *date: 9/5/2019
 *Description: Makes more Hal
 */
#include <iostream>;
#include <string>;
using namespace std;
int main(void) {
	cout << "Hello, my name is Hal!" << endl;
	cout << "What is your name?";
	string user_name;
	getline(cin, user_name);
	cout << "Hello, ";
	cout << user_name; 
	cout << ". I am glad to meet you!";
}