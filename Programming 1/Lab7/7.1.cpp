#include <iostream>
using namespace std;
double smallest(double x, double y, double z);
double average(double x, double y, double z);
int main(void)
{
	double x;
	double y;
	double z;
	cout << "enter three numbers: ";
	cin >> x >> y >> z;
	cout << "smallest value is: " << smallest(x, y, z)<<endl;
	cout << "average is: " << average(x, y, z);
}
double smallest(double x, double y, double z)
{
	double smallest = x;
	if (y < x && y < z)
	{
		smallest = y;
	}
	if (y > z && z < x)
	{
		smallest = z;
	}
	return smallest;
}
double average(double x, double y, double z)
{
	double average = (x + y + z) / 3;
	return average; 
}
