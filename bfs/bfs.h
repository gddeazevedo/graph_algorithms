#ifndef __bfs_h
#define __bfs_h


#include "../queue/queue.h"
#include "../graph/graph.h"
#include <limits.h>

#define NIL -1
#define WHITE 'w'
#define GREY 'g'
#define BLACK 'b'

void bfs(Graph* g, int init_node);
void print_int_array(int* array, int size);
void print_char_array(char* array, int size);
void print_arrays(Queue* q, int* d, int* pi, char* colors, int size);

#endif
