#ifndef Cola_H
#define Cola_H

#include <iostream>
#include <string>
using namespace std;

#include "Nodo.h"

template<class T>
class Cola {
private:
	Nodo<T> *frente, *final;

public:
	Cola();
	~Cola();
	bool Vacia();
	bool Insertar(T Valor);
	bool Remover(T &Valor);
};

// Implementación del Template

template<class T>
Cola<T>::Cola() {
	frente = NULL;
	final = NULL;
}

template<class T>
Cola<T>::~Cola() {
	Nodo<T> *p;
	while (!Vacia()) {
		p = frente->ObtDer();
		delete frente;
		frente = p;
	};
	final = NULL;
}

template<class T>
bool Cola<T>::Vacia() {
	return frente == NULL;
}

template<class T>
bool Cola<T>::Insertar(T valor) {
	Nodo<T> *nuevo = new Nodo<T>;
	if (nuevo != NULL) {
		nuevo->AsigInfo(valor);
		nuevo->AsigDer(NULL);
		if (final == NULL) {
			frente = nuevo;
		} else {
			final->AsigDer(nuevo);
		}
		final = nuevo;
		return true;
	}
	return false;
}

template<class T>
bool Cola<T>::Remover(T &valor) {
	if (!Vacia()) {
		Nodo<T> *primero = frente;
		valor = primero->ObtInfo();
		frente = primero->ObtDer();
		if (frente == NULL) {
			final = NULL;
		}
		delete primero;
		return true;
	}
	return false;
}

#endif
