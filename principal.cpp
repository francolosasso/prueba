
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

int main()
{
   // array y longitud
   Array<int> a = array<int>();
   cout << "agrego esto para ver si se guardan cambios" << endl;
   arrayAdd<int>(a, 10);
   arrayAdd<int>(a, 20);
   arrayAdd<int>(a, 30);
   // el size del array?

   cout << "prueba segunda  rama" << endl;

   cout << "prueba de nueva rama" << endl;
   cout << arraySize<int>(a) << endl; // Salida: 3
   return 0;
}

#endif
