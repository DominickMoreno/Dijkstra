/* Path class implementation file */

#include "Path.h"
#include <iostream>
#include <string>

//function definitions

//Constructor
Path::Path(Node nodeFrom, Node nodeTo, float paramWeight)
{
	/* First parameter node becomes nodeA, the second
	   nodeB. Also allocates this path's weight/distance
	*/
	nodeA = nodeFrom;
	nodeB = nodeTo;
	weight = paramWeight;
}

//Destructor, maybe not necessary?
Path::~Path()
{
	//do destructor stuff
}

//Getter for nodeA
Node Path::getA()
{
	return nodeA;
}

//Getter for nodeB
Node Path::getB()
{
	return nodeB;
}

//Getter for weight
float Path::getWeight()
{
	return weight;
}

//Sets the previous and next path, for the linked list
void Path::setLastNextPath(Path last, Path next)
{
	lastPath = &last;
	nextPath = &next;
}

//Getter for lastPath
Path* Path::getLastPath()
{
	return lastPath;
}

//Getter for nextPath
Path* Path::getNextPath()
{
	return nextPath;
}