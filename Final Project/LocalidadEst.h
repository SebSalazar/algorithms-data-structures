#ifndef localidad_h    
#define localidad_h 
#include <iostream>
#include "lista.h"


using namespace std;

struct localidad{
	
	//Datos de la localidad
	string nombre;
	Lista<string> listaBarrios;
        
};
       
#endif

