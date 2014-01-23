/* Author: Dominick Moreno
** Project: Dijkstra
** E-mail: Dominickmoreno92@gmail.com
** linkedin: www.linkedin.com/pub/dominick-moreno/65/2a6/841/
**
** General code info here
**
*/

#include <iostream>
#include "GraphCollection.h"
#include "Node.h"
#include "Edge.h"
#include "TextUI.h"
#include "Graph.h"

using namespace std;

int main(){
	//TextInterface::displayTextMenu(); //Call the interface
	int i,j;
	Graph *myGraph0 = new Graph("ExampleGraphFile0.txt");
	Graph *myGraph1 = new Graph("ExampleGraphFile1.txt");
	Graph *myGraph2 = new Graph("ExampleGraphFile2.txt");

	cout << "Graph 0 name is: " << myGraph0->getGraphName() << endl;
	cout << "Graph 1 name is: " << myGraph1->getGraphName() << endl;
	cout << "Graph 2 name is: " << myGraph2->getGraphName() << endl;

	GraphCollection myCollect = GraphCollection();
	cout << "Adding graph0 to collection\n";
	myCollect.addGraph(*myGraph0);
	myCollect.addGraph(*myGraph1);
	myCollect.addGraph(*myGraph2);

	cout << "myCollect now has: " << myCollect.getNumOfGraphs() << " graph(s)\n";
	cout << "They are named:\n";
	for (i = 0; i < myCollect.getNumOfGraphs(); i++)
	{
		cout << "\t" << myCollect.getGraphAtIndex(i)->getGraphName() << endl;
		cout << "\tAnd have Nodes:\n";
		for (j = 0; j < myCollect.getGraphAtIndex(i)->getNumOfNodes(); j++)
		{
			cout << "\t\t" << myCollect.getGraphAtIndex(i)->getNodeAtIndex(j)->getNodeNumber() << endl;
		}
	}

	system("pause");
	return 0;
}