
# Assignment_10

## Problem Statement:-

Implement DFS and BFS on a Graph.  

### Code_1 :- bfs.c

In this example, we create a Graph data structure using an adjacency list representation. We also create two helper functions 
createNode() and createGraph() to create nodes and graphs, respectively.

The addEdge() function is used to add an edge between two nodes in the graph.

The dfs() and bfs() functions implement the DFS and BFS algorithms, respectively. The DFS algorithm uses recursion to traverse 
the graph, while the BFS algorithm uses a queue to traverse the graph in a breadth-first manner.

In the main() function, we create a small example graph and call the DFS and BFS functions with the starting node of 2.


### Run the program.

    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc bfs.c -o bfs



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./bfs

    DFS: 2 3 0 1

    BFS: 2 3 0 1


