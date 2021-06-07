/*Codigo hecho por Daniel Alejandro Rodriguez 20172020009 y Sebastian Salazar - 20172020016
*/


#include <iostream>
#include<windows.h>
using namespace std;

void ordenShell(int *, int);
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
			ordenShell(a, k);		
		QueryPerformanceCounter(&endTime);
		//muestra el tiempo
		cout << k << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		cout << endl;	
	}
	
	delete []a;
	
	return 0;
}

void ordenShell(int *a, int N){
	int i,j,h; int v;
	for(h=1; h<=N/9; h= 3*h+1);
	for(; h>0; h/=3)
	for(i=h+1;i<N; i+=1)
		{v=a[i]; j=i;
		while(j > h && a[j-h] > v)
			{a[j] = a[j-h]; 
			j-=h;}
		a[j]=v;
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
