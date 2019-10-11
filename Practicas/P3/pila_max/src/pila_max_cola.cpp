/**
  * @file pila_max_vd.cpp
  * @brief Fichero implementacion del TDA Pila max con cola
  * @author Jose Antonio Padial Molina
  */

#include <sstream>
using namespace std;

template <class T>
Pila_max_cola<T>::Pila_max_cola(){
	
}

template <class T>
Pila_max_cola<T>::Pila_max_cola(const Pila_max_cola & pmCo) {
	datos = pmCo.datos;
}

template <class T>
Pila_max_cola<T>::~Pila_max_cola(){
	
}

template <class T>
Pila_max_cola<T> & Pila_max_cola<T>::operator = (const Pila_max_cola & pmCo) {
	datos = pmCo.datos;
	return *this;
}

template <class T>
void Pila_max_cola<T>::push(T e) {
	elemento<T> auxElem;
	int contador = 0;

	auxElem.ele = e;

	if (datos.vacia())
		auxElem.maximo = e;
	else
		while (contador < datos.num_elementos()) {
			contador++;
			if (contador == datos.num_elementos())
				if (datos.frente().maximo > e)
					auxElem.maximo = datos.frente().maximo;
				else
					auxElem.maximo = e;
			datos.push(datos.frente());
			datos.quitar();
		}
	datos.push(auxElem);
}

template <class T>
void Pila_max_cola<T>::pop() {
	int contador = 0;

	while (contador < datos.num_elementos()) {
		contador++;
		if (contador < datos.num_elementos())
			datos.push(datos.frente());
		datos.quitar();
	}
}

template <class T>
elemento<T> Pila_max_cola<T>::peek() {
	int contador = 0;
	elemento<T> auxElem;

	while (contador < datos.num_elementos()) {
		contador++;
		if (contador == datos.num_elementos())
			auxElem = datos.frente();
		datos.push(datos.frente());
		datos.quitar();
	}
	return auxElem;
}

template <class T>
T Pila_max_cola<T>::elem() {
	int contador = 0;
	T auxElem;

	while (contador < datos.num_elementos()) {
		contador++;
		if (contador == datos.num_elementos())
			auxElem = datos.frente().ele;
		datos.push(datos.frente());
		datos.quitar();
	}
	return auxElem;
}

template <class T>
T Pila_max_cola<T>::max() const {
	return datos.frente().maximo;
}

template <class T>
void Pila_max_cola<T>::clear() {
	Pila_max_cola<T> aux;
	*this = aux;
}

template <class T>
ostream & operator << (ostream & os, const Pila_max_cola<T> & pmCo) {
	int contador = 0;
	Pila_max_cola<T> colaAux = pmCo;

	while (contador < colaAux.datos.num_elementos()) {
		contador++;
		os << colaAux.datos.frente() << endl;
		colaAux.datos.push(pmCo.datos.frente());
		colaAux.datos.quitar();
	}
	return os;
}

template <class T>
istream & operator >> (istream & is, Pila_max_cola<T> & pmCo) {
	if (is)
		while (is.peek() != '\0' && !is.eof()) {
			int num;
			is >> num;
			pmCo.push(num);
		}
	return is;
}