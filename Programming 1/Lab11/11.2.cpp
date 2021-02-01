#include <iostream>
#include <string>
using namespace std;
bool isCardValid(int digits[], int size);
int main(void)
{
	string digitstring;
	int size = 16;
	int digits[16];
	cout << "enter an 16 digit number: ";
	cin >> digitstring;
	for (int i = 0; i < 16; i++)
	{
		digits[i] = digitstring[i] - 48;
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
	int sum1 = digits[7] + digits[5] + digits[3] + digits[1] + digits[9] + digits[11] + digits[13] + digits[15];
	int doubled1 = digits[0] * 2;
	int doubled2 = digits[2] * 2;
	int doubled3 = digits[4] * 2;
	int doubled4 = digits[6] * 2;
	int doubled5 = digits[8] * 2;
	int doubled6 = digits[10] * 2;
	int doubled7 = digits[12] * 2;
	int doubled8 = digits[14] * 2;
	int adder1 = doubled1 % 10;
	int adder2 = doubled2 % 10;
	int adder3 = doubled3 % 10;
	int adder4 = doubled4 % 10;
	int adder11 = doubled1 / 10;
	int adder22 = doubled2 / 10;
	int adder33 = doubled3 / 10;
	int adder44 = doubled4 / 10;
	int adder5 = doubled5 % 10;
	int adder6 = doubled6 % 10;
	int adder7 = doubled7 % 10;
	int adder8 = doubled8 % 10;
	int adder55 = doubled5 / 10;
	int adder66 = doubled6 / 10;
	int adder77 = doubled7 / 10;
	int adder88 = doubled8 / 10;
	if ((sum1 + adder1 + adder2 + adder3 + adder4 + adder11 + adder22 + adder33 + adder44 + adder5 + adder6 + adder7 + adder8 + adder55 + adder66 + adder77 + adder88) % 10 == 0)
	{
		return true;
	}
	return false;
}