/* Codigo modificado por 
   Sebastian Salazar - 20172020016*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<windows.h>

using namespace std;

void MoverDisco(int, int, int, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	system ("COLOR 0B");
	cout<<"\t\t-------------------------------------------\n"<<endl;
	cout<<"\t\t*      TORRES DE HANOI <PROBLEMA NP>      *\n"<<endl;
	cout<<"\t\t-------------------------------------------\n\n"<<endl;	
	//---------------
	int discos;
	ofstream archivo;
	LARGE_INTEGER iniTime, endTime;
	archivo.open("Tiempos_Hanoi.txt",ios::out);
	
	for(int j=1; j<=50; j++){
		discos = j;
		
		QueryPerformanceCounter(&iniTime);
		MoverDisco( discos, 1, 2, 3);
		QueryPerformanceCounter(&endTime);
		
		//---Impresion de los tiempos---
		cout << j << " discos: " << performancecounter_diff(&endTime, &iniTime) << " segundos" <<endl;
		archivo << j << " discos: " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
	}
	
	archivo.close();
	return 0;
}

void MoverDisco(int num, int Origen, int Intermedio, int Destino){ 
	if ( num > 1 ){
		MoverDisco( num - 1, Origen, Destino, Intermedio);
		//cout <<"\nMueve el disco " <<  N  << " de " << Origen << " a " <<  Destino << endl;
		MoverDisco( num - 1, Intermedio, Origen, Destino);
	}	
}

//Metodo para calcular el tiempo en segundos
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
