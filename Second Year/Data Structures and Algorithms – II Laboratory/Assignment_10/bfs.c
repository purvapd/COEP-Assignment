#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int data;
    int visited;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* head[MAX_NODES];
    int numNodes;
} Graph;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->visited = 0;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numNodes) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        graph->head[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

void dfs(Graph* graph, int node) {
    graph->head[node]->visited = 1;
    printf("%d ", node);
    Node* adj = graph->head[node];
    while (adj != NULL) {
        if (!graph->head[adj->data]->visited) {
            dfs(graph, adj->data);
        }
        adj = adj->next;
    }
}

void bfs(Graph* graph, int start) {
    int queue[MAX_NODES], front = 0, rear = 0;
    queue[rear++] = start;
    graph->head[start]->visited = 1;
    printf("%d ", start);
    while (front < rear) {
        int curr = queue[front++];
        Node* adj = graph->head[curr];
        while (adj != NULL) {
            int next = adj->data;
            if (!graph->head[next]->visited) {
                graph->head[next]->visited = 1;
                printf("%d ", next);
                queue[rear++] = next;
            }
            adj = adj->next;
        }
    }
}

int main() {
    int numNodes = 6;
    Graph* graph = createGraph(numNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("DFS: ");
    dfs(graph, 2);
    printf("\n");

    // Reset visited flags
    for (int i = 0; i < numNodes; i++) {
        if (graph->head[i] != NULL) {
            graph->head[i]->visited = 0;
        }
    }

    printf("BFS: ");
    bfs(graph, 2);
    printf("\n");

    return 0;
}
