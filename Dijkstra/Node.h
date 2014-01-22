/* Node class header file.

A node represents a location on a map. Important
values of this classinclude a list of all the
other nodes a given one connects to. This is
implemented with a linked list of Path objects
*/

#ifndef NODE_H
#define NODE_H

class EdgeLinkedList;
class Edge;

#include "EdgeLinkedList.h"
class Node
{
private:
	int nodeNumber; //Identifies this node (in a map) w/ a num. Maybe not needed
	int numNodesConnected; //Number of nodes this node is connected to
	EdgeLinkedList connectingEdges; //Linked List of all the Edges this node is connected to
public:
	Node(int); //Constructor
	Node(); //Default constructor - I get yelled at without this
	bool addEdge(Edge&); //Add a Edge to the connectingEdges
	EdgeLinkedList getConnectingEdges(); //Getter for connectingEdges
	int getNodeNumber(); //Getter for nodeNumber
	int getNumNodesConnected(); //Getter for numNodesConnected
	Edge *doNodesConnect(Node*); //Determines if two Nodes connect, returns ptr to that Edge
};

#endif