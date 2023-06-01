#include "./graph/graph.h"
#include "./bfs/bfs.h"
#include "./dfs/dfs.h"

void main() {
    int nodes, edges;
    int node1, node2, weight;
    scanf("%d %d", &nodes, &edges);

    Graph *g = newGraph(nodes);
    int w[nodes][nodes];

    for (int i = 1; i <= edges; i++) {
        scanf("%d %d %d", &node1, &node2, &weight);
        add_edge(g, node1, node2);
        w[node1][node2] = weight;
        w[node2][node1] = weight;
    }

    print_graph(g);
}
