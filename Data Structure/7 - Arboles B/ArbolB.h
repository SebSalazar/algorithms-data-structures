#ifndef ARBOLB_H
#define ARBOLB_H
#include <iostream>

using namespace std;

struct nodo{
	int *claves;
    nodo **hijos;
    int Nclaves;
    bool hoja;
};
     	         	     
class arbolB {
	private:
		nodo * raiz;
		int d;
	public:
		arbolB(int ord){ d= ord;
		raiz=crear_nodo();
		raiz->Nclaves=0; raiz-> hoja = true;}
		nodo *crear_nodo();
		nodo *get_raiz ();
		int  dividir_nodo(nodo *actual, nodo **hermano);
		void insertar(int clave);
		nodo* buscar_nodo(int clave, nodo *Actual, nodo **padre);
		int InsertarNodoNormal(int clave, nodo *Actual);
		void InsertarNodoLleno(int clave, nodo *Actual, nodo *padre);
		nodo * buscar_padre (int clave, nodo *Actual, nodo *padre);
		int borrar(int clave);
		int buscar_clave(int clave, nodo *actual, nodo **padre);
		int borrarEn_hoja(int clave, int pos, nodo * actual, nodo * padre);
		void Ajustar_nodo(int pos,nodo * actual);
		int buscar_lugarEntreHnos(int clave, nodo* padre);
		bool Ayuda_hnoDer(nodo *padre, int posActual);
		bool Ayuda_hnoIzq(nodo *padre, int posActual);
		void juntar(nodo *padre, int pos, int posActual);
		void reemplazar_Der(nodo *actual, nodo *padre, int posActual);
		void reemplazar_Izq(nodo *actual, nodo *padre, int posActual);
		void unir_Hno_Der(nodo *padre, int posClave, int posActual);
		void unir_Hno_Izq(nodo *padre, int posClave, int posActual);
		void AjustarNivelPadre(nodo *actual, int posclave);
		int borrarEn_Ninterno(int pos,nodo* actual);
		bool verificar_der(nodo *hijo, nodo*padre);
		bool verificar_izq(nodo *hijo, nodo*padre);
		void imprimir(nodo *nodo);
};

nodo *arbolB::crear_nodo(){
	nodo * nuevo;
	nuevo = new nodo;
  	nuevo -> claves= new int[2*d-1];
  	nuevo->hijos = new nodo* [2*d];
    nuevo->Nclaves=0;
  	nuevo->hoja=true;
  	return nuevo;
}

nodo *arbolB::get_raiz (){
	return raiz;
}

void arbolB::insertar(int clave){
	nodo * padre= NULL, *Actual=raiz;
  	Actual=buscar_nodo(clave, Actual, &padre);
   	if (Actual->Nclaves<2*d-1){
   		InsertarNodoNormal(clave, Actual);
		imprimir(Actual);
	   }
		
   	else{
   		InsertarNodoLleno(clave, Actual, padre);
		imprimir(Actual);
	   }		
	std::cout<<"Nodo: "<<clave<<" ha sido ingresado!\n";
}

nodo * arbolB:: buscar_nodo(int clave, nodo *Actual, nodo **padre){
 	int i=0;
 	while((i < Actual ->Nclaves) && clave> Actual->claves[i]) i++;
 	if (Actual ->hoja){
		if (Actual==raiz)
			*padre=NULL;
 		return Actual;
	}else{
		*padre= Actual;
 		Actual= Actual ->hijos[i];
		return buscar_nodo(clave, Actual, padre);
	}
}

int arbolB::InsertarNodoNormal(int clave, nodo *Actual){
	int i, j;
  	i=Actual->Nclaves;
  	while((i-1)>=0 && clave< Actual->claves[i-1]){
	  	Actual->claves[i]=Actual->claves[i-1];
 		if (!Actual->hoja) //si el nodo no es una hoja
		Actual->hijos[i+1]=Actual->hijos[i];
		i--;
	}
  	Actual->claves[i]=clave;
  	(Actual->Nclaves)++;
	return i;
}

void arbolB:: InsertarNodoLleno( int clave, nodo *Actual, nodo *padre){
	int pos, sube;
  	nodo *nuevo, * nivelad=NULL;
  	sube = dividir_nodo(Actual, &nuevo);
  	if(clave < sube)
		InsertarNodoNormal(clave, Actual);
	else	
		InsertarNodoNormal(clave, nuevo);
	 if(Actual != raiz && padre->Nclaves< 2*d-1){
	 	pos= InsertarNodoNormal(sube, padre);
		padre->hijos[pos]=Actual;
	 	padre->hijos[pos+1]=nuevo;}
	 else{
	 	if (Actual==raiz){
		 	nivelad=crear_nodo();
		 	nivelad->hoja = false;
			nivelad->Nclaves=1;
			nivelad->hijos[0]= Actual;
		 	nivelad->hijos[1]=nuevo;
	}else{
		nivelad=buscar_padre(padre->claves[0], padre, nivelad);
		InsertarNodoLleno(padre->claves[d-1], padre, nivelad);}
	}
	imprimir(Actual);
}

