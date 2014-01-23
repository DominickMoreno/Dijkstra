/* Implementation file for TextUI.h*/

#define LOWOPTION 1
#define HIGHOPTION 4

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
	string graphName; //Holds the name of the map being worked with
	short optionSelection = 0; //Holds option selection

	TextInterface::readText("IntroductoryText.txt"); //Display introductory text
	TextInterface::readText("New Text Document.txt");

	while (optionSelection != HIGHOPTION)
	{
		GraphCollection allGraphs = *new GraphCollection();
		TextInterface::readText("MenuInformationText.txt"); //Display menu options

		//Take in user selection
		cout << "Select Option: ";
		cin >> optionSelection;
		cout << "\n";

		//Process selection
		switch (optionSelection)
		{
			case 1:
			{
				cout << "Enter map name: "; //Prompt for name of GraphFile to be loaded
				cin >> graphName; //Take in user input
				graphName += ".txt"; //Add the filetype
				try
				{
					
					if (TextInterface::loadMap(graphName, &allGraphs))
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
					cout << e.what();
				}
				break;
			}
			case 2:
			{
				TextInterface::selectMap("Dumb text");
				break;
			}
			case 3:
			{
				TextInterface::viewLoadedMaps(&allGraphs);
				break;
			}
			case 4: //do nothing
				break;
			case 5:
			{
				cout << optionSelection << " Is an invalid choice. Please select a valid option.\n";
				break;
			}
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

bool TextInterface::loadMap(string mapName, GraphCollection *allGraphs)
{
	/* Uses the name stored in the string mapName
	   to open a map file with that name. The data
	   in that map file, if it exists and is correctly
	   formatted, will then be parsed and stored into
	   a Mab object. A correctly instantiated Map
	   object means the map is loaded.

	   Returns true if file is found, correctly parsed,
			and succesfully instantiated
		Returns false otherwise
	*/

	//Dummy filler text
	if (allGraphs->addGraph(*new Graph(mapName)))
	{
		//Graph was added correctly
		return true;
	}

	//Graph was added incorrectly
	return false;
}

bool TextInterface::selectMap(string mapName)
{
	/* User selects a map. They can select it by its
	   name or number. If an invalid name or number is
	   entered, a message is displayed saying such, and
	   main menu is brought up. If a valid name or
	   number is entered, a new menu is brought up,
	   the Map Options menu.

	   Returns true for valid map selection
	   Returns false for invalid map selection
	*/

	//Dummy filler text
	cout << "Select Map Function called.\n";
	return true;
}

bool TextInterface::viewLoadedMaps(GraphCollection *allGraphs)
{
	/* Display all of the loaded (succesfully
	   instantiated) maps with their associated map
	   numbers

	   Returns true if there are any maps
	   Returns false if there are no maps
	*/
	if (!(allGraphs->getNumOfGraphs() > 0))
	{
		cout << "Number of graphs: " << allGraphs->getNumOfGraphs() << endl;
		return false;
	}

	cout << "The following Graphs are loaded:\n";
	for (int i = 0; i < allGraphs->getNumOfGraphs(); i++)
	{
		cout << allGraphs->getGraphAtIndex(i)->getGraphName() << "\t";
	}

	return true;
}