
# Assignment_9

## Problem Statement:-

 Write a program to read a map stored in a text file with (city1, city2, distance) comma separated values. Build a graph using 
 this data. Print all pairs shortest paths information between all pairs of cities. 
 

### Code_1 :- floyd.c

Here's the C program that reads a map stored in a text file and builds a graph from it. It then uses the Floyd Warshall algorithm 
to find the shortest paths between all pairs of cities and prints out the information.

This program should properly declare the city array and fix the errors. Again, please note that this program assumes that there are
at most 100 cities in the map, and that the names of the cities are at most 20 characters long. If your requirements differ, you can 
adjust the MAXCITIES and MAXLEN constants accordingly.


The output of the program will depend on the contents of the input file map.txt, which should contain a list of comma-separated values
in the following format: city1, city2, distance.


### Run the program.


    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ gcc floyd.c -o floyd



    VSK@DESKTOP-8LMS4JT MINGW64 ~

    $ ./floyd

    Shortest paths between all pairs of cities:

    NewYork, - Boston,: 215

    NewYork, - Washington,: 611

    NewYork, - Chicago,: 787

    NewYork, - LosAngeles,: 2802

    NewYork, - Miami,: 1534

    Boston, - Washington,: 396

    Boston, - Chicago,: 1002

    Boston, - LosAngeles,: 3017

    Boston, - Miami,: 1319

    Washington, - Chicago,: 1398

    Washington, - LosAngeles,: 3413

    Washington, - Miami,: 923

    Chicago, - LosAngeles,: 2015

    Chicago, - Miami,: 2321

    LosAngeles, - Miami,: 4336




