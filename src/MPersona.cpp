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

Nodo<InfoPersona>* MPersona::BuscarPersona(string cedulaPersona) {
	Nodo<InfoPersona> *p, *valor, *marca;
	p = frente;
	marca = frente;
	valor = NULL;
	bool encontro = false;
	InfoPersona q;

	if (!Vacia()) {
		return valor;
	}

	do {
		if (frente->ObtInfo().cedula == cedulaPersona) {
			valor = frente;
		}
		Insertar(frente->ObtInfo());
		Remover(q);

	} while (marca->ObtInfo().cedula != frente->ObtInfo().cedula);

	/*while (!(encontro)) {
	 if (p->ObtInfo().cedula == cedulaPersona) {
	 valor = p;
	 encontro = true;
	 while(marca->ObtInfo().cedula != final->ObtInfo().cedula){
	 Insertar(p->ObtInfo());
	 p = frente;
	 }
	 } else {
	 Insertar(p->ObtInfo());
	 if(marca == p)
	 while(marca->ObtInfo().cedula != final->ObtInfo().cedula){
	 Insertar(p->ObtInfo());
	 p = frente;
	 }
	 encontro = true;
	 else
	 Remover(q);
	 p = frente;
	 }
	 }*/

	return valor;
}

bool MPersona::ModificarPersona(InfoPersona persona) {
	Nodo<InfoPersona> *p = this->BuscarPersona(persona.cedula);
	if (p != NULL) {
		p->AsigInfo(persona);
		return true;
	}
	return false;

}

bool MPersona::EliminarPersona(string cedulaPersona) {
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
	} else
		return false;
}
