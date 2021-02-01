#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	int enteries= 0,on = 1;
	double sum = 0, sumofsqrs = 0, n = 0, average = 0, deviation = 0;
	while (true)
	{
		cout << "enter number or enter q to quit: ";
		cin >> n;
		if (cin.fail())
		{
			break;
		}
		else
		{
			enteries += 1;
			sum = sum + n;
			sumofsqrs = sumofsqrs + (n * n);
		}
	}
	if (enteries == 0)
	{
		cout << "no data to process - exiting";
	}
	else
	{
		cout << endl << "you entered " << enteries << " numbers\n";
		average = sum / enteries;
		cout << "the average of the nubmers that you entered was " << average << endl;
		double x = (sumofsqrs - ((sum * sum) / enteries)) / (enteries - 1);
		deviation = sqrt(x);
		cout << "your standard deviation is " << deviation;
	}
}