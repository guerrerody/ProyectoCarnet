/*
 * MRol.cpp
 *
 * Author: Dorieliz Guerrero
 */

#include "MRol.h"

MRol::MRol() {

}

MRol::~MRol() {

}

bool MRol::IncluirRol(InfoRol rol) {
	return InsComienzo(rol);
}

Nodo<InfoRol>* MRol::BuscarRol(int codigoRol) {
	Nodo<InfoRol> *p = ObtPrimero();
	while (p != NULL) {
		if (p->ObtInfo().codigo == codigoRol) {
			break;
		}
		p = p->ObtDer();
	}
	return p;
}

bool MRol::ModificarRol(InfoRol rol) {
	Nodo<InfoRol> *p = this->BuscarRol(rol.codigo);
	if (p != NULL) {
		p->AsigInfo(rol);
		return true;
	}
	return false;
}

bool MRol::eliminarRol(int codigoRol, InfoRol &rol) {
	Nodo<InfoRol> *p = ObtPrimero();
	Nodo<InfoRol> *pAnt = NULL;

	while (p != NULL) {
		if (p->ObtInfo().codigo == codigoRol) {
			if (pAnt == NULL) {
				EliComienzo(rol);
			} else {
				EliDerecho(pAnt, rol);
			}
			return true;
		}
		pAnt = p;
		p = p->ObtDer();
	}
	return false;
}
