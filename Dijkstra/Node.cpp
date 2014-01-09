/* Implementation file for Node class*/

#include "Node.h"
#include <iostream>
#include <string>

//function definitions
//General use constructor
Node::Node(int nodeNumParam)
{
	nodeNumber = nodeNumParam;
}


//Default constructor
Node::Node()
{
	nodeNumber = 0;
}

int Node::getNodeNumber()
{
	return nodeNumber;
}