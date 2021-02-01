#include <iostream>
#include <algorithm>
#include <chrono>
#include <array>
/*
	Assigment 5 DSA 
	Author- Jesse Montel
	written 9/21/2020
*/
using namespace std;
pair<int,int> binarySearch(int list[], int start, int finish, int key);
pair<int,int> linearSearch(int list[], int listSize, int key);
void arrayCreator();
int const listSize = 1000000;//making array size a const varible makes changing code easier
int list[listSize];
int main(void) {
	cout << "***********************************************************************" << endl;
	cout << "Linear Search: " << endl << "--------------" << endl;
	cout << "Input Size = " << listSize << endl;
	double linearTimeAverage = 0; //used to track and output the average of the linear times
	int linearComparisions = 0;
	//this for is for running the linear search 5 times in a row to test its speed
	for (int j = 0; j < 5; j++) {
		auto start = chrono::steady_clock::now();
		srand(time(0));//this will assure a different list is generated each time we run the program
		arrayCreator();
		pair<int, int> linearOutput = linearSearch(list, listSize, (listSize*3) + 1);
		auto stop = chrono::steady_clock::now();
		chrono::duration<double> linearTime = stop - start;
		cout << "	" << "elapsed time for run#" << j + 1 << ": " << fixed <<  linearTime.count() << "s" << endl;
		linearTimeAverage += linearTime.count();
		linearComparisions += linearOutput.first;
	}//end for
	cout << endl << "	" << "average search time: " << linearTimeAverage / 5 << endl;
	cout << "	#of comparisons made: " << linearComparisions << endl;
	cout << endl << "***********************************************************************" << endl;
	cout << "Binary Search:" << endl <<  "--------------" << endl;
	cout << "Input Size = " << listSize << endl;
	srand(time(0));//this will assure a different list is generated each time we run the program
	arrayCreator();
	auto start = chrono::steady_clock::now();
	sort(begin(list), end(list));
	auto stop = chrono::steady_clock::now();
	chrono::duration<double> sortTime = stop - start;
	double binaryTimeAverage = 0;
	int binaryComparisions = 0;
	//for used for testing timing 5 times (note this is setup to sort the same list 5 times in a row im not sure if thats how you wanted it or not)
	for (int j = 0; j < 5; j++) {
		auto start = chrono::steady_clock::now();
		pair<int, int> binaryOutput = binarySearch(list, 0, listSize, (listSize*3) + 1);
		auto stop = chrono::steady_clock::now();
		chrono::duration<double> binaryTime = stop - start;
		cout << "	" << "elapsed time for run#" << j + 1 << ": " << fixed << binaryTime.count() << "s" << endl;
		binaryTimeAverage += binaryTime.count();
		binaryComparisions += binaryOutput.first;
	}//end for
	cout << endl << "	" << "average search time: " << binaryTimeAverage / 5 << endl;
	cout << "	" << "sorting time: " << sortTime.count() << endl;
	cout << "	" << "# of comparisions made: " << binaryComparisions << endl;
	
}//end main

/*
	implements a binary search
	list - the array to be searched
	start - the starting point of the search
	finish - the ending point of the search
	key - what number we are looking for in the array
	returns a pair with the first number being the times binary search called itself and the 2nd being the location of the key if found
*/
pair<int,int> binarySearch(int list[], int start, int finish, int key) {
	static int timesCalled = 0;
	int location = -1;//location will be negative 1 if key isn't found
	if (start <= finish) {
		int middle = (finish + start) / 2;
		//if the searched value ends up in the middle then we are done
		if (list[middle] == key) {
			timesCalled++;
			location = middle;
			return make_pair(timesCalled, location);
		}//end if
		if (list[middle] > key) {
			timesCalled++;
			return binarySearch(list, start, middle - 1, key);
		}//end if
		if (list[middle] < key) {
			timesCalled++;
			return binarySearch(list, middle + 1, finish, key);
		}//end if
	}//end if
	return make_pair(timesCalled, location);
}//end binarySearch
/*
	linear search 
	searches list of listSize for an it key
	returns pair of ints the first being the comparisions and the 2nd being the location of the value if found
*/
pair<int,int> linearSearch(int list[], int ListSize, int key) {
	int comparisions = 0;
	int location = -1;//will return -1 if not found in array
	for (int j = 0; j < ListSize; j++) {
		comparisions++;
		if (list[j] == key) {
			location = j;
			return make_pair(comparisions, location);
		}//end if
	}//end for
	return make_pair(comparisions, location);
}//end linearSearch
/*
	array creator creates the new array to the specs needed for the test run
*/
void arrayCreator() {
	for (int j = 0; j < listSize; j++) {
		list[j] = rand() % (listSize * 6) - (listSize * 3);//creates a random number;
	}//end for
}//end arrayCreator
