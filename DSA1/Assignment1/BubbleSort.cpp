//bubble sort c++ code with comparison and swap counters
#include <iostream>
#include <vector>
using namespace std;
vector<int> list;
int main(void) {
	int x = 0;
	int comps = 0;
	int swaps = 0;
	//gets the values to be added to the array
	while (cin >> x) {
		list.push_back(x);
		if (cin.fail()) {
			break;
		}
	}
	//prints out list to confirm its in the proper order before sorting
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i) << endl;
	}
	//sorts the values using bubble sort
	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j < list.size()-1; j++) {
			comps++; //the program compares here so we increment the compare counter
			if (list.at(j) > list.at(j + 1)) {
				swaps++; //the program performs a swap so we will increment the swap counter
				int holder = list.at(j); //holds the value in order to swap it with the value in front of it
				//completes the swap
				list.at(j) = list.at(j + 1);
				list.at(j + 1) = holder;
			}
		}
	}
	cout << "swaps: " << swaps << endl;
	cout << "compares: " << comps << endl;
	//prints out list to confirm its in the proper order after sorting
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i) << endl;
	}
}