/*----------------------------------------------------------------------------------------------------------------------------------" 
                                     REPRESENTACION DE UN ARBOL EN UN ARREGLO
										  SEBASTIAN SALAZAR - 2017202016
"-----------------------------------------------------------------------------------------------------------------------------------*/

#ifndef COLAP_H
#define COLAP_H

#include<iostream>
using namespace std;

template <class TIPO>
struct Colas{
	TIPO clave;
	char letra;
};

template <class TIPO>
class ColaP{
	Colas <TIPO> *cola;
	int tam, posActual;
	
	public:
		ColaP<TIPO>(int tamano){
			cola  = new Colas <TIPO> [tamano];
			int tam= tamano;
			posActual=0;
		}
		~ColaP<TIPO>(){
			delete cola;
		}
		void insertar(TIPO dato, char info);
		int atender();
		bool ColaLlena();
		bool ColaVacia();
		int TamanoCola();
		void imprimirColaP(); 
};

template <class TIPO>
void ColaP<TIPO>::insertar(TIPO dato, char info){
	if(ColaLlena()==false){
		posActual++;
		int padre = posActual/2;
		int hijo = posActual;
		int aux;
		char aux1;
		cola[posActual].clave = dato;
		cola[posActual].letra = info;
		while (padre!=0 && dato > cola[padre].clave){
			aux = cola[padre].clave;
			aux1 = cola[padre].letra;
			cola[padre].clave = cola[hijo].clave;
			cola[padre].letra = cola[hijo].letra;
			cola[hijo].clave = aux;
			cola[hijo].letra = aux1;
			hijo = padre;
			padre /= 2;
		}
		cout<<"Dato insertado en la Cola"<<endl;	
	}else{
		cout<<"La cola esta llena no se puede insertar otro elemento"<<endl;	
	}
}

template <class TIPO>
int ColaP<TIPO>::atender(){
	int atendido = cola[1].clave;

	cola[1].clave = cola[posActual].clave;
	posActual--;

	int pos = 1, aux, hijo1, hijo2, mayor;
	char auxletra;
	do{
		hijo1 = 2*pos;
		hijo2 = 2*pos+1;

		if(cola[hijo1].clave > cola[hijo2].clave){
			mayor = hijo1;
		}else{
			mayor = hijo2;
		}

		if(cola[pos].clave < cola[mayor].clave){
			aux = cola[pos].clave;
			auxletra = cola[pos].letra;
			cola[pos].clave = cola[mayor].clave;
			cola[pos].letra = cola[mayor].letra;
			cola[mayor].clave = aux; 
			cola[mayor].letra = auxletra;
		}

		pos = mayor;

	}while(hijo1 <= posActual || hijo2 <= posActual);

	return atendido; 
}

template <class TIPO>
bool ColaP<TIPO>::ColaLlena(){
	if(tam == posActual){
		return true;
	}else{
		return false;
	}
}

template <class TIPO>
bool ColaP<TIPO>::ColaVacia(){
	return (cola[1].clave==NULL);
}

template <class TIPO>
int ColaP<TIPO>::TamanoCola(){
	int aux;
	for (int i = 1; i <= posActual ; ++i){
		aux++;
	};
	return aux;
}

template <class TIPO>
void ColaP<TIPO>::imprimirColaP(){ 
	for (int i = 1; i <= posActual ; ++i){
		cout<<cola[i].clave<< " con letra: "<<cola[i].letra<<" "<<endl;
	};
	cout << endl;
}
#endif
