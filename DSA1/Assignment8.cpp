/*
	Author: Dr. Al-Haj and Jesse Montel
	Course: ECCS 2671 Data Structures and Algorithms 1
	Date: October 2020

	Use this code to submit your assignment #8.

	The QueueList is a linked list implementation of a queue abstract data type.

	You are not allowed to modify the QueueList Class, only complete class implementation.

	Complete the missing lines, test your code, and then submit your report and cpp files.

	Methods to be completed:
	* QueueList()
	* ~QueueList()
	* isEmpty()
	* isFull()
	* enqueue()
	* dequeue()
	* peek()
	* size()
	* dispalyQueue()

*/


#include <iostream>
#include <string>

using namespace std;

class QueueList{

private:
	struct Node{
		string data;
		Node* next;
	};

	int capacity;
	int currentSize;
	Node* head;
	Node* tail;

public:
	// constructor to initialize the queue and set the capacity
	QueueList(int c=5);
	// destructor to free all allocated memory
	~QueueList();
	// insert to the queue
	bool enqueue(const string addData);
	// remove from the queue
	string dequeue();
	// look at the front of the queue
	string peek();
	// check if the queue is empty
	bool isEmpty();
	// check if the queue is full (reached the max capacity)
	bool isFull();
	// get the current size
	int size();
	// print the contents of the queue
	void displayQueue();
};

// all proper initializations should be done here
QueueList::QueueList(int c){
	capacity = c;
	currentSize = 0;
	head = nullptr;
	tail = nullptr;
}

// deallocate any reserved memory
// you need to deallocate all created nodes
QueueList::~QueueList(){
	for (int j = 0; j < currentSize; j++) {//iterates through whole list and deletes each element
		Node* temp = head;
		temp = temp->next;
		delete head;
		head = temp;
	}//end for
	
}

// check if the queue is empty or not
// return true if queue is empty and false otherwise
bool QueueList::isEmpty(){
	if (currentSize == 0) {
		return true;
	}//end if
	return false;
}

// check if the queue is full or not
// return true if queue is full and false otherwise
bool QueueList::isFull(){
	if (currentSize == capacity) {
		return true;
	}//end if
	return false;
}

// insert an element into the Queue
// return true if element is inserted, false otherwise
bool QueueList::enqueue(const string addData){
	if (isFull()) {//handles full queue
		return false;
	}//end if
	//creates new node that is to be added
	Node* newNode = new Node;
	newNode->data = addData;
	newNode->next = nullptr;
	if (head == nullptr) {//how to add if the queue is empty
		head = newNode;
		tail = newNode;
	}//end if
	else {//adds node to list with elements
		tail->next = newNode;
		tail = newNode;
	}//end else
	currentSize++;//adds 1 to the current size varible to track queue size
	return true;
}

// remove the element at the front of the queue
string QueueList::dequeue(){
	string toRetrun;//the string that will be returned
	if (!isEmpty()) {
		toRetrun = head->data;//gets the data of the node being removed
		//update the head of the queue
		Node* temp = head;
		temp = temp->next;
		delete head;
		head = temp;
		currentSize--;//keep track of the queue size
		return toRetrun;
	}
}

// show the element at the front of the queue
string QueueList::peek(){
	return tail->data;

}

// return the current size of the Queue
int QueueList::size(){
	return currentSize;
}

// show the content of the queue.
// this function is for debugging purposes only
void QueueList::displayQueue(){
	Node* curr = head;//we use this node for output
	while (curr != nullptr) {//iterates through the whole current list
		cout << " <- (" << curr->data << ")";
		curr = curr->next;
	}//end while
	cout << endl;
}

int main(){

	QueueList myQueue;

	string inputName;
	int choice;

	do{
		cout<<"Enter your choice ... "<<endl;
		cout<<"1 -- enqueue"<<endl;
		cout<<"2 -- dequeue"<<endl;
		cout<<"3 -- peek"<<endl;
		cout<<"4 -- display"<<endl;
		cout<<"5 -- size"<<endl;
		cout<<"6 -- EXIT."<<endl;

		cin>>choice;
		cout<<endl;

		switch(choice){

			case 1:{
				cout<<"Enter a name:"<<endl;
				cin>> inputName;
				cout<<endl;
				if (myQueue.enqueue(inputName)) {
					cout << "Added: " << inputName << endl;//added this code looks cleaner to me
				}
				else {
					cout << "Queue is FULL" << endl;//also added a queue is full message if you attempt to add to a full queue
				}
				break;
			}
			case 2:{
				if( ! myQueue.isEmpty() ){
					cout<<"Dequeue: "<<myQueue.dequeue()<<endl;
				}
				else{
					cout<<"Queue is EMPTY"<<endl;
				}
				break;
			}
			case 3:{
				if( ! myQueue.isEmpty() ){
					cout<<"The element at the front is: "<<myQueue.peek()<<endl;
				}
				else{
					cout<<"Queue is EMPTY"<<endl;
				}
				break;
			}
			case 4:{
				myQueue.displayQueue();
				break;
			}
			case 5:{
				cout<<"Queue size is: "<<myQueue.size()<<endl;
			}

		}

	} while( choice != 6);



	return 0;
}
