#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{

   /* otra forma de hacerlo no se si funciona
    int i = 0;
   while(s[i] != '/0'){
      cout << (char) s[i] << endl;
      i++;
   }*/
  /*int i;
  for( i = 0 ; s[i] != '\0';i++);
   return i;*/

   int i=0;
      while(s[i]!='\0')
      {
         i++;
      }

      return i;
}


int charCount(string s,char c)
{
   int i = 0;
   int contadora = 0;
     for( ; s[i] != '\0';i++){
        if(c == s[i]){
           contadora++;
        }
     }
      return contadora;
}

string substring(string s,int d,int h)
{
    string acumulador;
        for( ; d < h;d++){
           acumulador = acumulador + s[d];

        }

   return acumulador;
}

string substring(string s,int d) // ok
{
   string acumulador;
           for( ; s[d] != '\0' ;d++){
              acumulador = acumulador + s[d];

           }

      return acumulador;
}

int indexOf(string s,char c) // ok
{
  int i = 0;
     for( ; s[i] != c && s[i] != '\0';i++);
     if(s[i] == '\0'){
               i = -1;
            }

      return i;

}

int indexOf(string s,char c,int offSet) // ok
{
       /* for( ; s[offSet] != c ;offSet++);

         return offSet;*/

   int i=offSet, pos=-1;
      /* while(s[i]!='\0')
      {
         if(s[i]==c)
         {
            pos=i;
            i=length(s)-1;
         }
         i++;
      } */

   int z=0;
         while(s[z]!='\0')
      {
         if(s[i]==c)
         {
            pos=i;
            s[i+1]='\0';
         }
         z++;
      }
      return pos;
}


int indexOf(string s,string toSearch) // ok
{
   int i = 0;
   char primerValor = toSearch[0];
        for( ; s[i] != primerValor && s[i] != '\0';i++);
        if(s[i] == '\0'){
                  i = -1;
               }

         return i;
}

int indexOf(string s,string toSearch,int offset) // ok
{
   int i=offset, pos=-1;
      int j=length(toSearch) + i;

      int z = 0;
      while(s[z]!='\0')
      {
         string sub = substring(s,i,j);
         if(sub==toSearch)
         {
            pos=i;
            s[i+1]='\0';
         }
         j++;
         z++;
      }
      return pos;
}
//sumarle lo anterior
int lastIndexOf(string s,string c)
{
   int i = 0;
   int contadora = 0;
   int sumaContadora = 0;
   int otraContadora = 0;

   while(s[contadora] != c[0]){
      contadora++;
   }
   while(c[i] != '\0'){
         i++;
      }
      char ultimoValor = c[i - 1];
        for( ; ultimoValor != c[otraContadora] ;otraContadora++);

        sumaContadora = contadora + otraContadora;
         return sumaContadora;
}

int indexOfN(string s,char c,int n)
{
   int i = 0;
   int acumulador = 0;

      for( ; acumulador < n && s[i] != '\0';i++  ){
         if(s[i] == c){
                 acumulador++;
              }
      }
      i = i -1;
      return i;
}


int charToInt(char c)
// valor numerico que representa c 'A'=10 (ok)
{
  int ret=c;

  if('A'<=c && c<='Z')
  {
     ret -= 55; //65=primer C.ASCCI
  }
  else
  {
     if('a'<=c && c<='z')
     {
        ret -= 87; //97=primer C.ASCCI
     }
     else
     {
        if('0'<=c && c<='9')
        {
           ret -= 48; //48=primer C.ASCCI
        }
     }
  }
  return ret;
}

//en este no es necesario tener en cuenta los valores minusculas
// 12 terminado
char intToChar(int i)
{

   char resultado=i;
      if(i >= 10 && i<=25)
      {
         resultado+=55;
      }
      else
      {
         if(i >= 0 && i<=9)
         {
            resultado+=48;
         }
      }
      return resultado;
   }







int getDigit(int n,int i)
{

   int variableAcumuladora = 1;
   int resultado;

   if(n < 0){
      n = -n;
   }

  while(i >= 0){
     variableAcumuladora = variableAcumuladora * 10;
     i--;
  }

   resultado = n % variableAcumuladora;

   while(resultado / 10 != 0){
      resultado = resultado / 10;
   }

   return resultado;
}

