/*----------------------------------------------------------------------------------------------------------------------------------" 
                                     REPRESENTACION DE UN ARBOL EN UN ARREGLO
										  SEBASTIAN SALAZAR - 2017202016
"-----------------------------------------------------------------------------------------------------------------------------------*/

#ifndef ARBOLAR_H
#define ARBOLAR_H


#include"Libreria_Pila.h"

using namespace std;

template <class TIPO>
struct nodoR{
	TIPO clave;
	int izq, der;
};

template <class TIPO>
class Arbolar{
	int tam;
	nodoR <TIPO> *nodos;
	public:
		Arbolar<TIPO>(int tamano){
			tam= tamano+1;
			nodos  = new nodoR <TIPO> [tamano+1];
			for (int i=0; i<tam-1;i++){ //Se inicializa los elementos del arreglo
				nodos[i].izq=0;
				nodos[i].clave=0;
				nodos[i].der=i+1;
			}
			nodos[tam-1].izq = nodos[tam-1].der = nodos[tam-1].clave =0;
		}
		
		void insertar(TIPO dato);
		void eliminar(TIPO dato);
		void buscar(TIPO dato);
		int buscarPocision(TIPO dato);
		int buscarPadreEliminar(TIPO dato);
		bool lleno();
		void inOrden(); //---Puse este metodo solo para verificae que estuviera bien lo demas al imprimir los datos despues de insertar o eliminar
};

template <class TIPO>
void Arbolar<TIPO>::insertar(TIPO dato){
	int actual;	
	actual= nodos[0].der; //guardo en la variable actual la proxima pocision vacia del arreglo	
	if(lleno()){
		cout<<"El arreglo esta lleno"<<endl;		
	}else{
			int aux;			
			nodos[actual].clave= dato; //en la pocision vacia guardo el dato 
			aux= nodos[actual].der;
			nodos[actual].der=0; //como el nuevo dato no tiene hijos se pone 0 y 0 a ambos lados
			nodos[actual].izq=0;
			nodos[0].der=aux; //Al nodo 0 se le guarda la proxima pocision vacia
			
			int aux_act= 0;
			int aux_sig= nodos[0].izq;
			
			while(aux_sig !=0){
				aux_act= aux_sig;
				if (dato< nodos[aux_sig].clave){
					aux_sig= nodos[aux_sig].izq;
				}else{
					aux_sig= nodos[aux_sig].der;
				}
			}
			if(dato < nodos[aux_act].clave || aux_act == 0){
				nodos[aux_act].izq= actual;
			}else{
				nodos[aux_act].der= actual;
			}
	}
}

template <class TIPO>
void Arbolar<TIPO>::buscar(TIPO dato){
	int aux = nodos[0].izq;
	if(aux == 0){ 
		cout<<"No hay elementos que buscar en el arbol"<<endl;
	}else{
		if(dato == nodos[aux].clave){ //--Cuando el dato ingresado coincide con la raiz
			cout<<"Elemento Encontrado en el Arbol! : "<<nodos[aux].clave<<"\nEn la pocision numero: "<<aux<<endl;
		}else{		
		do{
			//---Cuando el elemento no esta en este arreglo
			if(nodos[aux].clave != dato && nodos[aux].der == 0 && nodos[aux].izq == 0) {
				cout<<"El elemento a buscar no se ha encontrado"<<endl;
				goto reinicio;
			}
			if(dato< nodos[aux].clave){
				aux = nodos[aux].izq;
			}else{
				aux= nodos[aux].der;
			}
		}while(dato!= nodos[aux].clave); 		
		cout<<"Elemento Encontrado en el Arbol! : "<<nodos[aux].clave<<"\nEn la pocision numero: "<<aux<<endl;
		reinicio:
		cout<<""<<endl;
		}
	}	
}

template <class TIPO>
int Arbolar<TIPO>::buscarPocision(TIPO dato){
	int aux = nodos[0].izq;
		do{
			//---Cuando el elemento no esta en este arreglo
			if(nodos[aux].clave != dato && nodos[aux].der == 0 && nodos[aux].izq == 0) {
				cout<<"El elemento a eliminar no se ha encontrado"<<endl;
				goto reinicio;
			}
			if(dato< nodos[aux].clave){
				aux = nodos[aux].izq;
			}else{
				aux= nodos[aux].der;
			}
		}while(dato!= nodos[aux].clave); 		
		return aux;
		reinicio:
		cout<<""<<endl;
}

template <class TIPO>
int Arbolar<TIPO>::buscarPadreEliminar(TIPO dato){
	int aux = nodos[0].izq;
	int aux1 = aux;
		do{
			aux1= aux;
			if(dato< nodos[aux].clave){
				aux = nodos[aux].izq;
			}else{
				aux= nodos[aux].der;
			}
		}while(dato!= nodos[aux].clave); 		
		return aux1;
}	
	
