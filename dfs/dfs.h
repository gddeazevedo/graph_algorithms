#ifndef __dfs_h
#define __dfs_h

#include "../graph/graph.h"
#include <stdio.h>


static int time;

void depth_first_search(Graph *g);
void dfs_visit(Graph *g, int u, int *d, int *f, int *pi, enum Color *colors);


#endif
