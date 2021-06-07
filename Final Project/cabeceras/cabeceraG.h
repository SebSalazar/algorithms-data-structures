#ifndef cabeceraGeneral_h    
#define cabeceraGeneral_h 
#include <iostream>
#include "cabeceraActLaboral.h"
#include "cabeceraEdad.h"
#include "cabeceraiglesia.h"
#include "cabeceraLocalidad.h"
#include "cabeceraNumHijos.h"
#include "cabeceraSexo.h"
#include "cabeceraBarrio.h"
#include "cabeceraCiudad.h"

using namespace std;

struct cabeceraGeneral{
	
	cabeceraActLaboral actividadL;
	cabeceraEdad edad;
	cabeceraIglesia iglesia;
	cabeceraNumHijos numHijos;
	cabeceraSexo sexo;
	cabeceraBarrio barrio;
	cabeceraCiudad ciudad;
	
};
       
#endif

