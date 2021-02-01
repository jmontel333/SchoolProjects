//jesse montel	
#include <iostream>
using namespace std;
int main(void)
{
	//vars
	char temptype;
	int tempurature = 0;
	int cFreeze = 0;
	int fFreeze = 32;
	int Cboil = 100;
	int Fboil = 212;
	//get info from user
	cout << "please enter in temp type then temp(ie. C 20): ";
	cin  >> temptype >> tempurature;
	//determine f or c
	if (temptype == 'C')
	{
		if (tempurature == 0)
		{
			cout << "the water is a liquid and a solid";
		}
		if (tempurature < 0)
		{
			cout << "the water is frozen";
		}
		else if (tempurature == 100)
		{
			cout << "the water is a solid and a gas";
		}
		else if (tempurature > 100)
		{
			cout << "the water is a gas";
		}
		else
		{
			cout << "the water is a liquid";
		}
	}
	if (temptype == 'F')
	{
		if (tempurature < 32)
		{
			cout << "the water is frozen";
		}
		if (tempurature == 32)
		{
			cout << "the water is a liquid and a solid";
		}
		else if (tempurature > 212)
		{
			cout << "the water is a gas";
		}
		else if (tempurature == 212)
		{
			cout << "the water is a solid and a gas";
		}
		else
		{
			cout << "the water is a liquid";
		}
	}

}