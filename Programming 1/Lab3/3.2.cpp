#include <iostream>
using namespace std;
int main(void)
{
	//vars
	double cost = 0;
	double mpg = 0;
	double milesDrivenPerYear = 0;
	double gasPrice = 0;
	double yearsUsed = 0;
	double resaleAmount = 0;
	double priceToOwn = 0;
	//ask user for values
	cout << "enter cost of car: ";
	cin >> cost;
	cout << "enter MPG: ";
	cin >> mpg;
	cout << "enter miles driven per year: ";
	cin >> milesDrivenPerYear;
	cout << "enter price of gas: ";
	cin >> gasPrice;
	cout << "enter years of use: ";
	cin >> yearsUsed;
	cout << "enter car resale amount: ";
	cin >> resaleAmount;
	//calc price of owning car
	priceToOwn = (cost + (((milesDrivenPerYear * yearsUsed) / mpg) * gasPrice)) - resaleAmount;
	cout << "net cost of car ownship: " << priceToOwn;
	return 0;
}