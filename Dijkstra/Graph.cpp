/* Graph Linked List class implementation file */

#include "Graph.h"
#include <iostream>
#include <regex>
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
	nodeList = new Node[numOfNodes];

	//Initialize all of the Nodes that exist in the Graph
	//Node that nodeList[n] will contain Node number n
	for (int i = 0; i < numOfNodes; i++)
	{
		nodeList[i] = *(new Node(i));
	}

	cout << "The contents of nodeList are:\n";
	for (int i = 0; i < numOfNodes; i++)
	{
		cout << "nodeList[" << i << "]: " << nodeList[i].getNodeNumber() <<  " at address: " <<
			&nodeList[i] << endl;
	}
	cout << endl;

	//Parse file to instantiate all the Nodes and Paths
	if (!parseGraphFile(graphFileName)) //If the File is improperly formatted
	{
		//Throw Error/deal with it
		//TODO: Figure this out when you write loadMap
	}

}

//Determines the number of Nodes in the graph
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

//Parses a Graph file to generate a Graph
bool Graph::parseGraphFile(string fileName)
{
	ifstream graphFile; //File is only to be read, not modified
	string line; //iterator through the file, used to go through line by line
	int lineNum;
	graphFile.open(fileName);  //Open file

	for (lineNum = 0; lineNum < numOfNodes; lineNum++)
	{
		getline(graphFile, line);
		if (!parseGraphLine(line, lineNum)) //If the line is not properly parsed
		{
			//Throw Error/deal with it
			//TODO: Figure this out when you write loadMap
		}
	}

	return true;
}

