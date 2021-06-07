/*
	
*/
#ifndef DOBLECOLA_H
#define DOBLECOLA_H
#include <iostream>
#include "Libreria_Pila.h"
#include "Libreria_Cola.h"
using namespace std;

struct posicion{
	int info;
	char nombre;
	int izq, der;	//Nodo predeterminada para la lista doble
};


class Binario
{
	int tam,uso; 
	posicion *arr;
	public: 
   	 		Binario(int init){
   	 			uso = 0;
				tam = init+1; 
   	 		    arr = new posicion[init+1];
   	 		    //Inicializando todos los elementos de nuestro arbol binario
   	 		for(int i=0;i<tam-1;i++){ 
   	 			arr[i].izq = arr[i].info = 0; 
   	 			arr[i].der = i+1;	
			}
				arr[tam-1].izq = arr[tam-1].der = arr[tam-1].info =0;
			}
			void insertar(int dato, char);
			void eliminar(int dato);
			void preOrden();
			void posOrden();
			void inOrden();
			void nivelOrden(); 
			void buscar(int dato);
	private: 
			void eliminarSinHijos(int pos, int padre);
			void eliminarUnHijo(int pos, int padre);
			void eliminarDosHijos(int pos, int padre);
			void agregarListaLibres(int pos); 
 };
 
void Binario::agregarListaLibres(int pos){
	//agregar a la lista de libres 
	arr[pos].der = arr[0].der; 
	arr[0].der = pos;
	//Eliminar informacion
	arr[pos].info = 0;
}
void Binario::eliminarUnHijo(int pos, int padre){
	int nietoPos;
	
	if(arr[pos].der == 0){
		nietoPos = arr[pos].izq;
	}
	else{
		nietoPos = arr[pos].der;
	}
	//Si es la Raiz, desconectamos a la raiz y la colocamos al hijo como Raiz
	if(padre == 0){
		arr[0].izq = nietoPos;
		arr[pos].izq = arr[pos].der = 0;
	}
	else{
		//Desconectar del padre y reconectar al abuelo
		if(arr[padre].izq == pos){
			arr[padre].izq = nietoPos;
		}
		else{
			arr[padre].der = nietoPos; 
		}	
	}
	agregarListaLibres(pos); 
} 
void Binario::eliminarSinHijos(int pos, int padre){
	//Si es la Raiz a quien vamos a eliminar, desconectamos solo la posicion de control
	if(padre == 0){
		arr[0].izq = 0;
	}
	else{
		//Desconectar del padre
		if(arr[padre].izq == pos){
			arr[padre].izq = 0;
		}
		else{
			arr[padre].der = 0; 
		}	
	}
	agregarListaLibres(pos);
}
void Binario::eliminarDosHijos(int pos, int padre){
	int padRem = pos; 
	int posRem = arr[pos].der;
	
	//El mas menor para reemplazarlo
	while(arr[posRem].izq !=0){
		padRem = posRem; 
		posRem = arr[posRem].izq;
	}
	
	//Si el que voy a cambiar es la raiz
	if(padre == 0){
		arr[0].izq = posRem;  
	}
	//Si no voy a cambiar la raiz
	else{
		//Padre ahora se conecta al que vamos a reemplazar 
		if(arr[padre].der == pos ){
			arr[padre].der = posRem; 
		}
		else{
			arr[padre].izq = posRem;  	
		}	
	}
	
	//Si el Reemplazado tiene hijo en izquierda se lo pasa al padre de el
	if(padRem!=pos){
		arr[padRem].izq = arr[posRem].izq; 
	}
	//Si el reemplazado tiene hijo por derecha se la pasa al padre de el
	if(arr[posRem].der != 0){
		arr[padRem].der = arr[posRem].der; 
	}
	//El reemplazo copia las direcciones de quien se va a eliminar
	arr[posRem].izq = arr[pos].izq; 
	arr[posRem].der = arr[pos].der;
	
	//Si el hijo se apunta a si mismo
	if(arr[posRem].der == posRem){
		arr[posRem].der = 0; 
	}
	
	//Desconectamos al eliminado		
	arr[pos].der = 0;
	arr[pos].izq = 0; 
	agregarListaLibres(pos);
}
void Binario::eliminar(int dato){
 
	int pos, padre = 0; 
	bool romp = false; 
	if(arr[0].izq == 0){ 
		cout<<"No hay elementos que eliminar en el arbol"<<endl;
	}
	else{
		posicion buscador = arr[arr[0].izq];	
		pos = arr[0].izq;
		while(!romp){
			//no esta en este arreglo
			if(buscador.info != dato && buscador.der == 0 && buscador.izq == 0) {
				romp = true;
				cout<<"El elemento a buscar no se ha encontrado"<<endl;
				return; 
			}
			else if(buscador.info < dato ){ 
				padre = pos; 
				pos = buscador.der;
				buscador = arr[buscador.der];  
			}
			else if(buscador.info > dato ){
				padre = pos; 
				pos = buscador.izq;
				buscador = arr[buscador.izq]; 		
			}
			//Se encuentra la posicion que estaba buscando
			else if(buscador.info == dato)
				romp = true;  
		}
		//No tiene hijos
		if(buscador.izq == 0 && buscador.der == 0){
			eliminarSinHijos(pos,padre);
			
		}
		//Tiene ambos hijos
		else if(buscador.izq != 0 && buscador.der != 0){
			eliminarDosHijos(pos,padre);
			//Lo eliminamos
			agregarListaLibres(pos);
			
		}
		//Solo tiene un hijo
		else{
			eliminarUnHijo(pos,padre); 
		}
		uso--;
		cout<<"ELiminacion Realizada"<<endl;

	}
}

