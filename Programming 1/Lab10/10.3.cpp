#include <iostream>
#include <random>
#include <time.h>
#include <algorithm> 
using namespace std;
void displayRun(int values[], int size);
bool hasRun(int Values[], int size);
int main(void)
{
	int values[20];
	int size = 20;
	srand(time(NULL));
	while (true)
	{
		for (int i = 0; i < 20; i++)
		{
			values[i] = rand() % 6 + 1;
		}
		if (hasRun(values, size))
		{
			break;
		}
	}
	displayRun(values, size);
}
bool hasRun(int values[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (values[i] == values[j])
			{
				return true;
			}
		}
	}
	return false;
}
void displayRun(int values[], int size)
{
	for (int g = 0; g < size; g++)
	{
		cout << values[g] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (values[i] == values[i + 1])
		{
			cout << "(" << values[i];
			for (int j = i + 1; j<size;j++)
			{
				if (values[j] == values[i])
				{
					cout << " " << values[j];
				}
				if (values[j] != values[i])
				{
					cout << ") ";
					cout << values[j] << " ";
					i = j;
					j += size;
				}
			}
		}
		else
		{
			cout << values[i] << " ";
		}
	}
}