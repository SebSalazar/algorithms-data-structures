#include<iostream>
using namespace std;
struct nodo{int x,y;
	nodo*sig;
};

int main(){
	int n, i;
	nodo *cab = NULL,*aux;
	cin >> n;
	for(i = 0; i<n; i++){
		aux = new nodo;
		aux -> x = i;
		aux -> y = n-i;
		aux -> sig = cab;
		cab = aux;
		cout<<"tamanio = "<<sizeof(cab[i])*n<<endl;
	}
	cout<<"ahora otra cosa"<<endl;
	while(aux != NULL){
		cout<< aux -> x <<"," << aux -> y << ", size of = "<<sizeof(aux)<<endl;
		aux = aux -> sig;
	}
	
	for(aux = cab -> sig; aux!=NULL; aux = aux->sig){
		delete cab;
		cab = aux;
	}
	delete cab;
	return 0;
}
