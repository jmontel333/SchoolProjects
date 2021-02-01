

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void pressEnterToContinue();
int wordsInFile(string fileName);
int charsInFile(string fileName);

int main()
{
	string fileName;
	cout << "Input file: ";
	getline(cin, fileName);

	cout << endl << "Words: " << wordsInFile(fileName) << endl;
	cout << "Characters: " << charsInFile(fileName);

	pressEnterToContinue();
	return 0;
}

int wordsInFile(string fileName) {
	int count = 0;
	string word;
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile.is_open()) {
		cout << "File not found." << endl;
		return 1;
	}

	while (inFile >> word) {
		count++;
	}
	inFile.close();
	return count;
}

int charsInFile(string fileName) {
	int count = 0;
	char ch;
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile.is_open()) {
		cout << "File not found." << endl;
		return 1;
	}

	while (inFile >> ch) {
		count++;
	}
	inFile.close();
	return count;
}

void pressEnterToContinue()
{
	cout << "\nPress enter to continue... \n";
	cin.ignore(1024, '\n');
	cin.clear();
}