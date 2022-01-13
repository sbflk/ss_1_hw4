#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



pnode create_graph(int size)
{
    pnode n = NULL;
    for(int i = size -1; i >=0; i--)
    {
        n = create_node(i,n);
    }
    return n; //return first node
}

pnode create_node(int id, pnode next)
{
    pnode n = (pnode) malloc(sizeof(node));
    n -> node_num = id;
    n -> next = next;
    n -> edges = NULL;
    return n;
}

pedge create_edge(int w, pnode dest, pedge next)
{
    pedge e = (pedge) malloc(sizeof(edge));
    e -> weight = w;
    e -> endpoint = dest;
    e -> next = next;
    return e;
}

void build_graph_cmd(pnode *head)
{
    int id;
    scanf("%d", &id);
    pnode n = getNode(id, *head);
    pedge edge_of_node = NULL;

    while(scanf("%d", &id)==1){
   
        pnode dest = getNode(id, *head);
   
        scanf("%d", &id);
   
        edge_of_node = create_edge(id,dest,edge_of_node);
   
    }
   
    n->edges = edge_of_node;
}

pnode getNode(int id, pnode head)
{
    while (head){
        if (head -> node_num == id){
        
            return head;
        
        }
        head = head -> next;
    }
    return NULL;
}

void insert_node_cmd(pnode *head)
{
    int id;
    scanf("%d",&id);
    pnode n = getNode(id,*head);
    if(*head == NULL)//if this is the first node
    {
        *head = create_node(id,NULL);
        n = *head;
    }
    else if(n != NULL)//delete edges out of node if node exists
    {
        delete_out_edges(n);
    }
    else
    {
        n = create_node(id,*head);
    }

    pedge edge_of_node = NULL;
    while(scanf("%d", &id)==1){
   
        pnode dest = getNode(id, *head);
   
        scanf("%d", &id);
   
        edge_of_node = create_edge(id,dest,edge_of_node);
   
    }

    n -> edges = edge_of_node;

}

void delete_out_edges(pnode n)
{
    pedge current = n -> edges;

    while(current)
    {
        pedge prev = current;
        current = current -> next;
        free(prev);
    }
}

void delete_to_edges(int id, pnode n)
{
    pedge es = n -> edges;

    while(es -> next != NULL)
    {
        if(es -> next -> endpoint -> node_num == id)
        {
            pedge del = es -> next;
            es -> next = del -> next;
            free(del);
        }
    }
    es = es -> next;
}

void delete_node_cmd(pnode *head)
{
    int id;
    scanf("%d", &id);
    pnode current = *head;
    pnode del = NULL;
    if(current -> node_num == id)
    {
        head = &(current -> next);
        del = current;
    }
    else
    {
        while(current -> next != NULL)
        {
            if(current -> next -> node_num == id)
            {
                del = current -> next;
                current -> next = del -> next;
            }
            current = current -> next;
        }

    }
    delete_to_edges(id, *head);
    delete_out_edges(del);
    free(del);

}

void deleteGraph_cmd(pnode *head)
{
    pnode h = *head;
    while(h)
    {
        delete_out_edges(h);//deleting out edges because they dont rely on anything but the node itself
        pnode del = h;
        h = h -> next;
        free(del);
    }
}


int dijkstra(pnode head, int src, int dest)
{
    int size = 0;
    int shortest_path_weight = 0;
    pnode counter = head;
    while(counter != NULL)
    {
        counter = counter -> next;
        size++;
    }
    int dijkstra_table[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(i == j)
            {
                dijkstra_table[i][j] = 0;
            }
            else
            {
                dijkstra_table[i][j] = 99999;
            }
            
        }
    }

    int visited[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    visited[getindex(head,src)] = 1; 

    // put known weights in the table

    pnode nodes = head;
    pedge edge_list = NULL;
    int x = 0;
    int y = 0;

    while(nodes != NULL)
    {
        edge_list = nodes -> edges;
        while(edge_list != NULL)
        {
            x = getindex(head, nodes -> node_num);
            y = getindex(head, edge_list -> endpoint -> node_num);
            dijkstra_table[x][y] = edge_list -> weight;
            edge_list = edge_list -> next;
        }
        nodes = nodes -> next;
    }

    int distance[size];
    for(int i = 0; i < size; i++)
    {
        distance[i] = dijkstra_table[getindex(head,src)][i];
    }

    int closest_node = 0;
    for(int i = 0; i < size; i++)
    {
        closest_node = find_closest_to_node(size, visited,distance);
        visited[closest_node] = 1;
        for(int j = 0; j < size; j++)
        {
            if(visited[j] == 0)
            {
                if(distance[j] > distance[closest_node] + dijkstra_table[closest_node][j])
                {
                    distance[j] =  distance[closest_node] + dijkstra_table[closest_node][j];
                }

            }
        }
    }
    shortest_path_weight = distance[getindex(head, dest)];
    return shortest_path_weight;


}

int getindex(pnode head, int id)
{
    pnode search = head;
    int i = 0;
    while(search != NULL)
    {
        if(search -> node_num == id)
        {
            return i;
        }
        i++;
        search = search -> next;
    }
    return -1;
}


int find_closest_to_node(int size, int visited[], int distance[])
{
    int min = 99999;
    int index = 0;
    for(int i = 0; i < size; i++)
    {
        if(visited[index] == 0 && distance[index] < min)
        {
            min = distance[index];
            index = i;
        }
    }
    return index;
}

void shortsPath_cmd(pnode head)
{
    int src = 0;
    scanf("%d", &src);
    int dest = 0;
    scanf("%d", &dest);
    int w = dijkstra(head, src, dest);
    if(w == 99999)
    {
        w = -1;
    }
    printf("Dijsktra shortest path: %d \n", w);
}


void TSP_cmd(pnode head)
{
    int num_of_cities = 0;
    scanf("%d", &num_of_cities);
    printf("NUM OF CITIES: %d \n",num_of_cities);
    int cities[num_of_cities];
    int city_id = 0;
    for(int i = 0; i < num_of_cities; i++)
    {
        scanf("%d", &city_id);
        printf("city: %d \n",city_id);
        cities[i] = city_id;
    }
    int ans = 99999;
    TSP(head, cities, 0, num_of_cities-1, &ans, num_of_cities);
    if(ans == 99999)
    {
        ans = -1;
    }

    printf("TSP shortest path: %d \n", ans);
}


void TSP(pnode head, int cities[], int src, int dest, int* min_weight, int size)//min weight needs to be a pointer to keep track of the value during recursive calls
{
    if(src == dest)
    {
        printf("SRC == DEST \n");
        int sum = 0;
        for(int i = 0; i < size - 1; i++)
        {
            sum += dijkstra(head, getindex(head, cities[i]), getindex(head, cities[i+1]));

            printf("SUM = %d \n",sum);
        }
        if(sum < *min_weight)
        {
            printf("SUM < MIN_WEIGHT \n");
            *min_weight = sum;
        }

    }
    else
    {
        for(int i = src; i <= dest; i++)
        {
            swap((cities+src), (cities+i));
            printf("MIN_WEIGHT = %d \n",*min_weight);
            TSP(head, cities, src + 1, dest, min_weight, size);
            swap((cities+src), (cities+i));
        }
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


