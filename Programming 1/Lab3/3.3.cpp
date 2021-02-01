#include <iostream>
using namespace std;
int main(void)
{
	//vars
	double bookprice = 0;
	double bookspurchased = 0;
	double tax = 1.075;
	double shipping = 2.50;
	double orderPrice = 0;
	//get info from the user
	cout << "enter thotal cost of all books and number of books purchased: ";
	cin >> bookprice >> bookspurchased;
	//calc price of order
	orderPrice = (bookprice * tax) + (shipping * bookspurchased);
	//return the price
	cout << "the price of the order is: $" << orderPrice;
	return 0;
}