template <class TIPO>
void Arbolar<TIPO>::eliminar(TIPO dato){
	if(nodos[0].izq == 0){ 
		cout<<"No hay elementos que eliminar en el arbol"<<endl;
	}else{
		int numEliminar = buscarPocision(dato);	
		//---Cuando el nodo a eliminar no tiene hijos
		if(nodos[numEliminar].izq ==0 && nodos[numEliminar].der==0){
			int padreEliminar = buscarPadreEliminar(dato);
			if (nodos[numEliminar].clave < nodos[padreEliminar].clave){
				nodos[padreEliminar].izq = 0;
			}else{
				nodos[padreEliminar].der= 0;
			}
			nodos[numEliminar].clave=0;
			nodos[numEliminar].der = nodos[0].der;
			nodos[0].der= numEliminar;	
			cout<<"Nodo eliminado con exito!"<<endl;		
		}
		//---Cuando el nodo a eliminar tiene un solo hijo
		else if(nodos[numEliminar].izq != 0 && nodos[numEliminar].der == 0){
			int padreEliminar = buscarPadreEliminar(dato);
			if (nodos[numEliminar].clave < nodos[padreEliminar].clave){
				if(nodos[numEliminar].izq != 0){
					nodos[padreEliminar].izq=nodos[numEliminar].izq;
				}else{
					nodos[padreEliminar].izq=nodos[numEliminar].der;
				}
			}else{
				if(nodos[numEliminar].der != 0){
					nodos[padreEliminar].der=nodos[numEliminar].der;
				}else{
					nodos[padreEliminar].der=nodos[numEliminar].izq;
				}
			}
			nodos[numEliminar].clave=0;
			nodos[numEliminar].der= nodos[0].der;
			nodos[0].der= numEliminar;	
			cout<<"Nodo eliminado con exito!"<<endl;			
		}else if(nodos[numEliminar].izq == 0 && nodos[numEliminar].der != 0){
			int padreEliminar = buscarPadreEliminar(dato);
			if (nodos[numEliminar].clave < nodos[padreEliminar].clave){
				if(nodos[numEliminar].izq != 0){
					nodos[padreEliminar].izq=nodos[numEliminar].izq;
				}else{
					nodos[padreEliminar].izq=nodos[numEliminar].der;
				}
			}else{
				if(nodos[numEliminar].der != 0){
					nodos[padreEliminar].der=nodos[numEliminar].der;
				}else{
					nodos[padreEliminar].der=nodos[numEliminar].izq;
				}
			}
			nodos[numEliminar].clave=0;
			nodos[numEliminar].der= nodos[0].der;
			nodos[0].der= numEliminar;	
			cout<<"Nodo eliminado con exito!"<<endl;			
		}
		//---Cuando el nodo a eliminar tiene dos hijos
		else if(nodos[numEliminar].izq != 0 && nodos[numEliminar].der != 0){
			int padre_aux = numEliminar;
			int hijo_aux = nodos[numEliminar].der; //---Aplicando la eliminacion de derecha mas a la izquierda
			
			while(nodos[hijo_aux].izq != 0){
				padre_aux = hijo_aux;
				hijo_aux = nodos[hijo_aux].izq;
			}
			
			//--Criterio de lo hijos
			if (nodos[hijo_aux].der == 0 && nodos[hijo_aux].izq == 0){
				if(nodos[padre_aux].izq == hijo_aux){
					nodos[padre_aux].izq=0;
				}else{
					nodos[padre_aux].der=0;
				}
			}
			
			if(nodos[hijo_aux].der != 0){
				if(nodos[padre_aux].izq == hijo_aux){
					nodos[padre_aux].izq= nodos[hijo_aux].der;
				}else{
					nodos[padre_aux].der= nodos[hijo_aux].der;
				}
			}
			
			//---Se conecta el padre con su reemplazo
			int padre = buscarPadreEliminar(dato);
			if (nodos[padre].izq == numEliminar){
				nodos[padre].izq= hijo_aux;
			} else{
				nodos[padre].der= hijo_aux;
			}
			
			//---Remplazamos el nodo con los datos del nodo eliminado
			nodos[hijo_aux].izq=nodos[numEliminar].izq;
			nodos[hijo_aux].der=nodos[numEliminar].der;
			
			//---Por ultimo el nodo borrado pasa a la lista de pocisiones libres
			nodos[numEliminar].clave=0;
			nodos[numEliminar].der= nodos[0].der;
			nodos[0].der= numEliminar;	
			cout<<"Nodo eliminado con exito!"<<endl;
		}
	}	
}

template <class TIPO>
bool Arbolar<TIPO>::lleno(){
	return nodos[0].der == 0;
}

template <class TIPO>
void Arbolar<TIPO>::inOrden(){ 
	pila banco[1];
	int cont, pivot;
	
	cont = nodos[0].izq;
	pivot = cont;
	
	cout<<"IMPRESION POR IN-ORDEN: "<<endl;
	
	while(!banco[0].PilaVacia() || pivot!=0){
		
		//Se dirige hasta el fondo por izquierda en cada rama
		while(pivot!=0){
			banco[0].Push(pivot);
			pivot = nodos[pivot].izq;
		}	 
		pivot = banco[0].Pop();
		cout<<nodos[pivot].clave<<" ";
		//Se devuelve sobre el elemento impreso y por derecha se evalua
		//estando siempre al final de cada iteracion
		pivot = nodos[pivot].der;
	}
	cout<<endl; 
}
#endif
