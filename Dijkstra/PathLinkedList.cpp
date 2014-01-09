//stuff

#include "PathLinkedList.h"
#include <iostream>
#include <string>

//function definitions

//constructor
PathLinkedList::PathLinkedList()
{
	headPointer = NULL;
	tailPointer = NULL;
	numOfPaths = 0;
}

//Getter for numPaths
int PathLinkedList::getNumPaths()
{
	return numOfPaths;
}

//Returns the Path at the given index
Path PathLinkedList::getPath(int index)
{
	//stuff
}

void PathLinkedList::append(Path pathToBeAdded)
{
	if (headPointer == NULL)
	{
		//If there are not any existing Paths in the list
		headPointer = &pathToBeAdded;
		tailPointer = &pathToBeAdded;
	}
	else
	{
		//There are existing paths in the list
		*tailPointer.
	}
}

//Appends a path to the list using the '+' operator
PathLinkedList PathLinkedList::operator+(const Path &rhs)
{
	//stuff
}