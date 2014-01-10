/* Author: Dominick Moreno
** Project: Dijkstra
** E-mail: Dominickmoreno92@gmail.com
** linkedin: www.linkedin.com/pub/dominick-moreno/65/2a6/841/
**
** General code info here
**
*/

#include <iostream>
#include "Path.h"
#include "PathLinkedList.h"
#include "TextUI.h"
#include "Node.h"
using namespace std;

int main(){
	int i;
	Node nodeA = Node(0);
	Node nodeB = Node(1);
	Node nodeC = Node(2);

	Path path1 = Path(nodeA, nodeB, 10);
	Path path2 = Path(nodeB, nodeC, 20);
	Path path3 = Path(nodeC, nodeA, 30);

	cout << "!!!Addresses of Paths!!!\n";
	cout << "\tAddress of path1: " << &path1 << endl;
	cout << "\tAddress of path2: " << &path2 << endl;
	cout << "\tAddress of path3: " << &path3 << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!\n";

	PathLinkedList myList = PathLinkedList();
	myList = myList + path1;
	myList = myList + path2;
	myList = myList + path3;
	//TextInterface::displayTextMenu(); //Call the interface

	cout << "path1 nextPointer is currently: " << path1.getNextPath() << endl;
	cout << "path1 lastPointer is currently: " << path1.getLastPath() << endl;

	cout << "Address of node A is: " << &nodeA << endl;
	cout << "Address of node B is: " << &nodeB << endl;
	cout << "Address of node C is: " << &nodeC << endl;

	cout << "The paths in myList are:" << endl;

	for (i = 0; i < myList.getNumPaths(); i++)
	{
		cout << "\tIndex : " << i << endl;
		cout << "\t\tNode A address: " << &myList.getPath(i).getA() << endl;
		cout << "\t\tNode B address: " << &myList.getPath(i).getB() << endl;
		cout << "\t\tNode A: " << myList.getPath(i).getA().getNodeNumber() << endl;
		cout << "\t\tNode B: " << myList.getPath(i).getB().getNodeNumber() << endl;
		cout << "\t\tWeight : " << myList.getPath(i).getWeight() << endl;
	}
	system("pause");
	return 0;
}