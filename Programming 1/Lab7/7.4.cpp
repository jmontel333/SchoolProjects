#include <iostream>
#include <random>
#include <ctime>
using namespace std;
void movementSimulator(int seconds, int numberOfDrunks); //time in seconds
void displayDrunksLocation(int x, int y, int drunkardnumber);
int main(void)
{
	movementSimulator(120, 10);

}
void movementSimulator(int seconds, int numberOfDrunks)//time in seconds
{
	srand(time(NULL));
	for (int i = 1; i <= numberOfDrunks; i++)
	{
		int x = 0; 
		int y = 0;
		int movement;
		for (int j = 0; j <= seconds; j++)
		{
			movement = rand() % 9 + 1;
			switch (movement)
			{
			case 1: y += 1;
				break;
			case 2: x += 1, y += 1;
				break;
			case 3: x += 1;
				break;
			case 4: x += 1, y -= 1;
				break;
			case 5: y -= 1;
				break;
			case 6: x -= 1, y -= 1;
				break;
			case 7: x -= 1;
				break;
			case 8: x -= 1, y += 1;
			}
		}
		displayDrunksLocation(x, y, i);
	}
}
void displayDrunksLocation(int x, int y, int drunkardnumber)
{
	cout << "Dunkard #" << drunkardnumber << ": finished at location (" << x << ", " << y << ")"<<endl;
}


