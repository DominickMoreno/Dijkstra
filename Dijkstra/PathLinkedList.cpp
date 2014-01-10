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

//Returns the Path at the given index, 0-based
Path PathLinkedList::getPath(int index)
{
	int i; //iteration var
	Path *pathIter = headPointer; //iterating pointer

	//Iterate through loop enough times to reach the desired index
	for (i = 0; i < index; i++)
	{
		if (pathIter == NULL)
		{
			/* If the loop reaches the end of the list without
			   reaching the desired index (ie the index does not
			   exist in the list), return null pointer
			*/
			break;
		}
		//Traverse the list
		pathIter = pathIter->getNextPath();
	}

	//Return the path
	return *pathIter;
}

void PathLinkedList::append(Path &pathToBeAdded)
{
	cout << "\t--Inside append--\n";
	cout << "\t\tpathToBeAdded node A: " << pathToBeAdded.getA().getNodeNumber() << endl;
	cout << "\t\tpathToBeAdded node B: " << pathToBeAdded.getB().getNodeNumber() << endl;
	cout << "\t\tpathToBeAdded address: " << &pathToBeAdded << endl;
	cout << "\t\tnextPath (before): " << pathToBeAdded.getNextPath() << endl;
	cout << "\t\tlastPath (before): " << pathToBeAdded.getLastPath() << endl;
	cout << "\t\tList headPointer (before): " << headPointer << endl;
	cout << "\t\tList tailPointer (before): " << tailPointer << endl;

	if (&pathToBeAdded == NULL)
	{
		//Do nothing, as the it's just a null pointer
	}
	else if (headPointer == NULL)
	{
		//If there are not any existing Paths in the list
		headPointer = &pathToBeAdded;
		tailPointer = &pathToBeAdded;
		numOfPaths++;
	}
	else
	{
		//There are existing paths in the list
		
		//Make the current tail pointer point to the appended Path
		tailPointer->setNextPath(pathToBeAdded);

		//Make the lastPath of the appended Path point to the current tail pointer
		pathToBeAdded.setLastPath(*tailPointer);

		//Make the appended Path the new tail pointer
		tailPointer = &pathToBeAdded;

		//nextPath of appended Path is already NULL, don't need to set

		numOfPaths++;
	}
	cout << "\t\tnextPath (after): " << pathToBeAdded.getNextPath() << endl;
	cout << "\t\tlastPath (after): " << pathToBeAdded.getLastPath() << endl;
	cout << "\t\tList headPointer (after): " << headPointer << endl;
	cout << "\t\tList tailPointer (after): " << tailPointer << endl;
	cout << "\t--*--\n";
}

//Appends a path to the list using the '+' operator
PathLinkedList PathLinkedList::operator+(Path &rhs)
{
	cout << "-Inside operator-" << endl;
	cout << "\trhs node A: " << rhs.getA().getNodeNumber() << endl;
	cout << "\trhs node B: " << rhs.getB().getNodeNumber() << endl;
	cout << "\trhs address: " << &rhs << endl;
	cout << "-*-\n";
	this->append(rhs);
	return *this;
}