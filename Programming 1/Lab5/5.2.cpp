//Jesse Montel 9-26-19
#include <iostream>
using namespace std;
int main(void)
{
	//vars
	int input;
	int smallest = 99999;
	int largest = 0;
	int evenins = 0;
	int oddins = 0;
	while (true)
	{
		cout << "please enter in a number or q to quit: ";
		cin >> input;
		if (cin.fail())
		{
			cout << endl<< "the largest number was: " << largest << " the smallest number was: " << smallest << endl << " the number of even numbers was: " << evenins << " the number of odds numbers entered was: " << oddins;
			return 0;
		}
		if (input > largest)
		{
			largest = input;
		}
		if (input < smallest)
		{
			smallest = input;
		}
		if (input % 2 == 0)
		{
			evenins += 1;
		}
		else
		{
			oddins += 1;
		}

    }
}