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
	headCell.lastCell = NULL;
	headCell.nextCell = NULL;
	tailCell.lastCell = NULL;
	tailCell.lastCell = NULL;
	numOfEdges = 0;
}

EdgeCell EdgeLinkedList::convertEdgeToEdgeCell(Edge &edgeToConvert)
{
	EdgeCell newCell;

	newCell.nextCell = NULL;
	newCell.lastCell = NULL;
	newCell.listEdge = &edgeToConvert;

	return newCell;
}

//Getter for numEdges
int EdgeLinkedList::getNumEdges()
{
	return numOfEdges;
}

//Returns the Edge at the given index, 0-based
Edge EdgeLinkedList::getEdge(int index)
{
	//TODO: Error in here!
	int i; //iteration var
	EdgeCell *edgeCellIter = &headCell; //iterating pointer

	//Iterate through loop enough times to reach the desired index
	for (i = 0; i < index; i++)
	{
		if (edgeCellIter == NULL)
		{
			/* If the loop reaches the end of the list without
			reaching the desired index (ie the index does not
			exist in the list), return null pointer
			*/
			break;
		}
		//Traverse the list
		edgeCellIter = edgeCellIter->nextCell;
	}

	//Return the edge
	return *edgeCellIter->listEdge;
}

void EdgeLinkedList::append(Edge &edgeToBeAdded)
{

	if (&edgeToBeAdded == NULL)
	{
		//Do nothing, as the it's just a null pointer
	}
	else if (numOfEdges == 0)
	{
		//If there are not any existing Edges in the list
		
		//Convert edgeToBeAdded into an EdgeCell
		headCell = convertEdgeToEdgeCell(edgeToBeAdded);

		//Fix the next and last pointers in the new EdgeCell
		headCell.lastCell = &headCell;
		headCell.nextCell = NULL;

		tailCell = headCell;

		//iterate number of edges
		numOfEdges++;
	}
	else
	{
		//There are existing edges in the list

		/* Convert the appending edge to an edge cell and
		   make the current tail cell point to the appending edge
		*/
		tailCell.nextCell = &convertEdgeToEdgeCell(edgeToBeAdded);

		//Make the appending edge back pointer point towards the current tail cell
		tailCell.nextCell->lastCell = &tailCell;

		//Make the tail pointer point towards the appending edge
		tailCell = *tailCell.nextCell;

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