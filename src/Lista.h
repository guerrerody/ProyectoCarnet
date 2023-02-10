#ifndef Lista_H
#define Lista_H

#include <iostream>
#include <string>
using namespace std;

#include "Nodo.h"

template<class T>
class Lista {
private:
	Nodo<T> *primero;
public:

	Lista();
	~Lista();
	Nodo<T>* ObtPrimero();
	void AsigPrimero(Nodo<T> *p);
	bool Vacia();
	bool Llena();
	bool InsComienzo(T valor);
	bool EliComienzo(T &valor);
	bool InsDerecho(Nodo<T> * p, T valor);
	bool EliDerecho(Nodo<T> * p, T &valor);

};

// Implementación del Template

template<class T>
Lista<T>::Lista() {
	primero = NULL;
}

template<class T>
Lista<T>::~Lista() {
	Nodo<T> *p;
	while (!Vacia()) {
		p = primero->ObtDer();
		delete primero;
		primero = p;
	};
}

template<class T>
Nodo<T>* Lista<T>::ObtPrimero() {
	return primero;
}

template<class T>
void Lista<T>::AsigPrimero(Nodo<T> *p) {
	primero = p;
}

template<class T>
bool Lista<T>::Vacia() {
	return primero == NULL;
}

template<class T>
bool Lista<T>::Llena() {
	Nodo<T> *p = new Nodo<T>;
	if (p == NULL)
		return true;
	else {
		delete p;
		return false;
	}
}

template<class T>
bool Lista<T>::InsComienzo(T Valor) {
	if (!Llena()) {
		Nodo<T> * nuevo = new Nodo<T>;
		nuevo->AsigInfo(Valor);
		nuevo->AsigDer(primero);
		primero = nuevo;
		return true;
	}
	return false;
}

template<class T>
bool Lista<T>::EliComienzo(T &valor) {
	if (!Vacia()) {
		Nodo<T> * viejo = primero;
		valor = viejo->ObtInfo();
		primero = primero->ObtDer();
		delete viejo;
		return true;
	}
	return false;
}

template<class T>
bool Lista<T>::InsDerecho(Nodo<T> * p, T valor) {
	if (!Llena()) {
		if (Vacia()) {
			InsComienzo(valor);
			p = ObtPrimero();
			return true;
		} else if (p != NULL) {
			Nodo<T> * nuevo = new Nodo<T>;
			nuevo->AsigInfo(valor);
			nuevo->AsigDer(p->ObtDer());
			p->AsigDer(nuevo);
			return true;
		}
	}
	return false;
}

template<class T>
bool Lista<T>::EliDerecho(Nodo<T> * p, T &valor) {
	if (p != NULL && p->ObtDer() != NULL) {
		Nodo<T> * viejo = p->ObtDer();
		valor = viejo->ObtInfo();
		p->AsigDer(viejo->ObtDer());
		delete viejo;
		return true;
	};
	return false;
}

#endif
