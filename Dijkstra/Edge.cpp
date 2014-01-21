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
	std::cout << "Calling Edge constructor\n";
	nodeA = &nodeFrom;
	nodeB = &nodeTo;
	weight = paramWeight;
	std::cout << "Leaving Edge constructor\n";
}

//Default constructor
Edge::Edge()
{
	//Sets everything to a dummy value
	nodeA = NULL;
	nodeB = NULL;
	weight = -3.14;
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