int arbolB::dividir_nodo(nodo *actual, nodo **hermano){
	int i;
  	nodo *nuevo=crear_nodo();
  	nuevo->hoja=actual->hoja;
  	for(i=0; i<d-1; i++)
		nuevo->claves[i]=actual->claves[i+d];
  	if(!actual->hoja)
		for (i=0; i<d; i++)
			nuevo->hijos[i]=actual->hijos[i+d];
  	nuevo->Nclaves=actual->Nclaves=d-1;
  	*hermano=nuevo;
  	return actual->claves[d-1];
}

nodo *arbolB:: buscar_padre (int clave, nodo *Actual, nodo *padre){
	int i =1;
	if(clave== Actual->claves[0])
   		return padre;
			      else {while(i<Actual->Nclaves && clave > Actual->claves[i]) i++;
				   padre=Actual;
				   Actual= Actual -> hijos[i];
				   return buscar_padre(clave, Actual, padre);}
				}



int arbolB::borrar(int clave){
	int pos;
 	nodo *actual=raiz, *padre=NULL;
 	pos= buscar_clave(clave, actual, &padre);
 	if (pos >-1) if(actual->hoja)
	return borrarEn_hoja(clave, pos, actual, padre); 
 	else return borrarEn_Ninterno(pos, actual);
 	else return 0XFFFF;
}

int arbolB::buscar_clave(int clave, nodo *actual, nodo **padre){
	int i=0;
  	while(i<actual->Nclaves && clave>actual->claves[i]) i++;
   	if (actual->claves[i]==clave) return i;
		else {if (actual->hoja) return -1;
			else	{*padre=actual;
				actual= actual->hijos[i];
				return buscar_clave(clave, actual, padre);}
			}
}

int arbolB::borrarEn_hoja(int clave, int pos, nodo * actual, nodo * padre){
	int posAct, dato;
	  nodo *hnoDer, *hnoIzq;
	  bool izq, der;
	  dato=actual->claves[pos]; 
	  Ajustar_nodo(pos, actual);
	  if (actual != raiz && actual->Nclaves < d-1 ){
	  	posAct = buscar_lugarEntreHnos(actual->claves[0], padre);
		der=Ayuda_hnoDer(padre, posAct);
	if (!der){
		izq=Ayuda_hnoIzq(padre, posAct);
	if (!izq) 
		juntar(padre, pos, posAct);
	else 
		reemplazar_Der(actual, padre, posAct);}
	else 
		reemplazar_Izq(actual, padre, posAct);
	}
	return dato;
}	

void arbolB::Ajustar_nodo(int pos, nodo *actual){
	while(pos+1 < actual->Nclaves){
	actual->claves[pos]= actual->claves[pos+1];
 	pos++;}
 	actual->Nclaves--;
}

int arbolB::buscar_lugarEntreHnos(int clave, nodo* padre){
	int pos=0;
 	while (pos < padre->Nclaves && clave > padre->claves[pos]) pos++;
	return pos;
}

bool arbolB::Ayuda_hnoDer(nodo *padre, int posActual){
	nodo *hermano;
  	if (posActual < padre->Nclaves){
	  hermano= padre->hijos[posActual+1];
 	if (hermano-> Nclaves >= d)
		return true;}
  	return false;
}


void arbolB:: reemplazar_Izq(nodo *actual, nodo *padre, int posActual){ 
	nodo *hno= padre->hijos[posActual+1];
	actual->claves[actual->Nclaves]=padre->claves[posActual];
	actual->Nclaves++;
	padre->claves[posActual]= hno ->claves[0];
	if (!actual->hoja)
	{actual->hijos[actual->Nclaves]=hno->hijos[0];
	 int i=0;
	while (i<hno->Nclaves)
			{hno->hijos[i]=hno->hijos[i+1];
	i++;}
	imprimir(hno);
}
				}
bool arbolB::Ayuda_hnoIzq(nodo *padre, int posActual){
	nodo *hermano;
	  if (posActual > 0)
	{hermano= padre->hijos[posActual-1];
	 if (hermano-> Nclaves >= d)
	return true;}
	return false;
	imprimir(hermano);
}
			

void arbolB:: reemplazar_Der(nodo *actual, nodo *padre, int posActual){
	int i=actual->Nclaves;
	 nodo *hno= padre->hijos[posActual-1];
	while(i> 0) //se abre espacio
	{actual->claves[i]=actual->claves[i-1];
	 i--;}
	actual->claves[0]=padre->claves[posActual-1];
	padre->claves[posActual-1]= hno ->claves[hno->Nclaves-1];
	actual->Nclaves++;
	if(!actual->hoja) actual->hijos[0]=hno->hijos[hno->Nclaves];
	(hno->Nclaves)--;
	imprimir(hno);
}

