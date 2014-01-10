/* Path class header file

   Simple class that represents a connection
   between two nodes. Has 3 fields - the two
   nodes that are connected by that path,
   and the weight/distance of that path
*/

#ifndef PATH_H
#define PATH_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class Path
{
friend class PathLinkedList;
private:
	Node nodeA; //First node connected by path
	Node nodeB; //Second node connected by path
	float weight; //Path weight/distance

protected:
	Path *lastPath;
	Path *nextPath;
	void setLastPath(Path&);
	void setNextPath(Path&);
public:
	Path(Node, Node, float); //Constructor, class is immutable
	~Path(); //Destructor - maybe not necessary?
	Node getA(); //Getter for nodeA
	Node getB(); //Getter for nodeB
	float getWeight(); //Getter for weightin constructor?
	Path *getLastPath(); //Getter for lastPath
	Path *getNextPath(); //Getter for nextPath

};

#endif PATH_H