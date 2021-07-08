#ifndef VGRAPH_HH
#define VGRAPH_HH


#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <memory>
#include <ctime>
#include <string>
#include <cstring>
#include "edge.hh"
#include "value.hh"
#include "vertice.hh"
// #include<bits/stdc++.h>
// #include <ctime>

using namespace std;

template <int VERTICES_SIZE>
class VGraph
{
    vector<Vertice<int> > vertices;
    vector<Edge> edges;
    int properties[3];

public:
    // Graph();
    void Dijkstra(int *cost);
    void wyswietl()
    {
        int tab[VERTICES_SIZE][VERTICES_SIZE];
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            for (int j = 0; j < VERTICES_SIZE; j++)
            {
                tab[i][j] = 0;
            }
            // cout << endl;
        }
        for (int i = 0; i < edges.size(); i++)
        {
            tab[edges[i][0]][edges[i][1]] = edges[i].getweight();
        }
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            for (int j = 0; j < VERTICES_SIZE; j++)
            {
                cout << tab[i][j] << " ";
            }
            cout << endl;
        }
    }
    // void generate_graph(int EDGES_SIZE)
    // {
    //     properties[2] = 0;
    //     Vertice<int> vertice = Vertice<int>();
    //     for (int i = 0; i < VERTICES_SIZE; i++)
    //     {
    //         vertice.getelement() = i * 2;
    //         vertice.getnumber() = i;
    //         vertices.push_back(vertice);
    //     }
    //     // for (int i = 0; i < EDGES_SIZE; i++)
    //     // {
    //     int a = edges.size();
    //     for (int i = 0; i < EDGES_SIZE -a+1; i++)
    //     {
    //         // cout << i<< endl;
    //         edges.pop_back();
    //         // cout << "a" << endl;
    //     }
    // }
    void generate_graph(int EDGES_SIZE)
    {
        int a = edges.size();
        for (int i = 0; i < a; i++)
        {
            edges.pop_back();
        }
        properties[2] = 0;
        Vertice<int> vertice = Vertice<int>();
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            vertice.getelement() = i * 2;
            vertice.getnumber() = i;
            vertices.push_back(vertice);
        }
        generate_egde(EDGES_SIZE);
    }

    void generate_egde(int EDGES_SIZE)
    {
        Edge edge;
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            for (int j = 0; j < VERTICES_SIZE; j++)
            {
                edge[0] = i;
                edge[1] = j;
                edge.getweight() = rand() % 9 + 1;
                if (i != j)
                {
                    edges.push_back(edge);
                }
            }
        }
        for (int i = 0; i < EDGES_SIZE_C - EDGES_SIZE; i++)
        {
            edges.erase(edges.begin() + rand() % edges.size() - 1);
        }
        // cout << edges.size() << endl;
    }

    void change_edges(int EDGES_SIZE)
    {
        Edge edge;
        for (int i = 0; i < EDGES_SIZE / 2; i++)
        {
            edges.erase(edges.begin() + rand() % edges.size() - 1);
        }

        for (int i = 0; i < EDGES_SIZE / 2; i++)
        {
            edge[0] = rand() % VERTICES_SIZE;
            edge[1] = rand() % VERTICES_SIZE;
            //     for (int i = 0; i < edges.size(); i++)
            //     {
            //         if (edge[0] == edges[i][0] && edge[1] == edges[i][1])
            //         {
            //             edge[0] = rand() % VERTICES_SIZE;
            //             i--;
            //         }
            //         if (edge[0] == edge[1])
            //         {
            //             edge[1] = rand() % VERTICES_SIZE;
            //             i--;
            //         }
            //     }
            edge.getweight() = rand() % 9 + 1;
            edges.push_back(edge);
        }
    }
    void graph_from_file()
    {
        Edge edge;
        int a = 0, b = 0, c = 0;
        ifstream odczyt("../dane/dane.txt");
        odczyt >> properties[0];
        odczyt >> properties[1];
        odczyt >> properties[2];

        for (int i = 0; i < properties[1]; i++)
        {
            odczyt >> edge[0];
            odczyt >> edge[1];
            odczyt >> edge.getweight();
            edges.push_back(edge);
        }
        odczyt.close(); //zamknięcie pliku
    }
    void graph_to_file(int EDGES_SIZE,string sciezka)
    {
        ofstream zapis(sciezka);
        zapis << VERTICES_SIZE << " " << EDGES_SIZE << " " << properties[2] << endl;
        for (int i = 0; i < EDGES_SIZE; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                zapis << edges[i][0] << " " << edges[i][1] << " " << edges[i].getweight() << endl;
            }
        }
        zapis.close();
        cout << "poprawnie zostało zapisane" << endl;
    }
};

#endif
