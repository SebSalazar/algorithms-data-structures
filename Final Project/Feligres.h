#include<iostream>

struct Feligres{
	char Nombre[50];
	char Apellido[50];
	char TipoID[3];
	char NumID[11];
	char Sexo[2];
	char TEL_cel[13];
	char TEL_fijo[10];
	char e_mail[50];
	char F_nacimiento[12];
	char C_nacimiento[20];
	char Pais_nacimiento[20];
	char Ciudad_residencia[20];
	char Direccion[20];
	char Barrio[20];
	char A_laboral[20];
	bool I_hijos;
	int Numero_hijos;
	int *Rango_edades_hijos;
	char Iglesia[50];
	int edad;
		
};

char hijos(bool hi){
	if(hi){
		return 'S';
	}else{
		return 'N';
	}
}


