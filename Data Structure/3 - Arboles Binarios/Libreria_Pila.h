/*
	Tomado de la plataforma UDIN Ciencias de la Computación - Luz Deicy Alvarado Nieto
*/
#ifndef PILA_H     
#define PILA_H    
#include "Estructura.h"

class pila
	{
	  nodo *cab;
      public: pila(){
	  				 cab= new nodo;
                     cab->dato=0;
                     cab->sig=NULL;
					 }
             void Push( int v);
             int Pop();
             bool PilaVacia();
             ~pila();
      };
     
void pila::Push(int v){
     nodo *t = new nodo;
     t->dato=v; 
     t->sig=cab->sig;
     cab->sig= t;
}

int pila::Pop(){
     int x;
     nodo *t= cab->sig;
     cab->sig= t->sig; 
     x = t->dato;
     delete t;
     return x;
}

bool pila::PilaVacia(){
      return cab->sig== NULL;
}

pila::~pila(){
      nodo *t=cab;
     while (t!=NULL){
           cab=t;
           t=t->sig;
           delete cab;
           }
}
 
     
#endif

