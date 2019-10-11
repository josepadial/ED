/**
  * @file pila_max_vd.cpp
  * @brief Fichero implementacion del TDA Pila max con vector
  * @author Jose Antonio Padial Molina
  */
#include <sstream>
using namespace std;

template <class T>
void Pila_max_vd<T>::forcePush(T e, T max){
	if(num_elementos == tamanio) resize(2*tamanio);
	datos[num_elementos].ele = e;
	datos[num_elementos].maximo = max;
	num_elementos++;
}

template <class T>
void Pila_max_vd<T>::resize(int n){
	if(tamanio < n){
		vector<elemento<T> > aux(n);
		for(int i=0; i<tamanio; i++){
			aux[i] = datos[i];
		}
		datos=aux;
		tamanio = aux.size();
	}
	else if(tamanio > n){
		vector<elemento<T> > aux(n);
		aux = datos;
		datos = aux;
		tamanio = n;
	}
}

template <class T>
Pila_max_vd<T>::Pila_max_vd(){
	num_elementos = 0;
	tamanio = 10;
	vector<elemento<T> > aux(tamanio);
	datos = aux;
}

template <class T>
Pila_max_vd<T>::Pila_max_vd(int n){
	num_elementos = 0;
	tamanio = n;
	vector<elemento<T> > aux(tamanio);
	datos = aux;
}

template <class T>
Pila_max_vd<T>::Pila_max_vd(const Pila_max_vd<T>& pmVd){
	num_elementos = pmVd.num_elementos;
	tamanio = pmVd.tamanio;
	vector<elemento<T> > aux(tamanio);
	datos = aux;

	for(int i=0; i<tamanio; i++){
		datos[i] = pmVd.datos[i];
	}
}

template <class T>
Pila_max_vd<T>::~Pila_max_vd(){
	
}

template <class T>
Pila_max_vd<T>& Pila_max_vd<T>::operator = (const Pila_max_vd<T> & pmVd){
	if (this != &pmVd) {
		num_elementos = pmVd.size();

		if (pmVd.getTam() != tamanio) {
			tamanio = pmVd.getTam();
			resize(tamanio);
		}

		for (int i=0; i<num_elementos; i++) {
			datos[i].ele = pmVd.getPos(i).ele;
			datos[i].maximo = pmVd.getPos(i).maximo;
		}
		return *this;
	}
}

template <class T>
void Pila_max_vd<T>::push(T e){
	if (num_elementos == tamanio) resize(2*tamanio);
	datos[num_elementos].ele = e;

	// Si es el unico elemento de la pila es el maximo
	if (num_elementos == 0){
		datos[num_elementos].maximo = e;
	}
	// Si no es el unico elemento en la pila, comprobamos si es el maximo
	else {
		T maximoAnterior = datos[num_elementos - 1].maximo;
		if (maximoAnterior < e)
			datos[num_elementos].maximo = e;
		else
			datos[num_elementos].maximo = maximoAnterior;
	}
	num_elementos++;
}

template <class T>
void Pila_max_vd<T>::pop(){
	num_elementos--;
	resize(num_elementos);
}

template <class T>
void Pila_max_vd<T>::clear() {
	num_elementos = 0;
	tamanio = 10;
	vector<elemento<T> > aux(tamanio);
	datos = aux;
}

template <class T>
ostream& operator<<(ostream & os, const Pila_max_vd<T> & pmVd) {
	Pila_max_vd<T> aux1 = pmVd;
	Pila_max_vd<T> aux2 = pmVd;
	aux2.clear();

	while (!aux1.empty()) {
		aux2.forcePush(aux1.elem(), aux1.max());
		aux1.pop();
	}

	while (!aux2.empty()) {
		os << aux2.peek() << endl;
		aux2.pop();
	}
	return os;
}

template <class T>
istream& operator >> (istream & is, Pila_max_vd<T> & pmVd) {
	if (is)
		while (is.peek() != '\0' && !is.eof()) {
			int num;
			is >> num;
			pmVd.push(num);
		}
	return is;
}

