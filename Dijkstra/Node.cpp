/* Implementation file for Node class*/

#include "Node.h"

//function definitions
//General use constructor
Node::Node(int nodeNumParam, PathLinkedList paramPaths)
{
	nodeNumber = nodeNumParam;
	//connectingPaths = PathLinkedList();
}

//Getter for nodeNumber
int Node::getNodeNumber()
{
	return nodeNumber;
}