/* Implementation file for Node class*/

#include "Node.h"

//function definitions
//General use constructor
Node::Node(int nodeNumParam)
{
	nodeNumber = nodeNumParam;
	//connectingPaths = PathLinkedList();
}

Node::Node()
{
	nodeNumber = 0;
	//connectingPaths = PathLinkedList();
}

//Getter for nodeNumber
int Node::getNodeNumber()
{
	return nodeNumber;
}