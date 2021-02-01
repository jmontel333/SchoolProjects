#include <iostream>
using namespace std;
int romanCharValue(char r);
int convertRomanToInt(string s);
int main(void)
{
	string str;
	cout << "enter a roman number or Q to quit: ";
	while (true)
	{
		cin >> str;
		if (str == "Q")
		{
			break;
		}
		cout << str << "=" << convertRomanToInt(str);
	}
}
int romanCharValue(char r)
{
	int value = 0;
	switch (r)
	{
	case 'I': value = 1;
		break;
	case 'V': value = 5;
		break;
	case 'X': value = 10;
		break;
	case 'L': value = 50;
		break;
	case 'C': value = 100;
		break;
	case 'D': value = 500;
		break;
	case 'M': value = 1000;
		break;
	}
	return value;
}
int convertRomanToInt(string s)
{
	int total = 0;
	int i = 0;
	while(i < s.length())
	{
		if (romanCharValue(s[i]) > romanCharValue(s[i + 1]) || romanCharValue(s[i]) == romanCharValue(s[i + 1]) || s.length() == 1)
		{
			total += romanCharValue(s[i]);
			i++;
		}
		else
		{
			total += (romanCharValue(s[i + 1]) - romanCharValue(s[i]));
			i += 2;
		}
	}
	return total;
}