#include <iostream>
using namespace std;
int main(void)
{
	//vars
	double price;
	double paid;
	double change;
	int dollars;
	int quaters;
	int dimes;
	int nickles;
	int pennies;
	int cents;
	cout << "how much is the item: ";
	cin >> price;
	cout << "how much was paid: ";
	cin >> paid;
	change = paid - price;
	cents = change * 100;
	dollars = cents / 100;
	cents = cents - dollars * 100;
	quaters = cents / 25;
	cents = cents - quaters*25;
	dimes = cents / 10;
	cents = cents - dimes * 10;
	nickles = cents / 5;
	cents = cents - nickles * 5;
	pennies = cents;
	if (dollars != 0)
	{
		cout << dollars << "dollars" << endl;
	}
	if (quaters != 0)
	{
		cout << quaters << "quaters" << endl;
	}
	if (dimes != 0)
	{
		cout << dimes << "dimes" << endl;
	}
	if (nickles != 0)
	{
		cout << nickles << "nickels" << endl;
	}
	if (pennies != 0)
	{
		cout << pennies << "pennies"<<endl;
	}

}