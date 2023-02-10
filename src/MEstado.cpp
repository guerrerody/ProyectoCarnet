/*
 * MEstado.cpp
 *
 *  Created on: Jan 24, 2023
 *      Author: jsayago77
 */

#include "MEstado.h"

MEstado::MEstado() {

}

MEstado::~MEstado() {

}

bool MEstado::IncluirEstado(InfoEstado estado) {
	return Insertar(estado);

}

Nodo<InfoEstado>* MEstado::ObtTope() {
	return tope;
}

Nodo<InfoEstado>* MEstado::BuscarEstado(int codigo) {
	Nodo<InfoEstado> *p, *valor;
	Pila<InfoEstado> estAux;
	p = tope;

	valor = NULL;
	bool encontro = false;

	if (!Vacia()) {
		return valor;
	}

	while (!(encontro)) {
		if (p->ObtInfo().codigo == codigo) {
			valor = p;
			encontro = true;
			while (!estAux.Vacia()) {
				InfoEstado e;
				estAux.Remover(e);
				Insertar(e);
			}
		} else {
			InfoEstado q;
			Remover(q);

			estAux.Insertar(q);

			if (tope == NULL) {
				encontro = true;
				while (!estAux.Vacia()) {
					InfoEstado e;
					estAux.Remover(e);
					Insertar(e);
				}
			} else {
				p = tope;
			}
		}
	}
	return valor;

}

bool MEstado::ModificarEstado(InfoEstado estado) {
	Nodo<InfoEstado> *p = this->BuscarEstado(estado.codigo);
	Pila<InfoEstado> estAux;
	InfoEstado u;

	if (p != NULL) {
		p->AsigInfo(estado);
		return true;
	} else
		return false;

	/*if (p != NULL) {
	 while(tope != NULL){
	 estAux.Insertar(tope->ObtInfo());
	 Remover(u);
	 }
	 while(!estAux.Vacia()){
	 estAux.Remover(u);
	 if(u.codigo == p->ObtInfo().codigo){
	 Insertar(estado);
	 }
	 }
	 return true;
	 } else return false;*/
}

bool MEstado::EliminarEstado(int codigo) {
	Nodo<InfoEstado> *p = this->BuscarEstado(codigo);
	Pila<InfoEstado> estAux;
	InfoEstado u;

	if (p != NULL) {
		while (tope != NULL) {
			estAux.Insertar(tope->ObtInfo());
			Remover(u);
		}
		while (!estAux.Vacia()) {
			estAux.Remover(u);
			if (u.codigo != p->ObtInfo().codigo) {
				Insertar(u);
			}
		}
		return true;
	} else
		return false;
}
