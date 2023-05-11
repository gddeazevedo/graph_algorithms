#ifndef __graph_h
#define __graph_h

#include <stdlib.h>
#include <stdio.h>

typedef struct __node {
    int data;
    struct __node* next;
} Node;

typedef struct __graph {
    int total_nodes;
    Node** adj_list;
} Graph;

Graph* newGraph(int total_nodes);
Node* newNode(int data);
void add_node(Graph* g);
void add_edge(Graph* g, int n, int m);
void remove_node(Graph* g, int n);
void remove_edge(Graph* g, int n, int m);
void remove_helper(Graph* g, int n, int m);
void print_graph(Graph* g);

#endif
