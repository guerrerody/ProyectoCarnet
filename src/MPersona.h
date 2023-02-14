/*
 * MPersona.h
 *
 *  Created on: Jan 24, 2023
 *      Author: guerrerody
 */

#ifndef MPERSONA_H_
#define MPERSONA_H_

#include <iostream>
#include <string>
using namespace std;

#include "Nodo.h"
#include "Cola.h"
#include "MEstado.h"

struct InfoPersona {
	string cedula;
	string nombre;
	string apellido;
	int sexo;
	string correo;
	string decanato;
	MEstado *pilaEstado; // [Entregado, En Proceso, Verificado, etc.]

	InfoPersona() :
		sexo(1), pilaEstado(new MEstado()) { // Inicializacion de los valores numericos para el struct
	}
};

class MPersona: public Cola<InfoPersona> {

public:
	MPersona();
	~MPersona();

	bool BuscarPersona(string cedulaPersona, InfoPersona &persona);
	bool ModificarPersona(InfoPersona persona);
	bool EliminarPersona(string cedulaPersona, InfoPersona &persona);

};

#endif /* MPERSONA_H_ */
