#include <iostream>
#include <string>
using namespace std;

#include "Lista.h"

template<class Tipo>
Lista<Tipo>::Lista() {
	primero = NULL;
}

template<class Tipo>
Lista<Tipo>::~Lista() {
	Nodo<Tipo> *p;
	while (!Vacia()) {
		p = primero->ObtDer();
		delete primero;
		primero = p;
	};
}

template<class Tipo>
Nodo<Tipo>* Lista<Tipo>::ObtPrimero() {
	return primero;
}

template<class Tipo>
void Lista<Tipo>::AsigPrimero(Nodo<Tipo> *p) {
	primero = p;
}

template<class Tipo>
bool Lista<Tipo>::Vacia() {
	return primero == NULL;
}

template<class Tipo>
bool Lista<Tipo>::Llena() {
	Nodo<Tipo> *p = new Nodo<Tipo>;
	if (p == NULL)
		return true;
	else {
		delete p;
		return false;
	}
}

template<class Tipo>
bool Lista<Tipo>::InsComienzo(Tipo Valor) {
	if (!Llena()) {
		Apuntador nuevo = new Nodo<Tipo>;
		nuevo->AsigInfo(Valor);
		nuevo->AsigDer(primero);
		primero = nuevo;
		return true;
	}
	return false;
}

template<class Tipo>
bool Lista<Tipo>::EliComienzo(Tipo &valor) {
	if (!Vacia()) {
		Apuntador viejo = primero;
		valor = viejo->obtInfo();
		primero = primero->obtDer();
		delete viejo;
		return true;
	}
	return false;
}

template<class Tipo>
bool Lista<Tipo>::InsDerecho(Apuntador p, Tipo valor) {
	if (!Llena()) {
		if (Vacia()) {
			InsComienzo(valor);
			p = ObtPrimero();
			return true;
		} else if (p != NULL) {
			Apuntador nuevo = new Nodo<Tipo>;
			nuevo->AsigInfo(valor);
			nuevo->AsigDer(p->ObtDer());
			p->AsigDer(nuevo);
			return true;
		}
	}
	return false;
}

template<class Tipo>
bool Lista<Tipo>::EliDerecho(Apuntador p, Tipo &valor) {
	if (p != NULL && p->obtDer() != NULL) {
		Apuntador viejo = p->ObtDer();
		valor = viejo->ObtInfo();
		p->AsigDer(viejo->ObtDer());
		delete viejo;
		return true;
	};
	return false;
}

