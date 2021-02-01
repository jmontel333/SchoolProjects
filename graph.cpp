/*
// Author: Dr. Al-Haj and Jesse Montel
// ECCS 2681: Data Structures and Algorithms 2
// Date: January 2021

	Graph data structure implementation using adjacency list

  Assumptions:
	1. the number of vertices is known
	2. the implementation is for undirected unweighted graph
	3. The graph can be initialized from the main or from a given input file

  Summary of the code:
  Array of adjacency lists, each adjacency list is made from nodes.
  Implemented BFS and DFS

 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<stack>
#include<queue>
using namespace std;

/*
  Vertex node in the adjacency list
   --------
  |        |-->
   --------
 */

 // The vNode holds information about the destination vertex. The source
 // vertex have a list of all adjacent vertices to the source vertex.
struct vNode
{
	int dest;
	vNode* next;
};

/*
  adjacency list
		   --------      --------
head--> |        |--> |        |-->
		   --------      --------
 */
struct AdjList
{
	vNode* head;
};

/*
 * Class Graph

 The graph is an array of adjacency lists
 */
class Graph
{
private:
	int V; // total number of vertices
	AdjList* array; // the array of adjacency lists
public:
	// constructor
	// intitialize every vertex list to nullptr
	Graph(int size) {
		V = size;
		array = new AdjList[V];
		for (int i = 0; i < V; i++)
			array[i].head = nullptr;
	}

	// overloaded constructor to read data from  a file
	Graph(string inputFile) {
		std::ifstream inFile;
		inFile.open(inputFile, ios::in);
		if (inFile.is_open()) {
			int size;
			inFile >> size;
			if (size > 0) {
				V = size;
				array = new AdjList[V];
				for (int i = 0; i < V; i++)
					array[i].head = nullptr;

				int src, dest;
				while (inFile >> src >> dest) {
					cout << "adding edge between " << src << " and " << dest << endl;
					addEdge(src, dest);
				}

				inFile.close();
			}
			else {
				cerr << "incorrect graph size" << endl;
			}
		}
		else {
			cerr << "Can't open the file ..." << endl;
		}
	}

	vNode* createNode(int dest);
	void addEdge(int src, int dest);
	void displayGraph();
	void DFS(int startingIndex);
	void BFS(int startingIndex);

};

/*
	Creating new vertex node
*/
vNode* Graph::createNode(int dest)
{
	vNode* newNode = new vNode;
	newNode->dest = dest;
	newNode->next = nullptr;
	return newNode;
}
/*
	Adding Edge to Graph, here we add the edge twice
	because it is undirected graph: (v, w) + (w, v)

  The vertex info. will be inserted at the beginning of the adjacency list
*/
void Graph::addEdge(int v, int w)
{
	vNode* newNode = createNode(v);
	newNode->next = array[w].head;
	array[w].head = newNode;

	newNode = createNode(w);
	newNode->next = array[v].head;
	array[v].head = newNode;
}
/*
	Display the graph by printing the adjacency list for each vertex
*/
void Graph::displayGraph()
{
	for (int i = 0; i < V; i++)
	{
		vNode* curr = array[i].head;
		cout << "Vertex [" << i << "]:";
		while (curr != nullptr)
		{
			cout << "-> " << curr->dest;
			curr = curr->next;
		}
		cout << endl;
	}
}

/*
	Will perform a Depth first traversal of the graph starting from the given index and outputing the order that the vertecies are visited
*/
void Graph::DFS(int currentIndex) {
	bool* visitedList = new bool[V]; //list to check if the vertex has been visited
	int* visitOrder = new int[V]; //array to store the values or vertexes visited in order so that we can output in order at the end
	int numberVisited = 0; //keeps track of how many vertexes have been vistied in order to put them into the above array in order
	vNode* currentNode; //a node that we will use to traverse the liniked lists
	stack<int> stack;

	for (int j = 0; j < V; j++) { //sets all the vertcies to unvisited
		visitedList[j] = false;
	}
	currentNode = array[currentIndex].head; //setting current node to the first node we will check to travel to
	while (currentNode == nullptr) { //will take care of the case where there is just a singular node on an island
		visitedList[currentIndex] = true;
		visitOrder[numberVisited] = currentIndex;
		for (int i = 0; i < V; i++) {
			if (visitedList[i] == false) {
				currentIndex = i;
				numberVisited++;
				currentNode = array[currentIndex].head;
				break;
			}
			if (i == V - 1) {
				numberVisited++;
				goto stop; //allows us to break the infinite cycle if all the nodes have been visited and they all are singular islands (stop is on line 235)
			}
		}
	}
	visitedList[currentIndex] = true; //visit the first list and add it to the stack and visit array
	stack.push(currentIndex);
	visitOrder[numberVisited++] = currentIndex; //note we use "++" after to increment after the use of the number


	while (numberVisited < V) {



		if (visitedList[currentNode->dest] == false) { //if unvisted adj node is found then put it into the stack mark as visted and add to output list
			visitedList[currentNode->dest] = true;
			stack.push(currentNode->dest);
			visitOrder[numberVisited++] = currentNode->dest;
			currentIndex = currentNode->dest;
			currentNode = array[currentIndex].head;
		}

		while (visitedList[currentNode->dest] == true) {  //whill find the next adj unvisted vertex
			if (currentNode->next == nullptr) { //if no unvisted adj node is found pop off of the stack
				if (!stack.empty()) {
					stack.pop();
					if (!stack.empty()) {
						currentIndex = stack.top();
						currentNode = array[currentIndex].head;
					}

				}
				else if (numberVisited == V) {//if all visted then we are done
					break;
				}
				else {//if there are islands we will pick a node and start again from there (this new node will be unvisted and on an island)
					for (int i = 0; i < V; i++) {
						if (visitedList[i] == false) {
							currentIndex = i;
							currentNode = array[currentIndex].head;
							while (currentNode == nullptr) { //will take care of the case where there is just a singular node on an island
								visitedList[currentIndex] = true;
								visitOrder[numberVisited] = currentIndex;
								for (int j = 0; j < V; j++) {
									if (visitedList[i] == false) {
										currentIndex = i;
										numberVisited++; //have to increment here to avoid issue of overwritten many times while searching for new node
										currentNode = array[currentIndex].head;
										break;
									}
									if (j == V - 1) {
										numberVisited++;
										goto stop; //allows us to break the infinite cycle if all the nodes have been visited and the last one happens to be an singluar island
									}
								}
							}
						}
					}
				}
			stop:break;
			}

			currentNode = currentNode->next;

			if (visitedList[currentNode->dest] == false) { //if unvisted adj node is found then put it into the stack mark as visted and add to output list
				visitedList[currentNode->dest] = true;
				stack.push(currentNode->dest);
				visitOrder[numberVisited++] = currentNode->dest;
				currentIndex = currentNode->dest;
				currentNode = array[currentIndex].head;
				break;
			}
		}//end while
	}//end while
	cout << "Depth First Traversal order for the graph when starting at " << visitOrder[0] << ": \n";
	for (int j = 0; j < V; j++) { //outputs the order that the nodes are visited
		cout << visitOrder[j] << " ";
	}

	delete[] visitedList; //delete the array when done with it
}