bool Graph::parseGraphLine(string line, int lineNum)
{
	/* Note on terminology: A "Node nugget" refers to a 
	   "number,number" substring in a line in a graph file.
	   For example, the line:
	   "1,2 3,4 5,10" has 3 Node nuggets. They are:
	   "1,2", "3,4" and "5,10".
	*/
	Edge *newEdgeItem;
	regex nodeAndWeightRegex("^[0-9]+,[0-9]"); /* Regex to find the FIRST connecting
											   Node and the corresponding Edge weight
											   */
	regex nodeRegex("^[0-9]+"); //Regex to find just the Node number in the Node nugget
	regex weightRegex("[0-9]+$"); //Regext to find just the Edge weight in the Node nugget

	smatch nodeAndWeightRegexMatch; //Corresponding regex match object to nodeAndWeightRegex
	smatch nodeRegexMatch; //match object for nodeRegex
	smatch weightRegexMatch; //match object for weightRegex

	string nodeAndWeightStr; //Intermediate string to hold entire Node nugget
	string nodeStr; //Intermediate string to hold just the node number in the Node nugget
	string weightStr; //Intermediate string to hold just the edge weight in the Node nugget

	/* Parse line with the given regular expression.
	   The results are stored in regexMatch. Note that
	   this will ONLY grab the "first" Node. Eg, if
	   line is "1,2 3,4", regexMatch will ONLY find
	   "1,2".

	   The found substring is accessed as such:
	   "nodeAndWeightRegex[0].str()".l
	*/
	regex_search(line, nodeAndWeightRegexMatch, nodeAndWeightRegex);
	nodeAndWeightStr = nodeAndWeightRegexMatch[0].str(); //Put only the first Node nugget into a string

	if (!regex_search(line, nodeAndWeightRegexMatch, nodeAndWeightRegex))
	{
		/* No match was found, which means the given line is "depleted" of 
		   Node nuggets. The line is finished being parsed, or did not contain
		   any Node nuggets in the first place - ie the Node is not connected
		   to any other Nodes in the Graph
		*/
		return false;
	}

	regex_search(nodeAndWeightStr, nodeRegexMatch, nodeRegex); //Find the node number in the nugget
	regex_search(nodeAndWeightStr, weightRegexMatch, weightRegex); //Find the edge weight in the nugget

	//I get weird run-time errors when I don't make an intermediate string, so here they are
	nodeStr = nodeRegexMatch[0].str();
	weightStr = weightRegexMatch[0].str();

	cout << "line: " << line << endl;
	cout << "line number: " << lineNum << endl;
	cout << "nodeAndWeight Nugget: " << nodeAndWeightStr << endl;
	cout << "node Nugget: " << nodeStr << endl;
	cout << "weight Nugget: " << weightStr << endl;
	cout << "lineNum Node address: " << &nodeList[lineNum] << endl;
	cout << "Node nugget address: " << &nodeList[stoi(nodeStr)] << endl << endl;

	cout << "BEFORE:\n";
	cout << "nodeList[" << lineNum << "]'s connectingEdge's headCell address is: " << nodeList[lineNum].connectingEdges.headCell << endl;
	if (nodeList[lineNum].connectingEdges.headCell != NULL)
	{
		cout << "\tWith Edge Address: " << nodeList[lineNum].connectingEdges.headCell->listEdge << endl;
		cout << "\tWith Node A Address: " << nodeList[lineNum].connectingEdges.headCell->listEdge->nodeA << endl;
		cout << "\tWith Node B Address: " << nodeList[lineNum].connectingEdges.headCell->listEdge->nodeB << endl;
	}
	cout << "nodeList[" << stoi(nodeStr) << "]'s connectingEdge's headCell address is: "
		<< nodeList[stoi(nodeStr)].connectingEdges.headCell << endl;
	if (nodeList[stoi(nodeStr)].connectingEdges.headCell != NULL)
	{
		cout << "\tWith Edge Address: " << nodeList[stoi(nodeStr)].connectingEdges.headCell->listEdge << endl;
		cout << "\tWith Node A Address: " << nodeList[stoi(nodeStr)].connectingEdges.headCell->listEdge->nodeA << endl;
		cout << "\tWith Node B Address: " << nodeList[stoi(nodeStr)].connectingEdges.headCell->listEdge->nodeB << endl;
	}

	//Check if the Edge I'm about to create exists already
	if (nodeList[lineNum].doNodesConnect(&nodeList[stoi(nodeStr)]) != NULL)
	{
		//The connection already exists, use it and add to this Node's connecting Edges
		cout << "Connection already exists. Adding it" << endl;
	}
	else
	{
		//The connection does not exist, create it and add to this Node's connecting Edges
		cout << "Connection does NOT already exist. Creating it" << endl;

		//Create the new Edge object
		newEdgeItem = &(Edge(nodeList[lineNum], nodeList[stoi(nodeStr)], stof(weightStr)));

		//Add the new Edge object to each Node's Edge list
		if (nodeList[lineNum].addEdge(*newEdgeItem))
		{
			cout << "Adding edge to node " << nodeList[lineNum].getNodeNumber() << " SUCCESSFULL\n";
		}
		else
		{
			cout << "Adding edge to node " << nodeList[lineNum].getNodeNumber() << " UNSUCCESSFULL\n";
		}
		if (nodeList[stoi(nodeStr)].addEdge(*newEdgeItem))
		{
			cout << "Adding edge to node " << nodeList[stoi(nodeStr)].getNodeNumber() << " SUCCESSFULL\n";
		}
		else
		{
			cout << "Adding edge to node " << nodeList[stoi(nodeStr)].getNodeNumber() << " UNSUCCESSFULL\n";
		}
	}
	cout << "AFTER:\n";
	cout << "nodeList[" << lineNum << "]'s connectingEdge's headCell address is: "
		<< nodeList[lineNum].connectingEdges.headCell << endl;
	if (nodeList[lineNum].connectingEdges.headCell != NULL)
	{
		cout << "\tWith Edge Address: " << nodeList[lineNum].connectingEdges.headCell->listEdge << endl;
		cout << "\tWith Node A Address: " << nodeList[lineNum].connectingEdges.headCell->listEdge->nodeA << endl;
		cout << "\tWith Node B Address: " << nodeList[lineNum].connectingEdges.headCell->listEdge->nodeB << endl;
	}
	cout << "nodeList[" << stoi(nodeStr) << "]'s connectingEdge's headCell address is: "
		<< nodeList[stoi(nodeStr)].connectingEdges.headCell << endl;
	if (nodeList[stoi(nodeStr)].connectingEdges.headCell != NULL)
	{
		cout << "\tWith Edge Address: " << nodeList[stoi(nodeStr)].connectingEdges.headCell->listEdge << endl;
		cout << "\tWith Node A Address: " << nodeList[stoi(nodeStr)].connectingEdges.headCell->listEdge->nodeA << endl;
		cout << "\tWith Node B Address: " << nodeList[stoi(nodeStr)].connectingEdges.headCell->listEdge->nodeB << endl;
	}
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	//Truncate the Node nugget I just used from line

	//call parseGraphLine() recursively

	//Return true (?)
	return true;
	
}

int Graph::getNumOfNodes()
{
	//stuff
	return numOfNodes;
}

Node Graph::getNodeAtIndex(int index)
{
	return nodeList[index];
}