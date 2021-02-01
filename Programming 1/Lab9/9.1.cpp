#include <iostream>
using namespace std;
bool isprime(int n);
int main(void)
{
	int x;
	while (true)
	{
		cout << "enter an integer or Q to Quit: ";
		cin >> x;
		if (cin.fail())
		{
			break;
		}
		if (isprime(x))
		{
			cout << x << " is a prime number" << endl;
		}
		else
		{
			cout << x << " isn't a prime number" << endl;
		}
	}
}
//checks if a number is prime
//@param int n that will be checked
//@return returns true if the number is prime false otherwise
bool isprime(int n)
{
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			total++;
		}
	}
	if (total == 2)
	{
		return true;
	}
	return false;
}