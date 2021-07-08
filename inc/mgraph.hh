#ifndef MGRAPH_HH
#define MGRAPH_HH

#include "library.hh"
#include "edge.hh"
#include "value.hh"
#include "vertice.hh"
#include "vector.hh"
// #include <ctime>

using namespace std;

template <int VERTICES_SIZE>
class MGraph
{
    vector<Vertice<int> > vertices;
    Vector<VERTICES_SIZE> neighbour_matrix[VERTICES_SIZE];
    // int properties[3];

public:
    // operatory indeksujace (dzieki nim mozna operowac na prywatnej czesci klasy)
    Vector<VERTICES_SIZE> operator[](int Ind) const { return neighbour_matrix[Ind]; }
    Vector<VERTICES_SIZE> &operator[](int Ind) { return neighbour_matrix[Ind]; }
    void Dijkstra(int *cost);
    MGraph()
    {
        // properties[2] = 0;
        Vertice<int> vertice = Vertice<int>();
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            vertice.getelement() = 1;
            vertice.getnumber() = i;
            vertices.push_back(vertice);
        }
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            for (int j = 0; j < VERTICES_SIZE; j++)
            {
                neighbour_matrix[i][j] = 0;
            }
        }
    }
    void generate_graph(int EDGES_SIZE)
    {
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            for (int j = 0; j < VERTICES_SIZE; j++)
            {
                neighbour_matrix[i][j] = 0;
            }
        }
        int a = 0, b = 0;
        for (int j = 0; j < EDGES_SIZE; j++)
        {
            a = rand() % VERTICES_SIZE;
            b = rand() % VERTICES_SIZE;
            while (neighbour_matrix[a][b] != 0 || a == b)
            {
                a = rand() % VERTICES_SIZE;
                b = rand() % VERTICES_SIZE;
            }
            neighbour_matrix[a][b] = rand() % 9 + 1;
        }
    }
    void graph_from_file()
    {
        int a = 0, b = 0, c = 0;
        ifstream odczyt("../dane/dane.txt");
        odczyt >> properties[0];
        odczyt >> properties[1];
        odczyt >> properties[2];

        for (int i = 0; i < properties[1]; i++)
        {
            odczyt >> a;
            odczyt >> b;
            odczyt >> c;
            neighbour_matrix[a][b] = c;
            cout << i << ". " << a << " " << b << " " << c << endl;
        }
        odczyt.close(); //zamknięcie pliku
    }

    void wypisz()
    {
        for (int i = 0; i < VERTICES_SIZE; i++)
        {
            for (int j = 0; j < VERTICES_SIZE; j++)
            {
                cout << neighbour_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif