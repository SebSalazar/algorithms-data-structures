/*----------------------------------------------------------------------------------------------------------------------------------" 
                                     PROYECTO FINAL IGLESIAS Y FELIGRESES
                                                      POR 
										  SEBASTIAN SALAZAR - 2017202016  
"-----------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <time.h>
#include <conio.c>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
typedef std::string String; // para no escribir todo el tiempo std::string

#include "Feligres.h"
#include "feligresL.h"
#include "Iglesia.h"
#include "iglesiaL.h"
#include "IglesiaEst.h"
#include "Localidad.h"
#include "localidadL.h"
#include "localidadEst.h"
#include "Fecha.h"
#include "lista_javier.h"
#include "Multilista.h"
#include "cabeceras/cabeceraG.h"


using namespace std;

void Crear_Feligres(void);
void Agregar_Feligres(void);
void Editar_Feligres(void);
void Borrar_Feligres(void);
void Listar_Feligres(void);
void Crear_Iglesia(void);
void Agregar_Iglesia(void);
void Editar_Iglesia(void);
void Borrar_Iglesia(void);
void Crear_Localidades(void);
void Listar_Localidad(void);
//-------------------------Funciones menus------------------------------
void fecha();
void menu_principal();
void menu_consultas();
void menu_ingresar();
void menu_feligreses();
void menu_iglesias();
void menu_localidades();
void menu_desarrolladores(); 
void leerarchivoFeligres();
void leerarchivoIglesias();
void leerarchivoLocalidades();
void consulta_2(int rangoI,int rangoS, Multilista miLista);
void consulta_3(string ciudad, Multilista miLista);
void consulta_5(Multilista miLista);
//--------------Archivos planos para feligreses, iglesias y localidades-----------------------
char nombre_fichero_feligreses[] = "Feligres.txt";
char nombre_fichero_iglesias[] = "Iglesia.txt";
char nombre_fichero_localidades[] = "Localidad.txt";
FILE *abrir_fichero_b(char cadena[], int metodo);
time_t theTime = time(NULL);
struct tm *aTiempo = localtime(&theTime);
void splitFeligres(string str, char pattern); //funcion para hacer el split de los datos
void splitIglesias(string str, char pattern); //funcion para hacer el split de los datos
void splitLocalidades(string str, char pattern); //funcion para hacer el split de los datos
Multilista miLista(100);//Defino el tamaño de mi Multilista estatica

int main(){
	SetConsoleTitle("Sistemas Minuto de Dios :V"); //Titulo de consola
	menu_principal();
	
}

//---------------FUNCIONES PARA MENUS Y SUB-MENUS----------------  
void menu_principal(){
	    int i, opc;
	    fecha();
  		do{
        system("CLS");
        system ("COLOR E");
		fecha(); 
        for(i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(22,7);
  	    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	    gotoxy(33,9);
	    textcolor (WHITE);
        cout<<"MENU PRINCIPAL"<<endl;
        gotoxy(22,11);
        textcolor (YELLOW);
        cout<<"1> Para insertar los datos del los .txt"<<endl;
        gotoxy(22,12);
        cout<<"2> Para ingresar, editar o eliminar datos"<<endl;
        gotoxy(22,13);
        cout<<"3> Para realizar las consultas"<<endl;
        gotoxy(22,14);
        cout<<"4> Info de los desarrolladores"<<endl;
        gotoxy(22,15);
        cout<<"5> Para salir del programa"<<endl;
        gotoxy(22,20);
  	    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        gotoxy(33,17);
        textcolor (WHITE);
        cout<<"Ingrese Opcion"<<endl;
        gotoxy(40,19);
        cin>>opc;
        switch(opc){
        case 1:
        	    system("CLS");
        	    leerarchivoFeligres();
        	    leerarchivoIglesias();
        	    leerarchivoLocalidades();
                break;
        case 2:
        	    system("CLS");
                menu_ingresar();       
                break;
		case 3:
        	    system("CLS");
                menu_consultas();             
                break;  
		case 4:
        	    system("CLS");
                Listar_Feligres();                
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

void menu_consultas(){
	int i, opc, iz=0, der=0;
	string igle, ciudad;
	lista<feligres> *l;
	lista<string> iglesiasN;
	lista<feligres> l6;
	    fecha();
  		do{
        system("CLS");
        system ("COLOR 9");
		fecha(); 
        for(i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(5,4);
  	    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	    gotoxy(33,6);
	    textcolor (WHITE);
        cout<<"CONSULTAS"<<endl;
        gotoxy(12,8);
        textcolor (CYAN);
        cout<<"1> Numero total de personas que asisten"<<endl;
        gotoxy(12,9);
        cout<<"a una iglesia dada"<<endl;
        gotoxy(12,10);
        cout<<"2> Listado de los nombres y apellidos de aquellos"<<endl;
        gotoxy(12,11);
        cout<<"que tienen  un numero de hijos dado (en rangos) "<<endl;
        gotoxy(12,12);
        cout<<"3> Nombre y apellidos de las personas"<<endl;
        gotoxy(12,13);
        cout<<"que viven en una ciudad dada "<<endl;
        gotoxy(12,14);
        cout<<"4> Numero de iglesias a las que asiste un "<<endl;
        gotoxy(12,15);
        cout<<"numero de personas superior a un numero dado "<<endl;
        gotoxy(12,16);
        cout<<"5> Obtener el numero de hombres y el número de "<<endl;
        gotoxy(12,17);
        cout<<"mujeres que asisten a las diferentes iglesias "<<endl;
        gotoxy(12,18);
        cout<<"6> Dado un rango de edad y una actividad laborar "<<endl;
        gotoxy(12,19);
        cout<<"mostrar la lista de feligreses de esa edad"<<endl;
        gotoxy(12,20);
        cout<<"7> Volver"<<endl;
        gotoxy(5,22);
  	    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        gotoxy(33,23);
        textcolor (WHITE);
        cout<<"Ingrese Opcion"<<endl;
        gotoxy(40,24);
        cin>>opc;
        switch(opc){
        case 1:
        	
        	system("CLS");
		    system ("COLOR F");
			fecha(); 
		    for(i=1;i<81;i++){
		       	gotoxy(i,1);
		        printf("%c",219);
		      	gotoxy(i,25);
		        printf("%c",219);
		    }
		    for(i=1;i<25;i++){
		        gotoxy(1,i);
		        printf("%c",219);
		      	gotoxy(80,i);
		        printf("%c",219);
		    }
		    	gotoxy(5,4);
        	    cout<<"Inserte el nombre de la iglesia: "<<endl;
        	    gotoxy(10,5);
        	    cin>>igle;
        	    l = miLista.consulta1(igle);
        	    gotoxy(5,7);
        	    cout<<"sin hijos: "<<l[0].tamLista()<<endl;
        	    gotoxy(5,8);
				cout<<"Edad de 0-5: "<<l[1].tamLista()<<endl;
				gotoxy(5,9);
				cout<<"Edad de 6- 10: "<<l[2].tamLista()<<endl;
				gotoxy(5,10);
				cout<<"Edad de 11 - 18: "<<l[3].tamLista()<<endl;
				gotoxy(5,11);
				cout<<"Edad de mas de 18: "<<l[4].tamLista()<<endl;
            break;
        case 2:
        	int num;
        	system("CLS");
		    system ("COLOR F");
			fecha(); 
		    for(i=1;i<81;i++){
		       	gotoxy(i,1);
		        printf("%c",219);
		      	gotoxy(i,25);
		        printf("%c",219);
		    }
		    for(i=1;i<25;i++){
		        gotoxy(1,i);
		        printf("%c",219);
		      	gotoxy(80,i);
		        printf("%c",219);
		    }
		    	gotoxy(5,4);
        	    cout<<"Eliga el rango a buscar: "<<endl;
        	    gotoxy(5,5);
				cout<<"Inserte el limite inferior"<<endl;				
				cin>>iz;
				cout<<"Inserte el limite superior"<<endl;				
				cin>>der;	
				gotoxy(5,8);
				consulta_2(iz, der, miLista);
                break;
		case 3:
        	system("CLS");
		    system ("COLOR F");
			fecha(); 
		    for(i=1;i<81;i++){
		       	gotoxy(i,1);
		        printf("%c",219);
		      	gotoxy(i,25);
		        printf("%c",219);
		    }
		    for(i=1;i<25;i++){
		        gotoxy(1,i);
		        printf("%c",219);
		      	gotoxy(80,i);
		        printf("%c",219);
		    }
		    	gotoxy(5,4);
        	    cout<<"Escribe la ciudad: "<<endl;
        	    gotoxy(5,5);
				cin>>ciudad;				
				//(el metodo retorna una lista de feligreses que tienen que ser 
				//clasificados teniendo en cuenta a que localidad pertenece el barrio)
				//implementado en el main porque la implementacion en la multilista puede producir apuntodores colgantes
				consulta_3(ciudad,miLista);
                break;  
		case 4:
			int num2;
        	system("CLS");
		    system ("COLOR F");
			fecha(); 
		    for(i=1;i<81;i++){
		       	gotoxy(i,1);
		        printf("%c",219);
		      	gotoxy(i,25);
		        printf("%c",219);
		    }
		    for(i=1;i<25;i++){
		        gotoxy(1,i);
		        printf("%c",219);
		      	gotoxy(80,i);
		        printf("%c",219);
		    }
		    	gotoxy(5,4);
        	    cout<<"Escribe el numero: "<<endl;
        	    gotoxy(5,5);
				cin>>num2;				
				//consulta 4, devuelve los nombres de las iglesias a las que asisten mas de n feligreses
				gotoxy(5,7);
				iglesiasN = miLista.consulta4(num2);
				cout<<endl<<endl;
				for(int i = 1;i <= iglesiasN.tamLista();i++){
					cout<<"nombre: "<<iglesiasN.getDato(i)<<endl;
				}
                break;   
        case 5:
        	system("CLS");
		    system ("COLOR F");
			fecha(); 
		    for(i=1;i<81;i++){
		       	gotoxy(i,1);
		        printf("%c",219);
		      	gotoxy(i,25);
		        printf("%c",219);
		    }
		    for(i=1;i<25;i++){
		        gotoxy(1,i);
		        printf("%c",219);
		      	gotoxy(80,i);
		        printf("%c",219);
		    }
		    	gotoxy(5,4);
        	    cout<<"Mujeres y hombres que asisten a las diferentes iglesias --> "<<endl;			
				gotoxy(5,7);
				//(el metodo retorna una lista de feligreses que tienen que ser 
				//clasificados teniendo en cuenta a que localidad pertenece el barrio)
				//implementado en el main porque la implementacion en la multilista puede producir apuntodores colgantes
				consulta_5(miLista);
                break;   
		case 6:
			string acti, edad1, edad2, rango;
        	system("CLS");
		    system ("COLOR F");
			fecha(); 
		    for(i=1;i<81;i++){
		       	gotoxy(i,1);
		        printf("%c",219);
		      	gotoxy(i,25);
		        printf("%c",219);
		    }
		    for(i=1;i<25;i++){
		        gotoxy(1,i);
		        printf("%c",219);
		      	gotoxy(80,i);
		        printf("%c",219);
		    }
		    	gotoxy(5,4);
        	    cout<<"Escriba el rango de edad y actividad laboral: "<<endl;
				gotoxy(5,5);
        	    cout<<"Edad 1: "<<endl;	
        	    cin>>edad1;
        	    gotoxy(5,6);
        	    cout<<"Edad 2: "<<endl;	
        	    cin>>edad2;
        	    gotoxy(5,7);
        	    cout<<"Actividad Laboral en MAYUSCULAS "<<endl;	
        	    cin>>acti;
        	    rango = edad1+"-"+edad2;
        	    cout<<rango<<endl;
				gotoxy(5,10);
				//devuelve la lista de feligreses que estan en ese rango de edad y tienen esa actividad laboral
				l6 = miLista.consulta6(rango, acti);
				cout<<endl<<"Feligreses obtenidos en la consulta"<<endl<<endl;
				for(int i = 1;i <= l6.tamLista();i++){
					for(int j = 1;j<= miLista.getAtributos().iglesia.Iglesias.tamLista();j++ ){
						cout<<"Iglesia: "<<miLista.getAtributos().iglesia.Iglesias.getDato(j).nombre<<endl;
						for(int k = 1;k <= miLista.getAtributos().barrio.barrios.tamLista();k++){
							cout<<"Barrio: "<<miLista.getAtributos().barrio.barrios.getDato(k).nombre<<endl;
							if(l6.getDato(i).iglesia == miLista.getAtributos().iglesia.Iglesias.getDato(j).nombre && l6.getDato(i).barrio == miLista.getAtributos().barrio.barrios.getDato(j).nombre){
								cout<<"Nombre: "<<l6.getDato(i).nombre<<" Apellido: "<<l6.getDato(i).apellido<<endl;
							}
						}
					}
				}
                break;     		  
        }
    //--------Solo para cuando sea una de las opciones-------------
    if(opc<7){
    	cout<<"\n\nPresiona cualquier tecla para regresar al menu";
        getch();
    }
    }while(opc!=7); 
}

void menu_ingresar(){
		int i, opc;
		do{
        system("CLS");
	    fecha();
  		system("COLOR B");
  		
        for(i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
  		gotoxy(20,10); //---Menu de ingreso---
  		cout<<"******************************************"<<endl;
  		gotoxy(20,11);
  		cout<<"*	                                    *"<<endl;
  		gotoxy(20,12);
  		cout<<"*	    IGLESIAS MINUTOS DE DIOS!       *"<<endl;
  		gotoxy(20,13);
  		cout<<"*	                                    *"<<endl;
  		gotoxy(20,14);
  		cout<<"*	    1) Para Feligreses              *"<<endl;
  		gotoxy(20,15);
  		cout<<"*	    2) Para Iglesias                *"<<endl;
  		gotoxy(20,16);
  		cout<<"*	    3) Para Localidades             *"<<endl;
  		gotoxy(20,17);
  		cout<<"*	    4) Volver                       *"<<endl;
  		gotoxy(20,18);
  		cout<<"*	                                    *"<<endl;
  		gotoxy(20,19);
  		cout<<"******************************************"<<endl;
		gotoxy(28,21);
  		cin>>opc;
  		switch(opc){
        case 1:
        	    system("CLS");
                menu_feligreses();
                break;
        case 2:
        	    system("CLS");
                menu_iglesias();
                break; 
		case 3:
        	    system("CLS");
                menu_localidades();
                break;      
        }
    //--------Solo para cuando sea una de las opciones-------------
    if(opc<4){
    	cout<<"\n\nPresiona cualquier tecla para regresar al menu";
        getch();
    }
    }while(opc!=4); 
}

void menu_feligreses(){
	int i, opc;
	    fecha();
  		do{
        system("CLS");
        system ("COLOR B");
		fecha(); 
        for(i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(20,7);
  	    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	    gotoxy(33,9);
	    textcolor (WHITE);
        cout<<"FELIGRESES"<<endl;
        gotoxy(30,11);
        textcolor (LIGHTCYAN);
        cout<<"1> Para ingresar"<<endl;
        gotoxy(30,12);
        cout<<"2> Para editar"<<endl;
        gotoxy(30,13);
        cout<<"3> Para eliminar"<<endl;
        gotoxy(30,14);
        cout<<"4> Volver"<<endl;
        gotoxy(20,19);
  	    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        gotoxy(33,16);
        textcolor (WHITE);
        cout<<"Ingrese Opcion"<<endl;
        gotoxy(40,18);
        cin>>opc;
        switch(opc){
        case 1:
        	    system("CLS");
					Crear_Feligres();
					Agregar_Feligres();
                break;
        case 2:
        	    system("CLS");
              		Editar_Feligres();
                break;       
        case 3: 
                system("CLS");
              		Borrar_Feligres();
                break;
        }
    //--------Solo para cuando sea una de las opciones-------------
    if(opc<4){
    	cout<<"\n\nPresiona cualquier tecla para regresar al menu";
        getch();
    }
    }while(opc!=4); 
}

void menu_iglesias(){
	int i, opc;
	    fecha();
  		do{
        system("CLS");
        system ("COLOR C");
		fecha(); 
        for(i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(20,7);
  	    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	    gotoxy(33,9);
	    textcolor (WHITE);
        cout<<"IGLESIAS"<<endl;
        gotoxy(30,11);
        textcolor (LIGHTRED);
        cout<<"1> Para ingresar"<<endl;
        gotoxy(30,12);
        cout<<"2> Para editar"<<endl;
       gotoxy(30,13);
        cout<<"3> Para eliminar"<<endl;
        gotoxy(30,14);
        cout<<"4> Volver"<<endl;
        gotoxy(20,19);
  	    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        gotoxy(33,16);
        textcolor (WHITE);
        cout<<"Ingrese Opcion"<<endl;
        gotoxy(40,18);
        cin>>opc;
        switch(opc){
        case 1:
        	    system("CLS");
        	    	Crear_Iglesia();
					Agregar_Iglesia();
                break;
        case 2:
        	    system("CLS");
              		Editar_Iglesia();
                break;       
        case 3: 
                system("CLS");
              		Borrar_Iglesia();
                break;
        }
    //--------Solo para cuando sea una de las opciones-------------
    if(opc<4){
    	cout<<"\n\nPresiona cualquier tecla para regresar al menu";
        getch();
    }
    }while(opc!=4); 
}

void menu_localidades(){
	int i, opc;
	    fecha();
  		do{
        system("CLS");
        system ("COLOR F");
		fecha(); 
        for(i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(20,7);
  	    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
	    gotoxy(33,9);
	    textcolor (CYAN);
        cout<<"LOCALIDADES"<<endl;
        gotoxy(30,11);
        textcolor (WHITE);
        cout<<"1> Listar localidades y sus barrios"<<endl;
        gotoxy(30,12);
        cout<<"2> Volver"<<endl;
        gotoxy(20,17);
  	    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        gotoxy(33,14);
        textcolor (CYAN);
        cout<<"Ingrese Opcion"<<endl;
        gotoxy(40,16);
        cin>>opc;
        switch(opc){
        case 1:
        	    system("CLS");
        	        Crear_Localidades();
        	        Listar_Localidad();
                break;
        }
    //--------Solo para cuando sea una de las opciones-------------
    if(opc<2){
    	cout<<"\n\nPresiona cualquier tecla para regresar al menu";
        getch();
    }
    }while(opc!=2); 
}

void menu_desarrolladores(){
	system ("COLOR 2");
    fecha(); 
    
    for(int i=1;i<81;i++){
        gotoxy(i,1);
        printf("%c",219);
    }
    for(int i=1;i<25;i++){
        gotoxy(1,i);
        printf("%c",219);
      	gotoxy(80,i);
        printf("%c",219);
    }
    string exito = "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    textbackground(LIGHTGRAY);
	int mover = 12;
	for(int i = 0 ; i <= exito.length(); i++){
    	gotoxy(mover, 8);
		cout << exito[i];
		Sleep(1);
		mover++;
	}
	cout<<endl;

    gotoxy(30,10);
    textbackground(BLACK);
    cout<<"PROGRAMA DESARROLLADO POR: ";
    gotoxy(18,12);
    cout<<"SEBASTIAN CAMILO SALAZAR IBANEZ - 20172020016";
	gotoxy(18,14);	
    cout<<"DANIEL ALEJANDRO RODRIGUEZ SUAREZ - 20172020009";
	gotoxy(18,16);
    cout<<"UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS";	
    gotoxy(18,18);
    cout<<"FACULTAD DE INGENIERIA - INGENIERIA DE SISTEMAS";
	gotoxy (12,20);
	textbackground(LIGHTGRAY);
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;		
	gotoxy (12,23);	

}
//-------------FECHA-----------------
void fecha(){
	//---Se utiliza las herramientas de la libreria time.h--- 
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];

    strftime(output, 128, "%d/%m/%y\n %H:%M", tlocal);
    gotoxy(2,2);
    cout<<output<<endl;
}

/* 
Desde aca todas las funciones para almacenar en memoria secundaria es decir en Archivos
*/
/*-----------------------------------------------------------------------------------------
Funcion que Carga el Archivo y regresa un apuntador con que se va a manejar el Archivo
Recibe: El nombre del Archivo , y el método con que se va abrir el Archivo.
Un Apuntador tipo Archivo: 
	0 - Solo Lectura 
	1 - Para crearlo de nuevo desde cero
    2 - Añadir Informacion 
	3 - Para Lectura y Escritura.
Regresa: El apuntador de tipo FILE, con el cual se abrio el Archivo*/
FILE *abrir_fichero_b(char cadena[], int metodo){
    FILE *x;
    switch(metodo){
        case 0:
            x = fopen(cadena,"rb");
            break;
        case 1:
            x = fopen(cadena,"wb");
            break;
        case 2:
            x = fopen(cadena,"ab");
            break;
        case 3:
            x = fopen(cadena,"r+b");
            break;
    }
    return x;
}
//--------------------------------------------------------------------------------
void Crear_Feligres(void){
    FILE *fp;
    char cad[4];
    fp = abrir_fichero_b(nombre_fichero_feligreses,0); //--Abre el fichero en modo lectura--
    if( fp ) //--Verifica si ya existe el Archivo en caso que se cumpla la condicion cierra el Archivo--
    {
        fclose(fp);
    }
    else{ //--Si la condicion anterior no se cumple crea el Archivo desde cero--
    	system ("COLOR C");
        fecha(); 
        for(int i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(int i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(26,13);
        cout<<"Error <NO SE ENCONTRO EL ARCHIVO DE FELIGRESE>";
        gotoxy(13,14);
        cout<<"Presiona cualquier tecla para continuar y crear el Archivo de Feligreses";
        fp = abrir_fichero_b(nombre_fichero_feligreses,1); //--Crea el fichero en caso que no exista--
        fclose(fp);
        getch();
		system("CLS");  
	}
}

/*---------------------------------------------------------------------
Funcion que sirve para agregar un registro dentro del Archivo */
void Agregar_Feligres(void){
	int opc, ID,*ran;
	int dia, mes, ano;
	const size_t BUFFER_SIZE = 1024;
	char *info = new char[BUFFER_SIZE];
	Feligres fel;
    FILE *fp;
    char cad[4];
    
    system("COLOR F0");
    fecha();
    textcolor(BLACK);
    gotoxy(25,1);
    cout<<"|Insertando datos del nuevo feligres|";
    gotoxy(25,2);
    cout<<"-------------------------------------"<<endl;
    
    fp=abrir_fichero_b(nombre_fichero_feligreses,2); //---Se abre el Archivo en modo (2) para Insertar informacion--- 
    if(!(fp)) cout<<"\n Error de apertura del archivo Feligreses.txt\n";
    else{
        //------Introduciendo los Datos del Feligres--------
        for(int i=1;i<26;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(20,7);
        textcolor(RED);
  	    cout<<"=========================================================================================="<<endl;
	    gotoxy(12,9);                                   
        cout<<"INGRESA LOS DATOS EN 'MAYUSCULA Y SEPARELAS LAS PALABRAS CON _' DEL FELIGRES"<<endl;
        gotoxy(33,11);
        textcolor (BLACK); cout<<"NOMBRE = "; 
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Nombre, info);
        gotoxy(33,12);
        textcolor (BLACK); cout<<"APELLIDO = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Apellido, info);
        gotoxy(33,13);
        do{
	        textcolor (BLACK);cout<<"TIPO DE IDENTIFICACION= "<<endl;
	        gotoxy(33,14);cout<<"<1> Cedula ciudadania"<<endl;
	        gotoxy(33,15);cout<<"<2> Cedula extranjeria"<<endl;
	        gotoxy(33,16);cout<<"<3> Tarjeta de identidad"<<endl;
	        gotoxy(40,17);textcolor(RED); cin>>opc;
    	}while(opc<0 || opc >3); 
        switch(opc){
        case 1:
			strcpy(fel.TipoID, "CC");
            break;
        case 2:
            strcpy(fel.TipoID, "CE");
            break;       
        case 3: 
            strcpy(fel.TipoID, "TI");
            break;
        }
        gotoxy(33,18);
        textcolor (BLACK); cout<<"# DE IDENTIFICACION = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.NumID, info);
        gotoxy(33,19);
        do{
	        textcolor (BLACK);cout<<"SEXO: "<<endl;
	        gotoxy(33,20);cout<<"<1> Masculino"<<endl;
	        gotoxy(33,21);cout<<"<2> Femenino"<<endl;
	        gotoxy(40,22);textcolor(RED); cin>>opc;
    	}while(opc<0 || opc>2); 
        switch(opc){
        case 1:
			strcpy(fel.Sexo, "M");;
            break;
        case 2:
            strcpy(fel.Sexo, "F");;
            break;       
        }
        gotoxy(33,23);
        textcolor (BLACK); cout<<"TEL. CELULAR = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.TEL_cel, info);    
        gotoxy(33,24);
        textcolor (BLACK); cout<<"TEL. FIJO = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.TEL_fijo, info);
		gotoxy(33,25);
        textcolor (BLACK); cout<<"EMAIL = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.e_mail, info);
		gotoxy(33,26);
        textcolor (BLACK); cout<<"FECHA NACIMIENTO  = "; 
		textcolor(RED);cout<<"Dia: "; cin>>dia;
		textcolor(RED);cout<<"Mes: "; cin>>mes;
		textcolor(RED);cout<<"Anio: "; cin>>ano;
		//Crea variables con la fecha actual para realizar la comparacion de mayoria de edad
		int diaActual = aTiempo->tm_mday;
		int mesActual = aTiempo->tm_mon + 1; 
		int anioActual = aTiempo->tm_year + 1900;
		//Creacion de las estructuras Fecha 
		Date dt1 = {dia, mes, ano}; 
		Date dt2 = {diaActual, mesActual, anioActual};
		//Comparacion para comprobar mayoria de edad
		if ((getDifference(dt1, dt2)/365)<18){
			cout<<"No se permiten edades menores a 18, vuelva a ingresar"<<endl;
			do{
				textcolor (BLACK); cout<<"FECHA NACIMIENTO  = "; 
				textcolor(BLACK);cout<<"Dia: "; textcolor(RED); cin>>dia;
				textcolor(BLACK);cout<<"Mes: "; textcolor(RED); cin>>mes;
				textcolor(BLACK);cout<<"Anio: "; textcolor(RED); cin>>ano;
				//Creacion de las estructuras Fecha 
				dt1 = {dia, mes, ano}; 
		   }while((getDifference(dt1, dt2)/365)<18);
		}			
		textcolor (BLACK); cout<<"FECHA NACIMIENTO FORMATO (DD/MM/AAAA) = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.F_nacimiento, info);
		fel.edad= getDifference(dt1, dt2)/365;
		cout<<"LA EDAD ES: "<<fel.edad<<endl;		
		gotoxy(33,27);
        textcolor (BLACK); cout<<"CIUDAD NACIMIENTO = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.C_nacimiento, info);
		gotoxy(33,28);
        textcolor (BLACK); cout<<"PAIS NACIMIENTO = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Pais_nacimiento, info);
		gotoxy(33,29);
        textcolor (BLACK); cout<<"CIUDAD DE RESIDENCIA = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Ciudad_residencia, info);
		gotoxy(33,30);
        textcolor (BLACK); cout<<"DIRECCION = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Direccion, info);
		gotoxy(33,31);
        textcolor (BLACK); cout<<"BARRIO = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Barrio, info);
		gotoxy(33,32);
        textcolor (BLACK); cout<<"ACTIVIDAD LABORAL = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.A_laboral, info);
		gotoxy(33,33);
        do{
	        textcolor (BLACK);cout<<"¿TIENE HIJOS?: "<<endl;
	        gotoxy(33,34);cout<<"<1> SI"<<endl;
	        gotoxy(33,35);cout<<"<2> NO"<<endl;
        gotoxy(40,36);textcolor(RED); cin>>opc;
    	}while(opc<0 || opc>2); 
        switch(opc){
        case 1:
        		system("CLS");
					fel.I_hijos= true;
					gotoxy(33,37);
					textcolor (BLACK); cout<<"NUMERO DE HIJOS = ";
					int numHijos;
					textcolor(RED);cin>>numHijos;
					fel.Numero_hijos= numHijos;
					ran = new int [numHijos];
					fel.Rango_edades_hijos = new int [numHijos];
					gotoxy(33,38);
					textcolor (BLACK); cout<<"RANGO DE EDADES HIJOS = "<<endl;
					gotoxy(33,39);cout<<"RANGOS -> "<<endl;
					gotoxy(33,40);cout<<"<1> [0 a 5] - <2> [6 a 10] - <3> [11 a 18] - <4> [Mayor a 18]";
					
					cout<<endl;
					for (int k=0; k<numHijos; k++){
						gotoxy(33,41+k);cout<<"En que rango se encuentra el HIJO["<<k+1<<"]:"<<endl;
						gotoxy(40,42+k);cin>>ran[k];
						fel.Rango_edades_hijos[k]= ran[k];
					}
					gotoxy(33,43+numHijos);
        			textcolor (BLACK); cout<<"IGLESIA A LA QUE ASISTE = ";
					info =  new char[BUFFER_SIZE];
					textcolor(RED);cin>>info;
					strcpy(fel.Iglesia, info);
                break;
        case 2:
              		fel.I_hijos=false;
              		fel.Numero_hijos=0;
              		gotoxy(33,37);
              		fel.Rango_edades_hijos =0;
        			textcolor (BLACK); cout<<"IGLESIA A LA QUE ASISTE = ";
					info =  new char[BUFFER_SIZE];
					textcolor(RED);cin>>info;
					strcpy(fel.Iglesia, info);
                break;       
        }
        gotoxy(20,46);
        textcolor(RED);
  	    cout<<"============================================"<<endl;
  	    
        //Se escribe la informacion digitada sobre el archivo a través del (fwrite)
        fwrite(&fel, sizeof(fel), 1, fp); 
        fclose(fp);
   }
    textcolor(BLACK);
	string exito = ".........AGREGANDO.........";
    textcolor(RED);
	gotoxy(20,48);
	cout <<  "********************************************" << endl;
	int mover = 30;
	for(int i = 0 ; i <= exito.length(); i++){
    	gotoxy(mover, 20);
		cout << exito[i];
		Sleep(40);
		mover++;
	}
	cout<<endl;
	gotoxy(27,48);
	textcolor(BLACK);
	cout<<"Feligres agregado con exito!"<<endl;
	//---Creacion de Archivo para guardar la info---
    	fstream archivo("DatosFeligreses.txt",ios::app);  //--ios::app Operaciones de añadidura sobre el txt de datos feligreses ya existente
        archivo<<""<<fel.NumID; 
        archivo<<"|"<<fel.Nombre;
        archivo<<"|"<<fel.Apellido;
        archivo<<"|"<<fel.TipoID; 
        archivo<<"|"<<fel.Sexo;
        archivo<<"|"<<fel.TEL_cel;
        archivo<<"|"<<fel.TEL_fijo; 
		archivo<<"|"<<fel.e_mail; 
		archivo<<"|"<<dia;
		archivo<<"|"<<mes;
		archivo<<"|"<<ano;
        archivo<<"|"<<fel.C_nacimiento;
        archivo<<"|"<<fel.Pais_nacimiento; 
        archivo<<"|"<<fel.Ciudad_residencia;
        archivo<<"|"<<fel.Direccion;
        archivo<<"|"<<fel.Barrio; 
        archivo<<"|"<<fel.A_laboral;
        archivo<<"|"<<hijos(fel.I_hijos); 
        archivo<<"|"<<fel.Numero_hijos;
        for(int i=0; i<fel.Numero_hijos; i++){
        	archivo<<"|"<<fel.Rango_edades_hijos[i]; 	
		}
        archivo<<"|"<<fel.Iglesia;
        archivo<<"";
    	archivo.close(); // Cerramos el archivo	
	
}
//-----Funcion que sirve para modificar los datos de un determindado producto-----
void Editar_Feligres(void){
	const size_t BUFFER_SIZE = 1024;
	char *info = new char[BUFFER_SIZE];
	FILE *fp;
    Feligres aux;
    int n;
    char cadena[25],cad[2];
    
    system ("COLOR E");
    fecha(); 
    for(int i=1;i<81;i++){
        gotoxy(i,1);
        printf("%c",219);
      	gotoxy(i,25);
        printf("%c",219);
    }
    for(int i=1;i<25;i++){
        gotoxy(1,i);
        printf("%c",219);
      	gotoxy(80,i);
        printf("%c",219);
    }
    fp=abrir_fichero_b(nombre_fichero_feligreses,3); //---Abre el Archivo para Lectura y escritura---
    if(!(fp))
        cout<<"\nError de apertura del Feligres\n";
    else{
    	gotoxy(20,7);
    	textcolor(WHITE);
  		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
		gotoxy(24,9);
		textcolor(YELLOW);
        cout<<"Digita el ID (numero de identificacion) del feligres a editar: ";
        gotoxy(40,11);
        cin>>cadena;
        //----------------Buscando el producto dentro del Archivo------------------
        while ((n=fread(&aux, sizeof(aux), 1, fp))!=0 && stricmp(aux.NumID,cadena)!=0);
        if (n==0){
            gotoxy(20,13);
            textcolor(YELLOW);
            cout<<"|No se encuentra el feligres con el ID: "<<cadena<<"|";
    	}
        else{
        	system("CLS");
        	system ("COLOR B");
        	fecha();
    	for(int i=1;i<81;i++){
        	gotoxy(i,1);
        	printf("%c",219);
      		gotoxy(i,25);
        	printf("%c",219);
    	}
    	for(int i=1;i<25;i++){
        	gotoxy(1,i);
        	printf("%c",219);
      		gotoxy(80,i);
        	printf("%c",219);
    	}
        	gotoxy(20,1);
      		textcolor(LIGHTCYAN);
  	    	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
      		gotoxy(33,3);
	    	textcolor (WHITE);
        	cout<<"|FELIGRES ENCONTRADO!|";
        	gotoxy(27,5);
        	textcolor (LIGHTCYAN);
        	cout<<"ID...........................: "<<aux.NumID<<endl;
        	gotoxy(27,6);
        	cout<<"Nombre.......................: "<<aux.Nombre<<endl;
        	gotoxy(27,7);
        	cout<<"Apellido.....................: "<<aux.Apellido<<endl;
        	gotoxy(27,8);
        	cout<<"Tipo ID......................: "<<aux.TipoID<<endl;
        	gotoxy(27,9);
        	cout<<"Ciudad de Residencia.........: "<<aux.Ciudad_residencia<<endl;
        	gotoxy(27,10);
        	cout<<"Tel. Celular.................: "<<aux.TEL_cel<<endl;
        	gotoxy(27,11);
        	cout<<"Iglesia a la que asiste.........: "<<aux.Iglesia<<endl;
        	gotoxy(20,13);
      		textcolor(LIGHTCYAN);
  	    	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
        	//---Cambio de los datos para el producto--- 
      		gotoxy(34,14);
	    	textcolor (WHITE);
        	cout<<"|CAMBIA LOS DATOS EN MAYUSCULAS|";
        	gotoxy(27,16);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el nuevo ID=  ";cin>>info; strcpy(aux.NumID, info);
        	gotoxy(27,17);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el Nombre = ";cin>>info; strcpy(aux.Nombre, info);
        	gotoxy(27,18);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el Apellido = ";cin>>info; strcpy(aux.Apellido, info);
        	gotoxy(27,19);
        	char tipo[3];
        	cout<<"Ingrese el tipo de ID (CC), (CE), (TI)= ";cin>>tipo; strcpy(aux.TipoID, tipo);
        	gotoxy(27,20);
        	char sexo[2];
        	cout<<"Ingrese el sexo  (M), (F) = ";cin>>sexo; strcpy(aux.Sexo, sexo);
        	gotoxy(27,21);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el telefono celular = ";cin>>info; strcpy(aux.TEL_cel, info);
        	gotoxy(27,22);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el telefono fijo = ";cin>>info; strcpy(aux.TEL_fijo, info);
        	gotoxy(27,23);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el e-mail = ";cin>>info; strcpy(aux.e_mail, info);
        	gotoxy(27,24);
        	cout<<"Fecha de nacimiento no se puede cambiar = "; aux.F_nacimiento;
        	gotoxy(27,25);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese ciudad de residencia= ";cin>>info; strcpy(aux.Ciudad_residencia, info);
        	gotoxy(27,26);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese direccion = ";cin>>info; strcpy(aux.Direccion, info);
        	gotoxy(27,27);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese barrio = ";cin>>info; strcpy(aux.Barrio, info);
        	gotoxy(27,28);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese actividad laboral = ";cin>>info; strcpy(aux.A_laboral, info);
        	gotoxy(27,29);
        	int hijos;
        	cout<<"Ingrese numero de hijos= ";cin>>hijos; aux.Numero_hijos=hijos;
        	gotoxy(27,30);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese iglesia a la que asiste = ";cin>>info; strcpy(aux.Iglesia, info);
            gotoxy(27,32);
        	cout<<"\nGUARDANDO CAMBIOS Y CERRANDO ARCHIVO...";
        	textcolor(WHITE);
			string exito = "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        	textcolor(LIGHTCYAN);
	    	int mover = 1;
	    	for(int i = 0 ; i <= exito.length(); i++){
    		gotoxy(mover, 25);
			cout << exito[i];
			Sleep(20);
			mover++;
			}
			cout<<endl;
		//--Sobreescribe los nuevos datos al Archivo--
        fseek(fp,-1*sizeof(aux),SEEK_CUR);
        fwrite(&aux, sizeof(aux), 1, fp);
      	}
      	fclose(fp);  //---Cerramos el archivo---
    }
    gotoxy (12,22);	
}

void Borrar_Feligres(void){
	FILE *fp,*fd;
    Feligres aux;
    int encontrado=0;
    char cadena[25];
    
    system ("COLOR 7");
    fecha(); 
    for(int i=1;i<81;i++){
        gotoxy(i,1);
        printf("%c",219);
      	gotoxy(i,25);
        printf("%c",219);
    }
    for(int i=1;i<25;i++){
        gotoxy(1,i);
        printf("%c",219);
      	gotoxy(80,i);
        printf("%c",219);
    }
    gotoxy(20,7);
    textcolor(LIGHTGRAY);
  	cout<<"========================================================"<<endl;
	gotoxy(24,9);                                   
    cout<<" INGRESA EL ID (#IDENTIFICACION) DEL FELIGRES A BORRAR: "<<endl;
    gotoxy(41,11); 
    cin>>cadena;
   
    string exito = "Buscando feligres......";
        textcolor(LIGHTGRAY);
	    int mover = 32;
	    for(int i = 0 ; i <= exito.length(); i++){
    	gotoxy(mover, 13);
		cout << exito[i];
		Sleep(30);
		mover++;
	}
	cout<<endl;
    
	fp=abrir_fichero_b(nombre_fichero_feligreses,0); //---Abre el fichero---
    if(!(fp))
        cout<<"\nError de apuertura del archivo Feligres.txt\n";
    else{
        fd=abrir_fichero_b("paso.$$$",1); //--Realiza la creacion de un archivo auxiliar para poder borrar los datos--
        if(!(fd))
            cout<<"\nError Imposible crear archivo auxiliar\n";
        else{
            while ((fread(&aux, sizeof(aux), 1, fp))!=0)
                /*Compara las cadenas aux.ID y cadena a través de stricmp y verifica 
				  a través de un condicional que las cadenas sean iguales para poder borrar el producto*/
				if(stricmp(aux.NumID,cadena)!=0) 
                fwrite(&aux, sizeof(aux), 1, fd);
            else
                encontrado=1;
        fclose(fd); //---Cierra el Archivo auxiliar creado---
        }
        fclose(fp); //---Cierra el Archivo principal---
        if(encontrado){
        system("del Feligres.txt"); 
        system("ren paso.$$$ Feligres.txt");
        gotoxy(30,15);
        cout<<"El feligres fue encontrado!";
        gotoxy(29,16);
        cout<<"_____________________________";
        
		string exito = "FELIGRES BORRADO CON EXITO!!!";
        textcolor(LIGHTGRAY);
	    int mover = 29;
	    for(int i = 0 ; i <= exito.length(); i++){
    	    gotoxy(mover, 17);
		    cout << exito[i];
		    Sleep(30);
		    mover++;
	    }
	    cout<<endl;
        }
        else{
            system("del paso.$$$");
            gotoxy(18,16);
            cout<<"________________________________________________";
            gotoxy(18,17);
            cout<<"El feligres no se encontro, no pudo ser borrado!";
        }
    }
    gotoxy (12,22);	
}
void Listar_Feligres(void){
    FILE *fp;
    Feligres aux;
    
    system ("COLOR B");
    fecha(); 
    for(int i=1;i<81;i++){
        gotoxy(i,1);
        printf("%c",219);
      	gotoxy(i,25);
        printf("%c",219);
    }
    
    fp = abrir_fichero_b(nombre_fichero_feligreses,0); //---Recupera el Archivo en modo lectura---
    if(!(fp)) cout<<"\n Error de apertura del archivo Inventario.txt\n";
    else{
   	gotoxy(20,2);
    textcolor(WHITE);
    cout<<"******************************************"<<endl;
	textcolor(LIGHTCYAN);
	gotoxy (29,3);
	cout<<"FELIGRESES UNIMINUTO\n\n"<<endl;
	gotoxy(20,4);
	textcolor(WHITE);
    cout<<"******************************************"<<endl;
    //------------------------------TABLA DE ALGUNOS DATOS DE LOS FELIGRESE-----------------------------
		textcolor(WHITE);
		gotoxy(1,6);	
	    cout <<" ------------------------------------------------------------------------------"<<endl;
	    textcolor (LIGHTCYAN);
	    gotoxy(1,7);
	    cout <<" "<< "|  ID  |" << setw(10) <<" NOMBRE |" << setw(10) << "   APELLIDO   |" << setw(11)
	    << " TIPO ID |" << setw(10) << "  CELULAR |" << setw(11) << "CIUDAD|" << setw(3) << "# HIJOS|"<< setw(10) << "IGLESIA"<< endl;
		
		textcolor(WHITE);
		gotoxy(1,8);
	    cout <<" ------------------------------------------------------------------------------"<<endl;
        while ((fread(&aux, sizeof(aux), 1, fp))!=0){
	    cout <<" | "<< setw(4)<< aux.NumID<<" |" << setw(7) <<  aux.Nombre<<" |"
		<< setw(12) <<  aux.Apellido<<"|" << setw(8) << aux.TipoID<<"  |" << setw(12) 
		<<  aux.TEL_cel<<" |" << setw(9) <<  aux.Ciudad_residencia<<" |"<<setw(3) <<  aux.Numero_hijos<<" |" <<setw(10) << aux.Iglesia<< endl;
		cout <<" ------------------------------------------------------------------------------"<<endl;	
        }   
        fclose(fp);
    }
    gotoxy(1,22);
}

//--------------------------------------------------------------------------------
void Crear_Iglesia(void){
    FILE *fp;
    char cad[4];
    fp = abrir_fichero_b(nombre_fichero_iglesias,0); //--Abre el fichero en modo lectura--
    if( fp ) //--Verifica si ya existe el Archivo en caso que se cumpla la condicion cierra el Archivo--
    {
        fclose(fp);
    }
    else{ //--Si la condicion anterior no se cumple crea el Archivo desde cero--
    	system ("COLOR C");
        fecha(); 
        for(int i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(int i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(26,13);
        cout<<"Error <NO SE ENCONTRO EL ARCHIVO DE IGLESIA.txt>";
        gotoxy(13,14);
        cout<<"Presiona cualquier tecla para continuar y crear el Archivo de Feligreses";
        fp = abrir_fichero_b(nombre_fichero_iglesias,1); //--Crea el fichero en caso que no exista--
        fclose(fp);
        getch();
		system("CLS");  
	}
}

/*---------------------------------------------------------------------
Funcion que sirve para agregar un registro dentro del Archivo */
void Agregar_Iglesia(void){
	const size_t BUFFER_SIZE = 1024;
	char *info = new char[BUFFER_SIZE];
	IglesiaArc fel;
    FILE *fp;
    char cad[4];
    
    system("COLOR F0");
    fecha();
    textcolor(BLACK);
    gotoxy(25,1);
    cout<<"|Insertando datos de la iglesia|";
    gotoxy(25,2);
    cout<<"-------------------------------------"<<endl;
    
    fp=abrir_fichero_b(nombre_fichero_iglesias,2); //---Se abre el Archivo en modo (2) para Insertar informacion--- 
    if(!(fp)) cout<<"\n Error de apertura del archivo Iglesia.txt\n";
    else{
        //------Introduciendo los Datos del Feligres--------
        for(int i=1;i<26;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(20,7);
        textcolor(RED);
  	    cout<<"========================================================================"<<endl;
	    gotoxy(27,9);                                   
        cout<<"INGRESA LOS DATOS DEL LA IGLESIA EN MAYUSCULAS Y SEPARADOS CON '_'"<<endl;
        gotoxy(33,11);
        textcolor (BLACK); cout<<"NOMBRE = "; 
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Nombre, info);
        gotoxy(33,12);
        textcolor (BLACK); cout<<"DIRECCION = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Direccion, info);
        gotoxy(33,13);
        textcolor (BLACK); cout<<"BARRIO = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.Barrio, info);
		gotoxy(33,14);
        textcolor (BLACK); cout<<"NOMBRE DEL SACERDOTE = ";
		info =  new char[BUFFER_SIZE];
		textcolor(RED);cin>>info;
		strcpy(fel.NombreSacer, info);
        gotoxy(20,16);
        textcolor(RED);
  	    cout<<"============================================"<<endl;
  	    
        //Se escribe la informacion digitada sobre el archivo a través del (fwrite)
        fwrite(&fel, sizeof(fel), 1, fp); 
        fclose(fp);
   }
    textcolor(BLACK);
	string exito = ".........AGREGANDO.........";
    textcolor(RED);
	gotoxy(20,48);
	cout <<  "********************************************" << endl;
	int mover = 30;
	for(int i = 0 ; i <= exito.length(); i++){
    	gotoxy(mover, 20);
		cout << exito[i];
		Sleep(40);
		mover++;
	}
	cout<<endl;
	gotoxy(27,48);
	textcolor(BLACK);
	cout<<"Iglesia agregada con exito!"<<endl;
	//---Creacion de Archivo para guardar la info---
    	fstream archivo("DatosIglesias.txt",ios::app);  //--ios::app Operaciones de añadidura para las iglesias que ya estaban--
        archivo<<"\n"<<fel.Nombre; 
        archivo<<"|"<<fel.Direccion;
        archivo<<"|"<<fel.Barrio; 
        archivo<<"|"<<fel.NombreSacer;
        archivo<<"";
    	archivo.close(); // Cerramos el archivo	
}
//-----Funcion que sirve para modificar los datos de un determindado producto-----
void Editar_Iglesia(void){
	const size_t BUFFER_SIZE = 1024;
	char *info = new char[BUFFER_SIZE];
	FILE *fp;
    IglesiaArc aux;
    int n;
    char cadena[25],cad[2];
    
    system ("COLOR E");
    fecha(); 
    for(int i=1;i<81;i++){
        gotoxy(i,1);
        printf("%c",219);
      	gotoxy(i,25);
        printf("%c",219);
    }
    for(int i=1;i<25;i++){
        gotoxy(1,i);
        printf("%c",219);
      	gotoxy(80,i);
        printf("%c",219);
    }
    fp=abrir_fichero_b(nombre_fichero_iglesias,3); //---Abre el Archivo para Lectura y escritura---
    if(!(fp))
        cout<<"\nError de apertura de la iglesia\n";
    else{
    	gotoxy(20,7);
    	textcolor(WHITE);
  		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
		gotoxy(24,9);
		textcolor(YELLOW);
        cout<<"Digita el nombre de la iglesia a editar: ";
        gotoxy(40,11);
        cin>>cadena;
        //----------------Buscando el producto dentro del Archivo------------------
        while ((n=fread(&aux, sizeof(aux), 1, fp))!=0 && stricmp(aux.Nombre,cadena)!=0);
        if (n==0){
            gotoxy(20,13);
            textcolor(YELLOW);
            cout<<"|No se encuentra la iglesia: "<<cadena<<"|";
    	}
        else{
        	system("CLS");
        	system ("COLOR B");
        	fecha();
    	for(int i=1;i<81;i++){
        	gotoxy(i,1);
        	printf("%c",219);
      		gotoxy(i,25);
        	printf("%c",219);
    	}
    	for(int i=1;i<25;i++){
        	gotoxy(1,i);
        	printf("%c",219);
      		gotoxy(80,i);
        	printf("%c",219);
    	}
        	gotoxy(20,1);
      		textcolor(LIGHTCYAN);
  	    	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
      		gotoxy(33,3);
	    	textcolor (WHITE);
        	cout<<"|IGLESIA ENCONTRADA!|";
        	gotoxy(27,5);
        	textcolor (LIGHTCYAN);
        	cout<<"Nombre..........................: "<<aux.Nombre<<endl;
        	gotoxy(27,6);
        	cout<<"Direccion.......................: "<<aux.Direccion<<endl;
        	gotoxy(27,7);
        	cout<<"Barrio..........................: "<<aux.Barrio<<endl;
        	gotoxy(27,8);
        	cout<<"Nombre Sacerdote................: "<<aux.NombreSacer<<endl;
        	gotoxy(20,10);
      		textcolor(LIGHTCYAN);
  	    	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
        	//---Cambio de los datos para la iglesia--- 
      		gotoxy(34,12);
	    	textcolor (WHITE);
        	cout<<"|CAMBIA LOS DATOS DE LA IGLESIA EN MAYUSCULAS Y PALABRAS SEPARADAS CON '_'|";
        	gotoxy(27,13);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el nuevo nombre =  ";cin>>info; strcpy(aux.Nombre, info);
        	gotoxy(27,14);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese la nueva direccion = ";cin>>info; strcpy(aux.Direccion, info);
        	gotoxy(27,15);
        	info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el nuevo barrio = ";cin>>info; strcpy(aux.Barrio, info);
        	gotoxy(27,16);
    		info =  new char[BUFFER_SIZE];
        	cout<<"Ingrese el nombre de cura ";cin>>info; strcpy(aux.NombreSacer, info);
            gotoxy(27,18);
        	cout<<"\nGUARDANDO CAMBIOS Y CERRANDO ARCHIVO...";
        	textcolor(WHITE);
			string exito = "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        	textcolor(LIGHTCYAN);
	    	int mover = 1;
	    	for(int i = 0 ; i <= exito.length(); i++){
    		gotoxy(mover, 25);
			cout << exito[i];
			Sleep(20);
			mover++;
			}
			cout<<endl;
		//--Sobreescribe los nuevos datos al Archivo--
        fseek(fp,-1*sizeof(aux),SEEK_CUR);
        fwrite(&aux, sizeof(aux), 1, fp);
      	}
      	fclose(fp);  //---Cerramos el archivo---
    }
    gotoxy (12,22);	
}

void Borrar_Iglesia(void){
	FILE *fp,*fd;
    IglesiaArc aux;
    int encontrado=0;
    char cadena[25];
    
    system ("COLOR 7");
    fecha(); 
    for(int i=1;i<81;i++){
        gotoxy(i,1);
        printf("%c",219);
      	gotoxy(i,25);
        printf("%c",219);
    }
    for(int i=1;i<25;i++){
        gotoxy(1,i);
        printf("%c",219);
      	gotoxy(80,i);
        printf("%c",219);
    }
    gotoxy(20,7);
    textcolor(LIGHTGRAY);
  	cout<<"============================================"<<endl;
	gotoxy(24,9);                                   
    cout<<" INGRESA EL NOMBRE DE LA IGLESIA A BORRAR: "<<endl;
    gotoxy(41,11); 
    cin>>cadena;
   
    string exito = "Buscando producto......";
        textcolor(LIGHTGRAY);
	    int mover = 32;
	    for(int i = 0 ; i <= exito.length(); i++){
    	gotoxy(mover, 13);
		cout << exito[i];
		Sleep(30);
		mover++;
	}
	cout<<endl;
    
	fp=abrir_fichero_b(nombre_fichero_iglesias,0); //---Abre el fichero---
    if(!(fp))
        cout<<"\nError de apuertura del archivo Iglesia.txt\n";
    else{
        fd=abrir_fichero_b("paso.$$$",1); //--Realiza la creacion de un archivo auxiliar para poder borrar los datos--
        if(!(fd))
            cout<<"\nError Imposible crear archivo auxiliar\n";
        else{
            while ((fread(&aux, sizeof(aux), 1, fp))!=0)
                /*Compara las cadenas aux.ID y cadena a través de stricmp y verifica 
				  a través de un condicional que las cadenas sean iguales para poder borrar el producto*/
				if(stricmp(aux.Nombre,cadena)!=0) 
                fwrite(&aux, sizeof(aux), 1, fd);
            else
                encontrado=1;
        fclose(fd); //---Cierra el Archivo auxiliar creado---
        }
        fclose(fp); //---Cierra el Archivo principal---
        if(encontrado){
        system("del Iglesia.txt"); 
        system("ren paso.$$$ Iglesia.txt");
        gotoxy(30,15);
        cout<<"La iglesia fue encontrada!";
        gotoxy(29,16);
        cout<<"_____________________________";
        
		string exito = "IGLESIA BORRADA CON EXITO!!!";
        textcolor(LIGHTGRAY);
	    int mover = 29;
	    for(int i = 0 ; i <= exito.length(); i++){
    	    gotoxy(mover, 17);
		    cout << exito[i];
		    Sleep(30);
		    mover++;
	    }
	    cout<<endl;
        }
        else{
            system("del paso.$$$");
            gotoxy(18,16);
            cout<<"________________________________________________";
            gotoxy(18,17);
            cout<<"La iglesia no se encontro, no pudo ser borrada!";
        }
    }
    gotoxy (12,22);	
}
//--------------------------------------------------------------------------------
void Crear_Localidades(void){
    FILE *fp;
    char cad[4];
    fp = abrir_fichero_b(nombre_fichero_localidades,0); //--Abre el fichero en modo lectura--
    if( fp ) //--Verifica si ya existe el Archivo en caso que se cumpla la condicion cierra el Archivo--
    {
        fclose(fp);
    }
    else{ //--Si la condicion anterior no se cumple crea el Archivo desde cero--
    	system ("COLOR C");
        fecha(); 
        for(int i=1;i<81;i++){
        	gotoxy(i,1);
          	printf("%c",219);
      		gotoxy(i,25);
          	printf("%c",219);
        }
        for(int i=1;i<25;i++){
        	gotoxy(1,i);
          	printf("%c",219);
      		gotoxy(80,i);
          	printf("%c",219);
        }
        gotoxy(26,13);
        cout<<"Error <NO SE ENCONTRO EL ARCHIVO DE LOCALIDADES.txt>";
        gotoxy(13,14);
        cout<<"Presiona cualquier tecla para continuar y crear el Archivo de LOCALIDADES";
        fp = abrir_fichero_b(nombre_fichero_localidades,1); //--Crea el fichero en caso que no exista--
        fclose(fp);
        getch();
		system("CLS");  
	}
}

/*---------------------------------------------------------------------
Funcion que sirve para agregar un registro dentro del Archivo */
void Listar_Localidad(void){
    FILE *fp;
    char cad[4];
    Localidad  aux;
    system("COLOR F0");
    fecha();
    textcolor(BLACK);
    gotoxy(25,1);
    cout<<"|Listando datos de la localidad|";
    gotoxy(25,2);
    cout<<"-------------------------------------"<<endl;
    
    fp=abrir_fichero_b(nombre_fichero_localidades,2); //---Se abre el Archivo en modo (2) para Insertar informacion--- 
    if(!(fp)) cout<<"\n Error de apertura del archivo Localidad.txt\n";
    else{
        while ((fread(&aux, sizeof(aux), 1, fp))!=0){
	    	cout<<aux.Nombre<<endl;
        }   
        fclose(fp);       
   }
}
   void leerarchivoFeligres(){
   		const string datostxt= "DatosFeligreses.txt";
   		char lineas[400];
   		char separador = '|';
   		string lineas2;
   		ifstream fichero;
   		fichero.open(datostxt.c_str());
   		if(!fichero.fail()){
   			fichero.getline(lineas, 400, '\n');
   			lineas2 = lineas;	
   			splitFeligres(lineas2, '|');
   			while(!fichero.eof()){ 			    		
   				cout<< lineas << endl;
   				fichero.getline(lineas, 400, '\n');	
   				lineas2= lineas;
   				splitFeligres(lineas2, '|');
		   }
		fichero.close();   	
		}

   }
   
   void splitFeligres(string str, char pattern) { //Funcion que me hace el split al txt de los datos
	    int posInit = 0;
	    int posFound = 0;
	    int dia, mes, ano, numHijos;
	    string splitted;
	    vector<string> resultados;
	    
	    while(posFound >= 0){
	        posFound = str.find(pattern, posInit);
	        splitted = str.substr(posInit, posFound - posInit);
	        posInit = posFound + 1;
	        resultados.push_back(splitted);
	    }	
			Feligres feli; //Aca inserto todos los datos a al objeto  -->Esta es para el archivo y su manejo pues solo se puede con datos nativos y no strings
			feligres felim; //Aca es para insertar en la multilista -->Esta es para la multilista
	    	if(resultados.size() >20 && resultados.size() != 0){//--Si tienes mas de 20 pocisiones es porque tiene hijos
		    	strcpy(feli.NumID,resultados[0].c_str());
		    	felim.numID = resultados[0];
		    	strcpy(feli.Nombre,resultados[1].c_str());
		    	felim.nombre = resultados[1];
		    	strcpy(feli.Apellido,resultados[2].c_str());
		    	felim.apellido = resultados [2];
		    	strcpy(feli.TipoID,resultados[3].c_str());
		    	felim.tipoID = resultados[3];
				strcpy(feli.Sexo,resultados[4].c_str());
				felim.sexo = resultados[4];
				strcpy(feli.TEL_cel,resultados[5].c_str());
				felim.telefonoC = resultados[5];
				strcpy(feli.TEL_fijo,resultados[6].c_str());
				felim.telefonoF = resultados[6];
				strcpy(feli.e_mail,resultados[7].c_str());
				felim.eMail = resultados[7];
				dia =  atoi(resultados[8].c_str());
				mes =  atoi(resultados[9].c_str());
				ano =  atoi(resultados[10].c_str());
				//Crea variables con la fecha actual para realizar la comparacion de mayoria de edad
				int diaActual = aTiempo->tm_mday;
				int mesActual = aTiempo->tm_mon + 1; 
				int anioActual = aTiempo->tm_year + 1900;
				//Creacion de las estructuras Fecha 
				Date dt1 = {dia, mes, ano}; 
				Date dt2 = {diaActual, mesActual, anioActual};
				felim.edad = getDifference(dt1, dt2)/365;
				strcpy(feli.F_nacimiento,resultados[10].c_str());
				felim.f_nacimiento = resultados[10];
				strcpy(feli.C_nacimiento,resultados[11].c_str());
				felim.ciudadN = resultados[11];
				strcpy(feli.Pais_nacimiento,resultados[12].c_str());
				felim.paisN = resultados[12];
				strcpy(feli.Ciudad_residencia,resultados[13].c_str());
				felim.ciudadR = resultados[13];
				strcpy(feli.Direccion,resultados[14].c_str());
				felim.direccion = resultados[14];
				strcpy(feli.Barrio,resultados[15].c_str());
				felim.barrio = resultados[15];
				strcpy(feli.A_laboral,resultados[16].c_str());
				felim.actLaboral = resultados[16];
				feli.I_hijos = true;
				felim.hijos = true;
				numHijos = atoi(resultados[18].c_str());
				felim.numHijos = numHijos;
				feli.Numero_hijos= numHijos;
				int *ran, i=0;
				ran = new int [numHijos];
				feli.Rango_edades_hijos = new int [numHijos];
				for (int k=19; k<(19+numHijos); k++){
					ran[i] = atoi(resultados[k].c_str());
					feli.Rango_edades_hijos[i]= ran[i]; //---En el archivo si estoy mandando el arreglo de rango de hijos
					i++;
				}
				felim.rangEdadHijos = feli.Rango_edades_hijos;	//--Pongo esto mientras Javier lo arregla para mandar un arreglo xd	
				strcpy(feli.Iglesia,resultados[19+numHijos].c_str());
				felim.iglesia = resultados[19+numHijos];
				felim.sigActividad =0; //...Inicializo las cabeceras en 0...
				felim.sigBarrio =0;
				felim.sigCiudad=0;
				felim.sigEdad=0;
				felim.sigIglesia=0;
				felim.sigNumHijos=0;
				felim.sigSexo=0;
				//---Aca ahora inserto los datos al archivo serializado con el que se va a trabajar los datos 
				//---Se va insertado linea por linea de los datos del txt
				FILE *fp;
	    		Crear_Feligres();
	    		fp=abrir_fichero_b(nombre_fichero_feligreses,2); //---Se abre el Archivo en modo (2) para Insertar informacion--- 
			    if(!(fp)) cout<<"\n Error de apertura del archivo Iglesia.txt\n";
			    else{
			        //Se escribe la informacion digitada sobre el archivo a través del (fwrite)
			        fwrite(&feli, sizeof(feli), 1, fp); 
			        fclose(fp);
		      	}
			}else if (resultados.size() > 3 && resultados.size() <=20){ //--No tiene hijos
				strcpy(feli.NumID,resultados[0].c_str());
				felim.numID = resultados[0];
		    	strcpy(feli.Nombre,resultados[1].c_str());
		    	felim.nombre = resultados[1];
		    	strcpy(feli.Apellido,resultados[2].c_str());
		    	felim.apellido = resultados[2];
		    	strcpy(feli.TipoID,resultados[3].c_str());
		    	felim.tipoID = resultados[3];
				strcpy(feli.Sexo,resultados[4].c_str());
				felim.sexo = resultados[4];
				strcpy(feli.TEL_cel,resultados[5].c_str());
				felim.telefonoC = resultados[5];
				strcpy(feli.TEL_fijo,resultados[6].c_str());
				felim.telefonoF = resultados[6];
				strcpy(feli.e_mail,resultados[7].c_str());
				felim.eMail = resultados[7];
				dia =  atoi(resultados[8].c_str());
				mes =  atoi(resultados[9].c_str());
				ano =  atoi(resultados[10].c_str());
				//Crea variables con la fecha actual para realizar la comparacion de mayoria de edad
				int diaActual = aTiempo->tm_mday;
				int mesActual = aTiempo->tm_mon + 1; 
				int anioActual = aTiempo->tm_year + 1900;
				//Creacion de las estructuras Fecha 
				Date dt1 = {dia, mes, ano}; 
				Date dt2 = {diaActual, mesActual, anioActual};
				felim.edad = getDifference(dt1, dt2)/365;
				strcpy(feli.F_nacimiento,resultados[10].c_str());
				felim.f_nacimiento = resultados[10];
				strcpy(feli.C_nacimiento,resultados[11].c_str());
				felim.ciudadN= resultados[11];
				strcpy(feli.Pais_nacimiento,resultados[12].c_str());
				felim.paisN = resultados[12];
				strcpy(feli.Ciudad_residencia,resultados[13].c_str());
				felim.ciudadR= resultados[13];
				strcpy(feli.Direccion,resultados[14].c_str());
				felim.direccion = resultados[14];
				strcpy(feli.Barrio,resultados[15].c_str());
				felim.barrio = resultados[15];
				strcpy(feli.A_laboral,resultados[16].c_str());
				felim.actLaboral = resultados[16];
				feli.I_hijos = false;
				felim.hijos = false;
				feli.Numero_hijos = 0;
				felim.numHijos = 0;
				feli.Rango_edades_hijos = 0;
				felim.rangEdadHijos = feli.Rango_edades_hijos;	
				strcpy(feli.Iglesia,resultados[19].c_str());
				felim.iglesia = resultados[19];
				felim.sigActividad =0; //...Inicializo las cabeceras en 0...
				felim.sigBarrio =0;
				felim.sigCiudad=0;
				felim.sigEdad=0;
				felim.sigIglesia=0;
				felim.sigNumHijos=0;
				felim.sigSexo=0;
				//---Aca ahora inserto los datos al archivo serializado con el que se va a trabajar los datos 
				//---Se va insertado linea por linea de los datos del txt
				FILE *fp;
	    		Crear_Feligres();
	    		fp=abrir_fichero_b(nombre_fichero_feligreses,2); //---Se abre el Archivo en modo (2) para Insertar informacion--- 
			    if(!(fp)) cout<<"\n Error de apertura del archivo Iglesia.txt\n";
			    else{
			        //Se escribe la informacion digitada sobre el archivo a través del (fwrite)
			        fwrite(&feli, sizeof(feli), 1, fp); 
			        fclose(fp);
		        }
			}else{
				cout<<"Todos los datos fueron leidos"<<endl;
			}
			/*---------------------------------------------------------------------------------
		        	 Aca hago la insercion de el feligres a la multilista segun se vaya leyendo
		    ---------------------------------------------------------------------------------*/
		    miLista.insertar(felim);//---Inserto el feligres a la multilista 
}

void leerarchivoIglesias(){
   		const string datostxt= "DatosIglesias.txt";
   		char lineas[400];
   		char separador = '|';
   		string lineas2;
   		ifstream fichero;
   		fichero.open(datostxt.c_str());
   		if(!fichero.fail()){
   			fichero.getline(lineas, 400, '\n');
   			lineas2 = lineas;	
   			splitIglesias(lineas2, '|');
   			while(!fichero.eof()){ 			    		
   				cout<< lineas << endl;
   				fichero.getline(lineas, 400, '\n');	
   				lineas2= lineas;
   				splitIglesias(lineas2, '|');
		   }
		fichero.close();   	
		}

}

 void splitIglesias(string str, char pattern) { //Funcion que me hace el split al txt de los datos
	    int posInit = 0;
	    int posFound = 0;
	    string splitted;
	    vector<string> resultados;
	    
	    while(posFound >= 0){
	        posFound = str.find(pattern, posInit);
	        splitted = str.substr(posInit, posFound - posInit);
	        posInit = posFound + 1;
	        resultados.push_back(splitted);
	    }
			IglesiaArc igle; //Aca inserto todos los datos a al objeto
			iglesia iglem; //Para insertar iglesias en la multilista
			iglesiaL igleml;
	    	if(resultados.size() != 0 && resultados.size() > 2){//--Si tiene 0 elementos no hay datos
		    	strcpy(igle.Nombre,resultados[0].c_str());
		    	iglem.nombre = resultados[0];	
		    	strcpy(igle.Direccion,resultados[1].c_str());
		    	iglem.direccion = resultados[1];
		    	strcpy(igle.Barrio,resultados[2].c_str());
		    	iglem.barrio = resultados[2];
		    	strcpy(igle.NombreSacer,resultados[3].c_str());
		    	iglem.sacerdote = resultados[3];
				//---Aca ahora inserto los datos al archivo serializado con el que se va a trabajar los datos 
				//---Se va insertado linea por linea de los datos del txt
				FILE *fp;
	    		Crear_Iglesia();
	    		fp=abrir_fichero_b(nombre_fichero_iglesias,2); //---Se abre el Archivo en modo (2) para Insertar informacion--- 
			    if(!(fp)) cout<<"\n Error de apertura del archivo Iglesia.txt\n";
			    else{
		        //Se escribe la informacion digitada sobre el archivo a través del (fwrite)
		        fwrite(&igle, sizeof(igle), 1, fp); 
		        fclose(fp);
		    	}
			}else{
				cout<<"Todos los datos fueron leidos"<<endl;
			}
			igleml.Iglesias.insertar(iglem,0);			
}

void leerarchivoLocalidades(){
	const string datostxt= "DatosLocalidades.txt";
   		char lineas[400];
   		char separador = '|';
   		string lineas2;
   		ifstream fichero;
   		fichero.open(datostxt.c_str());
   		if(!fichero.fail()){
   			fichero.getline(lineas, 400, '\n');
   			lineas2 = lineas;	
   			splitLocalidades(lineas2, '|');
   			while(!fichero.eof()){ 			    		
   				cout<< lineas << endl;
   				fichero.getline(lineas, 400, '\n');	
   				lineas2= lineas;
   				splitLocalidades(lineas2, '|');
		   }
		fichero.close();   	
	}
}
 void splitLocalidades(string str, char pattern) { //Funcion que me hace el split al txt de los datos
	    int posInit = 0;
	    int posFound = 0;
	    string splitted;
	    vector<string> resultados;
	    
	    while(posFound >= 0){
	        posFound = str.find(pattern, posInit);
	        splitted = str.substr(posInit, posFound - posInit);
	        posInit = posFound + 1;
	        resultados.push_back(splitted);
	    }
			Localidad loca; //Aca inserto todos los datos a al objeto
			localidad locam; //Aca inserto a la lista de localidades para despues manejar en la multilista
			localidadL locaml; 
			char *barriosaux;
			barriosaux = new char[resultados.size()-1];
	    	if(resultados.size() != 0 && resultados.size() > 2){//--Si tiene 0 elementos no hay datos
		    	strcpy(loca.Nombre,resultados[0].c_str());
		    	locam.nombre = resultados[0];
		    	for(int i=1; i<resultados.size(); i++){
					loca.barrios.insertarLista(strcpy(barriosaux,resultados[i].c_str()));
				}	   
				for(int i=1; i<resultados.size(); i++){
					locam.listaBarrios.insertarLista(resultados[i]);
				} 	
				FILE *fp;
	    		Crear_Localidades();
	    		fp=abrir_fichero_b(nombre_fichero_localidades,2); //---Se abre el Archivo en modo (2) para Insertar informacion--- 
			    if(!(fp)) cout<<"\n Error de apertura del archivo Iglesia.txt\n";
			    else{
		        //Se escribe la informacion digitada sobre el archivo a través del (fwrite)
		        fwrite(&loca, sizeof(loca), 1, fp); 
		        fclose(fp);
		    	}
			}else{
				cout<<"Todos los datos fueron leidos"<<endl;
			}
			locaml.Localidades.insertar(locam, 0);			
}

void consulta_2(int rangoI,int rangoS, Multilista miLista){
	cabeceraGeneral cab = miLista.getAtributos();;
	bool encontrado = false;
	int pos;
	for(int i = 1;i <= cab.ciudad.Ciudades.tamLista(); i++){
		int aux = cab.ciudad.Ciudades.getDato(i).cab;
		lista<feligres> l = miLista.consulta2(aux,rangoI,rangoS);
		cout<<cab.ciudad.Ciudades.getDato(i).nombre<<endl;
		for(int j = 1;j<= l.tamLista();j++){
			cout<<"Nombre :"<<l.getDato(j).nombre<<" Apellido: "<<l.getDato(j).apellido<<endl;
		}
	}
}

void consulta_3(string ciudad, Multilista miLista){
	cabeceraGeneral cab = miLista.getAtributos();
	int tamLista = cab.ciudad.Ciudades.tamLista();
	bool encontrado = false;
	int pos;
	for(int i = 1;i<=tamLista;i++){
		
		if(cab.ciudad.Ciudades.getDato(i).nombre == ciudad){
			encontrado = true;
			pos = i;
			break;
		}
	}
	if(encontrado){
		
		for(int i = 1;i <= cab.actividadL.actividades.tamLista(); i++){
			int aux = cab.actividadL.actividades.getDato(i).cab;
			lista<feligres> l = miLista.consulta3(aux,ciudad);
			cout<<cab.actividadL.actividades.getDato(i).nombre<<endl;
			for(int j = 1;j<= l.tamLista();j++){
				cout<<"Nombre :"<<l.getDato(j).nombre<<" Apellido: "<<l.getDato(j).apellido<<endl;
			}
		}
		
	}else{
		cout<<"La ciudad ingresada no existe"<<endl;
	}
}

void consulta_5(Multilista miLista){
	cabeceraGeneral cab = miLista.getAtributos();
	int tamLista = cab.iglesia.Iglesias.tamLista();
	bool encontrado = false;
	int pos;
		
	for(int i = 1;i <= tamLista; i++){
			int aux = cab.iglesia.Iglesias.getDato(i).cab;
			cout<<cab.iglesia.Iglesias.getDato(i).nombre<<endl;
			for(int j = 1;j<=cab.ciudad.Ciudades.tamLista();j++){
				string auxC = cab.ciudad.Ciudades.getDato(j).nombre;
				lista<feligres> m = miLista.consulta5(aux,auxC,0);
				lista<feligres> f = miLista.consulta5(aux,auxC,1);
				
				cout<<auxC<<endl;
				cout<<"Hombres :"<<m.tamLista()<<endl;
				cout<<"Mujeres :"<<f.tamLista()<<endl;
			}
			
		}
}


