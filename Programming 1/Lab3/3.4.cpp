/*
 * File: lab3 fencing
 * Author: Jesse Montel
 * Date: 9/12/2019
 *
 * Description: produces cost for length of fence
 */
#include <iostream>
using namespace std;
int main(void)
{
	//varibles
	double cost = 0;
	int length = 0;
	double const RAILCOST = 9.97;
	double const POSTCOST = 10.98;
	int sections = 0;
	//get length from user
	cout << "Enter the length of your fence (in 10s of feet): ";
	cin >> length;
	//checks if its a workable length
	while (length <= 0)
	{
		cout << "thats not a real length please try again: ";
		cin >> length;
	}
	//finds number of sections in the fence
	sections = length / 10;
	if (length % 10 != 0)
	{
		sections = sections + 1;
	}
	//finds the cost of the fence and returns fence cost
	cost = ((POSTCOST + 3 * RAILCOST)* sections) + POSTCOST;
	cout << "the price to build this fence will be: " << cost;
	return 0;
}