#include <iostream>
using namespace std;
int main(void)
{
	int number;
	int printed = 0;
	cout << "enter your number: ";
	cin >> number;
	while (number > 0)
	{
		printed = number % 2;
		number /= 2;
		cout << printed << endl;

	}
}