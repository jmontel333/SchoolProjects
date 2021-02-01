#include <iostream>
using namespace std;
bool all_the_same(int x, int y, int z);
bool all_different(int x, int y, int z);
bool sorted(int x, int y, int z);
int main(void)
{
	int x, y, z;
	while (true)
	{
		cout << "Enter three numbers or Q to quit: ";
		cin >> x >> y >> z;
		if (cin.fail())
		{
			break;
		}
		else
		{
			if (all_the_same(x, y, z))
			{
				cout << "the numbers are all the same" << endl;
			}
			else
			{
				cout << "the numbers are not all the same" << endl;
			}
			if (all_different(x, y, z))
			{
				cout << "the numbers are all different" << endl;
			}
			else
			{
				cout << "the numbers aren't all different" << endl;
			}
			if (sorted(x, y, z))
			{
				cout << "the numbers are sorted" << endl;
			}
			else
			{
				cout << "the numbers aren't sorted" << endl;
			}
		}
	}
}
bool all_the_same(int x, int y, int z)
{
	if (x == y && y == z)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool all_different(int x, int y, int z)
{
	if (x != y && y != z)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool sorted(int x, int y, int z)
{
	if (x <= y && y <= z)
	{
		return true;
	}
	else
	{
		return false;
	}
}