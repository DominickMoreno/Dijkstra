Personal Information:

	Author: Dominick Moreno
	
	Project: Dijkstra
	
	E-mail: Dominickmoreno92@gmail.com
	
	linkedin: www.linkedin.com/pub/dominick-moreno/65/2a6/841/

Special Notes: this project was worked on during Winter 2013-2014. A "*" indicates a design constraint that may be altered or removed at a later point.


The goal of this project is to find the shortest path between two points on a generic, discrete map. Maps will be defined as text files in a subfolder named "maps". There can be multiple maps in this folder.The program will not require the name of the maps to be entered, but will instead look through all files in this folder, and determine whether or not a given file in /maps/ is actually a graph*. A file of type ".gph" will be considered a graph, and will contain text that defines a graph. Also in this folder will be the two points between which a path is to be found.
	
	
Consider the graph "ExampleGraph.jpg" in the root folder of the Dijkstra project. Its .gph file would be defined as so, assuming the program calls for the shortest path between points A and E:

	1,1 3,1
	
	0,1 2,5
	
	1,5 4,7
	
	0,1 4,1
	
	2,7 3,1
	
	1-4

This file is 6 lines long - the first 5 lines for the 5 nodes in the graph, the last to determine the point between which the path is to be found. This will always be the case. For a graph with n nodes, the corresponding .gph file will have n+1 lines.


On each line is a pair of numbers, seperated by a coma. Each number pair represents a connection to a node and that connection's path weight. In the example .gph file, the 0th line represents connections to node 0 (node A in the graph). Because it has two number pairs, this means node 0 has connects to 2 other nodes, nodes 1 and 3 (B and D). The order does not matter, so long as it's consistent. From the first number pair we see that node 0 connects to node 1 with a path weight of 1, and also with node 3 with weight 1 as well. We then move on to line 1. It tells us that node 1 (from the line number) connects to node 0 with a path weight of 1, as well as to node 2 with weight 5. 


		Number pair order does not matter, nor does node order. If I wanted to use node D as node 0 and write
	it first, I could do that - as long as I was consistent. Also note that there is redundancy. Line 0 indicates
	that node 0 connects to node 1; likewise line 1 indicates that node 1 connects to node 0. This is acceptable
	to myself since the goal is not to write an elegantly designed graph, but to implement Dijkstra's.
		The final line of this example .gph indicates the starting and end points of the path. Intuitively
	we can see the shortest path will be B-A-D-E, and the output will report this accordingly. 
		The exact output format is not yet determined.

Specific Technical/Implementation Notes:
		I have attempted this project two times previously, but never to completion. The first time was in my first
	C programming course, and was done for one specific map that was built into the program. It asked for the two points
	between which a path was to be found at the prompt. I managed to get it to attempt to find a path - not always 
	succesfully, and certainly not always the shortest. The second time was again in C, but much more general. This 
	version of the program took in an input similar to the one for this program as input, and attempted to do the
	same as the current iteration - that is, find the shortest path for a general map. Input was stored in a file on a
	linux system, and was fed into the program using a simple BASH script. Output was stored in a text file, and
	compared to what the expected output should be. It had more restrictions than this current version - due to 
	lazy parsing methods, each number pair could only contain one digit. Also, it required more input (eg the number of
	nodes in the map). Again this version was usually able to find a path, and not always the shortest.
		Version 3 of this program is done in C++ to practice Object Oriented Programming. I haven't done any
	relatively large projects, and this is one I've always wanted to finish. In C I used very large and unwieldy structs,
	and it would have been nice to have access to class constructs.
		The recursive method to finding the shortest path is what I've always had problems with. However, I think
	this time around I can master it - after studying binary search trees in one of my computer science class, I toyed
	with the idea of how I could do this, and I think I can do it now. If I implement the search as a tree, which in
	object oriented programming is much easier to manage than in a purely procedural language, I can handle this much
	better than in the past.
















		