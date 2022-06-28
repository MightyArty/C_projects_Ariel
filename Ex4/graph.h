#ifndef GRAPH_
#define GRAPH_
#include <stdbool.h>

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int w;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    int w;
    int tag;
    int previous;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph_cmd(pnode *head, char *string);
void insert_node_cmd(pnode *head, char *string);
void delete_node_cmd(pnode *head ,char *string);
void deleteGraph_cmd(pnode* head,char *string);
void shortsPath_cmd(pnode *head);
pnode newNode(int node_num);
void TSP_cmd(pnode *head);
#endif