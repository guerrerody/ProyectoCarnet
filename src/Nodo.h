#ifndef Nodo_H
#define Nodo_H

template<class T>
class Nodo {

private:
	T info;
	Nodo<T> *der;
public:
	void AsigInfo(T in);
	T ObtInfo();
	void AsigDer(Nodo<T> *p);
	Nodo<T>* ObtDer();
};

// Implementación del Template

template<class T>
void Nodo<T>::AsigInfo(T in) {
	info = in;
}

template<class T>
T Nodo<T>::ObtInfo() {
	return info;
}

template<class T>
void Nodo<T>::AsigDer(Nodo<T> *p) {
	der = p;
}

template<class T>
Nodo<T>* Nodo<T>::ObtDer() {
	return der;
}

#endif
