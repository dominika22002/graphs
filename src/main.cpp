#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <iomanip>
#include "../inc/vgraph.hh"
#include "../inc/mgraph.hh"
#include "../inc/dijkstry.hh"
#include "../inc/porzadkowe.hh"

int main()
{
    unsigned long int czas;
    int time_tab[4][5];
    float DEN[4];
    DEN[3] = 0.25;
    DEN[2] = 0.5;
    DEN[1] = 0.75;
    DEN[0] = 1;
    int a = 0;
    clock_t start, stop;
    int cost[VERTICES_SIZE_C];
    int VERTICES_SIZE = 30;
    int EDGES_SIZE = VERTICES_SIZE * (VERTICES_SIZE - 1);
    // VGraph<30> vgrapha;
    // vgrapha.generate_graph(EDGES_SIZE);
    // vgrapha.graph_to_file(EDGES_SIZE, "../dane/graf.txt");
    // return 0;
    MGraph<30> mgraph;
    for (int k = 0; k < 4; k++)
    {
        EDGES_SIZE = DEN[k] * VERTICES_SIZE * (VERTICES_SIZE - 1);
        for (int j = 0; j < 5; j++)
        {

            for (int i = 0; i < 100; i++)
            {
                mgraph.generate_graph(EDGES_SIZE);
                start = clock();
                mgraph.Dijkstra(cost);
                stop = clock();
                czas = 1000000 * (stop - start) / CLOCKS_PER_SEC;
                a += czas;
            }
            time_tab[k][j] = a;
            a = 0;
        }
    }
    raport_do_pliku(time_tab, VERTICES_SIZE, "../dane/macierzowo.txt");
    // return 0;
    EDGES_SIZE = VERTICES_SIZE * (VERTICES_SIZE - 1);
    VGraph<30> vgraph;
    for (int k = 0; k < 4; k++)
    {
        EDGES_SIZE = DEN[k] * VERTICES_SIZE * (VERTICES_SIZE - 1);
        for (int j = 0; j < 5; j++)
        {
            for (int i = 0; i < 100; i++)
            {
                // cout << i << endl;
                vgraph.generate_graph(EDGES_SIZE);
                start = clock();
                vgraph.Dijkstra(cost);
                stop = clock();
                czas = 1000000 * (stop - start) / CLOCKS_PER_SEC;
                // cout << czas << endl;
                a += czas;
            }
            // cout << a << endl;
            time_tab[k][j] = a;
            a = 0;
        }
    }
    raport_do_pliku(time_tab, VERTICES_SIZE, "../dane/vectorowo.txt");
}
