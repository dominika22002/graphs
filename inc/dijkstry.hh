#ifndef DIJKSTRY_HH
#define DIJKSTRY_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include "vgraph.hh"
#include "mgraph.hh"
#include "vertice.hh"
#include "value.hh"
#include "edge.hh"

using namespace std;

//dla macierzy
template <int VERTICES_SIZE>
int Min_m(int *cost, bool *visited)
{
    int min = -1;
    int value = inf;
    for (int i = 0; i < VERTICES_SIZE; i++)
    {
        if ((!visited[i]) && (cost[i] < value))
        {
            min = i;
            value = cost[i];
        }
    }
    return min;
}

template <int VERTICES_SIZE>
void MGraph<VERTICES_SIZE>::Dijkstra(int *cost)
{
    int *previous = new int[MAX_VAL];
    bool *visited = new bool[MAX_VAL];
    for (int i = 0; i < VERTICES_SIZE; i++)
    {
        if (i == properties[2])
            cost[i] = 0;
        else
            cost[i] = inf;

        previous[i] = -1;
        visited[i] = false;
    }
    int min = Min_m<VERTICES_SIZE>(cost, visited);
    while (min != -1)
    {
        visited[min] = true;
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            if ((neighbour_matrix[min][i] > 0) && (cost[min] + neighbour_matrix[min][i] < cost[i]))
            {
                cost[i] = cost[min] + neighbour_matrix[min][i];
                previous[i] = min;
            }
        }
        min = Min_m<VERTICES_SIZE>(cost, visited);
    }
    delete[] previous;
    delete[] visited;
}

template <int VERTICES_SIZE>
int Min_v(int *cost, bool *visited)
{
    int min = -1;
    int value = inf;
    for (int i = 0; i < VERTICES_SIZE; i++)
    {
        if ((!visited[i]) && (cost[i] < value))
        {
            min = i;
            value = cost[i];
        }
    }
    return min;
}

template <int VERTICES_SIZE>
void VGraph<VERTICES_SIZE>::Dijkstra(int *cost)
{
    //
    // int a = 0;
    int *previous = new int[MAX_VAL];
    bool *visited = new bool[MAX_VAL];
    for (int i = 0; i < VERTICES_SIZE; i++)
    {
        if (i == properties[2])
            cost[i] = 0;
        else
            cost[i] = inf;

        previous[i] = -1;
        visited[i] = false;
    }
    int A = edges.size();
    int w =0,e=0;
    int min = Min_v<VERTICES_SIZE>(cost, visited);
    while (min != -1)
    {
        visited[min] = true;
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            for (int a = i; a < edges.size(); a++)
            {
                while (a < A && edges[a][0] != i)
                    a++;
                
                if (a < A)
                {
                    w = edges[a][0];
                    e = edges[a][1];
                    if (cost[w] + edges[a].getweight() < cost[e])
                    {
                        cost[e] = cost[w] + edges[a].getweight(); 
                        previous[w] = min;
                    }
                }
            }
           
        }
        
        min = Min_v<VERTICES_SIZE>(cost, visited);
         min = -1;
    }
    delete[] previous;
    delete[] visited;
}

#endif
