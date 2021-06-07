//Codigo original:
//https://algoritmosyalgomas.com/determinante-de-una-matriz-de-cualquier-orden-c/?snippet=9798a8b191&id=125
//Modificado por Daniel Rodriguez -20172020009
#include <iostream>
#include <cmath>
#include<cstdlib>
#include<windows.h>
#define MAX 100

using namespace std;

void mostrar_matriz(int matriz[][MAX], int orden);
int determinante(int matriz[][MAX], int orden);
int cofactor(int matriz[][MAX], int orden, int fila, int columna);
//funcion para medir tiempo
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);
int main()
{
   int matriz[MAX][MAX];
   LARGE_INTEGER iniTime, endTime; //variables del tiempo

   	for(int orden = 1; orden<=20;orden++){
   		for(int i=0;i<orden;i++)
			for(int j=0;j<orden;j++)
				matriz[i][j] = rand() % 100;
   		//calcula el tiempo
   		QueryPerformanceCounter(&iniTime);
   		determinante(matriz, orden);
   		QueryPerformanceCounter(&endTime);

		//muestra el tiempo
		cout << orden << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		cout << endl;
	   }

   return 0;
}

void mostrar_matriz(int matriz[][MAX], int orden)
{
   cout << "Orden: " << orden << endl;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         cout << "\t" << matriz[i][j];
      }
      cout << "\n";
   }
}


int determinante(int matriz[][MAX], int orden)
{
   int det = 0.0;
   
   if (orden == 1) {
      det = matriz[0][0];
   } else {
      for (int j = 0; j < orden; j++) {
         det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
      }
   }
   
   return det;
}


int cofactor(int matriz[][MAX], int orden, int fila, int columna)
{
   int submatriz[MAX][MAX];
   int n = orden - 1;
   
   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   
   return pow(-1.0, fila + columna) * determinante(submatriz, n);
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
