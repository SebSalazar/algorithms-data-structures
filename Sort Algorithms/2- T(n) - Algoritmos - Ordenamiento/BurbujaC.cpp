#include<iostream>
#include<cstdlib>
#include<windows.h>
//CREDITOS https://github.com/CarlosLopez98/Ciencias_Computacion_I/tree/master/Ordenamiento
// Algoritmo para ordenar arreglos "Burbuja"

using namespace std;

// Prototipos
void intercambio(int*, int, int);
void burbuja(int*, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	
	int n, *a;
	LARGE_INTEGER iniTime, endTime;
	
	for(int i=10; i<=500; i=i+10){
		n = i;
		
		a = new int[n];
		
		for(int j=0; j<=n-1; j++){
			a[j] = j+1;
		}
		
		QueryPerformanceCounter(&iniTime);
		burbuja(a, n);		
		QueryPerformanceCounter(&endTime);
		
		
		delete []a;
		
		cout << i << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		cout << endl;
	}
	return 0;
}

void intercambio(int *a, int x, int y){
	int aux;
	aux = a[x];
	a[x] = a[y];
	a[y] = aux;
}

void burbuja(int* a, int n){
	int i, j;
	
	for(i=n-1; i>=0; i--){
		for(j=1; j<=i; j++){
			if(a[j-1] > a[j]) intercambio(a, j-1, j);
		}
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
