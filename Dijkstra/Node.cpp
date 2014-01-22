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
	nodeNumber = -1;
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

//Edge *Node::doNodesConnect(const Node *seekerNode)
Edge *Node::doNodesConnect(Node *seekerNode)
{
	Edge *edgeIter = new Edge(); //Iterates through the linked list

	/* Just go through the whole list of other Nodes this Node
	   connects to. If you get a match (ie the seekerNode number
	   is on either of the ends in any of THIS Node's edges),
	   return that weight. If no such connection is found, return
	   -1
	*/
	for (int i = 0; i < connectingEdges.getNumEdges(); i++)
	{
		edgeIter = connectingEdges.getEdge(i);

		if (seekerNode->nodeNumber == edgeIter->getA().getNodeNumber()
			|| seekerNode->nodeNumber == edgeIter->getB().getNodeNumber())
		{
			return edgeIter; //Connection found, return pointer to that Edge
		}
	}

	return NULL; //Connection not found, return NULL
}