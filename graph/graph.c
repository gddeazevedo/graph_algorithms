#include "graph.h"

Graph* newGraph(int nodes) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->nodes = nodes;
    g->adj_list = (Node**) malloc(nodes * sizeof(Node*));

    for (int node = 0; node < nodes; node++) {
        g->adj_list[node] = NULL;
    }

    return g;
}

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(Graph* g) {
    g->nodes += 1;
    g->adj_list = realloc(g->adj_list, sizeof(Node*) * g->nodes);
    g->adj_list[g->nodes - 1] = NULL;
}

void d_add_edge(Graph* g, int n, int m) {
    if (n >= g->nodes || m >= g->nodes) return;

    Node* new_node = newNode(m);
    new_node->next = g->adj_list[n];
    g->adj_list[n] = new_node;
}

void add_edge(Graph* g, int n, int m) {
    d_add_edge(g, n, m);
    d_add_edge(g, m, n);
}

void remove_node(Graph* g, int n) {
    Node* node = g->adj_list[n];
    Node* aux = node;

    while (aux != NULL) {
        node = aux;
        aux = aux->next;
        if (node->data != n)
          remove_helper(g, node->data, n);
        free(node);
    }

    g->adj_list[n] = NULL;
}

void remove_helper(Graph* g, int n, int m) {
    // Removes the node m with an edge with node n

    Node* node = g->adj_list[n];
    Node* aux = node;

    while (aux != NULL && aux->data != m) {
      node = aux;
      aux = aux->next;
    }

    if (aux == NULL) return;

    if (node == aux) {
      node = node->next;
      aux->next = NULL;
      free(aux);
      g->adj_list[n] = node;
      return;
    }

    node->next = aux->next;
    aux->next = NULL;
    free(aux);
    aux = NULL;
}

void remove_edge(Graph* g, int n, int m) {
  remove_helper(g, n, m);
  remove_helper(g, m, n);
}

void print_graph(Graph* g) {
    for (int node = 0; node < g->nodes; node++) {
        Node* current = g->adj_list[node];

        printf("[%d] -> ", node);

        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }

        printf("//\n");
    }
}
