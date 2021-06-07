//Sebastian Salazar - 20172020016
//Daniel (Nacaca) Rodriguez - 20172020009

#include <iostream>
#include "ArbolBin.h"

   
int main(int argc, char** argv) { 
	system("color 0B");
	
	cout<<"			***********************************************************************"<< endl;
	cout<<"						ARBOLES BINARIOS" << endl;
	cout<<"	        	***********************************************************************"<<endl;
	int tam;
	char letra;
	cout<<"Ingrese el tamano del arreglo"<<endl;
	cin>>tam;
	cout<<endl;
	Binario listBin(tam);
	do{
		cout<<"Ingrese"<<endl;
		cout<<"1. Para ingresar un nuevo numero"<<endl;
		cout<<"2. Para eliminar un numero"<<endl;
		cout<<"3. Para buscar un numero"<<endl;
		cout<<"4. Para imprimir InOrden"<<endl;
		cout<<"5. Para imprimir PosOrden"<<endl;
		cout<<"6. Para imprimir PreOrden"<<endl;
		cout<<"7. Para imprimir Orden por Niveles"<<endl;
		cout<<"8. Para salir"<<endl; 
		cin>>tam;
		switch(tam){     
			case 1:{
				cout<<"Ingrese el numero"<<endl;
				cin>>tam;
				cout<<"Ingrese la letra "<<endl;
				cin>>letra;
				listBin.insertar(tam, letra);
				
				break;
			}
			case 2:{
				cout<<"Ingrese el numero a eliminar"<<endl;
				cin>>tam;
				listBin.eliminar(tam);
				break;
			}
			case 3:{
				cout<<"Ingrese el numero a buscar"<<endl;
				cin>>tam;
				listBin.buscar(tam);
				break;  
			}
			case 4:{
				listBin.inOrden(); 
				break;
			}
			case 5:{
				listBin.posOrden();   
				break;
			}
			case 6:{
				listBin.preOrden(); 
				break;
			}
			case 7:{
				listBin.nivelOrden();
				break;
			}
			case 8:{
				cout<<"Programa Finalizado"<<endl; 
				break;
			}
			default:{
				break;
			}
		}
		system("pause");  
		system("cls");
	}while(tam!=8);
	
	system("pause");
	return 0;
}  
