/* Graph Linked List class implementation file */

#include "Graph.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//function definitions

//(Text UI) constructor for making a Graph
Graph::Graph(string graphFileName)
{
	/* Attempts to open a Graph file with the 
	   given name (graphFileName). It then parses
	   the information contained - eg the Nodes,
	   which ones they connect to, and with what
	   weight. If it cannot find a file with
	   the given name, it throws an error.*/


	/* The following lines from the creation of the ifstream object
	   until the closing of graphFile object are the only times the
	   file is actually opened in the constructor. This is done just
	   to make sure the file exists.
	   
	   As a design choice, I want to use helper methods to parse all
	   of the text. Each of these functions will open/close the file
	   I'm working with
	*/
	ifstream graphFile; //File is only to be read, not modified
	graphFile.open(graphFileName);  //Open file

	if (!(graphFile.is_open())) //If the given file name couldn't be found
	{
		//Throw Error/deal with it
		//TODO: Figure this out when you write loadMap
	}

	graphFile.close(); //Close file now that I'm done with it

	//Determine how many Nodes are in the map
	numOfNodes = findNumOfNodesInFile(graphFileName);

	//Instantiate nodeList
	//nodeList[numOfNodes];
}

//Determines the number of Nodes in t
int Graph::findNumOfNodesInFile(string fileName)
{
	ifstream graphFile; //File is only to be read, not modified
	string line; //iterator through the file, used to count the lines
	int numOfNodes = 0; /* Keeps track of the number of Nodes (based on
						   the number of lines in the file)
						*/

	graphFile.open(fileName);  //Open file

	//Iterate though the entire file
	while(getline(graphFile, line))
	{
		numOfNodes++;
	}

	graphFile.close(); //Close file now that I'm done with it

	/* The final line is used to determine the endpoints. This
	   does not count towards the Node count
	*/
	return (numOfNodes - 1);
}

bool Graph::parseGraphFile(std::string)
{
	//stuff
	return true;
}

int Graph::getNumOfNodes()
{
	//stuff
	return numOfNodes;
}

Node Graph::getNodeAtIndex(int)
{
	//stuff
	Node myDumbNode = Node(0);
	return myDumbNode;
}