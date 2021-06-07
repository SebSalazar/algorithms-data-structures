//Realizado por: Javier Aponte 20172020036
// 				 

#include <iostream>
#include <windows.h>
#include <fstream>
#include "lista_javier.h"
#include "feligresL.h"
#include "iglesiaL.h"
#include "localidadL.h"
#include "cabeceras/cabeceraG.h"
#include "cabeceras/cabecera.h"
#include <string>


using namespace std;


//Declaracion de la clase
class Multilista{
	cabeceraGeneral atributos;
	feligres* feligreses;
	int tam,lim;
	
	public: Multilista(int cant){
				feligreses = new feligres[cant+1];
				lim = cant;
				tam = 0;
				inicializarCab();
			}
			~Multilista();
			int tam_multi();
			void inicializarCab();
			void ordenarActividadL(string dato,int tam);
			void ordenarIglesia(string dato,int tam);
			void ordenarLocalidad(string dato,int tam);
			void ordenarSexo(string dato,int tam);
			void ordenarEdad(int dato,int tam);
			void ordenarcantHijos(int cab,int tam);
			void ordenarBarrio(string dato,int tam);
			void ordenarCiudad(string ciudad, int tama);
			void insertar(feligres e);
//			bool elminar(int pos);
			feligres buscar(int pos);
			bool multi_vacia();
			bool multi_llena();
			int compararInt(int e1,int e2);
			
			lista<feligres>* consulta1(string iglesia);
			lista<feligres> consulta2(int aux,int rangoI,int rangoS);
			lista<feligres> consulta3(int aux,string ciudad);
			lista<feligres> consulta5(int aux,string ciudad,int op);
			lista <string> consulta4(int n);
			lista<feligres> consulta6(string, string);
			cabeceraGeneral getAtributos();
			
			
			
//			ListaE* getLista();
};

//Metodos de la clase multilista

int Multilista::tam_multi(){
	return tam;
}

void Multilista::inicializarCab(){
	//Se inicializa las cabeceras que consisten en rangows cerrados
	
	cabecera a;
	//Cabecera por sexo
	a.nombre = "M";
	a.cab = 0;
	atributos.sexo.Sexo.insertar(a,0);
	a.nombre = "F";
	a.cab = 0;
	atributos.sexo.Sexo.insertar(a,0);
	
	//Cabecera por edad
	a.nombre = "18-24";
	a.cab = 0;
	atributos.edad.rangosEdades.insertar(a,0);
	a.nombre = "25-35";
	a.cab = 0;
	atributos.edad.rangosEdades.insertar(a,0);
	a.nombre = "36-45";
	a.cab = 0;
	atributos.edad.rangosEdades.insertar(a,0);
	a.nombre = "46-60";
	a.cab = 0;
	atributos.edad.rangosEdades.insertar(a,0);
	a.nombre = ">60";
	a.cab = 0;
	atributos.edad.rangosEdades.insertar(a,0);
	cout<<atributos.edad.rangosEdades.getDato(5).nombre<<endl;
	
	//Cabecera por numero de hijos
	
	a.nombre = "Hijos";
	a.cab = 0;
	atributos.numHijos.NumHijos = a;

	
	
}

feligres Multilista::buscar(int pos){
	return feligreses[pos];
}

cabeceraGeneral Multilista::getAtributos(){
	return atributos;
}

bool Multilista::multi_llena(){
	if(tam == lim)
		return true;
	return false;
}

bool Multilista::multi_vacia(){
	if(tam==0)
		return true;
	return false;
}

void Multilista::insertar(feligres f){
	if(!multi_llena()){
		
		
		feligreses[tam+1] = f;
		tam++;
		
		//rangos abiertos
		ordenarActividadL(f.actLaboral,tam);
		ordenarIglesia(f.iglesia,tam);
		ordenarBarrio(f.barrio,tam);
		ordenarCiudad(f.ciudadR,tam);
		
		//rangos cerrados
		ordenarSexo(f.sexo,tam);
		ordenarEdad(f.edad,tam);
		ordenarcantHijos(atributos.numHijos.NumHijos.cab,tam);
		
		
	}else{
		cout<< "La Multilista esta llena en este momento, no ha sido imposible insertar el dato"<<endl;
	}
	
}


