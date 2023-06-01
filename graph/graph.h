#ifndef __graph_h
#define __graph_h

#include <stdlib.h>
#include <stdio.h>

#define NIL -1

enum Color {
    Black = 'b', Grey = 'g', White = 'w'
};

typedef struct __node {
    int data;
    struct __node* next;
} Node;

typedef struct __graph {
    int nodes;
    Node** adj_list;
} Graph;

Graph* newGraph(int nodes);
Node* newNode(int data);
void add_node(Graph* g);
void d_add_edge(Graph *g, int n, int m);
void add_edge(Graph* g, int n, int m);
void remove_node(Graph* g, int n);
void remove_edge(Graph* g, int n, int m);
void remove_helper(Graph* g, int n, int m);
void print_graph(Graph* g);

#endif
