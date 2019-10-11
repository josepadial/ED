/**
  * @file pila_max_cola.h
  * @brief Fichero cabecera del TDA Pila max con cola
  *
  * Gestiona una secuencia de elementos con facilidades para la insercion y
  * borrado de elementos en un extremo
  */

#ifndef _PILA_MAX_COLA_
#define _PILA_MAX_COLA_

#include <iostream>
#include "cola.h"

using namespace std;

template <class T>
struct elemento{
	T ele;
	T maximo;
	friend ostream& operator<<(ostream& os, const elemento<T>& e){
		os << "(" << e.ele << "|" << e.maximo << ")";
		return os;
	}

};

/**
 *  @brief T.D.A. Pila_max
 *
 * Una instancia @e v del tipo de datos abstracto Pila_max sobre el tipo @c entero es
 * una lista de pares de elementos <entero,entero > con un funcionamiento @e LIFO (Last In,
 * First Out). En una pila, las operaciones de insercion y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila_max de longitud
 * @e n donde @e ai es el elemento de la posicion i-esima. Y @e max{ai,...aj} es el maximo del conjunto de * elementos que van desde @e ai a @e aj
 * En esta pila, tendremos acceso unicamente al elemento del @e Tope, es decir,
 * a @e an. El borrado o consulta de un elemento sera sobre  @e an, y la
 * insercion de un nuevo elemento se hara sobre este. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila esta vacia.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el numero de elementos de la Pila_max.
 */

template <class T>
class Pila_max_cola{
	private:
		Cola<elemento<T> > datos;
	public:
		/**
		 * @brief Constructor por defecto
		 */
		Pila_max_cola();

		/**
		* @brief Constructor de copias
		* @param pm La pila de la que se hara la copia.
		*/
		Pila_max_cola(const Pila_max_cola& pmCo);

		/**
		* @brief Destructor
		*/
		~Pila_max_cola();

		/**
		* @brief Vacia la pila
		*/
		void clear();

		/**
		* @brief Operador de asignacion
		* @param pm La pila que se va a asignar.
		*/
		Pila_max_cola<T> & operator = (const Pila_max_cola & pmCo);

		/**
		* @brief Aniade un elemento "encima" del tope de la pila
		* @param e Elemento que se va a aniadir.
		*/
		void push(T e);

		/**
		* @brief Quita el elemento del tope de la pila
		*/
		void pop();

		/**
		* @brief Devuelve el elemento del tope de la pila y el maximo
		*/
		elemento<T> peek();

		/**
		* @brief Devuelve una posicion de la pila
		*/
		elemento<T> getPos(int i) const { return datos[i]; }

		/**
		* @brief Devuelve el elemento del tope de la pila
		*/
		T elem();

		/**
		* @brief Devuelve el maximo de la pila
		*/
		T max() const;

		/**
	     * @brief Comprueba si la pila esta vacia
	     */
		bool empty() const { return datos.vacia(); }

		/**
	     * @brief Devuelve el numero de elementos de la pila
	     */
		int size() const { return datos.num_elementos(); }

		/**
		* @brief Operador de igualdad. Dos pilas son iguales si tienen los mismos maximos
		* @param pm La pila con la que comparar
		*/
		bool operator == (const Pila_max_cola<T> & pmCo) { return this->max() == pmCo.max(); };

		/**
		* @brief Operador de desigualdad. Dos pilas son distintas si tienen maximos distintos
		* @param pm La pila con la que comparar
		*/
		bool operator != (const Pila_max_cola<T> & pmCo) { return this->max() != pmCo.max(); };

		/**
		* @brief Operador de comparacion menor que. Una pila es menor que otra si su maximo es menor
		* @param pm La pila con la que comparar
		*/
		bool operator < (const Pila_max_cola<T> & pmCo) { return this->max() < pmCo.max(); }

		/**
		* @brief Operador de comparacion mayor que. Una pila es mayor que otra si su maximo es mayor
		* @param pm La pila con la que comparar
		*/
		bool operator > (const Pila_max_cola<T> & pmCo) { return this->max() > pmCo.max(); }

		/**
		* @brief Operador flujo de salida
		*/
		friend ostream & operator << (ostream & os, const Pila_max_cola<T> & pmCo);

		/**
		* @brief Operador flujo de entrada
		*/
		friend istream & operator >> (istream & is, Pila_max_cola<T> & pmCo);
};

#include "../src/pila_max_cola.cpp"
#endif