/*
// Author: Dr. Al-Haj and Jesse Montel
// ECCS 2681: Data Structures and Algorithms 2
// Date: January 2021

	Directed and weighted graph data structure implementation using adjacency list

  Assumptions:
	1. the number of vertices is known
	2. the implementation is for directed weighted graph
	3. The graph can be initialized from the main or from a given input file

  Summary of the code:
  Array of adjacency lists, each adjacency list is made from nodes.
  A brute force implementation of the SSSP function has been implemented

 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
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
	int weight; //note this is weight from the starting vertex to this node
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
	int edgeWeight(int startV, int ending);
	bool edgeExsists(int starting, int ending);
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

				int src, dest, weight;
				while (inFile >> src >> dest >> weight) {
					cout << "adding edge between " << src << " and " << dest << " with a weight of " << weight << endl;
					addEdge(src, dest, weight);
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
	void addEdge(int src, int dest, int weight);
	void displayGraph();
	void sssp(int startV);

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
	Adding Edge to Graph

  The vertex info. will be inserted at the beginning of the adjacency list
*/
void Graph::addEdge(int v, int w, int weight)
{
	vNode* newNode = createNode(w);
	newNode->weight = weight;
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
			cout << "-> " << curr->dest << "[" << curr->weight << "]";
			curr = curr->next;
		}
		cout << endl;
	}
}

/*
* Will find the SSSP from the given Vertex in the graph(note this implementation is extremely ineficient as it uses a "brute force" technique)
*/
void Graph::sssp(int startV) {

	//verifing user input
	if (startV < 0 || startV >= V) {
		cout << "the specified number is not within the range of possible starting vertecies please use a new number\n";
		return;
	}

	//array of the shortest distance to a node to date
	//start by setting all but starting int to max int so that any path found will be smaller
	int* shortestDistanceArray = new int[V];
	shortestDistanceArray[startV] = 0;
	for (int j = 0; j < V; j++) {
		if (j != startV) {
			shortestDistanceArray[j] = INT_MAX;
		}
	}

	//shortest path to a node to date 
	string* shortestPathArray = new string[V];
	

	//create an array that we will use the next_permuations function on in order to check every possible path
	//the number of the starting vertext is excluded as we want to always uses this vertex first
	int* permArray = new int[V - 1];
	for (int j = 0; j < V; j++) {
		if (j != startV) {
			permArray[j] = j;
		}
	}
	sort(permArray, permArray + V - 1);

	//now we test every possible path to find the shortest path (this is obviously ineficient) 
	do {
		int currentWeight = 0;
		int currentVertex = startV;
		string currentPath = "" + to_string(startV);
		for (int j = 0; j < V - 1; j++) {
			//find if the edge for the current try exsists
			if (edgeExsists(currentVertex, permArray[j])) {
				currentWeight += edgeWeight(currentVertex, permArray[j]);
				currentPath = currentPath + ", " + to_string(permArray[j]);
				//if the current try is better than any before it then store it as best try
				if (shortestDistanceArray[permArray[j]] > currentWeight) {
					shortestDistanceArray[permArray[j]] = currentWeight;
					shortestPathArray[permArray[j]] = currentPath;
				}
				currentVertex = permArray[j];
			}
			else {
				break;
			}
		}

	} while (next_permutation(permArray, permArray + V));

	for (int j = 0; j < V; j++) {
		cout << "The shortest path from " << startV << " to " << j << " is " << shortestPathArray[j] << " with a weight of " << shortestDistanceArray[j] << endl;
	}

}

//sssp utility function used to find the cost of given path 
int Graph::edgeWeight(int startV, int ending) {
	if (edgeExsists(startV, ending)) {
		vNode* currNode = new vNode;
		currNode = array[startV].head;
		while (currNode != nullptr) {
			if (currNode->dest == ending) {
				return currNode->weight;
			}
			currNode = currNode->next;
		}
	}
	else {
		return INT_MAX;
	}
}

//will check if a path exsists between the two given nodes
bool Graph::edgeExsists(int starting, int ending) {
	vNode* currentNode = new vNode;
	currentNode = array[starting].head;
	while (currentNode != nullptr) {
		if (currentNode->dest == ending) {
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}


int main()
{

	Graph myGraph("input.txt");
	// display the graph
	myGraph.displayGraph();

	return 0;
}
