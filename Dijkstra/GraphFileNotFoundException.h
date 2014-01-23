/* GraphFileNotFoundException class header file
   
   Info about Exception class
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