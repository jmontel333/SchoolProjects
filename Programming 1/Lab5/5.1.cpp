//Jesse Montel 9-26-19
#include <iostream>
using namespace std;
int main(void)
{
	int sumeven = 0;
	for (int i = 0; i <= 100; i += 2)
	{
		sumeven += i;
	}
	int sumsqr = 0;
	for (int i = 0; i <= 100; i++)
	{
		sumsqr += i*i;
	}
	cout << "the sum of the even nubmers from 1-100 is: " << sumeven << " the sum of the squares from 1-100: " << sumsqr;

}