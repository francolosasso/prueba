#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>


template<typename T> void write(FILE* f, T t)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
   fseek(f,0,SEEK_CUR);
   fwrite(&t,sizeof(T),1,f);
}

template<typename T> T read(FILE* f)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
   fseek(f,0,SEEK_CUR);
   T t;
   fread(&t,sizeof(T),1,f);
   return t;
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n*sizeof(T),SEEK_SET);
}

template<typename T> int fileSize(FILE* f)
{
   int actual=ftell(f);
   fseek(f,0,SEEK_END);
   int ultimo=ftell(f);
   fseek(f,actual,SEEK_SET);

   return ultimo/sizeof(T);
}

template<typename T> int filePos(FILE* f)
{
   int actual=ftell(f);
   return actual/sizeof(T);
}

#endif


/*#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);
}

template<typename T> T read(FILE* f)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   // fseek(f,0,SEEK_CUR);

   T t;
   return t;
}

template<typename T> void seek(FILE* f, int n)
{
}

template<typename T> int fileSize(FILE* f)
{
   return 0;
}

template<typename T> int filePos(FILE* f)
{
   return 0;
}

#endif
*/

