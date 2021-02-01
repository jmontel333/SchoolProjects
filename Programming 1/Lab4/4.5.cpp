//Jesse Montel
//9-19-2019
//lab4 part a
//calculates state of ohio sales tax at a 6.5% rate
#include <iostream>
using namespace std;
int main(void)
{
	//vars
	double price = 0; 
	double taxrate = 0;
	//get price of purchase
	cout << "enter total price of purchase: ";
	cin >> price;
	cout << "what is the taxrate: ";
	cin >> taxrate;
	//calculate tax added and where to round the tax added
	
	double taxaddedon = price* taxrate;
	int taxadonint = taxaddedon;
	int decimals = (taxaddedon - taxadonint)*1000;
	int thirddecimal = decimals % 10;
	price = price + taxaddedon;
	//adds on rounded tax
	int filler = price * 100;
	price = filler / 100.0;
	filler = taxaddedon * 100;
	taxaddedon = filler / 100.0;
	if (thirddecimal >= 5)
	{
		price = price + 0.01;
		taxaddedon += 0.01;
	}
	
	//returns total cost
	cout << "the total cost is: " << price << " the tax is: " << taxaddedon;
	 

	

}