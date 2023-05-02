#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct edge {
    int dest;
    int weight;
    struct edge* next;
} edge_t;

typedef struct graph {
    int num_vertices;
    edge_t** adj_list;
} graph_t;

graph_t* create_graph(int num_vertices) {
    graph_t* g = (graph_t*) malloc(sizeof(graph_t));
    g->num_vertices = num_vertices;
    g->adj_list = (edge_t**) malloc(num_vertices * sizeof(edge_t*));

    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = NULL;
    }

    return g;
}

void add_edge(graph_t* g, int src, int dest, int weight) {
    edge_t* new_edge = (edge_t*) malloc(sizeof(edge_t));
    new_edge->dest = dest;
    new_edge->weight = weight;
    new_edge->next = g->adj_list[src];
    g->adj_list[src] = new_edge;
}

void print_graph(graph_t* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d:", i);

        edge_t* curr_edge = g->adj_list[i];
        while (curr_edge) {
            printf(" (%d, %d)", curr_edge->dest, curr_edge->weight);
            curr_edge = curr_edge->next;
        }

        printf("\n");
    }
}

typedef struct heap {
    int size;
    int* vertices;
    int* distance;
} heap_t;

heap_t* create_heap(int max_size) {
    heap_t* h = (heap_t*) malloc(sizeof(heap_t));
    h->size = 0;
    h->vertices = (int*) malloc(max_size * sizeof(int));
    h->distance = (int*) malloc(max_size * sizeof(int));
    return h;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap_t* h, int i) {
    int smallest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < h->size && h->distance[left_child] < h->distance[smallest]) {
        smallest = left_child;
    }

    if (right_child < h->size && h->distance[right_child] < h->distance[smallest]) {
        smallest = right_child;
    }

    if (smallest != i) {
        swap(&h->vertices[i], &h->vertices[smallest]);
        swap(&h->distance[i], &h->distance[smallest]);
        heapify(h, smallest);
    }
}

int pop_min(heap_t* h) {
    int min_vertex = h->vertices[0];
    h->vertices[0] = h->vertices[h->size - 1];
    h->distance[0] = h->distance[h->size - 1];
    h->size--;
    heapify(h, 0);
    return min_vertex;
}

void dijkstra(graph_t* g, int start_vertex, int* distances) {
    int max_distance = INT_MAX / 2; // prevent integer overflow
    heap_t* h = create_heap(g->num_vertices);
    for (int i = 0; i < g->num_vertices; i++) {
        distances[i] = max_distance;
        h->vertices[i] = i;
        h->distance[i] = max_distance;
    }

    distances[start_vertex] = 0;
    h->distance[start_vertex] = 0;
    h->size = g->num_vertices;

    while (h->size > 0) {
        int curr_vertex = pop_min(h);

        edge_t* curr_edge = g->adj_list[curr_vertex];
        while (curr_edge) {
            int dest_vertex = curr_edge->dest;
            int new_distance = distances[curr_vertex] + curr_edge->weight;
            if (new_distance < distances[dest_vertex]) {
                distances[dest_vertex] = new_distance;
                h->distance[dest_vertex] = new_distance;
            }
            curr_edge = curr_edge->next;
        }

        heapify(h, 0);
    }

    free(h->vertices);
    free(h->distance);
    free(h);
}

int main() {
    graph_t* g = create_graph(5);
    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 3, 5);
    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 3, 3);
    add_edge(g, 2, 4, 4);
    add_edge(g, 3, 2, 9);
    add_edge(g, 3, 4, 2);
    add_edge(g, 4, 0, 7);
    printf("Adjacency List:\n");
    print_graph(g);

    int distances[5];
    dijkstra(g, 0, distances);

    printf("Shortest Distances from Vertex 0:\n");
    for (int i = 0; i < 5; i++) {
        printf("Vertex %d: %d\n", i, distances[i]);
    }

    return 0;
}