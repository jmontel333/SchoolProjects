/*
* Programming 1 MP3.ccp
* Jesse Montel
* date:11/14/2019
* This program will play the game tic tac toe
* it will keep track of wins and losses all while switching who goes first and keeps xs and os the same
*
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
vector <string> playerNames(void);
int getPlayerInput(string playername);
bool isLegalMove(char board[], int location);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
bool hasThreeInRow(char board[], char playerMark);
void displayBoard(char board[]);
void displayGameStats(int ties, string player1Name, string player2Name, int player1score, int player2score);
const int BOARD_SIZE = 10;
const char X = 'X';
const char O = 'O';
int main(void)
{
	char board[BOARD_SIZE] = { '1','2','3','4','5','6','7','8','9','p' };		//sets up the starting game state board
	vector <string> names = playerNames();									    //gets the player names and returns them into an vector
	string player1 = names[0];
	string player2 = names[1];
	char playagain = ' ';
	int ties = 0;
	int player1score = 0;
	int player2score = 0;
	cout << player1 << " you are Xs and " << player2 << " you are Os" << endl;
	while (true)															    //this while loop contains the entire game which consists of 2 nearly identical while loops
	{																		    //the only difference being who goes first in each
		int turncounter = 0;													//this is a counter that will detect a tie
		while (true)                                                            //while loop for a whole game-player1 goes first in this game
		{
			displayBoard(board);
			while (true)                                                        //this loop will keep looping until a legal move is received
			{
				int player1move = getPlayerInput(player1);                      //will make sure the user inputs a number between 1-9 then it will check if that spot on the board is open
				if (isLegalMove(board, player1move))
				{
					placeMarkOnBoard(board, X, player1move);
					break;
				}
				else
				{
					continue;
				}
			}
			if (hasThreeInRow(board, X))                                        //ends the game if there are 3 Xs in a row
			{
				system("CLS");
				cout << player1 << " wins" << endl;
				displayBoard(board);
				player1score++;
				break;
			}
			turncounter++;
			if (turncounter == 9)                                               //keeps track of the turns taken and ends the game if 9 turns are reached(at 9 turns the game is tied)
			{
				cout << "the game ends in a tie" << endl;
				ties++;
				break;
			}
			system("CLS");
			displayBoard(board);
			while (true)                                                        //infinite loop that will only end once the game recives proper and legal input from the player
			{
				int player2move = getPlayerInput(player2);
				if (isLegalMove(board, player2move))
				{
					placeMarkOnBoard(board, O, player2move);
					break;
				}
				else
				{
					continue;
				}
			}
			if (hasThreeInRow(board, O))                                       //ends the game if the board has 3 Os in a row on it
			{
				system("CLS");
				cout << player2 << " wins" << endl;
				displayBoard(board);
				player2score++;
				break;
			}
			turncounter++;
			system("CLS");
		}
		clearBoard(board);
		displayGameStats(ties, player1, player2, player1score, player2score);  //displays the game stats inbetween games 
		turncounter = 0;
		cout << "would you like to play again? (Y or N): ";
		cin >> playagain;
		if (playagain == 'Y' || playagain == 'y')                             //will play another game if the player inputs Y or y, ends the program otherwise
		{

		}
		else
		{
			break;
		}
		while (true)                                                         //this loop contains another full game but this time player2 goes first, however X and O assignments remain the same
		{
			displayBoard(board);
			while (true)                                                     //infinite loop that will only end once the game recives proper and legal input from the player
			{
				int player2move = getPlayerInput(player2);
				if (isLegalMove(board, player2move))
				{
					placeMarkOnBoard(board, O, player2move);
					break;
				}
				else
				{
					continue;
				}
			}
			if (hasThreeInRow(board, O))                                    //ends the game if the board has 3 Os in a row on it
			{
				system("CLS");
				cout << player2 << " wins" << endl;
				displayBoard(board);
				player2score++;
				break;
			}
			turncounter++;
			if (turncounter == 9)                                           //keeps track of the turns taken and ends the game if 9 turns are reached(at 9 turns the game is tied)
			{
				cout << "the game ends in a tie" << endl;
				ties++;
				break;
			}
			system("CLS");
			displayBoard(board);
			while (true)                                                    //this loop will keep looping until a legal move is received
			{
				int player1move = getPlayerInput(player1);
				if (isLegalMove(board, player1move))
				{
					placeMarkOnBoard(board, X, player1move);
					break;
				}
				else
				{
					continue;
				}
			}
			if (hasThreeInRow(board, X))                                   //ends the game if there are 3 Xs in a row
			{
				system("CLS");
				cout << player1 << " wins" << endl;
				displayBoard(board);
				player1score++;
				break;
			}
			turncounter++;
			system("CLS");
		}
		clearBoard(board);
		displayGameStats(ties, player1, player2, player1score, player2score);
		turncounter = 0;
		cout << "would you like to play again? (Y or N): ";
		cin >> playagain;
		if (playagain == 'Y' || playagain == 'y')                         //will play another game if the player inputs Y or y, ends the program otherwise
		{

		}
		else
		{
			break;
		}
	}
}
//will ask for player1 and player2s names and return them in a vector with player1 in 0 and p2 in 1
//@return the players names in a vector
vector <string> playerNames(void)
{
	vector <string> names;
	string player1;
	string player2;
	cout << "what is player1's name?: ";
	cin >> player1;
	cout << "waht is player2's name?: ";
	cin >> player2;
	names.push_back(player1);
	names.push_back(player2);
	return names;
}
//gets the player input by asking for a number, will only return an int 1-9 inclusive
//****this program assumes that the input will be an integer******************
//@param playername - uses the name to ask for the player input by name
//@return an integer 1-9 inclusive 
int getPlayerInput(string playername)
{
	int space;
	while (true)//loops until the user inputs a number 1-9 inclusive
	{
		cout << "where would you like to go " << playername << " ?: ";
		cin >> space;
		if (space >= 1 && space <= 9)//checks if is within 1-9
		{
			return space;
		}
		else
		{
			cout << "that isn't 1-9, please enter a number 1-9";
		}
	}
}
//checks if the give int corresponds to an already taken location on the board
//@param char board- this the game board that will be checked(note array size is global so does not need to be passed)
//@param int location- this is the location that is being checked to see if it has already been played on
//@return bool- returns false if the location contains an X or O returns true otherwise
bool isLegalMove(char board[], int location)
{
	if (board[location - 1] == 'X' || board[location - 1] == 'O')//checks if the spot has already been played
	{
		return false;
	}
	else
	{
		return true;
	}
}
//will place a mark on the board, this function assumes that the move is legal
//@param char board- this is the game board that is to be marked
//@param char playermark- this gives the program either an X or an O to place
//@param int location- places the aforementioned X or O at 'location' on board
void placeMarkOnBoard(char board[], char playerMark, int location)
{
	board[location - 1] = playerMark;
}
//resests the board to its starting state
//@param char board- this is the board that will be reset aka location 0-8 will be set to numbers 1-9
void clearBoard(char board[])
{
	char list[9] = { '1','2','3','4','5','6','7','8','9' };//needed to use char list here becuase you can't enter ints into a char array
	for (int i = 0; i < 9; i++)
	{
		board[i] = list[i];
	}
}
//checks if board has 3 xs or os in a row-aka it checks to see if a player has won the game
//@param char board- this is the boad that is being checked
//@param char playerMark- this will either be X or O and this will be what is checked if there is 3 in a row of
//@return bool- returns treu if there is a three in a row returns false otherwise
bool hasThreeInRow(char board[], char playerMark)
{
	for (int i = 0; i < 10; i += 3)//sets i to first in each row ie 1,4,7
	{
		if (board[i] == playerMark && board[i] == board[i + 1] && board[i + 1] == board[i + 2])//if there is a 3 in a row across
		{
			return true;
		}
	}
	for (int i = 0; i < 3; i++)//sets i to posistion 1,2,3
	{
		if (board[i] == playerMark && board[i] == board[i + 3] && board[i + 3] == board[i + 6])//if 3 row in a row up and down
		{
			return true;
		}
	}
	if (board[0] == playerMark && board[0] == board[4] && board[4] == board[8])//checks for diagonal
	{
		return true;
	}
	if (board[2] == playerMark && board[2] == board[4] && board[4] == board[6])//check opposite diagonal
	{
		return true;
	}
	return false;
}
//this will print out the board in the proper format
//@param char board- this is the baord that will be printed out
void displayBoard(char board[])
{
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}
//displays the wins ties and losses from all of the previous games this run
//@param int ties- the number of ties
//@param string player1Name- player1's name
//@parm string player2name- player2's name
//@param int player1score- the number of wins player1 has
//@param int player2score- the number of wins player2 has
void displayGameStats(int ties, string player1Name, string player2Name, int player1score, int player2score)
{
	cout << "ties = " << ties << endl << player1Name << "'s wins: " << player1score << endl << player2Name << "'s wins: " << player2score << endl << endl;

}

