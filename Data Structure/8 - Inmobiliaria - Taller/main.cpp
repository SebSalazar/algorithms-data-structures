#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

//---Libreria de la lista para hacer la operaciones
#include "Estructura.h"
#include "Lista.h"

using namespace std;


int main(){
	int opc, num, tam;
	char letra;
	SetConsoleTitle("LISTAS DE PROPIEDADES"); 
	system ("COLOR B");
	
	cout<<"\t\t\t\t***************************************************"<<endl;
	cout<<"\t\t\t\t\t\tINMOBILIARIA"<<endl;
	cout<<"\t\t\t\t***************************************************"<<endl;
	Nodo pro;
    Lista  lista;
    Lista vendidos;
		do{
		system("CLS");
  	    cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        cout<<"\tMENU PRINCIPAL"<<endl;
        cout<<"1> Insertar inmueble para venta"<<endl;
        cout<<"2> Vender inmueble"<<endl;
        cout<<"3> Consultar inmuebles a la venta "<<endl;
        cout<<"4> Inmuebles vendidos"<<endl;
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
        	    cout<<"INGRESA CODIGO"<<endl;
        	    cout<<"Codigo = "; cin>>pro.codigo;
        	    cout<<"INGRESA LOCALIDAD"<<endl;
        	    cout<<"Localidad = "; cin>>pro.localidad;
        	    cout<<"INGRESA VIA"<<endl;
        	    cout<<"Via= "; cin>>pro.via;
        	    do{
        	    cout<<"INGRESA TIPO (1) Casa , (2) Apartamento, (3) Loft, (4) Aparta estudio"<<endl;
        	    cout<<"Tipo= "; cin>>pro.tipo;
        	    }while(pro.tipo<0 || pro.tipo>4);
        		cout<<"INGRESA VALOR"<<endl;
        	    cout<<"Valor= "; cin>>pro.valor;
        	    cout<<"INGRESA ESTRATO"<<endl;
        	    cout<<"Estrato= "; cin>>pro.estrato;
        	    lista.insertarLista(pro);	    
                break;
        case 2:
        	    system("CLS");
        	    int codigo;
        	    cout<<"Ingrese el codigo del inmueble a vender: "<<endl;
				cout<<"Codigo: "; cin>> codigo;
				pro.codigo = codigo;
				if(lista.buscarLista(pro)){
					Nodo vend;
					vend.codigo = pro.codigo;
					vend.estrato = pro.estrato;
					vend.localidad = pro.localidad;
					vend.tipo = pro.tipo;
					vend.valor = pro.valor;
					vend.via = pro.via;
					
					vendidos.insertarLista(vend);
					lista.eliminarElementoLista(pro);
				}else{
					cout<<"No se encontro el elemento";
				}
				
                break;
        case 3:
        	    system("CLS");
				cout<<"INMUEBLES A LA VENTA"<<endl;
				lista.mostrarLista();
                break;
        case 4: 
                system("CLS");
                cout<<"INMUEBLES VENDIDOS"<<endl;
				vendidos.mostrarLista();
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