int digitCount(int n)
{
   /*int i = 0;
     for( ; n[i] != '\0';i++);
      return i;*/
   int i = 0;
   while(n != 0){
      n = n/ 10;
      i++;
   }
   return i;
}

string intToString(int i)
{

   string s = "";
   int signoNegativo = 0;

       if (i == 0) {
           return "0";
       }

       if (i < 0) {
           signoNegativo++;
           i = -i;
       }

       while (i > 0) {
           char c = (i % 10) + '0';
           s = c + s;
           i /= 10;
       }

       if(signoNegativo == 1){
          s = "-" + s;
       }
       return s;
}


int stringToInt(string s,int b) // ok
{

    
   int result = 0;
       int power = 1;

       for (int i = length(s) - 1; i >= 0; --i) {
           int digit = charToInt(s[i]);
           if (digit == -1 || digit >= b) {
               // Car�cter inv�lido o fuera de rango de la base
               return -1;
           }
           result += digit * power;
           power *= b;
       }

       return result;
}

//ejercicio 17. Cuando yo accedo a un valor de la cadena del string y lo guardo en una variable int y retorno esta me devuelve el valor en codigo ascii, por ejemplo 1 me retorna 49
//esta funcion puede tomar valores positivos o 0
//no funciona no se por que
int stringToInt(string s) // ok
{

   int result = 0;
       int sign = 1;
       int i = 0;

       // Verificar si hay un signo negativo
       if (s[i] == '-') {
           sign = -1;
           i++;
       }

       // Convertir los caracteres de la cadena en un valor entero
       while (i < length(s)) {
           int digit = s[i] - '0';
           result = result * 10 + digit;
           i++;
       }

       return result * sign;

}


//18, esta bien
string charToString(char c)
{
   string resultado = "";

   resultado = resultado + c;

   return resultado;
}

//19, esta bien
char stringToChar(string s)
{

   return s[0];
}

//20, esta bien
string stringToString(string s)
{


   return s;
}

/*  este acordate que era dificil por eso no lo termine y no era necesario
string doubleToString(double d)
{


   string s = "";
   string z = "";
    int contador = 0;
 int parteEntera = d / 1;



 string parteEnteraResultado = intToString(parteEntera);


 // esta parte me calcula el resto
    double numero = 1;
    double i;
    double decimal;
    int resultadoEntero;

    resultadoEntero = d / numero;
    i = d / numero;
    decimal = (i - resultadoEntero) * numero;

    while(contador != 1){
       if( restoo(d) == 0){
          restoo(d) =   10;
          contador++;
       }
    }

    string parteDecimalResultado = intToString(0);

 return parteDecimalResultado;


    esta es inttostring
     string s = "";
      int signoNegativo = 0;

          if (i == 0) {
              return "0";
          }

          if (i < 0) {
              signoNegativo++;
              i = -i;
          }

          while (i > 0) {
              char c = (i % 10) + '0';
              s = c + s;
              i /= 10;
          }

          if(signoNegativo == 1){
             s = "-" + s;
          }
          return s;
}*/

//no hacer este
double stringToDouble(string s)
{

   return 1.1;
}

bool isEmpty(string s)
{
   bool ret=false;
     if(s=="")
     {
        ret=true;
     }
     return ret;
}

bool startsWith(string s,string x)
{
   bool ret=false;
     int xLength = length(x);

     if(substring(s,0,xLength)==x)
     {
        ret=true;
     }

     return ret;
}


bool endsWith(string s,string x) // true si x es sufijo de s
{
   bool ret=false;
   int xLength = length(x);
   int sLength = length(s);

   if(substring(s,sLength-xLength,sLength)==x)
   {
      ret=true;
   }
   return ret;
}

bool contains(string s,char c) // true si s contiene a c
{
   bool ret=false;
   if(indexOf(s,c)!=-1)
   {
      ret=true;
   }

   return ret;
}

string replace(string s,char oldChar,char newChar)
{
   int pos=0;
   int match=indexOf(s,oldChar,pos);
   while(match!=-1 )
   {
      s[match]=newChar;
      pos=match;
      match=indexOf(s,oldChar,pos);
   }
   return s;
}

string insertAt(string s,int pos,char c) // inserta caractes c en la posicion pos
{
   /* string add = substring(s,pos);
   s[pos]=c; */

   string newString=substring(s,0,pos);
   newString+=c;
   newString+=substring(s,pos);

   return newString;
}

