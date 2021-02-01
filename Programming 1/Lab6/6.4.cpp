#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double pi,times,temp = 1;
	int numtimes = 10000;
	for (numtimes; numtimes <= 100000; numtimes+=10000)
	{
		temp = 1;
		for (double i = 2; i <= numtimes; i++)
		{
			temp += (pow(-1.0,i+1.0)/((2.0*i)-1.0));
		}
		pi = 4 * temp;
		cout << fixed << setprecision(13) << pi << endl;
	}
}