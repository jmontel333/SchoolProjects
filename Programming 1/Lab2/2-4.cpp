/*
 *File: Lab2-1
 *Author: Jesse Montel
 *date: 9/5/2019
 *Description: mlts first 10 ints
 */
#include <iostream>;
#include <string>;
using namespace std;
int main(void) {
	double x = 1;
	int y = 1;
	while (x <= 10) {
		y = y*x;
		x++;
	}
	cout << y;


}