#ifndef VERTICE_HH
#define VERTICE_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>

using namespace std;

template <typename Typ>
class Vertice
{
    int number;
    Typ element;

public:
    Typ getelement() const { return element; }
    Typ &getelement() { return element; }
    int getnumber() const { return number; }
    int &getnumber() { return number; }

    void create(Vertice tmp)
    {
       number = tmp.getnumber();
       element = tmp.getelement();
    }
};

#endif
