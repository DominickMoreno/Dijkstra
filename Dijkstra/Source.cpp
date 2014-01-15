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

using namespace std;

int main(){
	//TextInterface::displayTextMenu(); //Call the interface
	int i;

	Node nodeA = Node(0);
	Node nodeB = Node(1);
	Node nodeC = Node(2);

	Edge edge1 = Edge(nodeA, nodeB, 1);
	Edge edge2 = Edge(nodeB, nodeC, 2);
	Edge edge3 = Edge(nodeC, nodeA, 3);

	nodeA.addEdge(edge1);
	nodeA.addEdge(edge2);
	nodeA.addEdge(edge3);
	nodeB.addEdge(edge1);
	nodeB.addEdge(edge2);
	nodeB.addEdge(edge3);
	nodeC.addEdge(edge1);
	nodeC.addEdge(edge2);
	nodeC.addEdge(edge3);
	
	cout << "NodeA (Node #: " << nodeA.getNodeNumber() << ") connecting edges:\n";
	for (i = 0; i < nodeA.getConnectingEdges().getNumEdges(); i++)
	{
		cout << "\tEdge#: " << i << endl;
		cout << "\tConnecting Edge Node A: " << nodeA.getConnectingEdges().getEdge(i).getA().getNodeNumber() << endl;
		cout << "\tConnecting Edge Node B: " << nodeA.getConnectingEdges().getEdge(i).getB().getNodeNumber() << endl;
		cout << "\tConnecting Edge weight: " << nodeA.getConnectingEdges().getEdge(i).getWeight() << endl;
		cout << endl;
	}

	cout << endl;
	cout << "NodeB (Node #: " << nodeB.getNodeNumber() << ") connecting edges:\n";
	for (i = 0; i < nodeB.getConnectingEdges().getNumEdges(); i++)
	{
		cout << "\tEdge#: " << i << endl;
		cout << "\tConnecting Edge Node A: " << nodeB.getConnectingEdges().getEdge(i).getA().getNodeNumber() << endl;
		cout << "\tConnecting Edge Node B: " << nodeB.getConnectingEdges().getEdge(i).getB().getNodeNumber() << endl;
		cout << "\tConnecting Edge weight: " << nodeB.getConnectingEdges().getEdge(i).getWeight() << endl;
		cout << endl;
	}

	cout << endl;
	cout << "NodeC (Node #: " << nodeC.getNodeNumber() << ") connecting edges:\n";
	for (i = 0; i < nodeC.getConnectingEdges().getNumEdges(); i++)
	{
		cout << "\tEdge#: " << i << endl;
		cout << "\tConnecting Edge Node A: " << nodeC.getConnectingEdges().getEdge(i).getA().getNodeNumber() << endl;
		cout << "\tConnecting Edge Node B: " << nodeC.getConnectingEdges().getEdge(i).getB().getNodeNumber() << endl;
		cout << "\tConnecting Edge weight: " << nodeC.getConnectingEdges().getEdge(i).getWeight() << endl;
		cout << endl;
	}


	system("pause");
	return 0;
}