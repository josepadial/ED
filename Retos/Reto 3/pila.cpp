/**
 * @file pila.cpp
 * @brief Fichero implementación métodos del TDA Pila
 * @author Jose Antonio Padial Molina
 */

#include <cassert>

template<class T>
Pila<T>::Pila(){

}

template<class T>
Pila<T>::Pila(const Pila<T> &original){
	this -> lista = original.lista;
}

template<class T>
Pila<T>::~Pila(){
	
}

template<class T>
Pila<T>& Pila<T>::operator=(const Pila<T> &otra){
	if(this != &otra){
		this -> lista = otra.lista;
	}

	return *this;
}

template<class T>
bool Pila<T>::vacia() const{
	return this -> lista.empty();
}

template<class T>
T& Pila<T>::top(){
	assert(!this -> vacia());
	return this -> lista.back();
}

template<class T>
const T& Pila<T>::top() const{
	assert(!this -> vacia());
	return this -> lista.back();
}

template<class T>
void Pila<T>::poner(const T &elemento){
	this -> lista.push_back(elemento);
}

template<class T>
void Pila<T>::quitar(){
	assert(!this -> vacia());
	this -> lista. pop_back();
}

template<class T>
void Pila<T>::limpiar(){
	this -> lista.clear();
}

template<class T>
int Pila<T>::num_elementos() const{
	return this -> lista.size();
}
