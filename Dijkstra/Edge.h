/* Edge class header file

Simple class that represents a connection
between two nodes. Has 3 fields - the two
nodes that are connected by that Edge
and the weight/distance of that Edge
*/

#ifndef EDGE_H
#define EDGE_H

class Node;

#include "Node.h"

class Edge
{
	friend class EdgeLinkedList;
private:
	Node *nodeA; //First node connected by edge
	Node *nodeB; //Second node connected by edge
	float weight; //Edge weight/distance

protected: //Used by friend class EdgeLinkedList
	Edge *lastEdge; //Previous edge in list
	Edge *nextEdge; //Next edge in list
	void setLastEdge(Edge&); //Setter for lastEdge
	void setNextEdge(Edge&); //Setter for nextEdge
public:
	Edge(Node&, Node&, float); //Constructor, class is immutable
	Node getA(); //Getter for nodeA
	Node getB(); //Getter for nodeB
	float getWeight(); //Getter for weightin constructor?
	Edge *getLastEdge(); //Getter for lastEdge
	Edge *getNextEdge(); //Getter for nextEdge

};

#endif EDGE_H