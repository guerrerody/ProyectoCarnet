#include <iostream>
#include <string>
using namespace std;


#include "Cola.h"

template <class Tipo>
Cola<Tipo>::Cola()
{
    frente = NULL;
    final = NULL;
};
template <class Tipo>
bool Cola<Tipo>::Vacia()
{
    return frente == NULL;
};
template <class Tipo>
bool Cola<Tipo>::Llena()
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
Cola<Tipo>::~Cola()
{
    Nodo<Tipo> *p;
    while (!Vacia())
    {
        p = frente->ObtDer();
        delete frente;
        frente = p;
    };
    final = NULL;
};

template <class Tipo>
bool Cola<Tipo>::Insertar(Tipo valor)
{
    Nodo<Tipo> *nuevo;
    if (!Llena())
    {
        nuevo = new Nodo<Tipo>;
        nuevo->AsigInfo(valor);
        nuevo->AsigDer(NULL);
        if (final == NULL)
            frente = nuevo;
        else
            final->AsigDer(nuevo);
        final = nuevo;
        return true;
    }
    else
        return false;
};
template <class Tipo>
bool Cola<Tipo>::Remover(Tipo &valor)
{
    Nodo<Tipo> *primero;
    if (!Vacia())
    {
        primero = frente;
        valor = primero->ObtInfo();
        frente = primero->ObtDer();
        if (frente == NULL)
            final = NULL;
        delete primero;
        return true;
    }
    else
        return false;
};
