/* GraphCollection class implementation file */

#include "GraphCollection.h"

//Function definitions

//Constructor, sets everything to NULL/0
GraphCollection::GraphCollection()
{
	headCell = new GraphCell;
	headCell->cell = NULL;
	headCell->next = NULL;
	numOfGraphs = 0;
}

//Getter for numOfGraphs
int GraphCollection::getNumOfGraphs()
{
	return numOfGraphs;
}

//Adds the given Graph to the collection
bool GraphCollection::addGraph(Graph &newGraph)
{
	if (&newGraph == NULL)
	{
		//newGraph is NULL, ie it's not a graph. Addition failed
		return false;
	}
	if (!headCell->cell == NULL)
	{
		if (newGraph.getGraphName() == headCell->cell->getGraphName())
		{
			/* If the headCell is not NULL, but the newGraph has the same
			   name as the headCell graph, then it's a copy. Addition failed
			*/
			return false;
		}
	}

	GraphCell *newCell = new GraphCell; //Set the newGraph into a GraphCell
	newCell->next = NULL; //Since it will be the end of the LL, make it's next ptr NULL
	newCell->cell = &newGraph; //Actually attach the newGraph into its cell

	GraphCell *cellIter = headCell; //Used to iterate through the LL

	//Iterate to the end of the LL
	while (cellIter->next != NULL)
	{
		cellIter = cellIter->next;
		if (newGraph.getGraphName() == cellIter->cell->getGraphName())
		{
			//If the newGraph is already found in the LL, don't add and return false
			delete newCell;
			std::cout << "++++I've been added before!++++\n";
			return false;
		}
	}

	/* cellIter is now at the last cell in the LL. Make cellIter
	   now point to newCell, adding newCell to the LL.
	*/
	cellIter->next = newCell;

	/* If the collection is empty, then headCell's next and cell fields
	   will both be NULL. It should instead just be the cell for the
	   first Graph in the collection. To make this so, I want to delete
	   the original headCell's struct from memory. This is done using
	   the cellIter so that I don't have to make a new struct object.*/
	if (headCell->cell == NULL)
	{
		cellIter = headCell; //Pass the address headCell has to cellIter
		headCell = headCell->next; //Change headCell to point to the first real cell
		delete cellIter; //Delete the "garbage" headCell pointer
	}

	//Incrememnt numOfGraphs
	numOfGraphs++;

	return true;
}

//Returns the Graph at the given index in the LL
Graph *GraphCollection::getGraphAtIndex(int index)
{
	if (headCell->cell == NULL)
	{
		return NULL;
	}

	GraphCell *cellIter = headCell; //Used to iterate through the LL
	int i; //iteration counter

	//Iterate through loop enough times to reach the desired index
	for (i = 0; i < index; i++)
	{
		if (cellIter == NULL)
		{
			/* If the loop reaches the end of the list without
			reaching the desired index (ie the index does not
			exist in the list), return null pointer
			*/
			break;
		}
		cellIter = cellIter->next; //Keep iterating through the list
	}

	return cellIter->cell;


}