/*
	will perform a Breadth first traversal of the graph starting from the passed index and outputing the order that the vertecies are visited
*/
void Graph::BFS(int currentIndex) {
	bool* visitedList = new bool[V]; //list to check if the vertex has been visited
	int* visitOrder = new int[V]; //array to store the values or vertexes visited in order so that we can output in order at the end
	int numberVisited = 0; //keeps track of how many vertexes have been vistied in order to put them into the above array in order
	vNode* currentNode; //a node that we will use to traverse the liniked lists
	queue<int> queue;

	for (int j = 0; j < V; j++) { //sets all the vertecies to unvisited
		visitedList[j] = false;
	}

	currentNode = array[currentIndex].head;
	while (currentNode == nullptr) { //will take care of the case where there is just a singular node on an island
		visitedList[currentIndex] = true;
		visitOrder[numberVisited] = currentIndex;
		for (int i = 0; i < V; i++) {
			if (visitedList[i] == false) {
				currentIndex = i;
				numberVisited++; //have to increment here to avoid issue of overwritten many times while searching for new node
				currentNode = array[currentIndex].head;
				break;
			}
			if (i == V - 1) {
				numberVisited++;
				goto BFSstop; //allows us to break the infinite cycle if all the nodes have been visited and the last one happens to be an singluar island
			}
		}
	}

	visitedList[currentIndex] = true;
	queue.push(currentIndex);
	visitOrder[numberVisited++] = currentIndex;

	while (numberVisited < V) {
		//while (visitedList[currentNode->dest] == false) { //will "visit" all the adj nodes to the current index
		while(currentNode != nullptr){
			if (visitedList[currentNode->dest] == false) {
				visitedList[currentNode->dest] = true;
				queue.push(currentNode->dest);
				visitOrder[numberVisited++] = currentNode->dest;
			}
			else {
				currentNode = currentNode->next;
			}
		}

		if (!queue.empty()) { //goes off the front of the queue to continue the transversal
			currentIndex = queue.front();
			queue.pop();
			currentNode = array[currentIndex].head;
		}
		else {//if the queue is empty then we need to check for islands
			for (int j = 0; j < V; j++) {
				if (visitedList[j] == false) {
					currentIndex = j;
					currentNode = array[currentIndex].head;
					while (currentNode == nullptr) { //will take care of the case where there is just a singular node on an island
						visitedList[currentIndex] = true;
						visitOrder[numberVisited] = currentIndex;
						for (int i = 0; i < V; i++) {
							if (visitedList[i] == false) {
								currentIndex = i;
								numberVisited++; //have to increment here to avoid issue of overwritten many times while searching for new node
								currentNode = array[currentIndex].head;
								break;
							}
							if (i == V - 1) {
								numberVisited++;
								goto BFSstop; //allows us to break the infinite cycle if all the nodes have been visited and the last one happens to be an singluar island
							}
						}
					}
				}
			}
		BFSstop:break;
		}

	}

	cout << "Breadth First Traversal order for the graph when starting at " << visitOrder[0] << ": \n";
	for (int j = 0; j < V; j++) { //outputs the order that the nodes are visited
		cout << visitOrder[j] << " ";
	}

	delete[] visitedList; //delete the array when done with it
}





int main()
{
	/*    Graph myGraph(6);
		myGraph.addEdge(0, 2);
		myGraph.addEdge(0, 4);
		myGraph.addEdge(1, 3);
		myGraph.addEdge(1, 4);
		myGraph.addEdge(2, 3);
		myGraph.addEdge(2, 4);
	*/

	Graph myGraph("input.txt");
	// display the graph
	myGraph.displayGraph();
	for (int j = 0; j < 7; j++) {
		myGraph.BFS(j); cout << "\n";
	}

	return 0;
}
