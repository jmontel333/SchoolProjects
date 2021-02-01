/*
	Author: Dr. Al-Haj and Jesse Montel
	ECCS 2671: Data Structures and Algorithms 1
	Date: October 2020

	Use this code to submit your assignment #9.

	Complete the missing lines, test your code, and then submit your report and cpp files.

	Methods to be completed:
	* getBalancedCopy()
	* levelTraversal()

	NOTE:
	1. You are NOT allowed to change the structure of BSTree Class,
	but you can define and add other private member functions “utility functions” if needed.
	2. You may ONLY use the following data structures: arrays, linked lists, queues and stacks; if needed.
	3. You are NOT allowed to use anything from C++ STL standard library, if you need something, implement it.

*/

#include <iostream>

using namespace std;

// Binary Search Tree
class BSTree{

private:
	struct Node{
		string data;				// key data
		Node* left;			// a pointer to the left subtree
		Node* right;		// a pointer to the right subtree

		// destructor to free memory used by node objects
		~Node(){
			delete left;
			delete right;
			//cout<<"a node has been deleted..."<<endl;
		}
	};

	// a pointer to the root node, it is declared as a private
	// so users cant access it directly.
	Node* root;

	// these functions are declared in the private section
	// to be used inside the class as utility functions,
	// user can't use them.
	Node* createNode(const string data);
	void insertNodeUtil(const string data, Node* subTreePtr);
	void printInOrderUtil(Node* subTreePtr);
	bool findKeyUtil(const string key, Node* subTreePtr);
	int treeHeightUtil(Node* subTreePtr);


	// insert any utility function you implement here
	void levelTraversalUtil(Node* subTreePtr);
	void printLevelUtil(Node* top, int level);
	void addToArrayUtil(Node* subTreePtr, string* z);
	void arrayToBalancedTree(string* treeArray, int begin, int end);
	int getSizeRecurse(Node* subTreePtr);
	int getSize();
	int size;
	int arrayLocation = 0;
	

public:
	BSTree();
	~BSTree();
	void insertNode(const string addData);
	void printInOrder();
	bool findKey(const string key);
	int treeHeight();
	void levelTraversal();
	void getBalancedCopy(BSTree& tree);
	
};
//------------------------------------------------------------//

// A Constructor -- initialize root pointer to nullptr
BSTree::BSTree(){

	root = nullptr;
}

// A Destructor -- deallocate all reserved space
BSTree::~BSTree(){

	delete root;
}


