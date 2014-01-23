/* Graph class header file
   
   The Graph class holds all of the information for a Graph.
   It is instantiated by its constructor, which requires a
   Graph text file to be instantiated. It parses the file
   line by line, expecting the Graph to be layed out in a
   specific format (see README.txt).

   This is done when the constructor calls the function
   parseGraphFile(), which in turn goes line by line, calling
   parseGraphLine() for each respective line. This method
   uses regular expressions to extract the information known
   as a "Node Nugget". Specifically, it grabs the first Node
   Nugget, removes that nugget from the line, and then makes
   a recursive call with the newly truncated line. It runs
   until the line has been "depleted" - ie it encounters
   an improperly formatted line/nugget or line is an empty
   string.

   This data is allocated in the array nodeList[]. This array
   is allocated using pointer tricks. It has getters for the
   number of Nodes it contains, as well as for each of those
   individual Nodes. 
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <regex>
#include <string>
#include "Node.h"
#include "GraphFileNotFoundException.h"

class Graph
{
private:
	std::string graphName; //Name of the string
	int numOfNodes; //Holds the number of Nodes in the Graph
	Node *nodeList; //Holds all of the Nodes in the Graph (array)
	bool parseGraphFile(std::string); //Parses a Graph file to generate a Graph
	bool parseGraphLine(std::string, int);
	int findNumOfNodesInFile(std::string); //Determines the number of lines in a Graph File
public:
	Graph(std::string); //Constructor to be used with Text interface
	int getNumOfNodes(); //Getter for number of nodes
	std::string getGraphName(); //Getter for stringname
	Node *getNodeAtIndex(int); //Returns the Node at the given index
};

#endif GRAPH_H