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
	cout << "\t++Inside getEdge()++\n";
	//TODO: Error in here!
	int i; //iteration var
	EdgeCell *edgeCellIter = headCell; //iterating pointer
	cout << "\t\theadPointer address: " << headCell << endl;
	cout << "\t\tedgeCellIter address: " << edgeCellIter << endl;
	cout << "\t\theadPointer edge address: " << headCell->listEdge << endl;
	cout << "\t\theadPointer nodeA address: " << headCell->listEdge->nodeA << endl;
	cout << "\t\theadPointer nodeB address: " << headCell->listEdge->nodeB << endl;

	//Iterate through loop enough times to reach the desired index
	for (i = 0; i < index; i++)
	{
		cout << "\t\titeration: " << i << endl;
		cout << "\t\tedgeCellIter address: " << edgeCellIter << endl;
		cout << "\t\tNULL address: " << NULL << endl;
		if (edgeCellIter == NULL)
		{
			/* If the loop reaches the end of the list without
			reaching the desired index (ie the index does not
			exist in the list), return null pointer
			*/
			cout << "\t\tedgeCellIter is NULL. BREAK\n";
			break;
		}
		//Traverse the list
		cout << "\t\tedgeCell is not NULL.\n";
		cout << "\t\tedgeCellIter address: " << edgeCellIter << endl;
		edgeCellIter = edgeCellIter->nextCell;
	}

	//Return the edge
	cout << "\t\theaderCell's data address: " << headCell->listEdge << endl;
	cout << "\t\tEdge's node A address: " << headCell->listEdge->nodeA << endl;
	cout << "\t\tEdge's node B address: " << headCell->listEdge->nodeB << endl;
	cout << "\t++Leaving getEdge()++\n";
	return edgeCellIter->listEdge;
}

void EdgeLinkedList::append(Edge &edgeToBeAdded)
{
	cout << "\t!!!Entering append()!!!\n";
	//Convert edgeToBeAdded into an edgeCell
	EdgeCell *cellToBeAdded = convertEdgeToEdgeCell(edgeToBeAdded);
	cout << "\t\tnumOfEdges is: " << numOfEdges << endl;
	cout << "\t\tcellToBeAdded's Edge Address: " << cellToBeAdded->listEdge << endl;
	cout << "\t\tcellToBeAdded node A Address: " << cellToBeAdded->listEdge->nodeA << endl;
	cout << "\t\tcellToBeAdded node B Address: " << cellToBeAdded->listEdge->nodeB << endl;

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
	cout << "\t\theadCell Address: " << headCell << endl;
	cout << "\t\theadCell Edge Address: " << headCell->listEdge << endl;
	cout << "\t\theadCell node A address: " << headCell->listEdge->nodeA << endl;
	cout << "\t\theadCell node B address: " << headCell->listEdge->nodeB << endl;
	cout << "\t!!!Exiting append()!!!\n";
}

//Appends a edge to the list using the '+' operator
EdgeLinkedList EdgeLinkedList::operator+(Edge &rhs)
{
	//Simply use the private append method
	this->append(rhs);
	return *this;
}