// a utility function to create a new node and returns a pointer
// pointing at the created node	
BSTree::Node* BSTree::createNode(const string addData){

	Node* newNode = new Node;

	newNode->data = addData;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

// node insertion is done recursively, that's why we have
// a utility function that has two parameters: data + pointer
// user can access this function but not the utility function
void BSTree::insertNode(const string addData){

	insertNodeUtil(addData, root);
}

// this function uses recursion to find the right place for
// new node to be inserted. Every subtree is considered a tree.

// To control the recursion, we need to pass private information
// as a parameter, that's why this function is not declared as public.

// Divide-an-Conquer: sub-problem <==> sub-tree
void BSTree::insertNodeUtil(const string data, Node* subTreePtr) {

		// case 1: empty tree
		// create a node and make it root
		if(root == nullptr){
			// this statement is correct; pointer = pointer
			// keep in mind that createNode(...) function returns a pointer
			root = createNode(data);
		}
		// case 2: data to be inserted in the left side of the subtree
		// check the left side of the tree
		else if (data <= subTreePtr->data){
			// keep going to the left until we find a node that has no left child
			if( subTreePtr->left == nullptr){
				subTreePtr->left = createNode(data);
			}
			else{ // keep going left
				insertNodeUtil(data, subTreePtr->left);
			}
		}
		// case 3: data to be inserted in the left side of the subtree
		// check the right side of the tree
		else {//if(data > subTreePtr->data){
			if( subTreePtr->right == nullptr){
				subTreePtr->right = createNode(data);
			}
			else{ // keep going right
				insertNodeUtil(data, subTreePtr->right);
			}

		}
	}

// in-order traversal: Left-Parent-Right
// we use a recursive utility function
void BSTree::printInOrder(){

	printInOrderUtil(root);
	cout<<endl;

}

// level by level traversal: prints each row of parents left to right top to bottom
// will use a recursive utility funtion
void BSTree::levelTraversal() {

	levelTraversalUtil(root);
	cout << endl;
}

// utility function to traverse a tree 
// in-order traversal:
// 1) explore left side - 2) print parent node - 3) expolre right side
void BSTree::printInOrderUtil(Node* subTreePtr){

	if (root == nullptr) {
		cout<<"The TREE is Empty ..."<<endl;
	} else {
		// 1) explore left side
		if(subTreePtr->left != nullptr){
			printInOrderUtil(subTreePtr->left);
		}

		// 2) print node
		cout<<subTreePtr->data<<" ";

		// 3) expolre right side
		if(subTreePtr->right != nullptr){
			printInOrderUtil(subTreePtr->right);
		}
	}

}

// utility function that will traverse a tree 
// level by level traversal: parents top to bottom left to right
void BSTree::levelTraversalUtil(Node* subTreePtr) {
	// handles an empty tree
	if (root == nullptr) {
		cout << "The tree is EMPTY!" << endl;
	}
	// will go through every level of the tree top to bottom and use the print level function to print them
	else{
		int level = treeHeight();
		for (int j = 1; j <= level; j++) {
			printLevelUtil(root, j);
		}
	}
}

// this utility function will recurse to print the given level in the parameter
// it calls its self until it gets to every node within that level and prints them out left to right
void BSTree::printLevelUtil(Node* top, int level) {
	if (top == nullptr) {
		return;
	}
	// once the deisred level is reached output the data
	if (level == 1) {
		cout << top->data << " ";
	}
	// if we havent reach the deisred level yea we recurse into 2 more calls
	if (level > 1) {
		// calling the the left recursion first will output the line left to right as opposed to right to left
		printLevelUtil(top->left, level - 1);
		printLevelUtil(top->right, level - 1);
	}
}

// Search for a key in a binary search tree
bool BSTree::findKey(const string key){

	// use the recursive utility function
	return findKeyUtil(key, root);
}

// Utility function to find a key
bool BSTree::findKeyUtil(const string key, Node* subTreePtr){

	// check if the tree is empty.
	if(root == nullptr){
		cout<<"Key ("<<key<<") is NOT found, it is an empty tree ..."<<endl;
		return false;
	}

	// base case 1: no subtree, this case applies when you check left and
	// right subtrees of a leaf node. There are no subtrees, right!!
	if(subTreePtr == nullptr){
		cout<<"Key ("<<key<<") is NOT found"<<endl;
		return false;
	}
	// base case 2: we found the key
	else if(subTreePtr->data == key){
		cout<<"Key ("<<key<<") is FOUND"<<endl;
		return true;
	}
	// key is less than the data in this node, search in the left subtree
	else if(key < subTreePtr->data){
		return findKeyUtil(key, subTreePtr->left);
	}
	// key is larger than the data in this node, search in the right subtree
	else { //if(key > subTreePtr->data)
		return findKeyUtil(key, subTreePtr->right);
	}
}


// find the height of a tree, the height of an empty tree is 0
// treeHeight() function will call treeHeightUtil(root) function to
// find the height of a given treen recursively
int BSTree::treeHeight(){

	if(root == nullptr)
		return 0;
	else
		return treeHeightUtil(root);

}


// this utility function will find the height of a given tree by
// taking the maximum height of left and right subtrees.
int BSTree::treeHeightUtil(Node* subTreePtr){

	if(subTreePtr == nullptr){
		return 0;
	}
	else{
		int lHeight = treeHeightUtil(subTreePtr->left);
		int rHeight = treeHeightUtil(subTreePtr->right);

		return (lHeight >= rHeight ? lHeight+1 : rHeight+1);
		/* another way to do it using if-else
		if( lHeight >= rHeight){
			return lHeight + 1;
		}
		else{
			return rHeight + 1;
		}
		*/
	}
}

// this function will store a blanaced version into the tree parameter
void BSTree::getBalancedCopy(BSTree& tree) {
	arrayLocation = -1;
	int treeSize = getSize();
	// array to store the values of the tree in
	string* storeArray = new string[treeSize];
	// now we add the tree to the array (the -1 is to keep track of where to add to the array)
	addToArrayUtil(root, storeArray);
	// now the array is turned into a tree
	tree.arrayToBalancedTree(storeArray, 0, treeSize);
}

// this function will return the number of nodes in the tree
int BSTree::getSize() {
	size = 0;
	getSizeRecurse(root);
	return size;
}
// this function will recurse through a tree getting the number of nodes
int BSTree::getSizeRecurse(Node* subTreePtr) {
	if (root == nullptr) {
		return 0;
	}
	else {
		// 1) explore left side
		if (subTreePtr->left != nullptr) {
			getSizeRecurse(subTreePtr->left);
		}

		// 2) increment size
		size++;

		// 3) expolre right side
		if (subTreePtr->right != nullptr) {
			getSizeRecurse(subTreePtr->right);
		}
	}
}

// this utility function will take an array and turn it into a balanced tree
void BSTree::arrayToBalancedTree(string* treeArray, int begin, int end) {
	if (begin < end) {
		// go to the middle of the array
		int middle = (begin + end) / 2;

		// insert the middle into the tree
		insertNode(treeArray[middle]);

		//recursivle insert the nodes into the tree resulting in a balanced tree
		arrayToBalancedTree(treeArray, begin, middle);
		arrayToBalancedTree(treeArray, middle+1, end);
	}
}

// this utility function will add to an array from a tree in in-order order
void BSTree::addToArrayUtil(Node* subTreePtr, string* z) {
	// empty tree case
	if (root == nullptr) {
		return;
	}
	else
	{
		//go left
		if (subTreePtr->left != nullptr) {
			// recursion is needed to go deeper into the tree in the proper order
			addToArrayUtil(subTreePtr->left, z);
		}

		// add the node to the array
		arrayLocation++;
		z[arrayLocation] = subTreePtr->data;


		// now explore the right side in the same way as the left side
		if (subTreePtr->right != nullptr) {
			addToArrayUtil(subTreePtr->right, z);

		}
	}
}


int main(){

	// animals are stored in an array for simplicity
	const int arraySize = 13;
	string testData[arraySize] = {"1", "2", "3", "4", "5", "6", "7", "8",
			"9", "10", "11", "12", "13"};
	 


	// create a BST object, myTree
	BSTree myTree;

	// print empty tree
	cout<<"In-Order Traversal:"<<endl;
	cout<<"Empty tree height: "<<myTree.treeHeight()<<endl;
	myTree.printInOrder();
	cout<<"======================================================================"<<endl;

	// insert the numbers to myTree one-by-one
	for(int i = 0; i < arraySize ; i++){
		myTree.insertNode(testData[i]);
	}

	// print the tree using in-order traversal
	cout<<"In-Order traversal after building:"<<endl;
	cout<<"Original Tree height: "<<myTree.treeHeight()<<endl;
	myTree.printInOrder();
	cout<<"======================================================================"<<endl;


	// print the tree using in-order traversal
	cout<<"Level by level traversal after building:"<<endl;
	myTree.levelTraversal();
	cout<<"======================================================================"<<endl;


	// make a balanced copy
	BSTree myTree2;

	myTree.getBalancedCopy(myTree2);


	// print the tree using in-order traversal
	cout<<"In-Order traversal after balancing (Original Tree):"<<endl;
	cout<<"Original Tree height after balancing: "<<myTree.treeHeight()<<endl;
	myTree.printInOrder();
	cout<<"======================================================================"<<endl;


	// print the tree using in-order traversal
	cout<<"In-Order traversal after balancing (Balanced Tree):"<<endl;
	cout<<"Balanced Tree height after balancing: "<<myTree2.treeHeight()<<endl;
	myTree2.printInOrder();
	cout<<"======================================================================"<<endl;


	// print the tree using level traversal
	cout<<"Level by level traversal after balancing:"<<endl;
	cout<<"Balanced Tree height after balancing: "<<myTree2.treeHeight()<<endl;
	myTree2.levelTraversal();
	cout<<"======================================================================"<<endl;



	return 0;
}
