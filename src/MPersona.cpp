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

bool MPersona::IncluirRol(InfoPersona persona){
	return Insertar(persona);

}
Nodo<InfoPersona>* MPersona::BuscarPersona(string cedulaPersona){
	Nodo<InfoPersona> *p = frente->ObtDer();
	int marca,valor;
	marca = -1;
	bool encontro;
	if (!Vacia()){
		Insertar(marca);
	}	encontro = false;
		while (!(encontro)) {
			if (p->ObtInfo().cedula == cedulaPersona) {
				break;
			}
			Remover(valor);
			if (valor == marca)
				encontro = true;
			else {

			}
		}
		return p;

}
bool MPersona::ModificarPersona(InfoPersona persona){
	Nodo<InfoPersona> *p = this->BuscarPersona(persona.cedula);
		if (p != NULL) {
			p->AsigInfo(persona);
			return true;
		}
		return false;

}
bool MPersona::EliminarPersona (string cedulaPersona){
	Nodo<InfoPersona> *p = this->BuscarPersona(persona.cedula);

	Nodo<InfoPersona> *primero;
	    if (p != NULL)
	    {
	        primero = frente;
	        persona = primero->ObtInfo();
	        frente = primero->ObtDer();
	        if (frente == NULL)
	            final = NULL;
	        delete primero;
	        return true;
	    }
	    else
	        return false;


}
