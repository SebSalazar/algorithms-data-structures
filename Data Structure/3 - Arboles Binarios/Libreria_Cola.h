
#include <cstdlib>
#include <iostream>
#include "estructura.h"

#ifndef COLA_H     
#define COLA_H 

using namespace std;

class cola{
		nodo *cab,*fin;
      public: cola(){cab=fin=NULL;}
      void InsCola(int i);
      int AtenderCola();
      void ImprimirCola();
      bool ColaVacia();
      ~cola();
 };

void cola::InsCola(int i){
     nodo *nuevo;
     nuevo= new nodo;
     nuevo->dato=i;
     nuevo->sig= NULL;
     if (cab==NULL)
         {cab=nuevo;}
     else {fin->sig = nuevo;}
     fin=nuevo;
}



int cola::AtenderCola()
{   int x;
    nodo *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
    }

void cola::ImprimirCola(){
     nodo *aux;
     aux=cab;
     while(aux!=NULL){
       cout<<aux->dato<<" ";
       aux=aux->sig;}    
}

bool cola::ColaVacia(){
     return (cab==NULL);
     }

cola::~cola(){
     nodo *aux;
     while(cab!=NULL)
       {aux= cab;
        cab=aux->sig;
        delete aux;}
     delete cab;
     }

#endif
 


