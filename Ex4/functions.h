#include <stdbool.h>
#include "graph.h"

pnode idFinder (pnode * head, int node_id);
void createEdge (pnode src, pnode dest, int w);
void put_in_the_end (int value, pnode * head);
void insert (node ** head, int id, int w);
int dijkstra (pnode src, pnode dest, pnode * src_pointer);
void reset (pnode * head);
bool update (pnode src, pnode dest, int w);
void remove_edges_out (pnode * head, pnode node);
void remove_edges_in (pnode * head, pnode node);
node *tempNode (int id, int w);