string removeAt(string s,int pos) // elimina el caracter de la posicion pos
{
   string newString=substring(s,0,pos);
   newString+=substring(s,pos+1);
   return newString;
}

string ltrim(string s) // quita los espacios sobrantes de la izquierda
{
   /* int i = 0;
   string resultado="";
   while(s[i] != '\0'){
      if(s[i] != ' '){
         resultado=substring(s,i);
         s[i+1]='\0';
      }
      i++;
   } */
   string ret="";
   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]!=' ')
      {
         ret=substring(s,i);
         s[i+1]='\0';
      }
   }
   return ret;
}

string rtrim(string s) // quita los espacios sobrantes de la derecha
{
   /* string resultado="";
   int i=length(s)-1;
   if(s[i]!=' ')
   {
      resultado=s;
   }
   else
   {
      for(i;s[i]==' ';i--)
      {
         resultado=substring(s,0,i);
      }
   } */
   string ret="";
   int i;
   for( i = length(s)-1;s[i]!='\0';i--)
   {
      if(s[i]!=' ')
      {
         ret=substring(s,0,i+1);
         s[i-1]='\0';
      }
   }
   return ret;
}

string trim(string s) // quita los espacios sobrantes a izquierda y derecha
{
   string ret="";
   ret=ltrim(s);
   ret=rtrim(ret);
   return ret;
}

string replicate(char c,int n) // Genera una cadena de caracteres compuesta por n caracteres c.
{
   string ret="";
   for(int i=0;i<n;i++)
   {
      ret+=c;
   }
   return ret;
}

string spaces(int n) // Genera una cadena de caracteres compuesta por n caracteres ' '
{
   string ret="";
   for(int i=0;i<n;i++)
   {
      ret+=' ';
   }
   return ret;
}

string lpad(string s,int n,char c) // genera con caracteres c hasta completar el espacio n a izquierda
{
   string ret="";
   int slength=length(s);
   ret=replicate(c,n-slength);
   ret+=s;

   return ret;
}

string rpad(string s,int n,char c) //genera con caracteres c hasta completar el espacio n a derecha
{
   string ret="";
   int slength=length(s);
   ret=s;
   ret+=replicate(c,n-slength);

   return ret;
}

string cpad(string s,int n,char c)
{
   string ret="";
   int slength=length(s);
   int add=n-slength;
   ret+=replicate(c,(add/2));
   ret+=s;
   if(add%2==1)
   {
      ret+=replicate(c,(add/2)+1);
   }
   else
   {
      ret+=replicate(c,(add/2));
   }

   return ret;
}

bool isDigit(char c)
{
   bool ret=false;
   if(48<=c && c<=57)
   {
      ret=true;
   }
   return ret;
}

bool isLetter(char c)
{
   bool ret=false;
   if((65<=c && c<=90) || (97<=c && c<=122))
   {
      ret=true;
   }
   return ret;
}

bool isUpperCase(char c)
{
   bool ret=false;
   if(65<=c && c<=90)
   {
      ret=true;
   }
   return ret;
}

bool isLowerCase(char c)
{
   bool ret=false;
   if(97<=c && c<=122)
   {
      ret=true;
   }
   return ret;
}

char toUpperCase(char c)
{
   char ret=c;
   if(97<=c && c<=122)
   {
      ret-=32;
   }
   return ret;
}

char toLowerCase(char c)
{
   char ret=c;
   if(65<=c && c<=90)
   {
      ret+=32;
   }
   return ret;
}
/*
string toUpperCase(string s)
{
   //no se por que no funciona slc

   int i=0;
   string ret="";
   while(s[i]!='\0')
   {
      ret+=toUpperCase(s[i]);
      i++;
   }
   return ret;*/
//}
/*
string toLowerCase(string s)
{
   //no se por que no funciona si lc
  */ /*int i=0;
   string ret="";
   while(s[i]!='\0')
   {
      ret+=toLowerCase(s[i]);
      i++;
   }
   return ret;*/
//}
int cmpString(string a,string b)
{
   int ret=1;
   if(a<b)
   {
      ret=-1;
   }
   else
   {
      if(a==b)
      {
         ret=0;
      }
   }
   return ret;
}

int cmpDouble(double a,double b)
{
   int ret=1;
   if(a<b)
   {
      ret=-1;
   }
   else
   {
      if(a==b)
      {
         ret=0;
      }
   }
   return ret;
}

#endif
