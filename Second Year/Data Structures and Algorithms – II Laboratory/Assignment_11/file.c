#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct node {
    int dest;
    int weight;
    bool visited;
    struct node* next;
};

struct graph {
    struct node* nodes[MAX_NODES];
    bool* visited;
    int size;
};

struct graph* create_graph() {
    struct graph* graph = malloc(sizeof(struct graph));
    graph->visited = calloc(MAX_NODES, sizeof(bool));
    graph->size = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->nodes[i] = NULL;
    }
    return graph;
}

void add_edge(struct graph* graph, int src, int dest, int weight) {
    struct node* node = malloc(sizeof(struct node));
    node->dest = dest;
    node->weight = weight;
    node->visited = false;
    node->next = graph->nodes[src];
    graph->nodes[src] = node;
}

void dfs(struct graph* graph, int vertex, int* component) {
    graph->visited[vertex] = true;
    component[vertex] = graph->size;
    struct node* node = graph->nodes[vertex];
    while (node != NULL) {
        int dest = node->dest;
        if (!graph->visited[dest]) {
            dfs(graph, dest, component);
        }
        node = node->next;
    }
}

void find_components(struct graph* graph) {
    int component[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        component[i] = -1;
    }
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph->nodes[i] != NULL && !graph->visited[i]) {
            dfs(graph, i, component);
            graph->size++;
        }
    }
    for (int i = 0; i < graph->size; i++) {
        printf("Component %d: ", i);
        for (int j = 0; j < MAX_NODES; j++) {
            if (component[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    char* input_file = argv[1];
    FILE* file = fopen(input_file, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", input_file);
        return 1;
    }
    struct graph* graph = create_graph();
    int src, dest, weight;
    while (fscanf(file, "%d, %d, %d", &src, &dest, &weight) == 3) {
        add_edge(graph, src, dest, weight);
        add_edge(graph, dest, src, weight);
    }
    fclose(file);
    find_components(graph);
    return 0;
}
