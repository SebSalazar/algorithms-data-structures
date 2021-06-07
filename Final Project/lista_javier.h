#ifndef lista_H
#define lista_H

using namespace std;

template<class T>
struct nodo{
	nodo<T> *sig;
	T info;
	
};

template<class T>
class lista{
	nodo<T> *cab;
	int tam;
	void insertarFinal(nodo<T> *nuevo);
	void insertarInicio(nodo<T> *nuevo);
			
	public:
		lista(){ 
			tam=0; 
			cab=NULL;
		}
		~lista();
		bool lista_vacia();
		int tamLista();
		void insertar(T infonueva,int pos);	
		bool eliminar(int pos);
		bool buscar(T dato);
		T getDato(int pos);	
};

template<class T>

bool lista<T> :: lista_vacia(){
	if(tam==0)
		return true;
	else 
		return false;
}

template<class T>

int lista<T> :: tamLista(){
	return tam;
}

template<class T>

void lista<T> :: insertarInicio(nodo<T> *nuevo){
	nuevo->sig=cab;
	cab=nuevo;
}

template<class T>

void lista<T> :: insertarFinal(nodo<T> *nuevo){
	nodo<T> *aux = cab;
	for(int i=1;i<tam;i++)
		aux = aux->sig;
	aux->sig=nuevo;
}

template<class T>

void lista<T> :: insertar(T infNueva,int pos){
	nodo<T> *nuevo = new nodo<T>; 
	nodo<T> *aux; 
	nuevo->info = infNueva;
	nuevo->sig = NULL;
	
	if(pos>tam && pos!=1 && tam!=0)
		insertarFinal(nuevo);
	else if(pos==1 || tam==0)
		insertarInicio(nuevo);	
	else{
		aux = cab;
		for(int i=1;i<pos-1;i++)
			aux = aux->sig;
		nuevo->sig = aux->sig;
		aux->sig = nuevo;
	}
	tam++;
}

template<class T>

bool lista<T> :: eliminar(int pos){
	if (pos<=tam && pos>0){
		nodo<T> *aux = cab;
		tam--;
		if(pos==1){
			cab = cab->sig;
			return true;
		} else{
			nodo<T> *aux2;
			for(int i=1;i<pos-1;i++)
				aux = aux->sig;
			aux2 = aux->sig;
			aux->sig = aux2->sig;
			return true;
		}
	}
	return false;
}

template<class T>

bool lista<T> :: buscar(T dato){
	nodo<T> *aux = cab;
	for(int i=1;i<=tam;i++){
		if(aux->info==dato)
			return true;
		aux = aux->sig;	
	}
	return false;	
}

template<class T>

T lista<T> :: getDato(int pos){
	nodo<T> *aux = cab;
	for(int i=1;i<pos;i++)
		aux = aux->sig;
	return aux->info;	
}

template<class T>

lista<T>::~lista(){
}

#endif
