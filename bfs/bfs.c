#include "bfs.h"

void bfs(Graph *g, int init_node) {
    int parents[g->nodes];
    int distances[g->nodes];
    enum Color colors[g->nodes];
    Queue *q = newQueue();

    for (int i = 0; i < g->nodes; i++) {
        if (i != init_node) {
            parents[i] = NIL;
            distances[i] = INT_MAX;
            colors[i] = White;
        }
    }

    colors[init_node] = Grey;
    distances[init_node] = 0;
    parents[init_node] = NIL;
    enqueue(q, init_node);

    while (!is_empty(q)) {
        print_arrays(q, distances, parents, colors, g->nodes);
        int u = dequeue(q);

        for (Node *node = g->adj_list[u]; node != NULL; node = node->next) {
            int v = node->data;

            if (colors[v] == White) {
                colors[v] = Grey;
                distances[v] = distances[u] + 1;
                parents[v] = u;
                enqueue(q, v);
            }
        }

        colors[u] = Black;
    }

    print_arrays(q, distances, parents, colors, g->nodes);
}

void print_int_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == -1) {
            printf("NIL ");
            continue;
        }
        printf("%d ", array[i]);
    }

    printf("\n");
}

void print_colors_array(enum Color *colors, int size){
    for (int i = 0; i < size; i++) {
        printf("%c ", colors[i]);
    }

    printf("\n");
}

void print_arrays(Queue* q, int* d, int* pi, enum Color *colors, int size) {
    printf("\n--------\n");

    printf("Nodes:     ");
    for (int i = 0; i < size; i++) {
        printf("%d ", i);
    }

    printf("\nParents: ");
    print_int_array(pi, size);

    printf("Distances: ");
    print_int_array(d, size);

    printf("Colors:    ");
    print_colors_array(colors, size);

    printf("Queue: ");
    print_queue(q);
}
