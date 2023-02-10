#ifndef Pila_H
#define Pila_H

#include <iostream>
#include <string>
using namespace std;

#include "Nodo.h"

template <class T>
class Pila
{
protected:

    Nodo<T> *tope;

public:
    Pila();
    ~Pila();
    bool Vacia();
    bool Llena();
    bool Insertar(T Valor);
    bool Remover(T &Valor);
};

// Implementación del Template

template<class T>
Pila<T>::Pila() {
	tope = NULL;
}

template<class T>
Pila<T>::~Pila() {
	Nodo<T> *p;
	while (!Vacia()) {
		p = tope->ObtDer();
		delete tope;
		tope = p;
	}
}

template<class T>
bool Pila<T>::Vacia() {
	return tope == NULL;
}

template<class T>
bool Pila<T>::Llena() {
	Nodo<T> *p;
	p = new Nodo<T>;
	if (p == NULL)
		return true;
	else {
		delete p;
		return false;
	}
}

template<class T>
bool Pila<T>::Insertar(T valor) {
	Nodo<T> *nuevo;
	if (!Llena()) {
		nuevo = new Nodo<T>;
		nuevo->AsigInfo(valor);
		nuevo->AsigDer(tope);
		tope = nuevo;

		return true;
	} else
		return false;
}

template<class T>
bool Pila<T>::Remover(T &valor) {
	Nodo<T> *primero;
	if (!Vacia()) {
		primero = tope;
		valor = primero->ObtInfo();
		tope = primero->ObtDer();
		delete primero;

		return true;
	} else
		return false;
}

#endif
