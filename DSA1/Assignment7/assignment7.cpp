//Jesse Montel and Joren Kirsis
//10/9/2020
//a simple program that determines if braces are in the proper order
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template< class Type, int MaxStackSize = 10 >
class Stack {

private:
	// stackSize holds the capacity of the stack
	int stackSize;
	// top holds the index of the item at the top of the stack
	int top;
	// stackArray is an integer dynamic array to store contents of the stack
	// stackArray is defined using same datatype in the template
	Type* stackArray;

public:
	// constructor to initialize stack objects, default stack size is 10
	Stack();
	// destructor to free the allocated memory
	~Stack();
	// push function inserts an integer at the top of the stack
	bool push(Type x); //to insert an element "x" on the top of the stack
	// pop function removes an integer from the top of the stack
	Type pop();
	// peek function look at the top of the stack without removing any item
	Type peek();
	// isEmpty function checks if the stack is empty
	bool isEmpty();
	// isFull function checks if the stack is full
	bool isFull();
	//areMatching checks if the two characters are matching braces
	bool areMatching(char a, char b);
	// isCorrect checks if the stack has a correct arrangement of braces
	bool isCorrect();
	// display function is just for debugging purpose,
	// to test if we are adding and removing correctly
	void display();
};

// the constructor allocates the dynamic array based on the given size,
// if no size is give, a default value is used
// --> the default value was given in the class template definition
template< class Type, int MaxStackSize >
Stack<Type, MaxStackSize>::Stack() {
	//Stack::Stack(int s ){
	  // validate the stack size
	if (MaxStackSize <= 0) {
		throw "Invalid stack size ... \n";
	}
	// update the stack size based on the given input
	stackSize = MaxStackSize;

	// initialize the top of the stack, top = -1 means empty stack
	top = -1;

	// using new operator to allocate the needed memory space
	stackArray = new Type[stackSize];
}


// destructor to free all allocated memory space
template< class Type, int MaxStackSize >
Stack<Type, MaxStackSize>::~Stack() {
	delete [] stackArray;
}

// Push operation inserts item (x) at the top of the stack
template< class Type, int MaxStackSize >
bool Stack<Type, MaxStackSize>::push(Type data) {
	// insert only if the stack is not full
	// we can't insert more items to a full stack (avoid overflow)
	if (isFull()) {
		cout << "Stack is FULL" << endl;
		return false;
	}
	else {
		// increment the top before inserting the new item
		// (remember, the top is initialized to -1)
		top++;
		stackArray[top] = data;
		return true;
	}
}

// Pop operation removes the item at the top of the stack
template< class Type, int MaxStackSize >
Type Stack<Type, MaxStackSize>::pop() {
	// we can't pop from an empty stack (avoid underflow)
	if (isEmpty()) {
		throw "Stack is EMPTY ... \n";
	}
	else {
		// don't forget to decrement the top when you pop from stack
		return stackArray[top--];
	}

}

// Peek operation looks at the top of the stack without removing any item
template< class Type, int MaxStackSize >
Type Stack<Type, MaxStackSize>::peek() {
	if (isEmpty()) {
		throw "Stack is EMPTY ... \n";
	}
	else {
		// notice that top is not decremented here
		return stackArray[top];
	}
}

