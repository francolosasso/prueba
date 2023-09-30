#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[], int &len, T e)
{
   arr[len] = e;   // Agrega el elemento al final del array
   len++;          // Incrementa la longitud del array
   return len - 1; // Retorna la posición donde se ubicó el elemento agregado
}

template <typename T>
void insert(T arr[], int &len, T e, int p)
{
   // Desplazar elementos a la derecha para hacer espacio para el nuevo elemento
   for (int i = len; i > p; i--)
   {
      arr[i] = arr[i - 1];
   }

   arr[p] = e; // Insertar el nuevo elemento en la posición p
   len++;      // Incrementar la longitud del array
}

template <typename T>
T remove(T arr[], int &len, int p)
{
   T removedElement = arr[p]; // Guarda el elemento que se va a remover

   // Desplaza elementos a la izquierda para llenar el espacio
   for (int i = p; i < len - 1; i++)
   {
      arr[i] = arr[i + 1];
   }

   len--;                 // Decrementa la longitud del array
   return removedElement; // Retorna el elemento que fue removido
}

template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K))
{
   for (int i = 0; i < len; i++)
   {
      if (cmpTK(arr[i], k) == 0)
      {
         return i; // Retorna la posición si se encuentra una coincidencia
      }
   }
   return -1; // Retorna -1 si no se encuentra la coincidencia
}

template <typename T>
int orderedInsert(T arr[], int &len, T e, int cmpTT(T, T))
{
   int insertPosition = 0;

   // Encuentra la posición de inserción según la función de comparación
   while (insertPosition < len && cmpTT(arr[insertPosition], e) < 0)
   {
      insertPosition++;
   }

   // Desplaza elementos a la derecha para hacer espacio para el nuevo elemento
   for (int i = len; i > insertPosition; i--)
   {
      arr[i] = arr[i - 1];
   }

   arr[insertPosition] = e; // Inserta el nuevo elemento
   len++;                   // Incrementa la longitud del array

   return insertPosition; // Retorna la posición donde se insertó el elemento
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
   for (int i = 0; i < len - 1; i++)
   {
      for (int j = 0; j < len - i - 1; j++)
      {
         if (cmpTT(arr[j], arr[j + 1]) > 0)
         {
            // Intercambia los elementos si están en el orden incorrecto
            T temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

#endif
