/* EdgeLinkedList class header file

This class will be used to hold all of
the edges that a given node has. It is
a linked list that keeps track of the
number of elements it has, a function
to retrieve an element at a specific
index, and an append function (note
there is no delete function - not
necessary)

For convenience (and style points)
I made the actual append function
private, and overloaded the "+"
operator, so that I can write
"someLinkedList = someLinkedList + someEdge"
instead of "someLinkedList.append(someEdge)".
While this doesn't save typing space, I just
wanted the operator overloading practice,
and it looks cool
*/

#ifndef EDGELINKEDLIST_H
#define EDGELINKEDLIST_H

#include "Edge.h"

//Cell in the linked list
struct EdgeCell
{
	Edge *listEdge; //Data in the linked list cell
	EdgeCell *nextCell; //Next pointer in the list
	EdgeCell *lastCell; //Last pointer in the list
};

class EdgeLinkedList
{
private:


	EdgeCell *headCell; //Linked list starting point
	EdgeCell *tailCell; //Linked list ending point 
	int numOfEdges; //Number of elements (Edges) in list
	void append(Edge&); //Append method to add Edges
	static EdgeCell *convertEdgeToEdgeCell(Edge&); //Converts an Edge to an EdgeCell struct
public:
	EdgeLinkedList(); //Constructor. Note only a default one exists
	int getNumEdges(); //Returns the number of Edges in the list
	Edge getEdge(int); //Returns the Edge at the given index in the list
	EdgeLinkedList operator+(Edge&); //Adds a Edge to the list
};

#endif EDGELINKEDLIST_H