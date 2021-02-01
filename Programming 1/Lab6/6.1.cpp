#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cout << "enter numer of asterisks per side: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "*";
	}
	cout << " ";
	for (int i = 0; i < n; i++)
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < n - 2; i++)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "*";
		}
		cout << " ";
		cout << "*";
		for (int i = 0; i < (n - 2); i++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "*";
	}
	cout << " ";
	for (int i = 0; i < n; i++)
	{
		cout << "*";
	}
}