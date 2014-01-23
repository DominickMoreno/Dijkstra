/* Text Interface Header file

		This is what lets the user interact with the
	Dijkstra program. This class is menu driven. 
	Future versions may have a GUI instead.

		It's fairly simple, but that's on purpose.
	The goal is going to be to have this class do
	as little work as possible, as I'd like to 
	eventually make this program with a proper
	GUI.
*/

#ifndef TEXTUI_H
#define TEXTUI_H
 
#include <iostream>
#include <string>

#include "Graph.h"
#include "GraphCollection.h"

using namespace std;

class TextInterface
{
private:
	/* Helper function used to conveniently output
	   text in a written file.

	   Returns true if text is found
	   Returns false if text is not found
	*/
	bool static readText(string);

	/* Loads a map into the program. It takes a 
	   text file of the input name, parses its
	   data, and creates a Map object with it.

	   Returns true if succesful
	   Returns false if unsuccesful
	*/
	bool static loadMap(string, GraphCollection*);

	/* Asks user to select a (loaded) map. They will then
	   be brought to a new menu where they can decide
	   what they will do with the map (eg find shortest
	   edge, delete, view nodes)

	   Throws an error if file could not be found
	*/
	bool static selectMap(string);

	/* Lists all maps that have been loaded to the
	   program.

	   Returns true if there is one map or more
	   Returns false if there are no maps
	*/
	bool static viewLoadedMaps(GraphCollection*);

public:
	void static displayTextMenu(); //Text interface for Graph/Path classes
};

#endif