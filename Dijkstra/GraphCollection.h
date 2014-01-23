/* GraphCollection class header file
   
   This (mutable) class is a collectiong for all of
   the Graphs a user wishes to load. It is implemented
   as a linked list
*/

#ifndef GRAPHCOLLECTION_H
#define GRAPHCOLLECTION_H

#include "Graph.h"

class GraphCollection
{
private:
	/* This collection is just a linked list. I'm making
	   this list with a struct, not bothering with back
	   pointers this time
	*/
	struct GraphCell
	{
		Graph *cell; //Holds the actual graph in this node in the LL
		GraphCell *next; //Pointer to the next cell in the LL
	};
	GraphCell *headCell; //Pointer to the starting Node
	int numOfGraphs; //Holds the number of Graphs in the LL
public:
	GraphCollection(); //Constructor, sets everything to null/0
	int getNumOfGraphs(); //Getter for number of Graphs in the collection
	bool addGraph(Graph&); //Adds a Graph to the collectiong
	Graph *getGraphAtIndex(int); //Returns the Graph at the given index (if it exists)
};

#endif GRAPHCOLLECTION_H