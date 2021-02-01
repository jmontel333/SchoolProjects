#include <iostream>
#include <stdlib.h>
using namespace std;
string seats[13][4] = { {"A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","C","D" }, { "A","B","","" } };
string seatnums[13] = { " 1", " 2", " 3", " 4"," 5"," 6"," 7"," 8"," 9","10","11","12","14" };
void seatdisplays();
int main(void)
{
	bool checker = true;
	bool seatbool = true;
	int row,seatnum;
	string seat;
	seatdisplays();
	while (true)
	{
		seatbool = true;
		while (true)
		{
			while (seatbool)
			{
				cout << "what seat do u want you filthy animal(number lettter ex 11 C): ";
				cin >> row >> seat;
				if (row > 14 || row == 13 || row < 1)
				{
					cout << "seat no exsist dumb user" << endl;
					continue;
				}
				row--;
				if (row == 13)
				{
					row--;
				}
				if (seat == "A" || seat == "a")
				{
					seatnum = 0;
					seatbool = false;
				}
				if (seat == "B" || seat == "b")
				{
					seatnum = 1;
					seatbool = false;
				}
				if (seat == "C" || seat == "c")
				{
					seatnum = 2;
					seatbool = false;
				}
				if (seat == "D" || seat == "d")
				{
					seatnum = 3;
					seatbool = false;
				}
				if (seatbool == true)
				{
					cout << "seat no exsist dumb user" << endl;
				}
			}
			if (seats[row][seatnum] == "X")
			{
				cout << "ur an idiot" << endl;
				seatbool = true;
				continue;
			}
			break;
		}
		seats[row][seatnum] = "X";
		system("CLS");
		seatdisplays();
		while (checker)
		{
			for (int i = 0; i < 13; i++)
			{
				if (i == 12)
				{
					for (int j = 0; j < 2; j++)
					{
						if (seats[i][j] != "X")
						{
							checker = false;
						}
					}
				}
				else
				{
					for (int j = 0; j < 4; j++)
					{
						if (seats[i][j] != "X")
						{
							checker = false;;
						}
					}
				}
			}
			if (checker == true)
			{
				while (true)
				{

				}
			}
		}
		checker = true;
	}
}
void seatdisplays()
{
	for (int i = 0; i < 13; i++)
	{
		cout << seatnums[i] << " ";
		if (i == 12)
		{
			for(int j = 0; j < 2; j++)
			{
				cout << seats[i][j];
			}
		}
		else
		{
			for (int j = 0; j < 2; j++)
			{
				cout << seats[i][j];
			}
			cout << " ";
			for (int j = 2; j < 4; j++)
			{
				cout << seats[i][j];
			}
		}
		cout << endl;
	}
}