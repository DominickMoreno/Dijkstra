/* Node class header file.

A node represents a location on a map. Important
values of this classinclude a list of all the
other nodes a given one connects to. This is
implemented with a linked list of Path objects
*/

#ifndef NODE_H
#define NODE_H

class PathLinkedList;
class Path;

#include "PathLinkedList.h"
class Node
{
private:
	int nodeNumber; //Identifies this node (in a map) w/ a num. Maybe not needed
	int numNodesConnected; //Number of nodes this node is connected to
	PathLinkedList connectingPaths; //Linked List of all the Paths this node is connected to
public:
	Node(int, PathLinkedList); //Constructor
	int getNodeNumber(); //Getter for nodeNumber
	int getNumNodesConnected(); //Getter for numNodesConnected
};

#endif