void arbolB:: juntar(nodo *padre, int pos, int posActual){
	nodo *actual;
	actual = padre->hijos[posActual];
	if (pos >=actual->Nclaves/2 && posActual < padre->Nclaves)
	unir_Hno_Der(padre, pos, posActual);
	else  unir_Hno_Izq(padre, pos, posActual);
	if (padre==raiz && padre->Nclaves==0) raiz=actual;
}

void arbolB:: unir_Hno_Der(nodo *padre, int posClave, int posActual){
	nodo *hno, *actual=padre->hijos[posActual];
	 int i, j=0;
	 actual->claves[posClave]= padre->claves[posActual];
	 hno= padre->hijos[posActual+1];
	 i = posClave+1;
	 while(j <hno->Nclaves) // copia las claves del hermano en actual
	{actual->claves[i]=hno->claves[j];
	  i++;
	  j++;
	(actual->Nclaves)++;}
	delete [ ]hno->claves;
	delete []hno->hijos;
	delete hno;
	//reorganiza las claves y los apuntadores a los hijos del padre.}
	while(posActual+1<padre->Nclaves)
	{padre-> claves[posActual]=padre->claves[posActual + 1];
	*padre->hijos[posActual+1]=padre[posActual+2];
	posActual++;}
	(padre->Nclaves)--;
	if(padre->Nclaves< d-1)AjustarNivelPadre(padre,posActual);
}

void arbolB::unir_Hno_Izq(nodo *padre, int posClave, int posActual){
	nodo *hno, *actual=padre->hijos[posActual];
	 int i, j=0;
	 hno= padre->hijos[posActual-1];
	 hno->claves[hno->Nclaves]= padre->claves[posActual-1];
	 i =++(hno->Nclaves);
	 while(j <actual->Nclaves) // copia las claves del hermano en actual
	{hno->claves[i]=actual->claves[j];
	  i++;
	  j++;
	  (hno->Nclaves)++;}
	delete [ ]actual->claves;
	delete []actual ->hijos;
	delete actual;
	//reorganiza las claves y los apuntadores a los hijos del padre.}
	while(posActual<padre->Nclaves)
	{padre-> claves[posActual-1]=padre->claves[posActual];
	 *padre->hijos[posActual]=padre[posActual+1];
	 posActual++;}
	(padre->Nclaves)--;
	if(padre->Nclaves< d-1)AjustarNivelPadre(padre,posActual);
}

void arbolB::AjustarNivelPadre(nodo *actual, int posClave){
	nodo *padre;
	int posActual;
	bool der, izq;
	int pos;
	if (actual != raiz && actual->Nclaves < d-1 )
	{posActual = buscar_lugarEntreHnos(actual->claves[0], padre);
	der=Ayuda_hnoDer(padre, posActual);
	if (!der)
	{izq=Ayuda_hnoIzq(padre, posActual);
	 if (!izq) juntar(padre, pos, posActual);
	else reemplazar_Der(actual, padre, posActual);}
	else reemplazar_Izq(actual, padre, posActual);}
}

int arbolB::borrarEn_Ninterno(int pos, nodo *actual){
 nodo * hizq, * hder, * padreizq, *padreder;
  bool der, izq;
  hizq=hder=actual;
  der= verificar_der(hder, padreder);
  izq = verificar_izq(hizq, padreizq);
  if (der || (!der &&! izq))
{actual->claves[pos] = hder->claves[0];
 borrarEn_hoja(hder->claves[0],0,hder,padreder);}
			else	{actual->claves[pos] = hizq->claves[actual->Nclaves-1];
				 borrarEn_hoja(hizq->claves[actual->Nclaves-1],actual->Nclaves-1,hizq,padreizq);}
				 imprimir(actual);
}

bool arbolB::verificar_der(nodo *hijo, nodo*padre){
	padre=hijo;
	  hijo=hijo->hijos[hijo->Nclaves-1];
	  while(!hijo->hoja)
	{padre=hijo;
	  hijo=hijo->hijos[0];}
	return(hijo->Nclaves>=d);
}

bool arbolB::verificar_izq(nodo *hijo, nodo*padre){
	padre=hijo;
	 hijo=hijo->hijos[0];
	while(!hijo->hoja)
	{*padre=*hijo;
	 hijo=hijo->hijos[hijo->Nclaves-1];}
	return(hijo->Nclaves>=d);
}

void arbolB::imprimir(nodo *nodo){//Impresion por niveles
			std::cout << "NODO" << '\n';
			for (int i = 0; i < nodo->Nclaves; i++) {
				std::cout << nodo->claves[i] << ' ';
			}
			std::cout <<  '\n';
			
		}

#endif

