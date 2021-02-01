#include <iostream>
#include <string>
using namespace std;
int countWords(string str);
int main(void)
{
	int num = 0;
	string str;
	cout << "please enter a string or Q to quit: ";
	cin >> str;
	cout << "word count: " << countWords(str);
}
int countWords(string str)
{
	int num = 1;
	int numtimes = 1;
	while (true)
	{
		cin >> str;
		if (str == "Q")
		{
			break;
		}
		num++;

	}
	return num;
}
