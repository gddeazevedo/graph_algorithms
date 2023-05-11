#include "./graph/graph.h"
#include "./bfs/bfs.h"



void dfs(Graph* g, int init_node);

void main() {
    Graph* g = newGraph(6);

    // add_edge(g, 0, 1);

    // add_edge(g, 1, 0);
    // add_edge(g, 1, 4);
    // add_edge(g, 1, 2);

    // add_edge(g, 2, 3);

    // add_edge(g, 3, 0);
    // add_edge(g, 3, 4);

    // add_edge(g, 4, 1);


    add_edge(g, 0, 1);
    add_edge(g, 1, 0);

    add_edge(g, 0, 3);
    add_edge(g, 3, 0);

    add_edge(g, 1, 2);
    add_edge(g, 2, 1);

    add_edge(g, 3, 4);
    add_edge(g, 4, 3);

    add_edge(g, 3, 5);
    add_edge(g, 5, 3);

    add_edge(g, 4, 5);
    add_edge(g, 5, 4);

    print_graph(g);

    bfs(g, 0);
}

