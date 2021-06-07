#ifndef feligresL_h    
#define feligresL_h 
#include <iostream>

using namespace std;

struct feligres{
	
	//Datos del feligres
	string nombre, apellido,tipoID,numID,eMail,ciudadN,paisN,ciudadR,direccion,barrio,iglesia;
	string sexo,actLaboral,telefonoF,telefonoC,f_nacimiento,rangHijos;
	bool hijos;
	int numHijos,edad;
	
	int* rangEdadHijos;
	//
	
	int sigSexo,sigActividad,sigNumHijos,sigEdad,sigIglesia,sigBarrio,sigCiudad;
        
};
       
#endif

