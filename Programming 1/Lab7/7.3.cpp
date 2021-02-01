#include <iostream>
#include <string>
using namespace std;
int last(int num);
string first(int num);
int len(int num);
int main(void)
{
	int num;
	while (true)
	{
		cout << "Enter number or Q to quit: ";
		cin >> num;
		if (cin.fail())
		{
			break;
		}
		else
		{
			cout << "first digit: " << first(num) << " last digit: " << last(num) << " number of digits: " << len(num) << endl;
		}
	}
}
int last(int num)
{
	int lastdigit = num % 10;
	return lastdigit;
}
string first(int num)
{
	string first = to_string(num);
	first = first[0];
	return first;
}
int len(int num)
{
	string length = to_string(num);
	int len = length.length();
	return len;
}