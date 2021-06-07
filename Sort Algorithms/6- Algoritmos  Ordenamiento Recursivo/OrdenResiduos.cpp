/* Ordenamiento por residuos */

#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std; 
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

struct tipoElemento{
	int numero;
	inline unsigned bits(int x,int k, int j){
		return (x>>k)&~(~0<<j);
	}
};

void intercambio(tipoElemento arreglo[], int numeroUno, int numeroDos){
	int pivot = arreglo[numeroUno].numero;
	arreglo[numeroUno].numero = arreglo[numeroDos].numero;
	arreglo[numeroDos].numero = pivot;
}

void ordenResiduos(tipoElemento a[], int izq, int der, int b){
   int i,j;
   if (der>izq && b>0){
	 	 i = izq;
		 j = der;
	   while(j!=i){
	   	 while(!a[i].bits(a[i].numero,b,1) && i<j){
			i++;
		 }
	     while( a[j].bits(a[j].numero,b,1) && j>i){
			j--;
		 }
	     intercambio(a, i, j);
	   }
	   if (!a[i].bits(a[i].numero,b,1)){
	   		j++;
	   }
	   ordenResiduos(a, izq, j-1, b-1);
	   ordenResiduos(a, j, der, b-1);
   }
}

int main(){	
	system ("COLOR 0B");
	cout<<"\t\t-------------------------------------------\n"<<endl;
	cout<<"\t\t*  ORDENAMIENTO POR ALGORITMO DE RESIDUOS *\n"<<endl;
	cout<<"\t\t-------------------------------------------\n\n"<<endl;	
	//---------------
	LARGE_INTEGER iniTime, endTime; //variables del tiempo
	int tamano;

	cout<<"Tamano arreglo: ";
	cin>>tamano;

	tipoElemento a[tamano]; 	

	for(int i=0;i<tamano;i++){
		a[i].numero = rand()%63;	 
  	}

  	for(int i=0;i<tamano;i++){
    	cout<<a[i].numero<<" ";
  	}
  	cout<<endl;

	 //calcula el tiempo
	QueryPerformanceCounter(&iniTime);
		ordenResiduos(a,0,tamano-1,5);   
	QueryPerformanceCounter(&endTime);
	//muestra el tiempo
	cout << "\nTiempo arreglo de tamano: "<< tamano << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
	cout << endl;	
	

	for(int i=0;i<tamano;i++){
		cout<<a[i].numero<<" ";
	}
	
	cout<<endl;
	return main();
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
