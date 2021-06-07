/*Codigo hecho por Daniel Alejandro Rodriguez 20172020009
* y Sebastian Salazar 20172020016
* clase : ciencias de la computación 1
* Universidad Distrital FJC
* 2020
*/
#ifndef LISTA_CDOBLE_H
#define LISTA_CDOBLE_H
#include <iostream>
#include <stdlib.h>
using namespace std;

template <class TIPOD>
struct nodo{
	TIPOD dato;
	struct nodo <TIPOD> *sig;
	struct nodo <TIPOD> *atr;
};


template <class TIPOD>
class Lista{
	private :
		nodo <TIPOD> *primero = NULL;
		nodo <TIPOD> *ultimo = NULL;
		int tam;
	public :		
		Lista();
		void insertar_nodo(TIPOD);
		void mostrar_lista_derecho();
		void mostrar_lista_reves();
		void buscar_nodo_der(TIPOD);
		void eliminar_nodo(TIPOD dato);
		int getTamanio();
		
};

template <class TIPOD>
Lista<TIPOD>::Lista(){
	cout<<"me construi\n";
}

template <class TIPOD>
void Lista<TIPOD>::insertar_nodo(TIPOD dato){
	nodo <TIPOD> *nuevo = new nodo<TIPOD>;
	nuevo->dato = dato;
	
	if(primero == NULL){
		primero = nuevo;
		primero->sig = primero;
		ultimo = primero;
		primero->atr = ultimo;
	}else{
		ultimo->sig = nuevo;
		nuevo->sig = primero;
		nuevo->atr = ultimo;
		ultimo = nuevo;
		primero->atr = ultimo;
	}
	cout<<"el nodo ha sido ingresado \n\n";
}

template <class TIPOD>
void Lista<TIPOD>::mostrar_lista_derecho(){
	nodo <TIPOD> *actual = new nodo <TIPOD>;
	actual = primero;
	
	if(primero!=NULL){
		do{
			cout<<"<-"<<actual->dato<<"->";
			actual = actual->sig;
		}while(actual != primero);
		cout<<"\n\n";
	}else cout<<"la lista se encuentra vacia\n\n";
}

template <class TIPOD>
void Lista<TIPOD>::mostrar_lista_reves(){
	nodo <TIPOD> *actual = new nodo<TIPOD>;
	actual = ultimo;
	
	if(ultimo!=NULL){
		do{
			cout<<"<-"<<actual->dato<<"->";
			actual = actual->atr;
		}while(actual != ultimo);
		cout<<"\n\n";
	}else cout<<"la lista se encuentra vacia\n\n";
}

template <class TIPOD>
void Lista<TIPOD>::buscar_nodo_der(TIPOD dato){
	nodo <TIPOD> *actual = new nodo<TIPOD>;
	actual = primero;
	bool encontrado = false;
	
	if(primero!=NULL){
		do{
			if(actual->dato == dato) encontrado = true; 		
			actual = actual->sig;
		}while(actual != primero && encontrado != true);
		if(encontrado) cout <<"El nodo "<< dato <<"  ha sido encontrado\n";
		else cout <<"El nodo NO ha sido encontrado\n";
		cout<<"\n\n";
	}else cout<<"la lista se encuentra vacia\n\n";
}

template <class TIPOD>
void Lista<TIPOD>::eliminar_nodo(TIPOD dato){
	nodo <TIPOD> *actual = new nodo<TIPOD>;
	actual = primero;
	nodo <TIPOD> *anterior = new nodo<TIPOD>;
	anterior = NULL;
	bool encontrado = false;
	
	if(primero!=NULL){
		do{
			if(actual->dato == dato) {
				encontrado = true;
				
				if(actual == primero){
					primero = primero->sig;
					primero->atr = ultimo;
					ultimo->sig = primero;
				}else if(actual == ultimo){
					ultimo = anterior;
					ultimo->sig = primero;
					primero->atr = ultimo;
				}else{
					anterior->sig = actual->sig;
					actual->sig->atr = anterior;
				}
					
			} 		
			anterior = actual;
			actual = actual->sig;
		}while(actual != primero && encontrado != true);
		if(encontrado) cout <<"El nodo "<< dato <<"  ha sido BORRADO\n";
		else cout <<"El nodo NO ha sido encontrado\n";
		cout<<"\n\n";
	}else cout<<"la lista se encuentra vacia\n\n";
}

template <class TIPOD>
int Lista<TIPOD>::getTamanio(){
	nodo <TIPOD> *actual = new nodo<TIPOD>;
	actual = primero;
	int cont = 0;
	do{
		cont++;
		actual = actual->sig;
	}while(actual != primero);
	tam = cont;
	return tam;
}
#endif
