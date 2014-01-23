/* GraphFileNotFoundException class header file
   
   Used by the Graph class. Thrown when its constructor
   is passed a filename it can't find. Inherits from
   std::exception, overloads the char* what() method
*/

#ifndef GRAPHFILENOTFOUNDEXCEPTION_H
#define GRAPHFILENOTFOUNDEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

//using namespace std;

class GraphFileNotFoundException: public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "\nFile not Found.\n";
	}
} /*myFoo*/;

#endif GRAPHFILENOTFOUNDEXCEPTION_H