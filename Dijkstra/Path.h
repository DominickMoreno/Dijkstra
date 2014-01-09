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
private:
	Node nodeA; //First node connected by path
	Node nodeB; //Second node connected by path
	Path *lastPath;
	Path *nextPath;
	float weight; //Path weight/distance
public:
	Path(Node, Node, float); //Constructor, class is immutable
	~Path(); //Destructor - maybe not necessary?
	Node getA(); //Getter for nodeA
	Node getB(); //Getter for nodeB
	float getWeight(); //Getter for weight
	void setLastNextPath(Path, Path); /* Setter for the Path pointers.
										   These are used for the linked
										   list in which the path will be
										   stored.

										   TODO: Possibly make this private and
										   use in constructor?
										*/
	Path* getLastPath(); //Getter for lastPath
	Path* getNextPath(); //Getter for nextPath

};

#endif PATH_H