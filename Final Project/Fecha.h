#ifndef FECHA_H
#define FECHA_H
#include<iostream> 
using namespace std; 

// Estructura con datos dia, mes y año
struct Date 
{ 
	int d, m, y; 
}; 

/*
	Numero de dias para todos los meses del año
 	necesario para validar la fecha ingresada
*/
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
						31, 31, 30, 31, 30, 31}; 

/*
	Contador de años bisiestos antes de la fecha dada
*/
int countLeapYears(Date d) 
{ 
	int years = d.y; 

	//Verificar si el año ingresado se debe tener en cuenta como bisiesto
	if (d.m <= 2) 
		years--; 

	// Un año es un año bisesto si es multiplo de 4, 400 y no es
	// multiplo de 100. 
	return years / 4 - years / 100 + years / 400; 
} 

/*
	Funcion para conocer la diferencia entre dias de una fecha y otra
*/
int getDifference(Date dt1, Date dt2) 
{ 
	//Empieza contando los dias y los dias de cada año 
	long int n1 = dt1.y*365 + dt1.d; 

	//Agrega los dias de cada mes
	for (int i=0; i<dt1.m - 1; i++) 
		n1 += monthDays[i]; 

	//Agregar los dias de los años bisisestos
	n1 += countLeapYears(dt1); 

	//Se realiza el mismo proceso con las segunda fecha
	long int n2 = dt2.y*365 + dt2.d; 
	for (int i=0; i<dt2.m - 1; i++) 
		n2 += monthDays[i]; 
	n2 += countLeapYears(dt2); 

	return (n2 - n1); 
} 

#endif
