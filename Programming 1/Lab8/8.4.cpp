#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
string zellers(int day, int month, int year);
string monthshower(int month);
int yearshower(int month, int year);
int main(void)
{
	int day, month, year;
	while(true)
	{
		cout << "enter a date (day month year) or enter q to quit: ";
		cin >> day >> month >> year;
		if (cin.fail())
		{
			break;
		}
		else
		{
			cout << zellers(day, month, year) << ", " << monthshower(month) << " " << day << " " << yearshower(month, year) << endl;
		}
	}
}
//will return the day of the week for the day month and year
string zellers(int day, int month, int year)
{
	string dayofweek = "ewwwww";
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}
	int intday = (day + (((month + 1) * 26) / 10) + year + (year / 4) + (6 * (year / 100)) + (year / 400)) % 7;
	switch (intday)
	{
	case 1: dayofweek = "Sunday";
		break;
	case 2: dayofweek = "Monday";
		break;
	case 3: dayofweek = "Tuesday";
		break;
	case 4: dayofweek = "Wednesday";
		break;
	case 5: dayofweek = "Thursday";
		break;
	case 6: dayofweek = "Friday";
		break;
	case 0: dayofweek = "Saturday";
		break;
	}
	return dayofweek;
}
string monthshower(int month)
{
	string months = "";
	switch (month)
	{
	case 1: months = "Janurary";
		break;
	case 2: months = "Februrary";
		break;
	case 3: months = "march";
		break;
	case 4: months = "april";
		break;
	case 5: months = "may";
		break;
	case 6: months = "june";
		break;
	case 7: months = "july";
		break;
	case 8: months = "august";
		break;
	case 9: months = "september";
		break;
	case 10: months = "october";
		break;
	case 11: months = "november";
		break;
	case 12: months = "december";
		break;
	}
	return months;
}
int yearshower(int month, int year)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}
	return year;
}

