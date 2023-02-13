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
	int tipoPersona; // [Estudiante, Docente, Obrero, Administrativo]
	string correo;
	string decanato;
	MEstado pilaEstado; // [Entregado, Verificado]

	InfoPersona() :
		cedula(""), sexo(0), tipoPersona(0) { // Inicializacion de los valores numericos para el struct
	}
};

class MPersona: public Cola<InfoPersona> {

public:
	MPersona();
	~MPersona();

	Nodo<InfoPersona>* ObtFrente();
	bool IncluirPersona(InfoPersona persona);
	bool BuscarPersona(string cedulaPersona, InfoPersona &persona);
	bool ModificarPersona(InfoPersona persona);
	bool EliminarPersona(string cedulaPersona);

};

#endif /* MPERSONA_H_ */
