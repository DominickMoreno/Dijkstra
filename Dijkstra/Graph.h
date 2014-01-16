/* Graph class header file
   
   info text here
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "Node.h"

class Graph
{
private:
	int numOfNodes; //Holds the number of Nodes in the Graph
	Node nodeList[1]; //Holds all of the Nodes in the Graph
	bool parseGraphFile(std::string); //Parses a Graph file to generate a Graph
	int findNumOfNodesInFile(std::string); //Determines the number of lines in a Graph File
public:
	Graph(std::string); //Constructor to be used with Text interface
	int getNumOfNodes(); //Getter for number of nodes
	Node getNodeAtIndex(int); //Returns the Node at the given index
};

#endif GRAPH_H