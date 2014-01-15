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
#include "TextUI.h"

using namespace std;

int main(){
	//TextInterface::displayTextMenu(); //Call the interface
	int i;

	Node nodeA = Node(0);
	Node nodeB = Node(1);
	Node nodeC = Node(2);

	Path path1 = Path(nodeA, nodeB, 1);
	Path path2 = Path(nodeB, nodeC, 2);
	Path path3 = Path(nodeC, nodeA, 3);

	nodeA.addPath(path1);
	nodeA.addPath(path2);
	nodeA.addPath(path3);
	nodeB.addPath(path1);
	nodeB.addPath(path2);
	nodeB.addPath(path3);
	nodeC.addPath(path1);
	nodeC.addPath(path2);
	nodeC.addPath(path3);
	
	cout << "NodeA (Node #: " << nodeA.getNodeNumber() << ") connecting paths:\n";
	for (i = 0; i < nodeA.getConnectingPaths().getNumPaths(); i++)
	{
		cout << "\tPath#: " << i << endl;
		cout << "\tConnecting Path Node A: " << nodeA.getConnectingPaths().getPath(i).getA().getNodeNumber() << endl;
		cout << "\tConnecting Path Node B: " << nodeA.getConnectingPaths().getPath(i).getB().getNodeNumber() << endl;
		cout << "\tConnecting Path weight: " << nodeA.getConnectingPaths().getPath(i).getWeight() << endl;
		cout << endl;
	}

	cout << endl;
	cout << "NodeB (Node #: " << nodeB.getNodeNumber() << ") connecting paths:\n";
	for (i = 0; i < nodeB.getConnectingPaths().getNumPaths(); i++)
	{
		cout << "\tPath#: " << i << endl;
		cout << "\tConnecting Path Node A: " << nodeB.getConnectingPaths().getPath(i).getA().getNodeNumber() << endl;
		cout << "\tConnecting Path Node B: " << nodeB.getConnectingPaths().getPath(i).getB().getNodeNumber() << endl;
		cout << "\tConnecting Path weight: " << nodeB.getConnectingPaths().getPath(i).getWeight() << endl;
		cout << endl;
	}

	cout << endl;
	cout << "NodeC (Node #: " << nodeC.getNodeNumber() << ") connecting paths:\n";
	for (i = 0; i < nodeC.getConnectingPaths().getNumPaths(); i++)
	{
		cout << "\tPath#: " << i << endl;
		cout << "\tConnecting Path Node A: " << nodeC.getConnectingPaths().getPath(i).getA().getNodeNumber() << endl;
		cout << "\tConnecting Path Node B: " << nodeC.getConnectingPaths().getPath(i).getB().getNodeNumber() << endl;
		cout << "\tConnecting Path weight: " << nodeC.getConnectingPaths().getPath(i).getWeight() << endl;
		cout << endl;
	}


	system("pause");
	return 0;
}