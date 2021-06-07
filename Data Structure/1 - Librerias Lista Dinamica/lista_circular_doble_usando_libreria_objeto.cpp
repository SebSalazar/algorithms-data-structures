/*Codigo hecho por Daniel Alejandro Rodriguez 20172020009
* y Sebastian Salazar 20172020016
* clase : ciencias de la computación 1
* Universidad Distrital FJC
* 2020
*/
#include <iostream>
#include <stdlib.h>
#include "libreria_lista_circular_doble_objeto.h"
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
		cout<<"\t\t DEMOSTRACION LISTA CIRCULAR DOBLEMENTE ENLAZADA"<<endl;
		cout<<"1. Insertar dato"<<endl;
		cout<<"2. Mostrar lista al derecho"<<endl;
		cout<<"3. Mostrar lista al reves"<<endl;
		cout<<"4. Buscar nodo al derecho"<<endl;
		cout<<"5. Eliminar nodo"<<endl;
		cout<<"6. Mostrar tamanio lista"<<endl;
		cout<<"7. Salir"<<endl;
		cout<<"Digite su opcion: ";
		cin>>opcion;
		
		switch(opcion){
			int dato;
			case 1: cout<<"Digite el numero que desea ingresar: ";
					cin>>dato;
					lista.insertar_nodo(dato);
					system("pause");
					break;
			
			case 2: cout<<"\t Mostrando lista"<<endl;
					lista.mostrar_lista_derecho();
					system("pause");
					break;
			
			case 3: cout<<"\t Mostrando lista al reves"<<endl;
					lista.mostrar_lista_reves();
					system("pause");
					break;
			
			case 4: cout<<"Digite el nodo a buscar : ";
					cin>>dato;
					lista.buscar_nodo_der(dato);
					system("pause");
					break;
					
			case 5: cout<<"Digite el nodo a eliminar : ";
					cin>>dato;
					lista.eliminar_nodo(dato);
					system("pause");
					break;			
			
			case 6: dato = lista.getTamanio();
					cout << "El tamanio es: "<<dato<<"\n";
					system("pause");
					break; 
		}system("cls");
	}while(opcion != 7);
	cout<<"bye bye"<<endl;
}
