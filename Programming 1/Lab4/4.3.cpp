#include <iostream>
using namespace std;
int main(void)
{
	//vars
	int number;
	int digits = 0;
	cout << "enter a number lmao: ";
	cin >> number;
	//if neg make pos
	if (number < 0)
	{
		number = number * -1;
	}
	if (number >= 0)
	{
		digits++;
	}
	if (number >= 10)
	{
		digits++;
	}
	if (number >= 100)
	{
		digits++;
	}
	if (number >= 1000)
	{
		digits++;
	}
	if (number >= 10000)
	{
		digits++;
	}
	if (number >= 100000)
	{
		digits++;
	}
	if (number >= 1000000)
	{
		digits++;
	}
	if (number >= 10000000)
	{
		digits++;
	}
	if (number >= 100000000)
	{
		digits++;
	}
	if (number >= 1000000000)
	{
		digits++;
	}
	if (number >= 10000000000)
	{
		digits++;
	}
	cout << "the number has " << digits << " digits";
}