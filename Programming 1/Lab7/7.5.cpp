#include <iostream>
#include <random>
#include <ctime>
using namespace std;
double movementSimulator(int seconds, int numberOfDrunks); //time in seconds
double expectedfinaldistancecalc(double minutes);
int main(void)
{
	double userminutes;
	cout << "enter number of hours ofr each drunkard to stagger: ";
	cin >> userminutes;
	double expectedFinalDistance = expectedfinaldistancecalc(userminutes);
	cout << "expected distance: " << expectedFinalDistance << endl;
	int seconds = userminutes * 60;
	double averageDistance = movementSimulator(seconds, 10000);
	cout << "average distance: " << averageDistance;
}
double movementSimulator(int seconds, int numberOfDrunks)//time in seconds
{
	double distanceTraveled = 0;
	srand((unsigned)time(0));
	const double CORNERSTEPLENGTH = sqrt(2);
	double totaldistance = 0;
	for (int i = 1; i <= numberOfDrunks; i++)
	{
		distanceTraveled = 0;
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
		distanceTraveled += sqrt((x * x) + (y * y));
		totaldistance += distanceTraveled;
	}
	double averagedistance = totaldistance / numberOfDrunks;
	return averagedistance;
}
double expectedfinaldistancecalc(double minutes)
{
	const double AVERGAESTEPLENGTH = (4 + (4 * sqrt(2))) / 9.0;
	double seconds = minutes*60.0;
	double totalsteps = seconds;
	double expectedFinalDistance = sqrt(totalsteps * AVERGAESTEPLENGTH);
	return expectedFinalDistance;
}