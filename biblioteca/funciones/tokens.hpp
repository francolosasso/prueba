#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   int i;
   int contador = 1;

   if(s == ""){
      return 0;
   }else{
   for( i = 0 ; s[i] != '\0';i++){
        if(s[i] == sep){
              contador++;
        }
     }
   }
   return contador;
}

void addToken(string& s,char sep,string t)
{
   //string resultado = "";
   if(s == ""){
      s = s + t;
   }else{
   s = s + sep + t;
   }
   //cout << resultado << endl;
}

string getTokenAt(string s,char sep, int i)
{
   int z = 0;
   int contadora = 0;
   string resultado = "";

   while(s[z] != '\0'){
      if(s[z] == sep){
               contadora++;
            }
      if(contadora == i && s[z] != '|'){
      resultado = resultado + s[z];
      }

      z++;
   }

   return resultado;
}

void removeTokenAt(string& s,char sep, int i)
{
  /* int sep1=indexOfN(s,sep,i);
     int sep2=indexOfN(s,sep,i+1);
     string newS="";
     if(i == 0){
        newS+=substring(s,0,sep1);
             newS+=substring(s,sep2+1);
             //con ese mas uno se sale los palitos
             s=newS;
     }else if(tokenCount(s-1, sep) == i){
        newS+=substring(s,0,sep1);
             newS+='|';
             newS+=substring(s,sep2);
     }
     else{

     newS+=substring(s,0,sep1);
     newS+='|';
     newS+=substring(s,sep2+1);
     //con ese mas uno se sale los palitos
     s=newS;}*/

   //como lo habiamos hecho pero no funcionó
   /*int sep1=indexOfN(s,sep,i);
      int sep2=indexOfN(s,sep,i+1);
      string newS="";
      if(i==0)
      {
         newS+=substring(s,sep2+1);
      }
      else
      {
         newS+=substring(s,0,sep1);
         newS+=substring(s,sep2);
      }
      s=newS;*/

   int j=0;
     int contador=0;
     while(j<length(s)){
        if (s[j]==sep){
           contador++;
        }
        if (contador==i){
           do {
              s=removeAt(s,j);
           }while(s[j]!=sep && j<length(s));
           contador++;
        }
        j++;
     }
     if(startsWith(s,"|")){
        s=removeAt(s,0);
     }
}

void setTokenAt(string& s,char sep, string t,int i)
// Reemplaza por t el token de s ubicado en la posición i.
{
   //if(i == 0){

   //}else{
   int sep1=indexOfN(s,sep,i);
   int sep2=indexOfN(s,sep,i+1);
   string newS="";
   newS+=substring(s,0,sep1+1);
   newS+=t;
   newS+=substring(s,sep2);
   s=newS;
   //}

}


int findToken(string s,char sep, string t)
{
   int cantToken=tokenCount(s,sep);
   int pos=0;
   for(int i=0;i<cantToken;i++)
   {
      if(getTokenAt(s,sep,i)==t)
      {
         pos=i;
         i=cantToken;
      }
   }
   return pos;
}

#endif
