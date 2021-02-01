#include <iostream>
using namespace std;
int main(void)
{
	int ccnumber;
	int ccright;
	int ccrem;
	int right1;
	int right2;
	int right3;
	int right4;
	int rightsum;
	int rem1;
	int rem12;
	int rem2;
	int rem22;
	int rem3;
	int rem32;
	int rem4;
	int rem42;
	int remsum;
	int checker;
	cout << "please enter in cc number: ";
	cin >> ccnumber;
	ccright = ccnumber;
	ccrem = ccnumber;
	right1 = ccright % 10;
	ccright /= 100;
	right2 = ccright % 10;
	ccright /= 100;
	right3 = ccright % 10;
	ccright /= 100;
	right4 = ccright % 10;
	rightsum = right1 + right2 + right3 + right4;
	ccrem /= 10;
	rem1 = ccrem % 10;
	ccrem /= 100;
	rem2 = ccrem % 10;
	ccrem /= 100;
	rem3 = ccrem % 10;
	ccrem /= 100;
	rem4 = ccrem % 10;
	rem1 *= 2;
	rem2 *= 2;
	rem3 *= 2;
	rem4 *= 2;
	rem12 = rem1 % 10;
	rem1 /= 10;
	rem22 = rem2 % 10;
	rem2 /= 10;
	rem32 = rem3 % 10;
	rem3 /= 10;
	rem42 = rem4 % 10;
	rem4 /= 10;
	remsum = rem1 + rem2 + rem3 + rem4+ rem12 + rem22 + rem32 + rem42;
	checker = remsum + rightsum;
	checker %= 10;
	if (checker == 0)
	{
		cout << "that is a valid cc card";
	}
	else
	{
		cout<< "that is an invalid nubmer";
	}
	

	




}