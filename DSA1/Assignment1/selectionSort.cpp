#include <iostream>
#include <vector>
using namespace std;
//selection sort algorthim implementation 
vector<int> list;
int main(void) {
	int swaps = 0;
	int compares = 0;
	int smallest;
	//gets the list from the user
	int x;
	while (cin >> x) {
		list.push_back(x);
		if (cin.fail()) {
			break;
		}
	}
	//prints out list to check for correct input
	for (int j = 0; j < list.size(); j++) {
		cout << list.at(j) << endl;
	}
	//sorts the list using the selection sort method
	for (int j = 0; j < list.size() - 1; j++) {
		smallest = j;
		for (int i = j + 1; i < list.size(); i++) {
			compares++;
			if (list.at(i) < list.at(smallest)) {
				smallest = i;
			}
		}
		if (smallest != j) {
			int holder = list.at(smallest);
			list.at(smallest) = list.at(j);
			list.at(j) = holder;
			swaps++;
		}
	}
	cout << "swaps: " << swaps << endl << "compares: " << compares << endl;
	//prints out list to check for correct sorting
	for (int j = 0; j < list.size(); j++) {
		cout << list.at(j) << endl;
	}
}