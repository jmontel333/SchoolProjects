#include <iostream>
#include <random>
#include <time.h>
using namespace std;
int main(void)
{
	srand(time(NULL));
	const int LIST_SIZE = 10;
	int size[LIST_SIZE];
	for (int i = 0; i < LIST_SIZE; i++)
	{
		size[i] = rand() % 8999 + 1000;
	}
	cout << endl << "the random integers: ";
	for (int i = 0; i < LIST_SIZE; i++)
	{
		cout << size[i] << "  ";
	}
	cout << endl << "the even indices: ";
	for (int i = 0; i < LIST_SIZE; i+=2)
	{
		cout << size[i] << "  ";
	}
	cout << endl << "the even values: ";
	for (int i = 0; i < LIST_SIZE; i ++)
	{
		if (size[i] % 2 == 0)
		{
			cout << size[i] << "  ";
		}
	}
	cout << endl << "reversed order: ";
	for (int i = LIST_SIZE-1; i >= 0; i--)
	{
		cout << size[i] << "  ";
	}
	cout << endl << "first and last number: " << size[0] << "  " << size[LIST_SIZE-1];

}