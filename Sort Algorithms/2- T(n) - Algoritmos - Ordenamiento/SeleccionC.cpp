#include<iostream>
#include<cstdlib>
#include<windows.h>

// Algoritmo para ordenar arreglos "Seleccion"
//Creitos https://github.com/CarlosLopez98/Ciencias_Computacion_I/blob/master/Ordenamiento/seleccion.cpp

using namespace std;

// Prototipos
void intercambio(int*, int, int); 
void seleccion(int*, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	
	int n, *a;
	LARGE_INTEGER iniTime, endTime;
	for(int j=10; j<=500; j+=10){
		n = j;		
		a = new int[n];
		
		for(int i=0; i<n; i++){
			a[i] = i+1;
		}
		
		QueryPerformanceCounter(&iniTime);			
		seleccion(a, n);		
		QueryPerformanceCounter(&endTime);
		
		delete []a;
		
		cout << j << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
	}
	
	cout << endl;
	return 0;
}

void intercambio(int *a, int min, int i){
	int aux;
	aux = a[min];
	a[min] = a[i];
	a[i] = aux;
}

void seleccion(int *a, int n){
	int i, j, min;
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(a[j] < a[min]) min = j;
		}
		intercambio(a, min, i);
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
