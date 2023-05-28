#include "dfs.h"


void depth_first_search(Graph *g) {
    int d[g->nodes];
    int f[g->nodes];
    int pi[g->nodes];
    enum Color colors[g->nodes];

    for (int u = 0; u < g->nodes; u++) {
        colors[u] = White;
        pi[u] = NIL;
    }

    time = 0;

    for (int u = 0; u < g->nodes; u++) {
        if (colors[u] == White)
            dfs_visit(g, u, d, f, pi, colors);
    }


    for (int i = 0; i < g->nodes; i++) {
        printf("d[%d] = %d\n", i, d[i]);
    }

    for (int i = 0; i < g->nodes; i++) {
        printf("f[%d] = %d\n", i, f[i]);
    }
}

void dfs_visit(Graph *g, int u, int *d, int *f, int *pi, enum Color *colors) {
    time += 1;
    d[u] = time;
    colors[u] = Grey;

    for (Node *node = g->adj_list[u]; node != NULL; node = node->next) {
        int v = node->data;

        if (colors[v] == White) {
            pi[v] = u;
            dfs_visit(g, v, d, f, pi, colors);
        }
    }

    time += 1;
    f[u] = time;
    colors[u] = Black;
}
