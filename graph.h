#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);
pnode create_graph(int size);
pnode create_node(int id, pnode next);
pedge create_edge(int w, pnode dest, pedge next);
pnode getNode(int id, pnode head);
void delete_out_edges(pnode n);
void delete_to_edges(int id, pnode n);
int dijkstra(pnode head, int src, int dest);
int getindex(pnode head, int id);
int find_closest_to_node(int size, int visited[], int distance[]);
void TSP(pnode head, int cities[], int src, int dest, int* min_weight, int size);
void swap(int *x, int *y);


#endif
