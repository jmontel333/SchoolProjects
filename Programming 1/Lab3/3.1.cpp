#include <iostream>
using namespace std;
int main(void)
{
	//vars
	int number1 = 0;
	int number2 = 0;
	int sum = 0;
	int difference = 0;
	double product = 0;
	double average = 0;
	//ask user for the ints
	cout << "please enter 2 integers for me to analyze: ";
	cin >> number1 >> number2;
	//calcs sum difference product and average
	sum = number1 + number2;
	difference = number1 - number2;
	if (difference < 0)
	{
		difference = -difference;
	}
	product = number1 * number2;
	average = sum / 2.0;
	//prints out the answers
	cout << "the sum is: " << sum << endl << "the difference is: " << difference << endl << "the product is: " << product << endl << "the average is: " << average;
	return 0;
}