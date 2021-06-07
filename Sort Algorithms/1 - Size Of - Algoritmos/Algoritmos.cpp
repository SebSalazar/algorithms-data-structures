#include <iostream>


/*Calculo del tamaño en bytes de cada varaible para 3 algoritmos */
//Sebastian Salazar - 20172020016

using namespace std;


//Estructuras
struct nodo{
	int x=0,y=0;
	nodo*sig=NULL;
};

//Funciones
void Algoritmo1(int n){
	int acu=0;
	int i,j;
	int *a=NULL;
	for(i=0;i<n;i++){
		a=new int[n];
		acu=acu+sizeof(a[i]);
		for(j=0;j<n;j++){
			a[j]=j*i;
			cout <<a[j]<<"\t";
		}
		cout<<endl;
		//cout<<"Tamaño (bytes): "<<sizeof(n)+sizeof(i)+sizeof(j)+sizeof(a)<<endl;	//tamaño del arreglo antes de ser borrado
		delete[]a;	
	}
	cout<<"Tamano (bytes): "<<(sizeof(n))+(sizeof(i))+(sizeof(j))+(sizeof(a))+acu<<endl;
}
void Algoritmo2(int n){
	int acu=0;
	int i,j;
	int **a=NULL;
	a = new int *[n];
	for (i=0;i<n;i++){
		a[i]=new int[n];
		
		for(j=0;j<n;j++){
			a[i][j]=i*j;
			acu=acu+sizeof(a[i]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<"\t";			
		}
		delete[]a[i];
	}
	delete []a;
	cout<<"\nTamano (bytes): "<<(sizeof(n))+(sizeof(i))+(sizeof(j))+(sizeof(a))+acu<<endl;
}
void Algoritmo3(int n){
	int acu=0;
	int i;
	nodo*cab=NULL;
	nodo*aux=NULL;
	for(i=0;i<n;i++){
		aux = new nodo;
		acu=acu+sizeof(aux);
		aux->x=i;
		aux->y=n-i;
		aux->sig=cab;
		if(cab==NULL)
			cab=aux;
	}
	while(aux!=NULL){
		cout<<aux->x<<" "<<aux->y<<endl;
	}
	for(aux=cab->sig;aux!=NULL;aux->sig){
		delete []cab;
		cab=aux;
	}
	cout<<"Tamano (bytes): "<<(sizeof(n))+(sizeof(i))+(sizeof(cab))+(sizeof(aux))+acu<<endl;
}


int main(int argc, char** argv) {
	system ("COLOR 3F");
	int opcion=0;
	int num;
	cout<<"\t\t\t--------------------------------------\n"<<endl;
	cout<<"\t\t\t*  CALCULO DEL SIZE OF DE ALGORITMOS *\n"<<endl;
	cout<<"\t\t\t--------------------------------------\n\n"<<endl;
	do{
	cout << "\nSeleccione el Algoritmo"<<endl;
	cout << "1) Algoritmo 1\n2) Algoritmo 2\n3) Algoritmo 3"<<endl;
	cin>>opcion;
	switch (opcion){
		case 1:	
			cout <<"Ingrese n"<<endl;
			cin>>num;
			Algoritmo1(num);
			break;
		case 2:
			cout <<"Ingrese n"<<endl;
			cin>>num;
			Algoritmo2(num);
			break;
		case 3:
			cout <<"Ingrese n"<<endl;
			cin>>num;
			Algoritmo3(num);
			break;
		default: cout <<"Ingrese una opcion valida";
		
	}
	}while(opcion != 3);	
	return 0;
	
}