// An empty stack does not have any item, therefore top value is -1
template< class Type, int MaxStackSize >
bool Stack<Type, MaxStackSize>::isEmpty() {

	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

// A full stack means that we reached the maximum capacity, stackSize
template< class Type, int MaxStackSize >
bool Stack<Type, MaxStackSize>::isFull() {

	if (top == stackSize - 1) {
		return true;
	}
	else {
		return false;
	}
}

// display function is just for debugging purposes and
// having fun seeing it works correctly
template< class Type, int MaxStackSize >
void Stack<Type, MaxStackSize>::display() {

	if (isEmpty()) {
		cout << "Empty Stack ... NO data " << endl;
	}
	else {
		for (int i = 0; i <= top; i++) {
			cout << " | " << stackArray[i];
		}
		cout << " | " << endl;
	}
}

template< class Type, int MaxStackSize>
bool Stack<Type, MaxStackSize>::isCorrect() {
	Stack<char, 20> toBePaired;//this stack is for the unpaired chars
	if (isEmpty()) {//if the stack is empty then it is correct
		return true;
	}
	toBePaired.push(pop());
	while (!isEmpty()) {//iteraters throught the whole stack
		if (!toBePaired.isEmpty()) {
			if (areMatching(toBePaired.peek(), peek())) {//if they match pop them off the stacks and moveon
				toBePaired.pop();
				pop();
			}
			else {//if not add it to the tobepaired stack
				toBePaired.push(pop());
			}
		}
		else {//if the tobeparied stack is empty then we must add to it from the main stack
			toBePaired.push(pop());
		}
	}
	if (toBePaired.isEmpty()) {//if we have paired all the chars then the stack was correct
		return true;
	}
	else {//if we have unpaired chars then the stack was inncorrect
		return false;
	}
}//end iscorrect

template<class Type, int MaxStackSize>
bool Stack<Type, MaxStackSize>::areMatching(char a, char b) {
	if (a == '(' && b == ')') {
		return true;
	}
	if (a == '<' && b == '>') {
		return true;
	}
	if (a == '{' && b == '}') {
		return true;
	}
	if (a == '[' && b == ']') {
		return true;
	}
	return false;
}//end areMatching


int main(void) {

	Stack<char, 60> stk;
	int counter = 0;
	int spacesBetween;

	string spaces = "";
	string inputFile = "testme.txt";
	string outputFile = "result.txt";

	string correct = "---> correct";
	string incorrect = "---> incorrect";

	ifstream getTestingFile;
	ostringstream lineToRead;

	vector<string> examples;
	vector<int> exampleSizes;


	cout << "Name of input file to test: ";
	cin >> inputFile;
	cout << endl << "Name of output file to post results in: ";
	cin >> outputFile;


	getTestingFile.open(inputFile);

	string line;

	getline(getTestingFile, line);			//this grabs the number on the first line in order to determine how many lines of braces are beneath it.
	counter = stoi(line);


	while (getline(getTestingFile, line))  //adds all the lines of the input file into a vector
	{

		examples.push_back(line);

		exampleSizes.push_back(line.size()); // MIGHT broken

	}



	getTestingFile.close();

	// ------------------------------------------------------- 

	ofstream writeResultFile;
	writeResultFile.open(outputFile);

	writeResultFile << counter << endl;
	for (int i = 0; i < counter; i++) {		//this for will cycle through each line of the input file 
		spaces = "";
		spacesBetween = 25 - exampleSizes[i];						
		for (int h = 0; h < spacesBetween; h++) {					
			spaces.append(" ");
		}											//these lines will setup the output with proper spacing
		string s = examples[i];
		for (int a = 0; a < s.length(); a++) {		//this removes all of the spaces from the line to prepare it to be pushed onto the stack
			if (s[a] == ' ') s.erase(a, 1);
		}
		reverse(s.begin(), s.end());				//reverses the order of the chars in the string so that they go into the stck in the right order
		for(int j = 0; j < s.length(); j++) {		//pushes them into the stack
			stk.push(s[j]);
		}
		examples[i].append(spaces);					//adds the spaces into the output file
		if (stk.isCorrect()) {						//checks if the braces are in proper order and appends either correct or incorrect accordingly
			examples[i].append(correct);
		}
		else {
			examples[i].append(incorrect);
		}
		writeResultFile << examples[i] << endl;		//writes the updated line into the output file
		while (!stk.isEmpty()) {					//clears the stack of any access members
			stk.pop();
		}
	}

	writeResultFile.close();	
}//end main
