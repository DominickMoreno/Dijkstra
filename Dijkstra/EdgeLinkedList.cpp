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
	/*
	headCell->lastCell = NULL;
	headCell->nextCell = NULL;
	headCell->listEdge = NULL;
	tailCell->lastCell = NULL;
	tailCell->nextCell = NULL;
	tailCell->listEdge = NULL;
	*/
	numOfEdges = 0;
}

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
Edge EdgeLinkedList::getEdge(int index)
{
	//TODO: Error in here!
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
	return *edgeCellIter->listEdge;
}

void EdgeLinkedList::append(Edge &edgeToBeAdded)
{
	//Convert edgeToBeAdded into an edgeCell
	EdgeCell *cellToBeAdded = convertEdgeToEdgeCell(edgeToBeAdded);

	cout << "\t\t\t######Inside Append######\n";
	cout << "\t\t\t\tEdge address: " << &edgeToBeAdded << endl;
	cout << "\t\t\t\tnumOfEdges is: " << numOfEdges << endl;
	cout << "\t\t\t\tNew Edge Cell Address is: " << cellToBeAdded << endl;
	cout << "\t\t\t\tNew Edge Cell Edge Address: " << cellToBeAdded->listEdge << endl;
	cout << "\t\t\t\tBefore:\n";
	cout << "\t\t\t\t\theadCell Address: " << headCell << endl;
	if (headCell != NULL)
	{
		cout << "\t\t\t\t\theadCell.lastCell Address: " << headCell->lastCell << endl;
		cout << "\t\t\t\t\theadCell.nextCell Address: " << headCell->nextCell << endl;
		cout << "\t\t\t\t\theadCell.listEdge Address: " << headCell->listEdge << endl << endl;
	}
	cout << "\t\t\t\t\ttailCell Address: " << tailCell << endl;
	if (tailCell != NULL)
	{
		cout << "\t\t\t\t\ttailCell.lastCell Address: " << tailCell->lastCell << endl;
		cout << "\t\t\t\t\ttailCell.nextCell Address: " << tailCell->nextCell << endl;
		cout << "\t\t\t\t\ttailCell.listEdge Address: " << tailCell->listEdge << endl << endl;
	}
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
		cout << "\t\t\t\t$$$$$$$$Inside Append, with existing$$$$$$$\n";
		//There are existing edges in the list
		//Append this new edgeCell to the linked list
		//Make current tailCell point to new cell
		tailCell->nextCell = cellToBeAdded; //Assign 1 - GOOD

		cout << "\t\t\t\tAfter Assign 1:\n";
		cout << "\t\t\t\t\ttailCell Address: " << &tailCell << endl;
		cout << "\t\t\t\t\ttailCell lastCell Address: " << tailCell->lastCell << endl;
		cout << "\t\t\t\t\tnextCell lastCell Address: " << tailCell->nextCell << endl << endl;

		//Make new Cell point back to current tailCell
		cellToBeAdded->lastCell = tailCell; //Assign 2 - Maybe good - undetermined

		cout << "\t\t\t\tAfter Assign 2:\n";
		cout << "\t\t\t\t\ttailCell Address: " << &tailCell << endl;
		cout << "\t\t\t\t\ttailCell lastCell Address: " << tailCell->lastCell << endl;
		cout << "\t\t\t\t\tnextCell lastCell Address: " << tailCell->nextCell << endl << endl;
		
		//Make tailCell point to new cell
		tailCell = cellToBeAdded; //Assign 3 - Problem

		cout << "\t\t\t\tAfter Assign 3:\n";
		cout << "\t\t\t\t\ttailCell Address: " << &tailCell << endl;
		cout << "\t\t\t\t\ttailCell lastCell Address: " << tailCell->lastCell << endl;
		cout << "\t\t\t\t\tnextCell lastCell Address: " << tailCell->nextCell << endl << endl;

		//iterate number of edges
		numOfEdges++;
		cout << "\t\t\t\t$$$$$$$$Exiting Append, with existing$$$$$$$\n";
	}
	cout << "\t\t\t\tAfter:\n";
	cout << "\t\t\t\t\theadCell Address: " << headCell << endl;
	cout << "\t\t\t\t\theadCell.lastCell Address: " << headCell->lastCell << endl;
	cout << "\t\t\t\t\theadCell.nextCell Address: " << headCell->nextCell << endl;
	cout << "\t\t\t\t\theadCell.listEdge Address: " << headCell->listEdge << endl << endl;
	cout << "\t\t\t\t\ttailCell Address: " << tailCell << endl;
	cout << "\t\t\t\t\ttailCell.lastCell Address: " << tailCell->lastCell << endl;
	cout << "\t\t\t\t\ttailCell.nextCell Address: " << tailCell->nextCell << endl;
	cout << "\t\t\t\t\ttailCell.listEdge Address: " << tailCell->listEdge << endl << endl;
	cout << "\t\t\t######Exiting Append######\n";
}

//Appends a edge to the list using the '+' operator
EdgeLinkedList EdgeLinkedList::operator+(Edge &rhs)
{
	//Simply use the private append method
	this->append(rhs);
	return *this;
}

EdgeCell *EdgeLinkedList::getHeadCell()
{
	return headCell;
}

EdgeCell *EdgeLinkedList::getTailCell()
{
	return tailCell;
}