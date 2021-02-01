/*
* Programming 1 MP2.ccp
* Jesse Montel
* date:10/24/2019
* This program will simulate the dice game "roll em pigs"
* It randomly silumlates the die and adds to the scores as needed
*
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
int rollDie(void);
bool isTurnScoreLost(int die1value, int die2value);
bool isGameScoreLost(int die1value, int die2value);
char getUserInput(void);
void turnTimer(void);
void gotoxy(int x, int y);
void header(string player);
void rules(void);
void cleanup(void);
vector <string> playerNames(void);
int main(void)
{	
	rules(); // shows the rules of the game if the player wants
	srand(time(NULL)); // makes sure the game is truly random
	int die1;
	int die2;
	int player1GameTotal = 0;
	int tempPlayer1Total = 0;
	int compGameTotal = 0;
	int tempCompGameTotal = 0;
	int turnTotal;
	vector <string> names;
	string player1, rollStay;
	names = playerNames();
	player1 = names[0];
	system("CLS"); //clears the screen
	header(player1); // prints out the scoreboard that will be edited
	while (true)
	{
		turnTotal = 0;
		do //start of the huamns turn
		{
			die1 = rollDie();
			die2 = rollDie();
			gotoxy(30, 7); // sets the cursor and outputs the rolls for the player
			cout << die1;
			gotoxy(43, 7);
			cout << die2;
			if (isTurnScoreLost(die1, die2))
			{
				gotoxy(0, 8);
				cleanup();
				gotoxy(0, 8);//cleans the bottom of the screen
				cout << "you rolled a 1 resetting your total for the turn and ending your turn";
				turnTotal = 0;
				turnTimer();
				gotoxy((16 + player1.length() - 1), 4); // changes the marker over to the computers turn
				cout << " ";
				gotoxy((21 + player1.length() - 1), 4);
				cout << "x";
				break; //sends turn to the comuter
			}
			if (isGameScoreLost(die1, die2))
			{
				gotoxy(0, 8);//cleans the bottom of the screen
				cleanup();
				gotoxy(0, 8);
				cout << "you rolled 2 1s resetting your score total to 0 and ending your turn";
				gotoxy((15 + player1.length() - 1), 3);//resets the players game total
				player1GameTotal = 0;
				cout << player1GameTotal;
				turnTotal = 0;
				turnTimer();
				gotoxy((16 + player1.length() - 1), 4);// changes the marker over to the computers turn
				cout << " ";
				gotoxy((21 + player1.length() - 1), 4);
				cout << "x";
				break; //sends turn to the comuter
			}
			turnTotal += (die1 + die2);
			tempPlayer1Total = turnTotal;
			gotoxy(63, 7);//updates the turn total
			cout << turnTotal;
			gotoxy(0, 8);//cleans the bottom of the screen
			cleanup();
			gotoxy(0, 8);
			if ((player1GameTotal + turnTotal) >= 100) // ends the game if the player reaches 100 or more
			{
				gotoxy(0, 8);//cleans the bottom of the screen
				cleanup();
				gotoxy(0, 8);
				cout << player1 << " wins, congrats you have defeated the machine";
				break;
			}
		} while (getUserInput() == 'r'); //end of the player turn if 's'
		player1GameTotal += turnTotal;
		gotoxy((15 + player1.length() - 1), 3);//changes the players game score to the proper score
		cout << "   ";
		gotoxy((15 + player1.length() - 1), 3);
		cout << player1GameTotal;
		if (player1GameTotal >= 100) // ends the game if the player reaches 100
		{
			gotoxy(0, 8);//cleans the bottom of the screen
			cleanup();
			gotoxy(0, 8);
			cout << player1 << " wins, congrats you have defeated the machine";
			break;
		}
		turnTotal = 0;//resets the turn total for the computers turn
		gotoxy(63, 7);
		cout << "  ";
		gotoxy((16 + player1.length() - 1), 4); //changes the marker to the computers side
		cout << " ";
		gotoxy((21 + player1.length() - 1), 4);
		cout << "x";
		while (true)//start of the computers turn
		{
			die1 = rollDie();
			die2 = rollDie();
			gotoxy(30, 7);//shows the die values
			cout << die1;
			gotoxy(43, 7);
			cout << die2;
			if (isTurnScoreLost(die1,die2))
			{
				gotoxy(0, 8);//cleans the bottom of the screen
				cleanup();
				gotoxy(0, 8);
				cout << "the machine rolled a 1 resetting its total for the turn and ending its turn";
				turnTotal = 0;
				turnTimer();
				gotoxy((16 + player1.length() - 1), 4);//changes the marker back over to the players side
				cout << "x";
				gotoxy((21 + player1.length() - 1), 4);
				cout << " ";
				break;//sends turn back to the player
			}
			if (isGameScoreLost(die1, die2))
			{
				gotoxy(0, 8);//cleans the bottom of the screen
				cleanup();
				gotoxy(0, 8);
				cout << "the machine rolled 2 1s resetting its score total to 0 and ending its turn";
				compGameTotal = 0;
				turnTotal = 0;
				turnTimer();
				gotoxy((16 + player1.length() - 1), 4);//changes the marker back over to the players side
				cout << "x";
				gotoxy((21 + player1.length() - 1), 4);
				cout << " ";
				break;//sends the turn back to the player
			}
			turnTotal += (die1 + die2);
			tempCompGameTotal = turnTotal;
			gotoxy(63, 7); //updates the turn total
			cout << turnTotal;
			turnTimer();
			if ((compGameTotal + turnTotal) >= 100) //ends the game if the computer wins
			{
				gotoxy(0, 8);//cleans the bottom of the screen
				cleanup();
				gotoxy(0, 8);
				cout << "the machine ends its turn and wins the game... noob";//flames the user for losing
				break;
			}
			if (turnTotal < 25)//has the computer roll again if its turnscore is less than 25
			{
				gotoxy(0, 8);//cleans the bottom of the screen
				cleanup();
				gotoxy(0, 8);
				cout << "the machine chooses to roll again";
			}
			if (turnTotal >= 25)//ends the computers turn if it has more than 25 in its turn total
			{
				gotoxy(0, 8);//cleans the bottom of the screen
				cleanup();
				gotoxy(0, 8);
				cout << "the machine ends its turn";
				turnTimer();
				gotoxy((16 + player1.length() - 1), 4);//changes the turn indicator back over to the humans side
				cout << "x";
				gotoxy((21 + player1.length() - 1), 4);
				cout << " ";
				break;
			}
		}
		compGameTotal += turnTotal;
		gotoxy((21 + player1.length() - 1), 3);//sets computers game total
		cout << "   ";
		gotoxy((21 + player1.length() - 1), 3);
		cout << compGameTotal;
		if (compGameTotal >= 100)
		{
			break;
		}
		gotoxy(63, 7);//resets the turn total
		cout << "  ";
	}
}
//simulates rolling a die its currently set to roll from 1 to 6
//@param void
//@return die roll as an int
int rollDie(void)
{
	int roll;
	roll = rand() % 6 + 1; //will produce random number between 1 and 6
	return roll;
}
//checks if the turn score is lost when given 2 die values true means the score is lost and false means it isnt
//@param 1 die roll
//@param another die roll
//@return true or false based on if the turn score is lost
bool isTurnScoreLost(int die1value, int die2value)
{
	if (die1value == 1 || die2value == 1)
	{
		if (die1value != die2value)
		{
			return true;
		}
	}
	return false;
}
//checks if the game score is lost when given 2 die values true means the score is lost and false means it isnt
//@param 1 die roll
//@param another die roll
//@return true or false based on if the total game score is lost
bool isGameScoreLost(int die1value, int die2value)
{
	if (die1value == die2value)
	{
		if (die1value == 1)
		{
			return true;
		}
	}
	return false;
}
//determines if the user wants to roll again by outputting a prompt
//@param void
//@param returns 's' or 'r' to check if the user wants to roll again or not
char getUserInput(void)
{
	char rOrS;
	do
	{
		cout << "would you like to roll again or stop (r=roll again, s=stop rolling): ";
		cin >> rOrS;
		if (cin.fail())
		{
			continue;
		}
	} 
	while (rOrS != 'r' && rOrS != 'R' && rOrS != 's' && rOrS != 'S');
	if (rOrS == 'R')
	{
		rOrS = 'r';
	}
	if (rOrS == 'S')
	{
		rOrS = 's';
	}
	return rOrS;
}
//asks for the players name and returns it within a vector
//@param void
//@return the players name in a vector
vector <string> playerNames(void)
{
	vector <string> names;
	string player1;
	string player2;
	cout << "what is your name: ";
	cin >> player1;
	cout << "good luck defeating the evil machine " << player1 << endl;
	names.push_back(player1);
	return names;
}
//allows the user to more easily see what the computer is doing by slowing down the turns.
//@param void
//@return void
void turnTimer(void)
{
	double currenttime = time(NULL);
	while (time(NULL) <= (currenttime + 2))
	{

	}
}
//sets cursor location to allow for changing of the header
//@param x value which is how far from the left the cursor will be
//@param y value that is how far down from the top the cursor will be
//@return void
void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
//sets up the game board to be edited 
//@param the players name in a string
//@return void
void header(string player)
{
	
	cout << "				Roll Em Pigs						            " << endl;
	cout << "***********************************************************************" << endl;
	//for (int i = 0; i < player.length(); i++)
	//{
	//	cout << "i";
	//}
	cout << "		" << player << " vs The Machine " << endl;
	for (int i = 0; i < player.length(); i++)
	{
		cout << " ";
	}
	cout << "  Total score: 0 ** 0" << endl;
	for (int i = 0; i < player.length(); i++)
	{
		cout << " ";
	}
	cout << "  current turn x **  " << endl;

	cout << "***********************************************************************" << endl;
	cout << "***********************************************************************" << endl;
	cout << "current die values *** die1 =   *** die2 =   ****** turn total 0 ******" << endl;
	

}
//shows the player the rules if they want
//@param void
//@return void
void rules(void)
{
	string yOrN;
	while (true)
	{
		cout << "do you know how to play the game? (y=yes n=no): ";
		cin >> yOrN;
		if (cin.fail())
		{
			continue;
		}
		if (yOrN == "n" || yOrN == "N")
		{
			cout << "roll em pigs is a dice game for 2 players. You will be playing against a computer." << endl << "You roll 2 die and add them to your score total." << endl << "You can stop rolling and add that to your total or you can keep rolling." << endl;
			cout << "if you roll 1 1 then your score for the turn is reset and your turn ends" << endl << "if you roll 2 1s then your entire game score is reset and your turn ends." << endl << "First player to end their turn with a game score of 100 will win." << endl;
			break;
		}
		else
		{
			break;
		}
	}
}
//prints numerous spaces at the bottom of the screen inorder to clean up the screen
//@param void
//@return void
void cleanup(void)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			cout << "  ";
		}
		cout << endl;
	}
}