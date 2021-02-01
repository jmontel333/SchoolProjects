//Jesse Montel
//9-30-19
//Programming 1 MP1.ccp
//This program will take the number and kind of dougnuts purchased
//and produce the price with tax included
// it will then take in what the customer and outputs what change is to be given back
// this change is displayed in dollars, quarters, dimes, nickels, and pennies
#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
	//varibles 
	double CostPreTax, CostPostTax, AmountTendered, change;
	int RegDnuts, FancyDnuts, dollars, Quaters, dimes, nickels, cents, pennies;
	const double REG_DOUGHNUT = 0.75, FANCY_DOUGHNUT = 0.85, REG_DOZEN = 7.99, FANCY_DOZEN = 8.49, TAX = 0.075;
	//get the number of the different doughnuts from the costmer 
	cout << "Number of regular donuts ordered: ";
	cin >> RegDnuts;
	cout << "Number of fancy donuts ordered: ";
	cin >> FancyDnuts;
	//compute what the costomer owes including tax
	CostPreTax = (((RegDnuts / 12) * REG_DOZEN) + ((RegDnuts % 12) * REG_DOUGHNUT) + ((FancyDnuts / 12) * FANCY_DOZEN) + ((FancyDnuts % 12) * FANCY_DOUGHNUT));
	//calculate tax added and where to round the tax added
	double taxaddedon = CostPreTax * TAX;
	int taxadonint = taxaddedon;
	int decimals = (taxaddedon - taxadonint) * 1000;
	int thirddecimal = decimals % 10;
	CostPostTax = CostPreTax + taxaddedon;
	//adds on rounded tax and gets rid of the extranous decimals
	int filler = CostPostTax * 100;
	CostPostTax = filler / 100.0;
	filler = taxaddedon * 100;
	taxaddedon = filler / 100.0;
	if (thirddecimal >= 5)
	{
		CostPostTax = CostPostTax + 0.01;
		taxaddedon += 0.01;
	}
	//displays cost after tax
	cout << "Customer owes $" << CostPostTax << endl;
	//asks the user for how much the customer paid
	cout << "Customer pays $";
	cin >> AmountTendered;
	//calculates the best way to return the change
	change = AmountTendered - CostPostTax;
	cents = (change * 100)+0.5;//the +0.5 will round the cents up to prevent errors
	dollars = cents / 100;
	Quaters = (cents % 100) / 25;
	dimes = ((cents%100)%25) / 10;
	nickels = (((cents%100)%25)%10) / 5;
	pennies = ((((cents%100)%25)%10)%5);
	//returns the proper change 
	if (AmountTendered == CostPostTax)
	{
		cout << "Exact payment received - no change owed.";
	}
	else
	{
		cout << "Change owed is $" << fixed << setprecision(2) << change << " - ";//the fixed and setprecision will allow for the display of 2.50 instead of just 2.5
	}
	if (dollars != 0)
	{
		if (dollars == 1)
		{
			cout << dollars << " dollar";
		}
		else if (dollars > 1)
		{
			cout << dollars << " dollars";

		}
		//puts a period on the end if just dollars are to be given as change and if dollars isn't that last thing then a comma is added
		if (Quaters == 0 && nickels == 0 && dimes == 0 && pennies == 0)
		{
			cout << ".";
		}
		else
		{
			cout << ",";
		}
	}
	if (Quaters != 0)
	{
		if (Quaters == 1)
		{
			cout << " " << Quaters << " quarter";
		}
		else if (Quaters > 1)
		{
			cout << " " << Quaters << " quarters";

		}
		//puts a period on the end if quarters are the last peice of change given if quarters arent the last thing then a comma is added
		if (nickels == 0 && dimes == 0 && pennies == 0)
		{
			cout << ".";
		}
		else
		{
			cout << ",";
		}
	}
	if (dimes != 0)
	{
		if (dimes == 1)
		{
			cout << " " << dimes << " dime";
		}
		else
		{
			cout << " " << dimes << " dimes";

		}
		//puts a period on the end if dimes are the last peice of change given if dimes arent the last thing then a comma is added
		if (nickels == 0 && pennies == 0)
		{
			cout << ".";
		}
		else
		{
			cout << ",";
		}
	}
	if (nickels != 0)
	{
		if (nickels == 1)
		{
			cout << " " << nickels << " nickel";
		}
		else
		{
			cout << " " << nickels << " nickels";

		}
		//puts a period on the end if nickels are the last peice of change given if nickels arent the last thing then a comma is added
		if (pennies == 0)
		{
			cout << ".";
		}
		else
		{
			cout << ",";
		}
	}
	if (pennies != 0)
	{
		if (pennies == 1)
		{
			cout << " " << pennies << " penny.";
		}
		else
		{
			cout << " " << pennies << " pennies.";

		}
	}
}