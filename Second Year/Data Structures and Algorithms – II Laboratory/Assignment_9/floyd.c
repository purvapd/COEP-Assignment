#include <stdio.h>
#include <limits.h>
#include <string.h>

#define INF INT_MAX
#define MAXCITIES 100
#define MAXLEN 20

int dist[MAXCITIES][MAXCITIES];
char city[MAXCITIES][MAXLEN];

int main() {
    int i, j, k;
    int numCities = 0;
    char city1[MAXLEN], city2[MAXLEN];
    int distance;
    FILE *fp;

    // Initialize distances to infinity
    for (i = 0; i < MAXCITIES; i++) {
        for (j = 0; j < MAXCITIES; j++) {
            dist[i][j] = INF;
        }
    }

    // Open the file for reading
    fp = fopen("map.txt", "r");

    // Read the file and build the graph
    while (fscanf(fp, "%s %s %d", city1, city2, &distance) != EOF) {
        // Add the cities to the map if they haven't been added yet
        for (i = 0; i < numCities; i++) {
            if (strcmp(city1, city[i]) == 0) break;
        }
        if (i == numCities) {
            strcpy(city[numCities], city1);
            numCities++;
        }
        for (j = 0; j < numCities; j++) {
            if (strcmp(city2, city[j]) == 0) break;
        }
        if (j == numCities) {
            strcpy(city[numCities], city2);
            numCities++;
        }

        // Add the edge to the graph
        dist[i][j] = distance;
        dist[j][i] = distance;
    }

    // Floyd Warshall algorithm to find shortest paths
    for (k = 0; k < numCities; k++) {
        for (i = 0; i < numCities; i++) {
            for (j = 0; j < numCities; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest paths
    printf("Shortest paths between all pairs of cities:\n");
    for (i = 0; i < numCities; i++) {
        for (j = i + 1; j < numCities; j++) {
            printf("%s - %s: %d\n", city[i], city[j], dist[i][j]);
        }
    }

    return 0;
}
