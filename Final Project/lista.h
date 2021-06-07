/*Codigo hecho por Daniel Alejandro Rodriguez 20172020009
* y Sebastian Salazar 20172020016
* clase : ciencias de la computación 1
* Universidad Distrital FJC
* 2020
*/
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <string>
using namespace std;

template <class TIPOD>
struct Nodo{
	TIPOD dato;
	Nodo <TIPOD> *siguiente;
};

template <class TIPOD>
class Lista{
	private :
		Nodo <TIPOD> *cab = NULL;
		int tam;
	public :		
		Lista();
		void insertarLista(TIPOD);
		void mostrarLista();
		bool buscarLista(TIPOD);
		void eliminarElementoLista(TIPOD);
		int getTamanio();
		
};

template <class TIPOD>
Lista<TIPOD>::Lista(){

}

template <class TIPOD>
void Lista<TIPOD>::insertarLista(TIPOD n){
	Nodo <TIPOD> *nuevo_nodo = new Nodo<TIPOD>;
	nuevo_nodo -> dato = n;
	
	Nodo <TIPOD> *aux1 = cab;
	Nodo <TIPOD>*aux2;
	
	//insterta los elementos en onrden
	while((aux1 != NULL) && (aux1 -> dato < n)){
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}
	
	if(cab == aux1){
		cab = nuevo_nodo;
	}
	else{
		aux2 -> siguiente =  nuevo_nodo;
	}
	
	nuevo_nodo -> siguiente = aux1;
	
	cout<<"\nProducto: "<< n <<" insertado correctamente"<<endl;
}

template <class TIPOD>
void Lista<TIPOD>::mostrarLista(){
	Nodo <TIPOD> *actual = new Nodo <TIPOD>;
	actual = cab;
	
	while(actual != NULL){
		cout <<actual->dato<<" ";
		actual = actual->siguiente;
	}cout<<" | ";
}

template <class TIPOD>
bool Lista<TIPOD>::buscarLista(TIPOD n){
	bool band = false;
	Nodo <TIPOD> *actual = new Nodo <TIPOD>;
	actual = cab;
	while((actual != NULL) && (actual -> dato <= n)) {
		if(actual -> dato == n)
			band = true;
		actual = actual->siguiente;
	}
	if(band == true)
		return true;
	else
		return false;
}

template <class TIPOD>
void Lista<TIPOD>::eliminarElementoLista(TIPOD n){
	if(cab != NULL){
		Nodo <TIPOD> *aux_borrar;
		Nodo <TIPOD> *anterior = NULL;
		
		aux_borrar = cab;
		
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if(aux_borrar == NULL)
			cout<<"el elemento no ha sido encontrado\n";
			
		else if(anterior == NULL){
			cab = cab->siguiente;
			delete aux_borrar;
			cout<<"el elemento "<<n<<" ha sido borrado\n";
		}
		
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
			cout<<"el elemento "<<n<<" ha sido borrado\n";
		}
	}
	else
		cout<<"la lista esta vacia \n";
}

template <class TIPOD>
int Lista<TIPOD>::getTamanio(){
	Nodo <TIPOD> *actual = new Nodo <TIPOD>;
	actual = cab;
	int cont = 0;
	while(actual != NULL){
		cont++;
		actual = actual->siguiente;
	}tam = cont;
	return tam;
}
#endif
