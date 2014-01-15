/* Implementation file for Node class*/

#include <iostream>
#include "Node.h"

using namespace std;

//function definitions
//General use constructor
Node::Node(int nodeNumParam)
{
	nodeNumber = nodeNumParam; //Set nodeNumber
	connectingPaths = PathLinkedList(); //set the paths that this Node connects to
}

//Adds a Path to the connectingPaths in the Node
bool Node::addPath(Path &pathToBeAdded)
{
	/* Returns true if pathToBeAdded actually contains
	   the Node it's being added to. Otherwise returns
	   false
	   */
	cout << "\t----Inside addPath----\n";
	cout << "\t\tnodeNumber: " << nodeNumber << endl;
	cout << "\t\tpathToBeAdded nodeA number: " << pathToBeAdded.getA().getNodeNumber() << endl;
	cout << "\t\tpathToBeAdded nodeB number: " << pathToBeAdded.getB().getNodeNumber() << endl;
	cout << "\t\tpath weight: " << pathToBeAdded.getWeight() << endl;

	if (pathToBeAdded.getA().getNodeNumber() == nodeNumber
		|| pathToBeAdded.getB().getNodeNumber() == nodeNumber)
	{
		//pathToBeAdded does in fact have this Node as nodeA or B
		connectingPaths = connectingPaths + pathToBeAdded;
		cout << "\t----Exiting addPath, adding path----\n";
		return true;
	}
	
	//The pathToBeAdded doesn't connect this Node
	cout << "\t----Exiting addPath, not adding path----\n";
	return false;
}

//Getter for connectingPaths
PathLinkedList Node::getConnectingPaths()
{
	//TODO: Verify this will pass the address of connectingPaths
	return connectingPaths;
}

//Getter for nodeNumber
int Node::getNodeNumber()
{
	return nodeNumber;
}