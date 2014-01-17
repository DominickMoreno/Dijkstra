/* Graph class header file
   
   info text here
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <regex>
#include <string>
#include "Node.h"

class Graph
{
private:
	int numOfNodes; //Holds the number of Nodes in the Graph
	Node *nodeList; //Holds all of the Nodes in the Graph (array)
	bool parseGraphFile(std::string); //Parses a Graph file to generate a Graph
	bool parseGraphLine(std::string, int);
	int findNumOfNodesInFile(std::string); //Determines the number of lines in a Graph File
public:
	Graph(std::string); //Constructor to be used with Text interface
	int getNumOfNodes(); //Getter for number of nodes
	Node getNodeAtIndex(int); //Returns the Node at the given index
};

#endif GRAPH_H