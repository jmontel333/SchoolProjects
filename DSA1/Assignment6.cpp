/*
Course: ECCS 2671 -- Data Structures and Algorithms 1
Group Members: Wyatt Guethlein and Jesse Montel

This code is used to submit your assignment #6.

You need to do the following:

	1. implement another version of Bubble sort algorithm that works
	by swapping the pointers instead of swapping the data inside the nodes.

	2. implement a function that reverses the order of nodes in a list.

	3. implement a function that checks if two linked lists are identical.


You are NOT allowed to modify the LinkedList Class, only complete class implementation.

Complete the missing functions, test your code, and then submit your cpp file.

Member functions to be completed:
	1. sortBySwappingPointers()
	2. reverseList()
	3. checkIfIdentical(LinkedList l2)

*/

#include <iostream>
#include <string>

using namespace std;

class LinkedList{

private:
	struct Node{
		int data;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	LinkedList();
	void insertAtBeginning(const int addData);
	void bSortList();
	void sortBySwappingPointers();
	void reverseList();
	bool checkIfIdentical(LinkedList l2);

	// we will overload << operator to print linked lists :)
	friend ostream& operator<<(ostream& outputStream, const LinkedList& ll);

};

// initialize head and tail pointers to nullptr
LinkedList::LinkedList(){

	head = nullptr;
	tail = nullptr;
}

// to add a node at the beginning, we have two cases:
// 1. Empty list and 2. Non-empty list.
// if the list is empty we need to update both pointers head and tail.

void LinkedList::insertAtBeginning(const int addData){

	Node* newNode = new Node;
	newNode->data = addData;
	newNode->next = nullptr;

	if(head == nullptr){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}

}


// sort using bubble sort -- swapping contents
// notice how pointers are used in the for loop
void LinkedList::bSortList()
{
	Node *i, *j;
	int tempInt;

	for(i=head ; i != NULL ; i=i->next)
		for(j=head ; j->next != NULL ; j=j->next){
			if(j->data > j->next->data){

				// swap contents of the nodes
				tempInt = j->data;
				j->data = j->next->data;
				j->next->data = tempInt;
			}
		}
}

// another version of Bubble sort algorithm
void LinkedList::sortBySwappingPointers(){

	Node *j = head;
	Node* prev = nullptr;

	if (prev == nullptr) {
		head = j->next;
		j->next = head->next;
		head->next = j;
	}
	else {
		prev->next = j->next;
		j->next = prev->next->next;
		prev->next->next = j;
	}



}

// reverse the nodes order of a linked list
void LinkedList::reverseList(){

	Node* curr = head;
	Node *prev = NULL;
	Node *next = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}

	head = prev;
}

// check if two lists are identical
bool LinkedList::checkIfIdentical(LinkedList l2){
	Node* l2curr = l2.head;
	Node* curr = head;

	while (curr != NULL && l2curr != NULL) {
		if (curr->data != l2curr->data)
			return false;
		curr = curr->next;
		l2curr = l2curr->next;
	}
	return true;
}


// overloading << operator to print a linked list
// outputStream variable is output stream (ostream)
ostream& operator<<(ostream& outputStream, const LinkedList& ll)
{
	// Node structure is defined inside the LinkedList class, we need
	// to use the resolution operator :: to access it.
	// Thats why we defined this function as a friend function, so
	// we can access the Node struct and all private members.

	LinkedList::Node* current = ll.head;

	while( current != nullptr){
		outputStream<<"("<<current->data<<") -> ";
		current = current->next;
	}
	outputStream<<"00"<<endl;

	return outputStream;
}


int main(){

	LinkedList myList1, myList2;

	// testing checkIfIdentical function with two empty lists
	cout<<"List 1: "<<myList1; // using the overloaded operator
	cout<<"List 2: "<<myList2;
	cout<<"Test 1: checking identical lists"<<endl;
	if(myList1.checkIfIdentical(myList2)){
		cout<<"Empty lists are identical ..."<<endl;
	}
	else{
		cout<<"Empty lists are NOT identical !!!"<<endl;
	}


	myList1.insertAtBeginning(20);
	myList1.insertAtBeginning(10);
	myList1.insertAtBeginning(25);
	myList1.insertAtBeginning(75);


	myList2.insertAtBeginning(20);
	myList2.insertAtBeginning(10);
	myList2.insertAtBeginning(25);
	myList2.insertAtBeginning(75);


	// testing checkIfIdentical function
	cout<<"List 1: "<<myList1;
	cout<<"List 2: "<<myList2;
	cout<<"Test 2: checking identical lists"<<endl;
	if(myList1.checkIfIdentical(myList2)){
		cout<<"Lists are identical ..."<<endl;
	}
	else{
		cout<<"Lists are NOT identical ..."<<endl;
	}

	myList2.insertAtBeginning(101);


	// testing checkIfIdentical function
	cout<<"List 1: "<<myList1;
	cout<<"List 2: "<<myList2;
	cout<<"Test 3: checking identical lists"<<endl;
	if(myList1.checkIfIdentical(myList2)){
		cout<<"Lists are identical ..."<<endl;
	}
	else{
		cout<<"Lists are NOT identical ..."<<endl;
	}


	// testing reverseList function
	cout<<"Test 4: checking reversal function"<<endl;
	cout<<"List 1 before reversal ..."<<endl;
	cout<<"List 1: "<<myList1;
	myList1.reverseList();
	cout<<"List 1 after reversal ..."<<endl;
	cout<<"List 1: "<<myList1;


	//testing soring function
	cout<<"Test 5: checking sorting function"<<endl;
	cout<<"List 1 before sorting ..."<<endl;
	cout<<"List 1: "<<myList1;
	myList1.sortBySwappingPointers();
	cout<<"List 1 after sorting ..."<<endl;
	cout<<"List 1: "<<myList1;



	return 0;
}
