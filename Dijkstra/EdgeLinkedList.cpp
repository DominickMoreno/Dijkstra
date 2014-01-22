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
	headCell = NULL;
	tailCell = NULL;
	numOfEdges = 0;
}

//Used for convenience to make a new EdgeCell pointer from an Edge
EdgeCell *EdgeLinkedList::convertEdgeToEdgeCell(Edge &edgeToConvert)
{
	EdgeCell *newCell = new EdgeCell;
	newCell->nextCell = NULL;
	newCell->lastCell = NULL;
	newCell->listEdge = &edgeToConvert;

	return newCell;
}

//Getter for numEdges
int EdgeLinkedList::getNumEdges()
{
	return numOfEdges;
}

//Returns the Edge at the given index, 0-based
Edge *EdgeLinkedList::getEdge(int index)
{
	int i; //iteration var
	EdgeCell *edgeCellIter = headCell; //iterating pointer

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
	return edgeCellIter->listEdge;
}

void EdgeLinkedList::append(Edge &edgeToBeAdded)
{
	//Convert edgeToBeAdded into an edgeCell
	EdgeCell *cellToBeAdded = convertEdgeToEdgeCell(edgeToBeAdded);

	if (&edgeToBeAdded == NULL)
	{
		//Do nothing, as it's just a null pointer
	}
	else if (numOfEdges == 0)
	{
		//If there are not any existing Edges in the list
		//Make this new cell the only member in the linked list
		//Have headCell point to this new cell
		headCell = cellToBeAdded;


		//Have tailCell point to this new cell
		tailCell = cellToBeAdded;

		//iterate number of edges
		numOfEdges++;
	}
	else
	{
		//There are existing edges in the list
		//Append this new edgeCell to the linked list
		//Make current tailCell point to new cell
		tailCell->nextCell = cellToBeAdded; 

		//Make new Cell point back to current tailCell
		cellToBeAdded->lastCell = tailCell;

		//Make tailCell point to new cell
		tailCell = cellToBeAdded; 

		//iterate number of edges
		numOfEdges++;
	}
}

//Appends a edge to the list using the '+' operator
EdgeLinkedList EdgeLinkedList::operator+(Edge &rhs)
{
	//Simply use the private append method
	this->append(rhs);
	return *this;
}