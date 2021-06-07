/*----------------------------------------------------------------------------------------------------------------------------------" 
                                     REPRESENTACION DE UN ARBOL EN UN ARREGLO
										  SEBASTIAN SALAZAR - 2017202016
									  	  DANIEL RODRIGUEZ - 20172020009 
"-----------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

//---Libreria del Arbol
#include "Arbol_Arreglo.h"
using namespace std;


int main(){
	int opc, num, tam;
	SetConsoleTitle("Arboles en un Arreglo"); 
	system ("COLOR B");
	
	cout<<"\t\t\t\t***************************************************"<<endl;
	cout<<"\t\t\t\t\t\tARBOL EN UN ARREGLO"<<endl;
	cout<<"\t\t\t\t***************************************************"<<endl;
	cout<<"Ingrese el tamano del arreglo"<<endl;
	cin>>tam;
	cout<<endl;
	Arbolar <int>arb (tam);
		do{
		system("CLS");
  	    cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        cout<<"\tMENU PRINCIPAL"<<endl;
        cout<<"1> Insertar un numero <nodo> al arreglo"<<endl;
        cout<<"2> Buscar un numero <nodo> del arreglo"<<endl;
        cout<<"3> Eliminar un numero <nodo> del arreglo"<<endl;
        cout<<"4> Info de los desarrolladores + in-orden"<<endl;
        cout<<"5> Salir"<<endl;
  	    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"\nIngrese Opcion"<<endl;
        cin>>opc;
        while(opc<0 || opc>5){ //---Limitando la entrada de las opciones---
            system("CLS");
            main();
        }
        switch(opc){
        case 1:
        	    system("CLS");
        	    cout<<"INGRESA EL NUMERO A INSERTAR AL ARBOL"<<endl;
        	    cout<<"Numero = "; cin>>num;
        	    if(arb.lleno() == false) {
        	    	arb.insertar(num);
        	    	cout<<"NODO agregado!"<<endl;
				}
        	    else{
        	    	cout<<"No se pudo insertar - Arreglo lleno"<<endl;
				}        	    
                break;
        case 2:
        	    system("CLS");
        	    cout<<"INGRESA EL NUMERO A BUSCAR EN EL ARBOL"<<endl;
        	    cout<<"Numero = "; cin>>num;
				arb.buscar(num);
                break;
        case 3:
        	    system("CLS");
        	    cout<<"INGRESA EL NUMERO A ELIMINAR EN EL ARBOL"<<endl;
        	    cout<<"Numero = "; cin>>num;
                arb.eliminar(num);
                break;
        case 4: 
                system("CLS");
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
			    cout<<"\t\t\t\t\t\tPROGRAMA DESARROLLADO POR: "<<endl;
			    cout<<"\t\t\t\t\tSEBASTIAN CAMILO SALAZAR IBANEZ - 20172020016"<<endl;
			    cout<<"\t\t\t\t\tUNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS"<<endl;	
			    cout<<"\t\t\t\t\tCIENCIAS DE LA COMPUTACION 1"<<endl;
    			cout<<"\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
				arb.inOrden();	//---Solo lo puse para verificar que todo estuviera bien---
                break;
        case 5: 
                exit(1);
        }
        //--------Solo para cuando sea una de las opciones-------------
        if(opc<5){
            cout<<"\n\nPresiona cualquier tecla para regresar al menu";
            getch();
            }
        }while(opc!=5);     	
}


