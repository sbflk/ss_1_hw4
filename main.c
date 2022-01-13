#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);
pnode create_graph(int size);




int main()
{
    char cmd;
    pnode head = NULL;
    int out = 0;
    out = scanf("%c",&cmd);
    while(out != EOF)
    {
        if(cmd == 'A')
        {
            deleteGraph_cmd(&head);
            int size;
            scanf("%d", &size);
            head = create_graph(size);
        }
        if(cmd == 'n')
        {
            build_graph_cmd(&head);
        }
        if(cmd == 'B')
        {
            insert_node_cmd(&head);
        }
        if(cmd == 'T')
        {
            TSP_cmd(head);
        }
        if(cmd == 'S')
        {
            shortsPath_cmd(head);
        }
        if(cmd == 'D')
        {
            delete_node_cmd(&head);
        }
        out = scanf("%c", &cmd);
    }
    deleteGraph_cmd(&head);
    return 0;
}
