/**
 * @file pila.h
 * @brief Fichero cabecera del TDA Pila
 * @author Jose Antonio Padial Molina
 *
 * Gestiona una secuencia de elementos con funcionamiento de pila
 * a través de un tipo de dato List de la STL.
 */

#ifndef _PILA_H_
#define _PILA_H_

#include <list>

using namespace std;

template<class T>

class Pila{
	private:
		list<T> lista;
	public:
		/**
	     * @brief Constructor por defecto.
	     */
		Pila();

		/**
	     * @brief Constructor de copia.
	     * @param original Pila a copiar.
	     */
		Pila(const Pila<T> &original);

		/**
	     * @brief Destructor.
	     */
		~Pila();

		/**
	     * @brief Operador de asignación.
	     * @param otra Pila a asignar.
	     * @return Referencia a la cola modificada.
	     */
		Pila& operator=(const Pila<T> &otra);

		/**
	     * @brief Comprueba si la pila está vacía.
	     * @return Booleano indicador de si la pila está vacía.
	     */
		bool vacia() const;

		 /**
	     * @brief Devuelve el elemento del tope de la pila.
	     * @return Referencia al elemento del tope de la pila.
	     */
		T& top();

		/**
	     * @brief Devuelve el elemento del tope de una pila constante
	     * @return Referencia constante al elemento del tope de la pila.
	     */
		const T& top() const;

		/**
	     * @brief Añade un elemento al final de la pila.
	     * @param elem Elemento que se va a añadir.
	     */
		void poner(const T &elemento);

		/**
	     * @brief Quita el elemento del tope de la pila.
	     */
		void quitar();

		/**
	     * @brief Quita todos los elementos de la pila.
	     */
		void limpiar();

		/**
	     * @brief Devuelve el número de elementos de la pila.
	     * @return Entero con el número de elementos de la pila.
	     */
		int num_elementos() const;
};

#include "pila.cpp"

#endif