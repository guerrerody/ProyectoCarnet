#ifndef Lista_H
#define Lista_H

#include "Nodo.h"

template<class Tipo>
class Lista {
	typedef Nodo<Tipo> *Apuntador;
private:
	Nodo<Tipo> *primero;
public:

	Lista();
	~Lista();
	Nodo<Tipo>* ObtPrimero();
	void AsigPrimero(Nodo<Tipo> *p);
	bool Vacia();
	bool Llena();
	bool InsComienzo(Tipo valor);
	bool EliComienzo(Tipo &valor);
	bool InsDerecho(Apuntador p, Tipo valor);
	bool EliDerecho(Apuntador p, Tipo &valor);

};

#endif
