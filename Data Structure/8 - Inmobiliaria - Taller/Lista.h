
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Estructura.h"
using namespace std;


class Lista{
	private :
		int tam;
	public :	
		Nodo  *cab = NULL;	
		Lista();
		void insertarLista(Nodo n);
		void mostrarLista();
		bool buscarLista(Nodo n);
		void eliminarElementoLista(Nodo n);
		int getTamanio();
		
};

Lista::Lista(){
	cout<<"me construi\n";
}


void Lista::insertarLista(Nodo n){
	Nodo  *nuevo_nodo = new  Nodo;
	nuevo_nodo->codigo= n.codigo;
	nuevo_nodo->localidad= n.localidad;
	nuevo_nodo->via= n.via;
	nuevo_nodo->tipo= n.tipo;
	nuevo_nodo->estrato= n.estrato;
	nuevo_nodo->valor= n.valor;
	
	Nodo  *aux1 = cab;
	Nodo  *aux2;
	
	//insterta los elementos en onrden
	while((aux1 != NULL) && (aux1->codigo < n.codigo)){
		aux2 = aux1;
		aux1 = aux1->sig;
	}
	
	if(cab == aux1){
		cab = nuevo_nodo;
	}
	else{
		aux2->sig =  nuevo_nodo;
	}
	
	nuevo_nodo->sig  = aux1;
	
	cout<<"\telemento "<< n.codigo <<" insertado correctamente\n";
}


void Lista::mostrarLista(){
	Nodo  *actual = new Nodo ;
	actual = cab;
	
	while(actual != NULL){
		cout <<actual->codigo<<" -> "<< actual->localidad<<" -> " <<actual->tipo<< " -> "<<actual->via<<" -> "<<actual->valor<<" -> "<<actual->estrato<<" ->\n";
		actual = actual->sig;
	}cout<<"\n\n";
}


bool Lista::buscarLista(Nodo n){
	bool band = false;
	Nodo  *actual = new Nodo ;
	actual = cab;
	while((actual != NULL) && (actual -> codigo <= n.codigo)) {
		if(actual -> codigo == n.codigo)
			band = true;
		actual = actual->sig;
	}
	if(band == true){
		cout<<"El elemento : " << n.codigo << " SI ha sido encontrado \n";
		return true;
	}
		
	else{
		cout<<"El elemento : " << n.codigo << " NO ha sido encontrado \n";
		return false;
	}
		
}


void Lista::eliminarElementoLista(Nodo n){
	if(cab != NULL){
		Nodo  *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = cab;
		
		while((aux_borrar != NULL) && (aux_borrar->codigo != n.codigo)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sig;
		}
		
		if(aux_borrar == NULL)
			cout<<"el elemento no ha sido encontrado\n";
			
		else if(anterior == NULL){
			cab = cab->sig;
			delete aux_borrar;
			cout<<"el elemento "<<n.codigo<<" ha sido borrado\n";
		}
		
		else{
			anterior->sig = aux_borrar->sig;
			delete aux_borrar;
			cout<<"el elemento "<<n.codigo<<" ha sido borrado\n";
		}
	}
	else
		cout<<"la lista esta vacia \n";
}


int Lista::getTamanio(){
	Nodo  *actual = new Nodo ;
	actual = cab;
	int cont = 0;
	while(actual != NULL){
		cont++;
		actual = actual->sig;
	}tam = cont;
	return tam;
}
#endif
