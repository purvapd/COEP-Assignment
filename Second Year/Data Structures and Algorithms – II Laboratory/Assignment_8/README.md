
# Assignment_8

## Problem Statement:-

Write a graph implementation, using adjacency lists and demonstrate Djkstra‟s algorithm on it. 

### Code_1 :- dijkstra.c

The code is an implementation of Dijkstra's algorithm in C for finding the shortest path in a weighted graph using adjacency lists.
The program reads in a graph with weights assigned to the edges and then calculates the shortest distance to each vertex from a specified 
starting vertex using Dijkstra's algorithm. The output displays the adjacency list of the input graph and the shortest distances to all 
vertices from the specified starting vertex. The program uses a heap data structure to efficiently select the next vertex to visit during the algorithm.

### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc dijkstra.c -o dijkstra



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./dijkstra

    Adjacency List:

    Vertex 0: (3, 5) (1, 10)

    Vertex 1: (3, 3) (2, 1)

    Vertex 2: (4, 4)

    Vertex 3: (4, 2) (2, 9)

    Vertex 4: (0, 7)

    Shortest Distances from Vertex 0:

    Vertex 0: 0

    Vertex 1: 10

    Vertex 2: 11

    Vertex 3: 5

    Vertex 4: 7


