//Sebastian Salazar - 20172020016
//Daniel Rodriguez - 20172020009
//Ciencias 1 - 2019-2

#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <string.h>

using namespace std;

struct Datos {
	string nombre , carrera , hobby ;
	int  edad , sig_nombre , sig_carrera , sig_hobby , sig_edad;
};

struct Cab {
	string caracter;
	int primero; 	
};
 
 
Datos* ordenarNom(Cab &c, Datos d[], int pos){
	if(c.primero==0){
		c.primero=pos;
		d[pos].sig_nombre=0;
	}else {
		
		int cambio=1;
		int actual=c.primero;
		int sig= d[actual].sig_nombre;
		
		if(d[actual].nombre > d[pos].nombre){
			
			c.primero=pos;
			d[pos].sig_nombre=actual;
			cambio++;
		}else
			if(sig==0){
			
				d[actual].sig_nombre=pos;
				d[pos].sig_nombre=0;
				cambio++;
			}
			
		while(cambio==1){
			
			if(d[sig].nombre>d[pos].nombre){
				
				d[actual].sig_nombre=pos;
				d[pos].sig_nombre=sig;
				cambio++;
			}else if(d[sig].sig_nombre==0){
				
				d[sig].sig_nombre=pos;
				d[pos].sig_nombre=0;
				cambio++;
			}else{
				actual=d[sig].sig_nombre;
				sig=d[actual].sig_nombre;
			}
				
		};
	
	}
	return d;
}

Datos* ordenarCarr(Cab &c, Datos d[], int pos){

	int actual;
	int cambio=1;
	if(c.primero==0){
		c.primero=pos;
		d[pos].sig_carrera=0;
		cambio++;
	}
	actual= c.primero;
	do{
		if(d[actual].sig_carrera==0){
			d[actual].sig_carrera=pos;
			d[pos].sig_carrera=0;
			cambio++;
		}else{
			actual=d[actual].sig_carrera;
		}
		
	}while(cambio==1);
	
	return d;

}
Datos* ordenarHobbys(Cab &c, Datos d[], int pos){

	if(c.primero==0){
		c.primero=pos;
		d[pos].sig_hobby=0;
	}else{
		d[pos].sig_hobby=c.primero;
		c.primero=pos;
	}
	
	return d;
}

void Imp(Datos d[], int cab, int tipo){
	
	if(cab==0){
		cout<<"No hay datos";
	}
	
	while(cab!=0){
		printf("\n");
		cout<<"Nombre: "<<d[cab].nombre<<", Carrera: "<<d[cab].carrera<<", Hobby: "<<d[cab].hobby<<", Edad: "<<d[cab].edad;
		
		switch(tipo) {
			case 1: cab=d[cab].sig_nombre;
				break;
			case 2:cab=d[cab].sig_carrera;
				break;
			case 3:cab=d[cab].sig_hobby;
				break;
			case 4:cab=d[cab].sig_edad;
				break;
		
		
		}
	};

}

Datos* ordenarEdad(Cab &c, Datos d[], int pos){
	
	if(c.primero==0){
		
		c.primero=pos;
		d[pos].sig_edad=0;
		
	}else{
		
		int cambio=1;
		int actual= c.primero;
		int sig;
		
		if(d[actual].edad < d[pos].edad){
			
			c.primero=pos;
			d[pos].sig_edad=actual;
			cambio++;	
		} else  if(d[actual].sig_edad==0){
			
					d[actual].sig_edad=pos;
					d[pos].sig_edad=0;
					cambio++;
				}
		
			
		sig= d[actual].sig_edad;		
		
		while(cambio==1){
			
			
			if(d[sig].edad < d[pos].edad){
					
					d[pos].sig_edad=d[actual].sig_edad;
					d[actual].sig_edad=pos;
					
					cambio++;
				} else 
			
					if(d[sig].sig_edad==0){
			
					
					d[sig].sig_edad=pos;
					d[pos].sig_edad=0;
					cambio++;	
			
					} else{
						
						actual = sig;
						sig= d[actual].sig_edad;
						
					}  
	
		};
		
	}
	
   return d;
}



int main(int argc, char *argv[])
{
	system("color 0A");
	
	cout<<"			***********************************************************************"<< endl;
	cout<<"					MULTILISTA ESTATICA PARA ESTUDIANTES" << endl;
	cout<<"			***********************************************************************"<< endl;
	
	Datos b[11], *dat;
	dat= b;
	Cab c[10];
	c[0].caracter="nombre";
	c[0].primero = 0;
	c[1].caracter ="IS";
	c[1].primero = 0;
	c[2].caracter ="II";
	c[2].primero = 0;
	c[3].caracter ="IE";
	c[3].primero = 0;
	c[4].caracter ="IC";
	c[4].primero = 0;
	c[5].caracter ="danza";
	c[5].primero = 0;
	c[6].caracter ="basquetbol";
	c[6].primero = 0;
	c[7].caracter ="beisbol";
	c[7].primero = 0;
	c[8].caracter ="natacion";
	c[8].primero = 0;
	c[9].caracter ="edad";
	c[9].primero = 0;
	int pos=1;
	int op=0;	
	

	do{
		printf("\n");
		printf("1- Ingresar Estudiante \n");
		printf("2- Listado por nombres\n");
		printf("3- Listado por carrera \n");
		printf("4- Listado por hobby \n");
		printf("5- Listado por edad \n");
		cin>>op;
		
		switch(op) {
			case 1: 
					if(pos<11){
						
						int carr=0;
						int hob=0;
						
						cout<<"Ingrese el nombre del estudiante \n";
						cin>>dat[pos].nombre;
						cout<<"Ingrese la carrera \n";
						cout<<"1- IS \n";
						cout<<"2- II \n";
						cout<<"3- IE \n";
						cout<<"4- IC \n";
						cin>>carr;
						dat[pos].carrera=c[carr].caracter;
						cout<<"Ingrese un hobby \n";
						cout<<"1- danza \n";
						cout<<"2- basquetbol \n";
						cout<<"3- beisbol \n";
						cout<<"4- natacion \n";
						cin>>hob;
						hob=hob+4;
						dat[pos].hobby=c[hob].caracter;
						cout<<"Ingrese la edad  \n";
						cin>>dat[pos].edad;
					
						dat= ordenarCarr(c[carr],dat,pos);
						dat= ordenarHobbys(c[hob],dat,pos);
						dat= ordenarEdad(c[9],dat,pos);
						dat= ordenarNom(c[0],dat,pos);

						pos++;
					} else {
						
						cout<<"lleno";
					}		
					
			
					break;
			case 2: 
					Imp(dat,c[0].primero,1);
					
					break;
			case 3:
					int car;
					cout<<"seleccione una carrera \n";
					cout<<"1- IS \n";
					cout<<"2- II \n";
					cout<<"3- IE \n";
					cout<<"4- IC \n";
					cin>>car;
					Imp(dat,c[car].primero,2);
	
					break;
			case 4: 
			
					int hob;
					cout<<"seleccione un hobby \n";
						cout<<"1- danza \n";
						cout<<"2- basquetbol \n";
						cout<<"3- beisbol \n";
						cout<<"4- natacion \n";
					cin>>hob;
					hob=hob+4;
					Imp(dat,c[hob].primero,3);
					break;
			case 5: 
					Imp(dat,c[9].primero,4);	
					break;
					
			case 6: puts("adios");
					break;
			default: cout<<"no valido";
		}
		
		
	}while(op != 6);
				

}
