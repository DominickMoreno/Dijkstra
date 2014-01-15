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

//Adds an Edge to the connectingEdges in the Node
bool Node::addEdge(Edge &edgeToBeAdded)
{
	/* Returns true if edgeToBeAdded actually contains
	   the Node it's being added to. Otherwise returns
	   false
	   */
	cout << "\t----Inside addEdge----\n";
	cout << "\t\tnodeNumber: " << nodeNumber << endl;
	cout << "\t\tedgeToBeAdded nodeA number: " << edgeToBeAdded.getA().getNodeNumber() << endl;
	cout << "\t\tedgeToBeAdded nodeB number: " << edgeToBeAdded.getB().getNodeNumber() << endl;
	cout << "\t\tedge weight: " << edgeToBeAdded.getWeight() << endl;

	if (edgeToBeAdded.getA().getNodeNumber() == nodeNumber
		|| edgeToBeAdded.getB().getNodeNumber() == nodeNumber)
	{
		//edgeToBeAdded does in fact have this Node as nodeA or B
		connectingEdges = connectingEdges + edgeToBeAdded;
		cout << "\t----Exiting addEdge, adding edge----\n";
		return true;
	}
	
	//The edgeToBeAdded doesn't connect this Node
	cout << "\t----Exiting addEdge, not adding edge----\n";
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