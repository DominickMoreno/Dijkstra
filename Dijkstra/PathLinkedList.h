/* PathLinkedList class header file

This class will be used to hold all of
the paths that a given node has. It is
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
"someLinkedList = someLinkedList + somePath"
instead of "someLinkedList.append(somePath)".
While this doesn't save typing space, I just
wanted the operator overloading practice,
and it looks cool
*/

#ifndef PATHLINKEDLIST_H
#define PATHLINKEDLIST_H

#include "Path.h"

class PathLinkedList
{
private:
	Path *headPointer; //Linked list starting point
	Path *tailPointer; //Linked list ending point
	int numOfPaths; //Number of elements (Paths) in list
	void append(Path&); //Append method to add Paths
public:
	PathLinkedList(); //Constructor. Note only a default one exists
	int getNumPaths(); //Returns the number of Paths in the list
	Path getPath(int); //Returns the Path at the given index in the list
	PathLinkedList operator+(Path&); //Adds a Path to the list
};

#endif PATHLINKEDLIST_H