#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "library.hh"
#include "value.hh"
#include "vertice.hh"
using namespace std;

template <int VERTICES_SIZE>
class Vector
{
  int vector[VERTICES_SIZE];

public:
  //konstruktor
  Vector()
  {
    for (int i = 0; i < VERTICES_SIZE; i++)
    {
      vector[i] = 0;
    }
  }
  // operatory indeksujace (dzieki nim mozna operowac na prywatnej czesci klasy)
  int operator[](int Ind) const { return vector[Ind]; }
  int &operator[](int Ind) { return vector[Ind]; }
};

#endif