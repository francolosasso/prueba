#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;
// la de mi lugar de trabajo

/*template <typename T>
struct Array
{
   int point;    // Índice actual en el arreglo
   int size;     // Tamaño actual del arreglo
   int capacity; // Capacidad total del arreglo
};

template <typename T>
Array<T> array()
{
   Array<T> arr;
   arr.point = 0;
   arr.size = 0;
   return arr;
}

template <typename T>
int arrayAdd(Array<T> &a, T t)
{
   if (a.size == a.capacity)
   {
      // Realizar realocación de memoria si el arreglo está lleno
      // Aquí deberías aumentar la capacidad y copiar los elementos anteriores a la nueva ubicación
   }

   int newPosition = a.point + a.size;
   a.size++;
   return newPosition;
}

template <typename T>
T *arrayGet(Array<T> a, int p)
{
}

template <typename T>
void arraySet(Array<T> &a, int p, T t)
{
}

template <typename T>
void arrayInsert(Array<T> &a, T t, int p)
{
}

template <typename T>
int arraySize(Array<T> a)
{
   return 0;
}

template <typename T>
T arrayRemove(Array<T> &a, int p)
{
   T t;
   return t;
}

template <typename T>
void arrayRemoveAll(Array<T> &a)
{
}

template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K))
{
   return 0;
}

template <typename T>
int arrayOrderedInsert(Array<T> &a, T t, int cmpTT(T, T))
{
   return 0;
}

template <typename T>
void arraySort(Array<T> &a, int cmpTT(T, T))
{
}*/

template <typename T>
struct Array
{
   // Implementación a cargo del estudiante
   T *elements;
   int capacity;
   int length;
};

template <typename T>
Array<T> array()
{
   Array<T> arr;
   arr.elements = nullptr; // Inicializa el puntero de elementos como nulo
   arr.capacity = 0;       // Inicializa la capacidad como 0 (sin memoria asignada)
   arr.length = 0;         // Inicializa la longitud como 0 (sin elementos)
   return arr;
}

template <typename T>
int arrayAdd(Array<T> &a, T t)
{
   return add(a.elements, a.length, t); // Llama a la función add para agregar un elemento
}

template <typename T>
T *arrayGet(Array<T> &a, int p)
{
   if (p >= 0 && p < a.length)
   {
      return &a.elements[p]; // Retorna el puntero al elemento en la posición p
   }
   return nullptr;
}

template <typename T>
void arraySet(Array<T> &a, int p, T t)
{
   if (p >= 0 && p < a.length)
   {
      a.elements[p] = t; // Asigna el valor t al elemento en la posición p
   }
}

template <typename T>
void arrayInsert(Array<T> &a, T t, int p)
{
   insert(a.elements, a.length, t, p); // Llama a la función insert para insertar un elemento en la posición p
}

template <typename T>
int arraySize(Array<T> &a)
{
   return a.length; // Retorna la longitud actual del array
}

template <typename T>
T arrayRemove(Array<T> &a, int p)
{
   return remove(a.elements, a.length, p); // Llama a la función remove para eliminar un elemento en la posición p
}

template <typename T>
void arrayRemoveAll(Array<T> &a)
{
   a.length = 0; // Establece la longitud del array como 0
   if (a.elements)
   {
      delete[] a.elements; // Libera la memoria asignada para los elementos
      a.elements = nullptr;
      a.capacity = 0;
   }
}

template <typename T, typename K>
int arrayFind(Array<T> &a, K k, int cmpTK(T, K))
{
   return find(a.elements, a.length, k, cmpTK); // Llama a la función find para buscar un elemento en el array
}

template <typename T>
int arrayOrderedInsert(Array<T> &a, T t, int cmpTT(T, T))
{
   return orderedInsert(a.elements, a.length, t, cmpTT); // Llama a la función orderedInsert para insertar ordenadamente un elemento en el array
}

template <typename T>
T *arrayDiscover(Array<T> &a, T t, int cmpTT(T, T))
{
   int pos = find(a.elements, a.length, t, cmpTT); // Busca el elemento en el array
   if (pos != -1)
   {
      return &a.elements[pos]; // Si se encuentra, retorna el puntero al elemento
   }
   int insertPos = orderedInsert(a.elements, a.length, t, cmpTT); // Si no se encuentra, inserta ordenadamente el elemento en el array
   return &a.elements[insertPos];                                 // Retorna el puntero al elemento recién insertado
}

template <typename T>
void arraySort(Array<T> &a, int cmpTT(T, T))
{
   sort(a.elements, a.length, cmpTT); // Llama a la función sort para ordenar los elementos del array
}

#endif
