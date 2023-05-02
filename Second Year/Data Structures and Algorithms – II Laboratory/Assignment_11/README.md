
# Assignment_11

## Problem Statement:-

Write a program to find all connected components of a Graph, on a map specified in a text 
file as Source, Destination, distance comma separated values. 

### Code_1 :- file.c


The `read_graph()` function reads a graph from a text file where each line represents an edge, with three comma-separated 
values: the source vertex index, the destination vertex index, and the distance. The function returns a dynamically allocated 
`Graph` structure that stores the graph as an array of `Node`s, each with an array of pointers to its `Edge`s. The `print_graph()` 
function is used to debug and verify the input graph.

The `dfs()` function performs a depth-first search of the graph starting from a given vertex, and marks all visited nodes with a 
`visited` flag in the `Graph` structure. It also assigns a component number to each visited node by storing it in the `component` 
array. The `main()` function iterates over all vertices of the graph and performs a DFS from each unvisited vertex. For each connected 
component found, it prints the component number and the list of vertices that belong to it.

Note that this implementation assumes that the input graph is undirected. If the graph is directed, the `dfs()` function needs to be 
modified accordingly. Also, this implementation assumes that the vertex indices in the input file are zero-based and consecutive. 
If the indices are not consecutive or have gaps, additional logic is needed to map them to a contiguous array index.


### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc file.c -o file



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./file graph.txt

    Component 0: 0 1 2

    Component 1: 3 4

    Component 2: 5 6 7 8

    Component 3: 9 10

    Component 4: 11 12 13 14




