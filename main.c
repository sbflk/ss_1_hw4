#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "algo.h"


int main()
{
    char cmd;

    scanf(" %c",&cmd);

    while(cmd != 'D')
    {
        if(cmd == 'A')
        {
            if(arr_edges != NULL)
            {
                free(arr_edges);
               free(arr_nodes);
            }
            int n;
            scanf(" %d", &n);
            int edges_size = n*(n-1)*2+(n-1);
            int *arr_nodes=(int*)malloc(sizeof(int)*n);
            int *arr_edges=(int*)malloc(sizeof(int)*edges_size);
            scanf(" %c", &cmd);
            int index = 0;
            int node_index = 0;
            int last_was_n = 0;
            while(cmd != 'B' && cmd != 'D' && cmd != 'S' && cmd != 'T')
            {
                if(cmd == 'n')
                {
                    
                    arr_edges[index] = -1;
                    last_was_n = 1;
                }
                else
                {
                    int num = cmd - '0';
                    arr_edges[index] = num;
                    if(last_was_n == 1)
                    {
                        printf("HERE");
                        printf("\n");
                        arr_nodes[node_index] = num;
                        node_index++;
                        last_was_n = 0;
                    }
                }
                index++;
                scanf(" %c", &cmd);
            }


        }
        if(cmd == 'B')
        {
            int i,j;
            scanf("%d",&i);
            scanf("%d",&j);
            printf("\n");
        }
        if(cmd == 'C')
        {
            int i,j;
            scanf("%d",&i);
            scanf("%d",&j);
            printf("\n");
        }
        scanf("%s",&cmd);
    }
}