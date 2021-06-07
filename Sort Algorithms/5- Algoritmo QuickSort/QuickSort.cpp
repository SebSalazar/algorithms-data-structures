//Codigo hecho por Daniel alejandro Rodriguez - 20172020009
//Sebastian Salazar - 20172020016
#include <iostream>
#include <windows.h>

using namespace std;

void intercambio(int *, int, int);
void ordenRapido(int *, int, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	int *a;
	LARGE_INTEGER iniTime, endTime; //variables del tiempo
	
	for(int k = 10; k<=500; k+=10){
		a = new int[k];
		
		for(int i=0; i<k; i++)
			a[i] = k-i;
		 //calcula el tiempo
	    QueryPerformanceCounter(&iniTime);
			ordenRapido(a,0,k-1);	
		QueryPerformanceCounter(&endTime);
		//muestra el tiempo
		cout << k << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		cout << endl;	
	}	
	delete []a;
	
	return 0;
}

void intercambio(int *a, int x, int y){
	int aux;
	aux = a[x];
	a[x] = a[y];
	a[y] = aux;
}

void ordenRapido(int *a, int izq, int der){
	int i, j; int v;
  	if (der> izq){
		v= a[der]; i = izq -1; j= der;
        for(;;)
            {while (a[++i]<v);
              while (a[--j] >v);
              if(i>=j) break;
              intercambio(a,i,j);
             }
       intercambio(a, i, der);
       ordenRapido(a, izq, i-1);
       ordenRapido(a, i+1,der);
     }
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

