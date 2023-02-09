#ifndef Pila_H
#define Pila_H

#include "Nodo.h"

template <class Tipo>

class Pila
{
    Nodo<Tipo> *tope;

public:
    Pila();
    bool Vacia();
    bool Llena();
    bool Insertar(Tipo Valor);
    bool Remover(Tipo &Valor);
    ~Pila();
};

#endif