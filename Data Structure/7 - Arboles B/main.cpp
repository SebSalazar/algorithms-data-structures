#include <iostream>
#include <conio.h>

#include "ArbolB.h"
using namespace std;


int main(){
	int opc, num, tam;
	char letra;
	system ("COLOR B");
	
	cout<<"\t\t\t\t***************************************************"<<endl;
	cout<<"\t\t\t\t\t\tARBOLES B"<<endl;
	cout<<"\t\t\t\t***************************************************"<<endl;
	cout<<"Ingrese el orden del arreglo"<<endl;
	cin>>tam;
	arbolB ab (tam);
		do{
		system("CLS");
  	    cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        cout<<"\tMENU PRINCIPAL"<<endl;
        cout<<"1> Insertar una clave "<<endl;
        cout<<"2> Eliminar una clave "<<endl;
        cout<<"3> Imprimir por niveles el arbol "<<endl;
        cout<<"4> Info de los desarrolladores + tamano de la cola"<<endl;
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
        	    cout<<"INGRESA LA CLAVE"<<endl;
        	    cout<<"Numero = "; cin>>num; 
				ab.insertar(num);	    
                break;
        case 2:
        	    system("CLS");
				cout<<"INGRESA LA CLAVE A BORRAR: "<<endl;
        	    cout<<"Numero = "; cin>>num; 
        	    ab.borrar(num);
                break;
        case 3:
        		//--Es un ejemplo de como funciona, pues para el arbol como tal de verdad se va imprimiendo cada 
				//--vez que se va insertado y eliminando, este es un ejemplo
        	    system("CLS");
        	    for(int i=0; i<=3; i++){
					ab.insertar(i);
				}
				ab.imprimir(ab.get_raiz());
				ab.imprimir(ab.get_raiz()->hijos[0]);
				ab.imprimir(ab.get_raiz()->hijos[1]);
				ab.imprimir(ab.get_raiz()->hijos[2]);
                break;
        case 4: 
                system("CLS");
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
			    cout<<"\t\t\t\t\t\tPROGRAMA DESARROLLADO POR: "<<endl;
			    cout<<"\t\t\t\t\tSEBASTIAN CAMILO SALAZAR IBANEZ - 20172020016"<<endl;
			    cout<<"\t\t\t\t\tUNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS"<<endl;	
			    cout<<"\t\t\t\t\tCIENCIAS DE LA COMPUTACION 1"<<endl;
    			cout<<"\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    		
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


