#include <iostream>
#include <random>
#include <time.h>
using namespace std;
bool isSortedIncreasing(int list_size, int list[]);
bool isSortedDecreasing(int list_size, int list[]);
bool hasAdjecentDuplicates(int list_size, int list[]);
bool hasDuplicates(int list_size, int list[]);
int main(void)
{
	int list[6];
	for(int j = 0; j<6; j++)
	{
		int num;
		cout << "enter an integer: ";
		cin >> num;
		list[j] = num;
	}
	if (isSortedIncreasing(6, list))
	{
		cout << "the data is increasing" << endl;
	}
	else
	{
		cout << "the data isnt increasing" << endl;
	}
	if(isSortedDecreasing(6,list))
	{
		cout << " the data is decreasing" << endl;
	}
	else
	{
		cout << "the data isnt decreasing" << endl;
	}
	if (hasAdjecentDuplicates(6, list))
	{
		cout << "the data has adjacent duplicates" << endl;
	}
	else
	{
		cout << "the data doesnt have adjacent duplicates" << endl;
	}
	if (hasDuplicates(6, list))
	{
		cout << "the data has duplicates" << endl;
	}
	else
	{
		cout << "the data doesnt have duplicates" << endl;
	}
}
bool isSortedIncreasing(int list_size, int list[])
{
	for (int i = 0; i < list_size-1; i++)
	{
		if (list[i] > list[i + 1])
		{
			return false;
		}
	}
	return true;
}
bool isSortedDecreasing(int list_size, int list[])
{
	for (int i = 0; i < list_size - 1; i++)
	{
		if (list[i] < list[i + 1])
		{
			return false;
		}
	}
	return true;
}
bool hasAdjecentDuplicates(int list_size, int list[])
{
	for (int i = 0; i < list_size - 1; i++)
	{
		if (list[i] == list[i + 1])
		{
			return true;
		}
	}
	return false;

}
bool hasDuplicates(int list_size, int list[])
{
	for (int i = 0; i < list_size; i++)
	{
		for (int j = i + 1; j < list_size; j++)
		{
			if (list[i] == list[j])
			{
				return true;
			}
		}
	}
	return false;
}