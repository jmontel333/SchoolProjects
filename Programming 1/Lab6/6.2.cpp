#include <iostream>
using namespace std;
int main(void)
{
	int n;
	int r = 1;
	int length;
	int spaces;
	cout << "gimme n: ";
	cin >> n;
	length = n-1;
	spaces = n;
	spaces -= 1;
	for (int i = 0; i < length; i++)
	{
		for (int i = 0; i < spaces; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < r; i++)
		{
			cout << "*";
		}
		r += 2;
		spaces -= 1;
		cout << endl;
	}
	spaces -= 1;
	for (int i = 0; i <= length; i++)
	{
		spaces += 1;
		for (int i = 0; i < spaces; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < r; i++)
		{
			cout << "*";
		}
		r -= 2;
		cout << endl;
	}
}