//Recuperado de https://www.codespeedy.com/radix-sort-in-cpp/
//Modificado por Daniel Alejandro Rodriguez - 20172020009
#include<iostream>
#include <windows.h>
using namespace std;
 
 
//funciones
int getmax(int *, int);
void CountSort(int *, int, int);
void radixsort(int *, int);
double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);
 

int main()
{
	int *a;
	LARGE_INTEGER iniTime, endTime; //variables del tiempo
	
	for(int k = 10; k<=500; k+=10){
		a = new int[k];
		
		for(int i=0; i<k; i++)
			a[i] = k-i;
		
		 //calcula el tiempo
	    QueryPerformanceCounter(&iniTime);
			radixsort(a, k);		
		QueryPerformanceCounter(&endTime);
		//muestra el tiempo
		cout << k << ": " << performancecounter_diff(&endTime, &iniTime) << " segundos" << endl;
		cout << endl;	
	}
	
	delete []a;

  return 0;
}

// Function to get maximum value in array a[].
int getmax(int *a, int n)
{
  int max = a[0];
  for (int x=1; x<n; x++)
    if (a[x] > max)
      max = a[x];
  return max;
}


// Function to do counting sort according to significant digits repesented by
// exp (where exp is 10^i).
void CountSort(int *a, int n, int exp)
{  
  int result[n], i, count[10] = {0};
 
  // Counting occurence of digits
  for (i =0; i <n; i++)
    count[(a[i] / exp) % 10]++;
 
  // Changing the position of count so that it appears at actual position in result.
  for (i =1; i<10; i++)
    count[i] += count[i-1];
 
  // Resultant output array
  for (i =n-1; i>= 0; i--)
  {
    result[count[(a[i] / exp) % 10] - 1] = a[i];
    count[(a[i] / exp) % 10]--;
  }
  for (i =0; i <n; i++)
    a[i] = result[i];
}
 
// Radix Sort to sort a[] of given size.
void radixsort(int *a, int n)
{
  int exp, i;
  i = getmax(a, n);
  for (exp = 1; i/exp > 0; exp *= 10)
    CountSort(a, n, exp);
}
//Funcion para calcular el tiempo
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}
