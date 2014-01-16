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
	Graph graph0 = Graph("ExampleGraphFile0.txt");
	Graph graph1 = Graph("ExampleGraphFile1.txt");
	Graph graph2 = Graph("ExampleGraphFile2.txt");

	cout << "graph0 has " << graph0.getNumOfNodes() << " Nodes!\n";
	cout << "graph1 has " << graph1.getNumOfNodes() << " Nodes!\n";
	cout << "graph2 has " << graph2.getNumOfNodes() << " Nodes!\n";

	system("pause");
	return 0;
}