
//Suma de Matrices dinamicas y calculo de su T(N)
//Sebastian Salazar - 20172020016

#include <windows.h>
#include <iostream>

using namespace std;

double performancecounter_diff(LARGE_INTEGER*, LARGE_INTEGER*);

int main(){
	system ("COLOR 1F");
	cout<<"\t\t\t------------------------------------\n"<<endl;
	cout<<"\t\t\t*         T(N) DE MATRICES         *\n"<<endl;
	cout<<"\t\t\t------------------------------------\n\n"<<endl;
	int n=2, m=3;
	LARGE_INTEGER iniTime, endTime;
	
	while(n<=1024){
		int **A, **B, **C;
		
		A = new int*[n];
		B = new int*[n];
		for(int i=0; i<n; i++){
			A[i] = new int[m];
			B[i] = new int[m];
			for(int j=0; j<m; j++){
				A[i][j] = (i*n)+j;
				B[i][j] = (n*m)-((i*n)+j);
			}
		}
		
	    QueryPerformanceCounter(&iniTime);
	    C = new int*[n];
	    for(int i=0; i<n; i++){
	    	C[i] = new int[m];
			for(int j=0; j<m; j++){
				C[i][j] = A[i][j] + B[i][j];
			}
		}
		QueryPerformanceCounter(&endTime);
			
	    cout <<"--> Tiempo: " << performancecounter_diff(&endTime, &iniTime)<<" segundos \n \n";
	    

		for(int i=0; i<n; i++){
			delete A[i];
			delete B[i];
			delete C[i];
		}
		delete []A;
		delete []B;
		delete []C;
		n *= 2;
		m *= 2;
		
	}
    return 0;
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){ 
	LARGE_INTEGER freq; 
	QueryPerformanceFrequency(&freq); 
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;	
}

