#ifndef Cola_H
#define Cola_H


#include "Nodo.h"

template <class Tipo>

class Cola
{
private:
    Nodo<Tipo> *frente, *final;

public:
    Cola();
    bool Vacia();
    bool Llena();
    bool Insertar(Tipo Valor);
    bool Remover(Tipo &Valor);
    ~Cola();
};

#endif
