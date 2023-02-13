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

Nodo<InfoPersona>* MPersona::ObtFrente() {
	return frente;
}

bool MPersona::IncluirPersona(InfoPersona persona) {
	return Insertar(persona);

}

bool MPersona::BuscarPersona(string cedulaPersona, InfoPersona &persona) {
	InfoPersona marca, valor;

	bool encontro = false;
	if (!Vacia())
	{
		Insertar(marca);

		bool finCola = false;
		while (!finCola) {
			Remover(valor);
			if (valor.cedula == marca.cedula) {
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
	InfoPersona marca, valor;

	bool encontro = false;
	if (!Vacia())
	{
		Insertar(marca);

		bool finCola = false;
		while (!finCola) {
			Remover(valor);
			if (valor.cedula == marca.cedula) {
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

bool MPersona::EliminarPersona(string cedulaPersona) {
	InfoPersona marca, valor;

	bool encontro = false;
	if (!Vacia())
	{
		Insertar(marca);

		bool finCola = false;
		while (!finCola) {
			Remover(valor);
			if (valor.cedula == marca.cedula) {
				finCola = true;
			} else {
				if (valor.cedula == cedulaPersona) {
					encontro = true;
				} else {
					Insertar(valor);	
				}
			}
		}
	}

	return encontro;
}
