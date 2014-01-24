/* Implementation file for TextUI.h*/

#define LOWOPTION '1'
#define HIGHOPTION '4'

#include <iostream>
#include <string>
#include <fstream>
#include "TextUI.h"
#include "GraphCollection.h"

using namespace std;
//Function definitions

void TextInterface::displayTextMenu()
{
	/* Give a brief introduction and explanation. This is done
	   with a text file that's already been written. The 
	   program opens this, and displays it for the user.

	   
	*/
	bool graphSelectSuccess; //Used to indicate whether or not graph selection was successful
	string graphName; //Holds the name of the graph being worked with
	string optionSelection = ""; //Holds option selection
	string graphSelection; //Holds the user's choice of graph, could potentially be an int
	char optionSelectionAsChar = 0; //Holds the first char of the option selection

	regex findIsNumberRegex("^[0-9]+$"); //Used to determine if graphSelection is a number or a string

	TextInterface::readText("IntroductoryText.txt"); //Display introductory text

	GraphCollection allGraphs = *new GraphCollection(); //Instantiate the Graph Collection
	while (optionSelectionAsChar != HIGHOPTION)
	{
		TextInterface::readText("MenuInformationText.txt"); //Display menu options

		//Take in user selection
		cout << "Select Option: ";
		cin >> optionSelection;
		cout << "\n";

		//Make sure input is a digit and only 1 character
		if (!isdigit(optionSelection.c_str()[0]) || optionSelection.length() != 1)
		{
			optionSelectionAsChar = '5';
		}
		else
		{
			optionSelectionAsChar = optionSelection.c_str()[0];
		}

		//Process selection
		switch (optionSelectionAsChar)
		{
			case '1': //Load graph
				cout << "Enter graph name: "; //Prompt for name of GraphFile to be loaded
				cin >> graphName; //Take in user input
				graphName += ".txt"; //Add the filetype
				try
				{
					//Call the loadGraph method
					if (TextInterface::loadGraph(graphName, &allGraphs))
					{
						cout << "Graph Loaded Successfully.\n";
					}
					else
					{
						cout << "That Graph has already been loaded.\n";
					}
				}
				catch (exception& e)
				{
					//Display the exception
					cout << e.what();
				}
				break;
			case '2': //Choose a graph to interact with
				cout << "Enter graph name or number: ";
				cin >> graphSelection;
				cout << endl;

				if (regex_search(graphSelection, findIsNumberRegex))
				{
					//The entered input is a number
					graphSelectSuccess = TextInterface::selectGraph(allGraphs, stoi(graphSelection));
				}
				else
				{
					//The entered input is not a number
					graphSelectSuccess = TextInterface::selectGraph(allGraphs, graphSelection);
				}
				if (!graphSelectSuccess)
				{
					cout << "Invalid Graph Selection.\n";
				}
				break;
			case '3': //View all the loaded Graphs
				TextInterface::viewLoadedGraphs(&allGraphs);
				break;
			case '4': //Exit the program
				break;
			default: //Invalid Option selected
				cout << "\"" << optionSelection << "\" is an invalid selection.\n";
				break;
		}

		cout << "\n";
	}
	
}

bool TextInterface::readText(string fileToBeRead)
{
	/* Takes in a string, fileToBeRead, and tries to open
	   a file with that name. It then prints all of the
	   text in that file to the screen. 

	   Returns true if the file exists, false if it does
	   not. These return values are not always needed,
	   but possibly convenient.
	*/

	ifstream text(fileToBeRead); //IO stream object to be opened
	string line; //Iterating string object that holds a line

	if (text)
	{
		//File was found

		//Loop through every line in the file
		while (getline(text, line))
		{
			//Print out each line
			cout << line << '\n';
		}

		//Close the document
		text.close();

		cout << "\n";

		//return true because file was found
		return true;
	}

	//File was not found
	return false;
}

bool TextInterface::loadGraph(string graphName, GraphCollection *allGraphs)
{
	/* Uses the name stored in the string graphName
	   to open a graph file with that name. The data
	   in that graph file, if it exists and is correctly
	   formatted, will then be parsed and stored into
	   a Mab object. A correctly instantiated Graph
	   object means the graph is loaded.

	   Returns true if file is found, correctly parsed,
			and succesfully instantiated
		Returns false otherwise
	*/

	//Dummy filler text
	if (allGraphs->addGraph(*new Graph(graphName)))
	{
		//Graph was added correctly
		return true;
	}

	//Graph was added incorrectly
	return false;
}