// se ordenan como una pila 
void Multilista::ordenarActividadL(string dato,int tam){
	
	int tamLista = atributos.actividadL.actividades.tamLista();
	bool encontrado = false;
	int pos;
	for(int i = 1;i<=tamLista;i++){
		if(atributos.actividadL.actividades.getDato(i).nombre == dato){
			encontrado = true;
			pos =i;
			break;
		}
	}
	if(encontrado){
		int aux = atributos.actividadL.actividades.getDato(pos).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigActividad = 0;
			cabecera a;
			a.nombre = atributos.actividadL.actividades.getDato(pos).nombre;
			a.cab = tam;
			atributos.actividadL.actividades.eliminar(pos);
			atributos.actividadL.actividades.insertar(a,pos);
		}else{
			feligreses[tam].sigActividad = aux;
			cabecera a;
			a.nombre = atributos.actividadL.actividades.getDato(pos).nombre;
			a.cab = tam;
			atributos.actividadL.actividades.eliminar(pos);
			atributos.actividadL.actividades.insertar(a,pos);
		}
	}else{
		cabecera a;
		a.nombre = dato;
		a.cab = tam;
		atributos.actividadL.actividades.insertar(a,0);
	}
}

// se ordenan como una pila 
void Multilista::ordenarIglesia(string dato,int tam){
	
	int tamLista = atributos.iglesia.Iglesias.tamLista();
	bool encontrado = false;
	int pos;
	for(int i = 1;i<=tamLista;i++){
		if(atributos.iglesia.Iglesias.getDato(i).nombre == dato){
			encontrado = true;
			pos = i;
			break;
		}
	}
	if(encontrado){
		int aux =  atributos.iglesia.Iglesias.getDato(pos).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigIglesia = 0;
			cabecera a;
			a.nombre = atributos.iglesia.Iglesias.getDato(pos).nombre;
			a.cab = tam+1;
			atributos.iglesia.Iglesias.getDato(pos) = a;
			cout<<atributos.iglesia.Iglesias.getDato(pos).cab<<endl;
		}else{
			feligreses[tam].sigIglesia = aux;
			cabecera a;
			a.nombre = atributos.iglesia.Iglesias.getDato(pos).nombre;
			a.cab = tam;
			atributos.iglesia.Iglesias.eliminar(pos);
			atributos.iglesia.Iglesias.insertar(a,pos);
		}
	}else{
		cabecera a;
		a.nombre = dato;
		a.cab = tam;
		atributos.iglesia.Iglesias.insertar(a,0);
	}
}

void Multilista::ordenarBarrio(string dato,int tam){
	
	int tamLista = atributos.barrio.barrios.tamLista();
	bool encontrado = false;
	int pos;
	for(int i = 1;i<=tamLista;i++){

		if(atributos.barrio.barrios.getDato(i).nombre == dato){
			encontrado = true;
			pos = i;
			break;
		}
	}
	if(encontrado){
		int aux =  atributos.barrio.barrios.getDato(pos).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigBarrio = 0;
			cabecera a;
			a.nombre = atributos.barrio.barrios.getDato(pos).nombre;
			a.cab = tam;
			atributos.barrio.barrios.eliminar(pos);
			atributos.barrio.barrios.insertar(a,pos);
		}else{
			feligreses[tam].sigBarrio = aux;
			cabecera a;
			a.nombre = atributos.barrio.barrios.getDato(pos).nombre;
			a.cab = tam;
			atributos.barrio.barrios.eliminar(pos);
			atributos.barrio.barrios.insertar(a,pos);
		}
	}else{
		cabecera a;
		a.nombre = dato;
		a.cab = tam;
		atributos.barrio.barrios.insertar(a,0);
	}
}


