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

#include "Nodo.h"
#include "Pila.h"

struct InfoEstado {
	int codigo;
	string nombre;
	string fecha;

	InfoEstado() :
		codigo(0) { // Inicializacion de los valores numericos para el struct
	}
};

class MEstado: public Pila<InfoEstado> {

public:
	MEstado();
	~MEstado();

	bool IncluirEstado(InfoEstado estado);
	Nodo<InfoEstado>* ObtTope();
	bool BuscarEstado(int codigo, InfoEstado &estado);
	bool ModificarEstado(InfoEstado rol);
	bool EliminarEstado(int codigo, InfoEstado &estado);

};

#endif /* MESTADO_H_ */
