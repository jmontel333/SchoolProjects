/*
* Programming 1 MP4.ccp
* Jesse Montel
* date:12/5/2019
* This program will cipher and decipher text based on a keyword
* 
*
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
char encipher(char key, char plain);
char decipher(char key, char cipher);
int main(void)
{
	ofstream output;
	ifstream input;
	char eod, c;
	string filename;
	string outputfile;
	string keyword;
	int i = 0, keylen;
	cout << "what is the name of the file that you would like to work with: ";							//gets the name of the text file to be worked with (encoded or decoded)
	cin >> filename;
	input.open(filename.c_str());																		//opens file
	if (!input)																							//breaks if open fails
	{
		cout << "failed to open";
		return 1;
	}
	cout << "would you like to encode or decode your text file ('E' for encode || 'D' for decode): ";	//user chooses encoding mode or decoding mode
	cin >> eod;
	if (eod == 'E')																						//encoding mode
	{
		cout << "where would you like to output your encoded characters: ";
		cin >> outputfile;
		output.open(outputfile.c_str());
		if (!output)																					//breaks if open fails
		{
			cout << "failed to open";
			return 1;
		}
		cout << "enter the keyword with no whitespace: ";												//gets the keyword from the user
		cin >> keyword;
		keylen = keyword.length();
		while (input.get(c))																			
		{
			output.put(encipher(keyword[i%keylen], c));													//will change the characters based off the keywords and put them into the output file
			i++;																						//this will "loop" the keyword for the length of the file
		}
	}
	else if (eod == 'D')																				//decode mode
	{
		cout << "where would you like to output your decoded characters: ";								//gets output file from the user
		cin >> outputfile;
		output.open(outputfile.c_str());
		if (!output)																					//breaks if open fails
		{
			cout << "failed to open";
			return 1;
		}
		cout << "enter the keyword with no whitespace: ";												//gets the keyword from the user
		cin >> keyword;
		keylen = keyword.length();
		while (input.get(c))
		{
			output.put(decipher(keyword[i%keylen], c));													//decodes the character and puts the decoded character into the output file
			i++;																						//this will "loop" the keyword for the length of the file
		}
	}
	else
	{
		cout << "you entered in something wrong dummy boi";												// goes here if they miss enter E or D
	}
	input.close();
	output.close();
}
//enciphers the given plaintext character using the given key character
//@param char key- its a key out of the character key
//@param char plain- the plaintext character that will be encoded
//return returns the encoded character
char encipher(char key, char plain)
{
	char n = key + plain;
	return n;
}																										//note that the char key must be the same both times for the text to be decoded properly
//deciphers the given plaintext character using the given key character
//@param char key- its a key out of the character key
//@param char plain- the plaintext character that will be encoded
//return returns the decoded character
char decipher(char key, char cipher)
{
	char n = cipher - key;
	return n;
}

