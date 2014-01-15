/* Edge class implementation file */

#include <iostream>
#include "Edge.h"
//function definitions

//Constructor
Edge::Edge(Node &nodeFrom, Node &nodeTo, float paramWeight)
{
	/* First parameter node becomes nodeA, the second
	nodeB. Also allocates this edge's weight/distance
	*/
	nodeA = &nodeFrom;
	nodeB = &nodeTo;
	weight = paramWeight;
	lastEdge = NULL;
	nextEdge = NULL;
}

//Getter for nodeA
Node Edge::getA()
{
	return *nodeA;
}

//Getter for nodeB
Node Edge::getB()
{
	return *nodeB;
}

//Getter for weight
float Edge::getWeight()
{
	return weight;
}


//Setter for last Edge
void Edge::setLastEdge(Edge &previousEdge)
{
	lastEdge = &previousEdge;
}

//Setter for next Edge
void Edge::setNextEdge(Edge &followingEdge)
{
	nextEdge = &followingEdge;
}

//Getter for lastEdge
Edge* Edge::getLastEdge()
{
	return lastEdge;
}

//Getter for nextEdge
Edge* Edge::getNextEdge()
{
	return nextEdge;
}