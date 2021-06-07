
#include <iostream>
#include<string>
#include <sstream>  
typedef std::string String; // para no escribir todo el tiempo std::string
#ifndef ESTRUCTURA_H     
#define ESTRUCTURA_H 

struct Nodo{
		int codigo;
		String localidad;
		String via;
		int tipo;
		int estrato;
		int valor;
        Nodo *sig;
       };
       
#endif

