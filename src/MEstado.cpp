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

Nodo<InfoEstado>* MEstado::ObtTope(){
	return tope;
}

bool MEstado::IncluirEstado(InfoEstado estado) {
	return Insertar(estado);

}

bool MEstado::BuscarEstado(int codigo, InfoEstado &estado) {
	Pila<InfoEstado> estAux;

	bool encontro = false;

	if (!Vacia()) {
		while(!Vacia()){
			InfoEstado e;
			Remover(e);
			if(e.codigo == codigo){
				encontro = true;
				estado = e;
			}
			estAux.Insertar(e);
		}

		while(!estAux.Vacia()){
			InfoEstado e;
			estAux.Remover(e);
			Insertar(e);
		}
	}

	return encontro;
}

bool MEstado::ModificarEstado(InfoEstado estado) {
	Pila<InfoEstado> estAux;
	InfoEstado u;

	bool encontro = false;

	if (!Vacia()) {
		while(!Vacia()){
			InfoEstado e;
			Remover(e);
			if(e.codigo == estado.codigo){
				encontro = true;
				estAux.Insertar(estado);
			} else {
				estAux.Insertar(e);	
			}
		}

		while(!estAux.Vacia()){
			InfoEstado e;
			estAux.Remover(e);
			Insertar(e);
		}
	}

	return encontro;
}

bool MEstado::EliminarEstado(int codigo, InfoEstado &estado) {
	Pila<InfoEstado> estAux;
	InfoEstado u;

	bool encontro = false;

	if (!Vacia()) {
		while(!Vacia()){
			InfoEstado e;
			Remover(e);
			if(e.codigo == codigo){
				encontro = true;
				estado = e;
			} else {
				estAux.Insertar(e);	
			}
		}

		while(!estAux.Vacia()){
			InfoEstado e;
			estAux.Remover(e);
			Insertar(e);
		}
	}

	return encontro;
}
