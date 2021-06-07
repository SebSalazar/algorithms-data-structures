#include <conio.h>
#include <windows.h>
#include "Arboles_RN.h"
using namespace std;


 int main(){
	 	Arbol_RN <char>demo;
	    int info, input, opc;
		SetConsoleTitle("Arboles Roji-Negros");
		system("COLOR B"); 
		
		cout<<"\t\t\t\t***************************************************"<<endl;
		cout<<"\t\t\t\t\t\tARBOL ROJI-NEGRO"<<endl;
		cout<<"\t\t\t\t***************************************************"<<endl;

		do{
  	    cout<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        cout<<"\tMENU PRINCIPAL"<<endl;
        cout<<"1> Insertar un numero <nodo> al arbol"<<endl;
        cout<<"2> Buscar un numero <nodo> del arbol"<<endl;
        cout<<"3> Eliminar un numero <nodo> del arbol"<<endl;
    	cout<<"4> Recorrido en Preorden"<<endl;
    	cout<<"5> Recorrido en Postorden"<<endl;
    	cout<<"6> Recorrido en Inorden"<<endl;
        cout<<"7> Info de los desarrolladores"<<endl;
        cout<<"8> Salir"<<endl;
  	    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout<<"\nIngrese Opcion"<<endl;
        cin>>opc;
        
        while(opc<0 || opc>8){ //---Limitando la entrada de las opciones---
            system("CLS");
            main();
        }
        switch(opc){
        case 1: system("CLS");
				cout << "\nIngrese el elemento -- ";
                cin >> input; 
                cout<<"Ingrese la informacion --  : ";
                char info;
            	cin>>info;
				demo.InsertarNodo(input, info);
				system("pause");
				system("CLS");
                break;
        case 2: system("CLS");
				cout << "\nIngrese la clave del nodo a buscar -- ";
                cin >> input;
                if(demo.Buscar(input)){cout << "Elemento encontrado.\n"; 
					cout<<"Clave: "<<demo.Buscar(input)->clave<<endl;
					cout<<"Info: "<<demo.Buscar(input)->info<<endl;	
				}
                
                else { cout << "Element NO encontrado :c.\n"; }
                system("pause");
                system("CLS");
                break;
        case 3: system("CLS");
        		cout<<"Ingrese la clave del nodo a eliminar: ";
        	    cin >> input;
                demo.Eliminar(input);
                system("pause");
                system("CLS");
                break;
                
        case 4: system("CLS");
        		cout << "Recorrido en Preorden \n";
                demo.Preorden(demo.GetRaiz());
                cout << endl;
                system("pause");
                system("CLS");
                break;
        
        case 5: system("CLS");
        		cout << "Recorrido en Postorden \n";
                demo.Postorden(demo.GetRaiz());
                cout << endl;
                system("pause");
                system("CLS");
                break;
        
        case 6:system("CLS");
        		cout << "Recorrido en Inorden \n";
                demo.Inorden(demo.GetRaiz());
                cout << endl;
                system("pause");
                system("CLS");
                break;
        	
        case 7: 
                system("CLS");
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
			    cout<<"\t\t\t\t\t\tPROGRAMA DESARROLLADO POR: "<<endl;
			    cout<<"\t\t\t\t\tDANIEL ALEJANDRO RODRIGUEZ SUAREZ- 20172020009"<<endl;
			    cout<<"\t\t\t\t\tSEBASTIAN CAMILO SALAZAR IBANEZ - 20172020016"<<endl;
			    cout<<"\t\t\t\t\tUNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS"<<endl;	
			    cout<<"\t\t\t\t\tCIENCIAS DE LA COMPUTACION 1"<<endl;
    			cout<<"\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    			system("pause");
    			system("CLS");
                break;
        case 8: 
                exit(1);
        }

        }while(opc!=8);     	
}