void Multilista::ordenarCiudad(string dato,int tam){
	
	int tamLista = atributos.ciudad.Ciudades.tamLista();
	bool encontrado = false;
	int pos;
	for(int i = 1;i<=tamLista;i++){
		if(atributos.ciudad.Ciudades.getDato(i).nombre == dato){
			encontrado = true;
			pos = i;
			break;
		}
	}
	if(encontrado){
		int aux =  atributos.ciudad.Ciudades.getDato(pos).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigCiudad = 0;
			cabecera a;
			a.nombre = atributos.ciudad.Ciudades.getDato(pos).nombre;
			a.cab = tam+1;
			atributos.ciudad.Ciudades.getDato(pos) = a;
		}else{
			feligreses[tam].sigCiudad = aux;
			cabecera a;
			a.nombre = atributos.ciudad.Ciudades.getDato(pos).nombre;
			a.cab = tam;
			atributos.ciudad.Ciudades.eliminar(pos);
			atributos.ciudad.Ciudades.insertar(a,pos);
		}
	}else{
		cabecera a;
		a.nombre = dato;
		a.cab = tam;
		atributos.ciudad.Ciudades.insertar(a,0);
	}
}


// se ordenan como una pila
void Multilista::ordenarSexo(string dato,int tam){
	
	if(dato == "M"){
		int aux =  atributos.sexo.Sexo.getDato(1).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigSexo = 0;
			cabecera a;
			a.nombre = atributos.sexo.Sexo.getDato(1).nombre;
			a.cab = tam;
			atributos.sexo.Sexo.eliminar(1);
			atributos.sexo.Sexo.insertar(a,1);
		}else{
			feligreses[tam].sigIglesia = aux;
		    cabecera a;
			a.nombre = atributos.sexo.Sexo.getDato(1).nombre;
			a.cab = tam;
			atributos.sexo.Sexo.eliminar(1);
			atributos.sexo.Sexo.insertar(a,1);
		}
	}else{
		int aux =  atributos.sexo.Sexo.getDato(2).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigSexo = 0;
			cabecera a;
			a.nombre = atributos.sexo.Sexo.getDato(2).nombre;
			a.cab = tam;
			atributos.sexo.Sexo.eliminar(2);
			atributos.sexo.Sexo.insertar(a,2);
		}else{
			feligreses[tam].sigSexo = aux;
		    cabecera a;
			a.nombre = atributos.sexo.Sexo.getDato(2).nombre;
			a.cab = tam;
			atributos.sexo.Sexo.eliminar(2);
			atributos.sexo.Sexo.insertar(a,2);
		}
	}	
	
}

// se ordenan como una pila
void Multilista::ordenarEdad(int dato,int tam){
	
	
	if(dato >= 18 &&  dato <= 24){
		int aux =  atributos.edad.rangosEdades.getDato(1).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigEdad = 0;
			cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(1).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(1);
			atributos.edad.rangosEdades.insertar(a,1);
		}else{
			feligreses[tam].sigEdad = aux;
		    cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(1).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(1);
			atributos.edad.rangosEdades.insertar(a,1);
		}
	}else if (dato >= 25 &&  dato <= 35) { 
		int aux =  atributos.edad.rangosEdades.getDato(5).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigEdad = 0;
			cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(5).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(5);
			atributos.edad.rangosEdades.insertar(a,5);
		}else{
			feligreses[tam].sigEdad = aux;
		    cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(5).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(5);
			atributos.edad.rangosEdades.insertar(a,5);
		 }
	}else if(dato >= 36 &&  dato <= 45){
		int aux =  atributos.edad.rangosEdades.getDato(4).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigEdad = 0;
			cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(4).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(4);
			atributos.edad.rangosEdades.insertar(a,4);
		}else{
			feligreses[tam].sigEdad = aux;
		    cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(4).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(4);
			atributos.edad.rangosEdades.insertar(a,4);
		}
	}else if(dato >= 46 &&  dato <= 60){
		int aux =  atributos.edad.rangosEdades.getDato(3).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigEdad = 0;
			cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(3).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(3);
			atributos.edad.rangosEdades.insertar(a,3);
		}else{
			feligreses[tam].sigEdad = aux;
		    cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(3).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(3);
			atributos.edad.rangosEdades.insertar(a,3);
		 }
	}else{
		int aux =  atributos.edad.rangosEdades.getDato(2).cab;
		int cab = aux;
		if(cab == 0){
			feligreses[tam].sigEdad = 0;
			cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(2).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(2);
			atributos.edad.rangosEdades.insertar(a,2);
		}else{
			feligreses[tam].sigEdad = aux;
		    cabecera a;
			a.nombre = atributos.edad.rangosEdades.getDato(2).nombre;
			a.cab = tam;
			atributos.edad.rangosEdades.eliminar(2);
			atributos.edad.rangosEdades.insertar(a,2);
		 }
	}
	
}

