//Jesse Montel
#include <iostream>
using namespace std;
int main(void)
{
	//vars
	double number1;
	double number2;
	double number3;
	cout << "please enter 3 numbers with spaces inbetween: ";
	cin >> number1 >> number2 >> number3;
	if (number1 > number2 && number1 > number3)
	{
		cout << "the largest number is: " << number1;
	}
	else if (number2 > number3 && number2 > number1)
	{
		cout << "the largest number is: " << number2;
	}
	else if (number3 > number1 && number3 > number2)
	{
		cout << "the largest number is: " << number3;
	}
	else if (number3 == number1 && number3 == number2)
	{
		cout << "they are all equal";
	}
	else if (number3 == number1)
	{
		cout << number3 << "=" << number1;
	}
	else if (number2 == number1)
	{
		cout << number2 << "=" << number1;
	}
	else if (number2 == number3)
	{
		cout << number2 << "=" << number3;
	}
}