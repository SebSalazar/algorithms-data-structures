#include<iostream>
#include<cstdlib>
#include<windows.h>

// Algoritmo para ordenar arreglos "Insercion"
//creditos https://github.com/CarlosLopez98/Ciencias_Computacion_I/blob/master/Ordenamiento/insercion.cpp
using namespace std;

// Prototipos
void insercion(int*, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	
	int n, *a;
	LARGE_INTEGER iniTime, endTime;
	for(int j=10; j<=500; j+=10){
		n = j;
		
		a = new int[n];
		
		for(int i=0; i<=n-1; i++){
			a[i] = i+1;
		}
		
		QueryPerformanceCounter(&iniTime);
			
		insercion(a, n);
			
		QueryPerformanceCounter(&endTime);
		
		//for(int i=0; i<n; i++){
		//	cout << a[i] << " ";
		//}
		
		delete []a;
		
		cout << j << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
	}
	cout << endl;	
	return 0;
}

void insercion(int *a, int n){
	int i, j, v;
	
	for(i=1; i<n; i++){
		j = i;
		v = a[j];
		
		while(a[j-1] > v && j > 0){
			a[j] = a[j-1];
			j--;
		}
		a[j] = v;
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