// se ordenan como una pila
void Multilista::ordenarcantHijos(int cab,int tam){
	
	if(cab == 0){
		atributos.numHijos.NumHijos.cab = tam;
		feligreses[tam].sigNumHijos = 0;
	}else{
		int comparacion = compararInt(feligreses[cab].numHijos,feligreses[tam].numHijos);
		int aux = cab;
		if(comparacion == 2){
			atributos.numHijos.NumHijos.cab = tam;
			feligreses[tam].sigNumHijos = aux;
		}
		int anterior = aux;
		aux = feligreses[cab].sigNumHijos;
		if(comparacion == 1){
			if(aux == 0){
				feligreses[anterior].sigNumHijos =tam;
				feligreses[tam].sigNumHijos = 0; 
			}else{
				while(true){
					comparacion = compararInt(feligreses[aux].numHijos,feligreses[tam].numHijos);
					if(comparacion == 2){
						feligreses[anterior].sigNumHijos = tam;
						feligreses[tam].sigNumHijos = aux;
						break;
					}
					anterior = aux;
					aux = feligreses[aux].sigNumHijos;
					if(aux == 0){
						feligreses[anterior].sigNumHijos = tam;
						feligreses[tam].sigNumHijos = 0;
						break;
					}
				}
			}
		}
	}
	
}



lista<feligres>* Multilista::consulta1(string ig){
	
	lista<feligres> array[5];
	int tamLista = atributos.iglesia.Iglesias.tamLista();
	bool encontrado = false;
	int pos;
	for(int i = 1;i<=tamLista;i++){
		if(atributos.iglesia.Iglesias.getDato(i).nombre == ig){
			encontrado = true;
			pos = i;
			break;
		}
	}
	if(encontrado){
		
		int aux = atributos.iglesia.Iglesias.getDato(pos).cab;
		while(aux != 0){
			if(feligreses[aux].numHijos == 0){
				array[0].insertar(feligreses[aux],0);
			}
			aux = feligreses[aux].sigIglesia;
		}
		
		aux = atributos.iglesia.Iglesias.getDato(pos).cab;
		while(aux != 0){
			
			for(int k = 0; k<feligreses[aux].numHijos;k++){
				if(feligreses[aux].rangEdadHijos[k] == 0){
					array[1].insertar(feligreses[aux],0);
				}
			}
			aux = feligreses[aux].sigIglesia;
			
		}
		
		aux = atributos.iglesia.Iglesias.getDato(pos).cab;
		while(aux != 0){
			for(int k = 0; k<feligreses[aux].numHijos;k++){
				if(feligreses[aux].rangEdadHijos[k] == 1){
					array[2].insertar(feligreses[aux],0);
				}
			}
			aux = feligreses[aux].sigIglesia;
		}

		aux = atributos.iglesia.Iglesias.getDato(pos).cab;
		while(aux != 0){
		for(int k = 0; k<feligreses[aux].numHijos;k++){
				if(feligreses[aux].rangEdadHijos[k] == 2){
					array[3].insertar(feligreses[aux],0);
				}
			}
			aux = feligreses[aux].sigIglesia;
		}
		
		aux = atributos.iglesia.Iglesias.getDato(pos).cab;
		while(aux != 0){
		for(int k = 0; k<feligreses[aux].numHijos;k++){
				if(feligreses[aux].rangEdadHijos[k] == 3){
					array[4].insertar(feligreses[aux],0);
				}
			}
			aux = feligreses[aux].sigIglesia;
		}
		
		
	}else{
		cout<<"La iglesia ingresada no existe"<<endl;
	}
	return array;
}