bool TextInterface::selectGraph(GraphCollection &allGraphs, string graphName)
{
	/* User selects a graph. They can select it by its
	   name or number. If an invalid name or number is
	   entered, a message is displayed saying such, and
	   main menu is brought up. If a valid name or
	   number is entered, a new menu is brought up,
	   the Graph Options menu.

	   Returns true for valid graph selection
	   Returns false for invalid graph selection
	*/

	int i; //iteration counter
	Graph *currentGraph; /* First iterates through the
														   collection, then once found
														   (if it is at all) holds the
														   selected Graph
														*/
	
	//Iterate through the Graph until the correct Graph is found
	//If not found, return false
	for (i = 0; i < allGraphs.getNumOfGraphs(); i++)
	{
		//Grab the current iteration's Graph
		currentGraph = allGraphs.getGraphAtIndex(i);
		if (currentGraph->getGraphName() == graphName)
		{
			//If the graph is found, break the loop
			break;
		}
	}

	if (i == allGraphs.getNumOfGraphs())
	{
		/* If i reached the number of Graphs in the collection, the Graph
		   was not found. Return false.*/
		return false;
	}
	string optionSelection = ""; //Holds option selection
	char optionSelectionAsChar = 0; //Holds the first char of the option selection

	cout << "Graph Selected: " << currentGraph->getGraphName() << endl;
	cout << "Graph Options:\n\n";

	while (optionSelectionAsChar != HIGHOPTION)
	{
		TextInterface::readText("GraphOptionsText.txt"); //Display options

		//Take in user selection
		cout << "Select Option: ";
		cin >> optionSelection;
		cout << "\n";

		//Make sure input is a digit and only 1 character
		if (!isdigit(optionSelection.c_str()[0]) || optionSelection.length() != 1)
		{
			optionSelectionAsChar = '5';
		}
		else
		{
			optionSelectionAsChar = optionSelection.c_str()[0];
		}

		switch (optionSelectionAsChar)
		{
		case '1': //Find shortest path
			cout << "Finding shortest path\n";
			break;
		case '2': //Diagnostic Info
			cout << "Displaying diagnostic info:\n\n";

			cout << "\tGraph Name: " << currentGraph->getGraphName() << endl;
			cout << "\tNumber of Nodes: " << currentGraph->getNumOfNodes() << endl << endl;
			cout << "\tNode Connections:\n";
			for (int j = 0; j < currentGraph->getNumOfNodes(); j++)
			{
				cout << "\t\tNode " << j << " connections:\n";
				for (int k = 0; k < currentGraph->getNodeAtIndex(j)->getConnectingEdges().getNumEdges(); k++)
				{
					cout << "\t\t\tNode ";
					if (currentGraph->getNodeAtIndex(j)->getNodeNumber() ==
						currentGraph->getNodeAtIndex(j)->getConnectingEdges().getEdge(k)->getA().getNodeNumber())
					{
						//Node A is the same as node at this index
						//cout << "A";
						cout << currentGraph->getNodeAtIndex(j)->getConnectingEdges().getEdge(k)->getB().getNodeNumber();
					}
					else
					{
						//Node B is the same as the node at this index
						//cout << "B";
						cout << currentGraph->getNodeAtIndex(j)->getConnectingEdges().getEdge(k)->getA().getNodeNumber();
					}

					cout << " connects with weight: " << currentGraph->getNodeAtIndex(j)->
						getConnectingEdges().getEdge(k)->getWeight() << endl;
				}
				cout << endl;
			}


			break;
		case '3': //Delete Graph
			cout << "Deleting Graph\n";
			break;
		case '4': //Go back to Program Options
			cout << "Returning to program options\n";
			break;
		default: //Invalid input
			cout << "\"" << optionSelection << "\" is an invalid selection.\n";
			break;

		}
	}

	cout << endl;

	return true;
}

bool TextInterface::selectGraph(GraphCollection &allGraphs, int index)
{
	/* Same as selectGraph(string), but instead
	   chooses the Graph based on the viewLoadedGraphs
	   order (so not 0-based). This is done by finding
	   the correct graph, and then passing it to the
	   string parameter version
	*/
	if (allGraphs.getGraphAtIndex(index-1) != NULL)
	{
		//Make sure the index exists
		return selectGraph(allGraphs, allGraphs.getGraphAtIndex(index-1)->getGraphName());
	}

	return false;
}

bool TextInterface::viewLoadedGraphs(GraphCollection *allGraphs)
{
	/* Display all of the loaded (succesfully
	   instantiated) graphs with their associated graph
	   numbers

	   Returns true if there are any graphs
	   Returns false if there are no graphs
	*/
	if (!(allGraphs->getNumOfGraphs() > 0))
	{
		cout << "Number of graphs: " << allGraphs->getNumOfGraphs() << endl;
		return false;
	}

	cout << "The following Graphs are loaded:\n";
	for (int i = 0; i < allGraphs->getNumOfGraphs(); i++)
	{
		cout << (i+1) << ": " << allGraphs->getGraphAtIndex(i)->getGraphName() << "\t";
	}

	cout << endl;

	return true;
}