void Binario::buscar(int dato){
	int pos;
	bool romp = false; 
	if(arr[0].izq == 0){ 
		cout<<"No hay elementos que buscar en el arbol"<<endl;
	}
	else{
		posicion buscador = arr[arr[0].izq];	
		pos = arr[0].izq;
		while(!romp){
			//no esta en este arreglo
			if(buscador.info != dato && buscador.der == 0 && buscador.izq == 0) {
				romp = true;
				cout<<"El elemento a buscar no se ha encontrado"<<endl;
				return;  
			}
			//Si es mayor el dato, el buscador se dirige a la derecha
			else if(buscador.info < dato ){ 
				pos = buscador.der;
				buscador = arr[buscador.der];  
			}
			//Si es menor el dato, el buscador se dirige a la izquierda
			else if(buscador.info > dato ){
				pos = buscador.izq;
				buscador = arr[buscador.izq]; 		
			}
			//Se encuentra satisfactoriamente 
			else if(buscador.info == dato)
				romp = true;  
		}
	}
	cout<<"Elemento Encontrado en el Arbol! : "<<arr[pos].info<<endl;
	cout<<"con nombre : "<<arr[pos].nombre<<endl;
}
void Binario::preOrden(){
	
    pila banco[1];
    int pos = arr[0].izq;
	int pivot = pos;
	
    banco[0].Push(pivot);
    
    cout<<"IMPRESION POR PREORDEN: "<<endl;
    
    while(!banco[0].PilaVacia()){
		pivot = banco[0].Pop();
		cout << arr[pivot].info << " ";
		if(arr[pivot].der != 0){
			banco[0].Push(arr[pivot].der);
		}
		if(arr[pivot].izq != 0){
			banco[0].Push(arr[pivot].izq);
		} 
	}
    
    cout<<endl; 
}
void Binario::posOrden(){
	
	/*
		La primer pila guarda los elementos del arbol
		La segunda pila organiza los elementos en PosOrden a medida que se evalua la primer pila
	*/
	pila bancos[2];
	
	int pos = arr[0].izq;
	int pivot = pos; 
	
	//Como es Posorden, el primer elemento, el del fondo, debe ir en la primer posicion
	bancos[0].Push(pos);
	
	cout<<"IMPRESION POR POSORDEN: "<<endl;
	while(!bancos[0].PilaVacia()){
		
		pivot = bancos[0].Pop();
		bancos[1].Push(pivot);
		
		//Se inserta siempre la izquierda primero para concordar con el criterio PosOrden
		if(arr[pivot].izq != 0){
			bancos[0].Push(arr[pivot].izq);
		}
		if(arr[pivot].der != 0){ 
			bancos[0].Push(arr[pivot].der);
		}
	}
	
	while(!bancos[1].PilaVacia()){
		cout << arr[bancos[1].Pop()].info << " ";
	}
	cout<<endl;
}
void Binario::nivelOrden(){
	
	cola banco[1];
    int pos = arr[0].izq;
    
    cout<<"IMPRESION POR NIVELES: "<<endl;
    cout<<arr[pos].info<<" ";
    
    //Se empiezan por los elementos de la raiz
    if(arr[pos].izq!=0)
    	banco[0].InsCola(arr[pos].izq);
    if(arr[pos].der!=0)
		banco[0].InsCola(arr[pos].der);
    
    
    while(!banco[0].ColaVacia()){
		//A medida que existan elementos lo imprimira en orden izquierda - derecha		
		pos = banco[0].AtenderCola();
        cout<<arr[pos].info<<" ";
		        
		//El criterio de salida en el ciclo es la ausencia de mas elementos por imprimir 
		//(no hay elementos por izquierda o derecha en los nodos)
        if(arr[pos].izq != 0){
            banco[0].InsCola(arr[pos].izq);
        }
        if(arr[pos].der != 0){
            banco[0].InsCola(arr[pos].der);
        }
    } 
    cout<<endl;
}
void Binario::inOrden(){ 

	pila banco[1];
	int cont, pivot;
	
	cont = arr[0].izq;
	pivot = cont;
	
	cout<<"IMPRESION POR INORDEN: "<<endl;
	
	while(!banco[0].PilaVacia() || pivot!=0){
		
		//Se dirige hasta el fondo por izquierda en cada rama
		while(pivot!=0){
			banco[0].Push(pivot);
			pivot = arr[pivot].izq;
		}
		 
		pivot = banco[0].Pop();
		cout<<arr[pivot].info<<" ";
		//Se devuelve sobre el elemento impreso y por derecha se evalua
		//estando siempre al final de cada iteracion
		pivot = arr[pivot].der;
	}
	cout<<endl; 
}
void Binario::insertar(int dato, char nombre){ 

	int pos;
	bool romp = false;
	bool igual =false; 
	if(arr[0].der == 0){ 
		cout<<"La memoria ya esta llena"<<endl;
	}
	else{		
		//Si no hay raiz
		if(arr[0].izq == 0){
			int sig = arr[arr[0].der].der; 
			arr[0].izq = arr[0].der; 
			arr[arr[0].der].info = dato;
			arr[arr[0].der].der = arr[arr[0].der].izq = 0 ;
			arr[0].der = sig;  
		} 
		//Si ya tenemos raiz 
		else{
			//Busca desde raiz 
			posicion buscador = arr[arr[0].izq];
			pos = arr[0].izq;
			while(!romp){
				if(buscador.info < dato && buscador.der == 0){
					//le meto el libre al siguiente por izquierda del nodo asignado 
					buscador.der = arr[0].der;
					arr[pos] = buscador;
					int nuevo = arr[0].der;
					//corremos el siguiente nodo a insertar
					arr[0].der = arr[nuevo].der;  
					//asignamos el nuevo espacio con su informacion
					arr[nuevo].info = dato;
					arr[nuevo].nombre = nombre;
					arr[nuevo].izq = arr[nuevo].der = 0;   
					romp = true;
				}
				else if(buscador.info < dato ){ 
					pos = buscador.der;
					buscador = arr[buscador.der];  
				}
				else if(buscador.info > dato && buscador.izq == 0){
					//le meto el libre al siguiente por derecha del nodo asignado 
					buscador.izq = arr[0].der;
					arr[pos] = buscador;
					int nuevo = arr[0].der;
					//corremos el siguiente nodo a insertar
					arr[0].der = arr[nuevo].der;  
					//asignamos el nuevo espacio con su informacion
					arr[nuevo].info = dato;
					arr[nuevo].nombre = nombre;
					arr[nuevo].izq = arr[nuevo].der = 0;   
					romp = true; 
				}
				else if(buscador.info > dato ){ 
					pos = buscador.izq;
					buscador = arr[buscador.izq]; 		
				}
				else if(buscador.info == dato){
					cout<<"Numero Ingresado Previamente"<<endl; 
					romp = igual = true;
				}
			}
		}
		if(!igual){
			uso++;
			cout<<"Numero ingresado con exito"<<endl;
		}
			
	}
}

#endif
