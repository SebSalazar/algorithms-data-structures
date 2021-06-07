/*Codigo hecho por Daniel Alejandro Rodriguez 20172020009
* y Sebastian Salazar 20172020016
* clase : ciencias de la computación 1
* Universidad Distrital FJC
* 2020
*/
#include <iostream>
#include <stdlib.h>
#include "libreria_lista_enlazada_objeto.h"
using namespace std;


//prototipo de funciones
template<class TIPOD>
void menu(Lista<TIPOD>, TIPOD dato);


int main(){
	int opcion;
	cout<<"Digite si quiere trabajar con: ";
	cout<<"1.Int\t\t2.char\t\t3.float\n";
	cout<<"respuesta: ";
	cin>>opcion;
	
	if(opcion==1){
		Lista <int>lista = Lista<int>();
		int dato;
		menu(lista, dato);
	}
	else if(opcion==2){
		Lista <char>lista = Lista<char>();
		char dato;
		menu(lista, dato);
	}
	else if(opcion==3){
		Lista <float>lista = Lista<float>();
		float dato;
		menu(lista, dato);
	}
	else cout<<"opcion no valida"<<endl;
	return 0;
}

template<class TIPOD>
void menu(Lista <TIPOD>lista, TIPOD dato){
	int opcion;
	do{
		cout<<"\t MENU \n";
		cout<<"1. Insertar elementos en la lista \n";
		cout<<"2. Mostrar elementos de la lista \n";
		cout<<"3. Buscar un elemento \n";
		cout<<"4. Eliminar un elemento \n";
		cout<<"5. Mostrar tamanio lista \n";
		cout<<"6. Salir";
		cout<<"\n\nDigite su opcion : ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\n Digite un numero : ";
					cin>> dato;
					lista.insertarLista(dato);
					system("pause");
					break;
					
			case 2: lista.mostrarLista();
					cout<<"\n";
					system("pause");
					break;
					
			case 3: 
					cout<<"Digite el elemento a buscar : ";
					cin>> dato;
					lista.buscarLista(dato);
					system("pause");
					break;
					
			case 4:	cout<<"Digite el elemento a borrar : ";
					cin>>dato;
					lista.eliminarElementoLista(dato);
					system("pause");
					break;	
			
			case 5: dato = lista.getTamanio();
					cout << "El tamanio es: "<<dato<<"\n";
					system("pause");
					break;
			
		}
		system("cls");
	}while(opcion != 6);
	cout<<"bye bye";
}

