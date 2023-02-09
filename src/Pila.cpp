#include <iostream>
#include <string>
using namespace std;

#include "Pila.h"

template <class Tipo>
Pila<Tipo>::Pila()
{
    tope = NULL;
};
template <class Tipo>
bool Pila<Tipo>::Vacia()
{
    return tope == NULL;
};
template <class Tipo>
bool Pila<Tipo>::Llena()
{
    Nodo<Tipo> *p;
    p = new Nodo<Tipo>;
    if (p == NULL)
        return true;
    else
    {
        delete p;
        return false;
    }
};

template <class Tipo>
Pila<Tipo>::~Pila()
{
    Nodo<Tipo> *p;
    while (!Vacia())
    {
        p = tope->ObtDer();
        delete tope;
        tope = p;
    }
};

template <class Tipo>
bool Pila<Tipo>::Insertar(Tipo valor)
{
    Nodo<Tipo> *nuevo;
    if (!Llena())
    {
        nuevo = new Nodo<Tipo>;
        nuevo->AsigInfo(valor);
        nuevo->AsigDer(tope);
        tope = nuevo;

        return true;
    }
    else
        return false;
};
template <class Tipo>
bool Pila<Tipo>::Remover(Tipo &valor)
{
    Nodo<Tipo> *primero;
    if (!Vacia())
    {
        primero = tope;
        valor = primero->ObtInfo();
        tope = primero->ObtDer();
        delete primero;
        
        return true;
    }
    else
        return false;
};
