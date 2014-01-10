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
	lastPath = NULL;
	nextPath = NULL;
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


//Setter for last path
void Path::setLastPath(Path &previousPath)
{
	lastPath = &previousPath;
}

//Setter for next path
void Path::setNextPath(Path &followingPath)
{
	nextPath = &followingPath;
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