/* Implementation file for Node class*/

#include <iostream>
#include "Node.h"

using namespace std;

//function definitions
//General use constructor
Node::Node(int nodeNumParam)
{
	nodeNumber = nodeNumParam; //Set nodeNumber
	connectingEdges = EdgeLinkedList(); //set the edges that this Node connects to
}

//Default constructor. Not sure why necessary
Node::Node()
{
	nodeNumber = 0;
	connectingEdges = EdgeLinkedList();
}

//Adds an Edge to the connectingEdges in the Node
bool Node::addEdge(Edge &edgeToBeAdded)
{
	/* Returns true if edgeToBeAdded actually contains
	   the Node it's being added to. Otherwise returns
	   false
	*/
	if (edgeToBeAdded.getA().getNodeNumber() == nodeNumber
		|| edgeToBeAdded.getB().getNodeNumber() == nodeNumber)
	{
		//edgeToBeAdded does in fact have this Node as nodeA or B
		connectingEdges = connectingEdges + edgeToBeAdded;
		return true;
	}
	
	//The edgeToBeAdded doesn't connect this Node
	return false;
}

//Getter for connectingEdges
EdgeLinkedList Node::getConnectingEdges()
{
	//TODO: Verify this will pass the address of connectingEdges
	return connectingEdges;
}

//Getter for nodeNumber
int Node::getNodeNumber()
{
	return nodeNumber;
}