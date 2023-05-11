#include "bfs.h"

void bfs(Graph* g, int init_node) {
    int d[g->total_nodes]; // distance from init_node
    int pi[g->total_nodes]; // parantes of each node
    unsigned char colors[g->total_nodes]; // colors to keep track of seeing nodes
    Queue* q = newQueue();

    for (int i = 0; i < g->total_nodes; i++) {
        if (i != init_node) {
            d[i] = INT_MAX;
            pi[i] = NIL;
            colors[i] = WHITE;
        }
    }

    d[init_node] = 0;
    colors[init_node] = GREY;
    pi[init_node] = NIL;

    enqueue(q, init_node);

    while (!is_empty(q)) {
        print_arrays(q, d, pi, colors, g->total_nodes);

        int u = dequeue(q);

        for (Node* node = g->adj_list[u]; node != NULL; node = node->next) {
            int v = node->data;
            if (colors[v] == WHITE) {
                colors[v] = GREY;
                d[v] = d[u] + 1;
                pi[v] = u;
                enqueue(q, v);
            }
        }

        colors[u] = BLACK;
    }

    print_arrays(q, d, pi, colors, g->total_nodes);
}

void print_int_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void print_char_array(char* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", array[i]);
    }

    printf("\n");
}

void print_arrays(Queue* q, int* d, int* pi, char* colors, int size) {
    printf("\n--------\n");
    printf("Distances: ");
    print_int_array(d, size);

    printf("Parents: ");
    print_int_array(pi, size);

    printf("Colors: ");
    print_char_array(colors, size);

    printf("Queue: ");
    print_queue(q);
}
