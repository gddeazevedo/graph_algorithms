#ifndef __bfs_h
#define __bfs_h


#include "../queue/queue.h"
#include "../graph/graph.h"
#include <limits.h>

void bfs(Graph* g, int init_node);
void print_int_array(int* array, int size);
void print_colors_array(enum Color *colors, int size);
void print_arrays(Queue* q, int* d, int* pi, enum Color *colors, int size);

#endif
