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
	/*
	Nodo<InfoPersona> *p = this->BuscarPersona(persona.cedula);
	if (p != NULL) {
		p->AsigInfo(persona);
		return true;
	}
	*/
	return false;

}

bool MPersona::EliminarPersona(string cedulaPersona) {
	/*
	Nodo<InfoPersona> *p, *marca;
	p = this->BuscarPersona(cedulaPersona);
	InfoPersona q;
	marca = frente;
	if (p != NULL) {
		do {
			if (frente->ObtInfo().cedula != cedulaPersona) {
				Insertar(frente->ObtInfo());
				Remover(q);
			} else {
				Insertar(frente->ObtDer()->ObtInfo());
				Remover(q);
			}
		} while (marca->ObtInfo().cedula != frente->ObtInfo().cedula);

		return true;
	} else*/
		return false;
}
