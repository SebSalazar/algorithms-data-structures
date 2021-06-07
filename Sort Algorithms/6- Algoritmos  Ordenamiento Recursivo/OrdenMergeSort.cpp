/* Algotitmo de Ordenamiento MergeSort */
#include <windows.h>
#include <iostream>

using namespace std;

double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

void MergeListas(int arreglo[], int inicioUno, int finUno, int inicioDos, int finDos){

	int inicioFinal = inicioUno;
	int finFinal = finDos;
	int indiceC = 0;
	int resultado[finFinal-inicioFinal];

	while((inicioUno<=finUno) && (inicioDos<=finDos) ){

		if(arreglo[inicioUno] < arreglo[inicioDos]){
			resultado[indiceC] = arreglo[inicioUno];
			inicioUno+=1;
		}
		else{
			resultado[indiceC] = arreglo[inicioDos];
			inicioDos+=1;
		}
		indiceC+=1;
	}

	if(inicioUno<=finUno){
		for(int i=inicioUno;i<=finUno;i++){
			resultado[indiceC] = arreglo[i];
			indiceC+=1;
		}
	}
	else{
		for(int i=inicioDos;i<=finDos;i++){
			resultado[indiceC] = arreglo[i];
			indiceC+=1;
		}
	}

	indiceC = 0;
	for(int i=inicioFinal;i<=finFinal;i++){
		arreglo[i] = resultado[indiceC];
		indiceC+=1;
	}

}

void Merge(int arreglo[], int primero, int ultimo){

	int mitad;

	if (primero < ultimo){
			 mitad = ( primero + ultimo ) / 2;
			 Merge( arreglo, primero, mitad );
			 Merge( arreglo, mitad + 1, ultimo );
			 MergeListas( arreglo, primero, mitad, mitad+1, ultimo);
	}
}


int main(){
	system ("COLOR 0B");
	cout<<"\t\t--------------------------------------------\n"<<endl;
	cout<<"\t\t*  ORDENAMIENTO POR ALGORITMO DE MERGESORT *\n"<<endl;
	cout<<"\t\t--------------------------------------------\n\n"<<endl;	
	//---------------
	LARGE_INTEGER iniTime, endTime; //variables del tiempo
	int tamano,i;

	cin>>tamano;

	int a[tamano]; 	

	//Llenado del arreglo de mayor a menor -- Peor caso
	for(i=0;i<tamano;i++){
		a[i] = tamano-i;	  
	}

	QueryPerformanceCounter(&iniTime);
		Merge(a,0,tamano-1); 
	QueryPerformanceCounter(&endTime);
	cout << "\nTiempo arreglo de tamano: "<< tamano << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;

	//Impresion del arreglo ordenado--
	for(i=0;i<tamano;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return main();

}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
