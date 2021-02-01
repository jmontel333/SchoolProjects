#include <iostream>
#include <string>
using namespace std;
bool isCardValid(int digits[], int size);
int main(void)
{
	string digitstring;
	int size = 8;
	int digits[8];
	cout << "enter an 8 digit number: ";
	cin >> digitstring;
	for (int i = 0; i < 8; i++)
	{
		digits[i] = digitstring[i]-48;
	}
	if (isCardValid(digits, size))
	{
		cout << "the card is valid";
	}
	else
	{
		cout << "card not valid dummy theif";
	}
}
bool isCardValid(int digits[], int size)
{
	int sum1 = digits[7] + digits[5] + digits[3] + digits[1];
	int doubled1 = digits[0] * 2;
	int doubled2 = digits[2] * 2;
	int doubled3 = digits[4] * 2;
	int doubled4 = digits[6] * 2;
	int adder1 = doubled1 % 10;
	int adder2 = doubled2 % 10; 
	int adder3 = doubled3 % 10; 
	int adder4 = doubled4 % 10;
	int adder11 = doubled1 / 10;
	int adder22 = doubled2 / 10;
	int adder33 = doubled3 / 10;
	int adder44 = doubled4 / 10;
	if ((sum1 + adder1 + adder2 + adder3 + adder4 + adder11 + adder22 + adder33 + adder44) % 10 == 0)
	{
		return true;
	}
	return false; 
}