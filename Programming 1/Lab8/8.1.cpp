#include <iostream>
#include <string>
using namespace std;
int countVowl(string str);
int main(void)
{
	int num = 0;
	string str;
	cout << "please enter a string or Q to quit: ";
	num = countVowl(str);
	cout << "the number of vowls is " << num;
}
int countVowl(string str)
{
	int vnum = 0;
	while (true)
	{
		cin >> str;
		if (str == "Q")
		{
			break;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'A' || str[i] == 'a' || str[i] == 'E' || str[i] == 'e' || str[i] == 'I' || str[i] == 'i' || str[i] == 'O' || str[i] == 'o' || str[i] == 'U' || str[i] == 'u')
			{
				vnum += 1;
			}
		}
	}
	return vnum;
}
