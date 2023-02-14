/*
 * MRol.h
 *
 * Author: Dorieliz Guerrero
 */

#ifndef MROL_H_
#define MROL_H_

#include <iostream>
#include <string>
using namespace std;

#include "Nodo.h"
#include "Lista.h"
#include "MPersona.h"


struct InfoRol {
	int codigo;
	string nombre;
	string descripcion;
	float precioCarnet;
	int cantCensados;
	MPersona *cPersonas;

	InfoRol() :
		codigo(0), precioCarnet(0.00), cantCensados(0), cPersonas(new MPersona()) { // Inicializacion de los valores numericos para el struct
	}
};

class MRol: public Lista<InfoRol> {

public:
	MRol();
	~MRol();

	bool IncluirRol(InfoRol rol);
	Nodo<InfoRol>* BuscarRol(int codigoRol);
	bool ModificarRol(InfoRol rol);
	bool EliminarRol(int codigoRol, InfoRol &rol);
};

#endif /* MROL_H_ */
