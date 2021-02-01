// Jesse Montel Lab5 9-26-2019
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main(void)
{
	//vars
	string looper;
	int diesides = 0;
	//loops the whole program until the user presses "Q"
	while (true)
	{
		//get a proper die side value
		do {
			cout << "would you like to quit?, enter Q to quit ";
			cin >> looper;
			if (looper == "Q")
			{
				return 0;
			}
			cout << "what sided die would you like to use? (20, 12, 10, 8, 6, 4): ";
			cin >> diesides;
			
		
		} while (diesides != 20 && diesides != 12 && diesides != 10 && diesides != 8 && diesides != 6 && diesides != 4);
		//returns random roll within the specified die range
		int roll;
		roll = rand() % diesides+1;
		cout << "your roll is: " << roll << endl;
		diesides = 0;
	}
}