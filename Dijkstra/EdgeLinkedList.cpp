/* Edge Linked List class implementation file */

#include <iostream>
#include "Edge.h"
#include "EdgeLinkedList.h"
using namespace std;

//function definitions

//constructor
EdgeLinkedList::EdgeLinkedList()
{
	//Set all pointers to null, number of edges to 0
	headPointer = NULL;
	tailPointer = NULL;
	numOfEdges = 0;
}

//Getter for numEdges
int EdgeLinkedList::getNumEdges()
{
	return numOfEdges;
}

//Returns the Edge at the given index, 0-based
Edge EdgeLinkedList::getEdge(int index)
{
	int i; //iteration var
	Edge *edgeIter = headPointer; //iterating pointer

	//Iterate through loop enough times to reach the desired index
	for (i = 0; i < index; i++)
	{
		if (edgeIter == NULL)
		{
			/* If the loop reaches the end of the list without
			reaching the desired index (ie the index does not
			exist in the list), return null pointer
			*/
			break;
		}
		//Traverse the list
		edgeIter = edgeIter->getNextEdge();
	}

	//Return the edge
	return *edgeIter;
}

void EdgeLinkedList::append(Edge &edgeToBeAdded)
{

	if (&edgeToBeAdded == NULL)
	{
		//Do nothing, as the it's just a null pointer
	}
	else if (headPointer == NULL)
	{
		//If there are not any existing Edges in the list
		headPointer = &edgeToBeAdded;
		tailPointer = &edgeToBeAdded;

		numOfEdges++; //iterate
	}
	else
	{
		//There are existing edges in the list

		//Make the current tail pointer point to the appended Edge
		tailPointer->setNextEdge(edgeToBeAdded);

		//Make the lastEdge of the appended Edge point to the current tail pointer
		edgeToBeAdded.setLastEdge(*tailPointer);

		//Make the appended Edge the new tail pointer
		tailPointer = &edgeToBeAdded;

		//nextEdge of appended Edge is already NULL, don't need to set

		numOfEdges++; //iterate
	}
}

//Appends a edge to the list using the '+' operator
EdgeLinkedList EdgeLinkedList::operator+(Edge &rhs)
{
	//Simply use the private append method
	this->append(rhs);
	return *this;
}