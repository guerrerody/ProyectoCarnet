/*
 * MEstado.h
 *
 *  Created on: Jan 24, 2023
 *      Author: jsayago22
 */

#ifndef MESTADO_H_
#define MESTADO_H_

#include <iostream>
#include <string>
using namespace std;

#include "Nodo.cpp"
#include "Pila.cpp"

struct InfoEstado {
	int codigo;
	string nombre;
	string fecha;

	InfoEstado() :
		codigo(0), nombre(0) { // Inicializacion de los valores numericos para el struct
	}
};

class MEstado: public Pila<InfoEstado> {

public:
	MEstado();
	~MEstado();

	Nodo<InfoEstado>* MEstado::ObtTope();
	bool IncluirEstado(InfoEstado estado);
	Nodo<InfoEstado>* BuscarEstado(int codigo);
	bool ModificarEstado(InfoEstado rol);
	bool EliminarEstado(int codigo);

};

#endif /* MESTADO_H_ */