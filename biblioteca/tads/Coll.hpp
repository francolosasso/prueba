#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

template<typename T>
struct Coll
{
   //donde estaba string s habia luego un = """; lo saque para probar si ya no sale el error
   string s;
   char sep;
   int point=0;
};

template<typename T>
Coll<T> coll(char sep) // inicializacion de la coleccion con sep
{
   Coll<T> c;
   c.sep=sep;
   return c;
}

template<typename T>
Coll<T> coll() // inicializacion de la coleccion '|'
{
   Coll<T> c;
   c.sep='|';
   return c;
}

template<typename T>
int collSize(Coll<T> c) // Retorna la cantidad de elementos que contiene la colecci�n c.
{
   return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c) // Remueve de la colecci�n c todos sus elementos, dej�ndola vac�a.
{
   c.point=0;
   c.s="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p) // Remueve de la colecci�n c el elemento ubicado en la posici�n p.
{
   c.point--;
   removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T)) //Agrega el elemento t al final de la colecci�n c (devuelve la posicion)
{
   addToken(c.s,c.sep,tToString(t));
   c.point++;
   return tokenCount(c.s,c.sep) - 1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T)) // Reemplaza por t al elemento que se ubica en la posici�n p.
{
   setTokenAt(c.s,c.sep,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string)) // Retorna el elemento que se ubica en la posici�n p de la colecci�n c.
{
   T t=tFromString(getTokenAt(c.s,c.sep,p));
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string)) // Determina si la colecci�n c contiene al elemento k. (devuelve la posicion)
{
   int cantTokens=tokenCount(c.s,c.sep);
   int pos=-1;
   for(int i=0;i<cantTokens;i++)
   {
      string token=getTokenAt(c.s,c.sep,i);
      T tToken=tFromString(token);
      if(cmpTK(tToken,k)==0)
      {
         pos=findToken(c.s,c.sep,token);
      }
   }

   return pos;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T)) // Ordena los elementos de la colecci�n c seg�n el criterio de precedencia que establece cmpTT.
{
   int cantTokens = tokenCount(c.s,c.sep);
   int i=0, j=1;

   while(i<cantTokens)
   {
      while(j<cantTokens)
      {
         string sToken1 = getTokenAt(c.s,c.sep,i); // 11 Juan
         string sToken2 = getTokenAt(c.s,c.sep,j); // 10 Pedro
         T token1 = tFromString(sToken1);
         T token2 = tFromString(sToken2);
         if(cmpTT(token1,token2)>0)
         {
            setTokenAt(c.s,c.sep,sToken2,i);
            setTokenAt(c.s,c.sep,sToken1,j);
         }
         j++;
      }
      i++;
      j=i+1;
   }

}

template<typename T>
bool collHasNext(Coll<T> c)
{
   bool ret=false;
   int cantTokens = tokenCount(c.s,c.sep);
   if(c.point<cantTokens)
   {
      c.point++;
      ret=true;
   }
   return ret;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   string token = getTokenAt(c.s,c.sep,c.point);
   T t = tFromString(token);
   c.point++;
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   string token = getTokenAt(c.s,c.sep,c.point);
   T t = tFromString(token);
   endOfColl = collHasNext(c);

   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.point=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}


#endif

// lo que hice de la ultima vez
/*template<typename T>
struct Coll

{
   string s;
   char sep ;

};

template<typename T>
Coll<T> coll(char sep)
{

   Coll<T> c;
    c.sep = sep;
   return c;
}

template<typename T>
Coll<T> coll()
{
   Coll<T> c;
   c.sep = '|';
   return c;
}

template<typename T>
int collSize(Coll<T> c)
{

   return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s = "";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s,c.sep,t);
      return tokenCount(c.s,c.sep);
}

template <typename T>
//esta bien
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.s,c.sep,tToString(t),p );
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t=tFromString(getTokenAt(c.s,c.sep,p));
      return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{*/
   //estaba mal esto
   /*int x;
   while(c != '\0'){
   if(cmpTK(tFromString(getTokenAt(c.s,c.sep,i)),tFromString(k)) > 0){
       x = findToken(tFromString(c.s),c.sep,k);

   }
   i++;
   }
   return x;*/

   /*int cantTokens=tokenCount(c.s,c.sep);
     int pos=-1;
     for(int i=0;i<cantTokens;i++)
     {
        string token=getTokenAt(c.s,c.sep,i);
        T tToken=tFromString(token);
        if(cmpTK(tToken,k)==0)
        {
           pos=findToken(c.s,c.sep,token);
        }
     }

     return pos;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{

}

template<typename T>
bool collHasNext(Coll<T> c)
{
   return true;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t;
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{

}

#endif*/