lista<feligres> Multilista::consulta2(int aux,int rangoI,int rangoS){
	
	lista<feligres> l;
	
	while(aux != 0){
		
		if(feligreses[aux].numHijos>= rangoI && feligreses[aux].numHijos <= rangoS){
			l.insertar(feligreses[aux],0);
			cout<<feligreses[aux].sigCiudad<<endl;
		}
		aux = feligreses[aux].sigCiudad;
	}
	return l;
	
	return l;
}

lista<feligres> Multilista::consulta3(int aux,string ciudad){
	
	lista<feligres> l;
	while(aux != 0){
		
		if(feligreses[aux].ciudadR == ciudad){
			l.insertar(feligreses[aux],0);	
		}
		aux = feligreses[aux].sigActividad;
	}
	return l;
}

lista<feligres> Multilista::consulta5(int aux,string ciudad,int op){
	
	lista<feligres> l;
	if(op == 0){
		while(aux != 0){
		
			if(feligreses[aux].ciudadR == ciudad && feligreses[aux].sexo == "M" ){
				l.insertar(feligreses[aux],0);	
			}
			aux = feligreses[aux].sigIglesia;
		}
	}else{
		while(aux != 0){
		
			if(feligreses[aux].ciudadR == ciudad && feligreses[aux].sexo == "F" ){
				l.insertar(feligreses[aux],0);	
			}
			aux = feligreses[aux].sigIglesia;
		}
	}
	return l;
}

//retorna el nombre de las iglesias con mas de n personas
lista <string> Multilista::consulta4(int n){
	lista<string> iglesias;
	
	int tam = atributos.iglesia.Iglesias.tamLista();
	cout<<"el numero de iglesias es: "<<tam<<endl;
	
	for(int i = 1;i<=tam;i++){
		int aux = atributos.iglesia.Iglesias.getDato(i).cab;
		int j=0;
		string nombre;
		while(aux != 0){
			j++;
			nombre = feligreses[aux].iglesia;
			aux = feligreses[aux].sigIglesia;
		}
		if(j>=n){
			cout<<"el numero de personas que asiste a "<<nombre<<" es: "<<j<<endl;
			iglesias.insertar(nombre,0);
		}
		
	}
	return iglesias;
}


lista<feligres> Multilista::consulta6(string rango, string act){
	lista<feligres> l;
	int tam = atributos.edad.rangosEdades.tamLista();
	for(int i=1;i<=tam;i++){
		if(atributos.edad.rangosEdades.getDato(i).nombre==rango){
			int aux = atributos.edad.rangosEdades.getDato(i).cab;	
			while(aux != 0){
				if(feligreses[aux].actLaboral==act){
					cout<<feligreses[aux].nombre<<", edad: "<<feligreses[aux].edad<<endl;
					l.insertar(feligreses[aux],0);		
				}
			aux = feligreses[aux].sigEdad;
			}
		}
	}return l;
	

}

//Regresa cual de los dos int ingresados es mayor o si son iguales
int Multilista::compararInt(int e1,int e2){
	if(e1==e2)
		return 0;
	if(e1 > e2)
		return 1;
	return 2;
}

Multilista::~Multilista(){
}



