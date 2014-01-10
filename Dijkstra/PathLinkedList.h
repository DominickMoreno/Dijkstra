//info

#ifndef PATHLINKEDLIST_H
#define PATHLINKEDLIST_H

#include "Node.h"
#include "Path.h"
#include <iostream>
#include <string>
using namespace std;

class PathLinkedList
{
private:
	Path *headPointer;
	Path *tailPointer;
	int numOfPaths;
	void append(Path&);
public:
	PathLinkedList();
	int getNumPaths();
	Path getPath(int);
	PathLinkedList operator+(Path&);
};

#endif PATHLINKEDLIST_H