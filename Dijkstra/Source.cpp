/* Author: Dominick Moreno
** Project: Dijkstra
** E-mail: Dominickmoreno92@gmail.com
** linkedin: www.linkedin.com/pub/dominick-moreno/65/2a6/841/
**
** General code info here
**
*/

#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "TextUI.h"
#include "Graph.h"

using namespace std;

int main(){
	//TextInterface::displayTextMenu(); //Call the interface
	Graph *myGraph0 = new Graph("ExampleGraphFile0.txt");
	Graph *myGraph1 = new Graph("ExampleGraphFile1.txt");
	Graph *myGraph2 = new Graph("ExampleGraphFile2.txt");

	cout << "Graph 0 name is: " << myGraph0->getGraphName() << endl;
	cout << "Graph 1 name is: " << myGraph1->getGraphName() << endl;
	cout << "Graph 2 name is: " << myGraph2->getGraphName() << endl;

	system("pause");
	return 0;
}