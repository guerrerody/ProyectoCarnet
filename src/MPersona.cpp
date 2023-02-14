/*
 * MPersona.cpp
 *
 *  Created on: Jan 24, 2023
 *      Author: guerrerody
 */

#include "MPersona.h"

MPersona::MPersona() {

}

MPersona::~MPersona() {

}

bool MPersona::BuscarPersona(string cedulaPersona, InfoPersona &persona) {
	bool encontro = false;
	if (!Vacia())
	{
		InfoPersona marca;
		Insertar(marca);

		bool finCola = false;
		while (!finCola) {
			InfoPersona valor;
			Remover(valor);
			if (valor.cedula.empty()) {
				finCola = true;
			} else {
				if (valor.cedula == cedulaPersona) {
					encontro = true;
					persona = valor;
				}
				Insertar(valor);
			}
		}
	}
	return encontro;
}

bool MPersona::ModificarPersona(InfoPersona persona) {
	bool encontro = false;
	if (!Vacia())
	{
		InfoPersona marca;
		Insertar(marca);

		bool finCola = false;
		while (!finCola) {
			InfoPersona valor;
			Remover(valor);
			if (valor.cedula.empty()) {
				finCola = true;
			} else {
				if (valor.cedula == persona.cedula) {
					encontro = true;
					Insertar(persona);
				} else {
					Insertar(valor);
				}
			}
		}
	}
	return encontro;

}

bool MPersona::EliminarPersona(string cedulaPersona, InfoPersona &persona) {
	bool encontro = false;
	if (!Vacia())
	{
		InfoPersona marca;
		Insertar(marca);

		bool finCola = false;
		while (!finCola) {
			InfoPersona valor;
			Remover(valor);
			if (valor.cedula.empty()) {
				finCola = true;
			} else {
				if (valor.cedula == cedulaPersona) {
					encontro = true;
					persona = valor;
				} else {
					Insertar(valor);
				}
			}
		}
	}
	return encontro;
}
