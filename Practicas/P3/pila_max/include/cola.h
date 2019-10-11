/**
  * @file cola.h
  * @brief Fichero cabecera del TDA Pila cola
  * @author Jose Antonio Padial Molina
  *
  * Gestiona una secuencia de elementos con facilidades para la insercion y
  * borrado de elementos en un extremo
  */

#ifndef _COLA_H_
#define _COLA_H_

#include <cassert>
#include <iostream>

using namespace std;

/**
*  @brief T.D.A. Cola
*
*
* Una instancia @e c del tipo de dato abstracto Cola sobre un dominio @e T es
* una sucesion finita de elementos del mismo con un funcionamiento @e FIFO
* (First In, First Out}). En una cola, las operaciones de insercion tienen
* lugar en uno de los extremos, denominado @e final de la cola, mientras que
* el borrado y consulta se lleva a cabo en el otro extremo, denominado
* @e frente de la cola. Una cola de longitud @e n la denotamos

* - <a1,a2,a3,..,an<

* En esta cola, tendremos acceso unicamente al elemento del @e Frente,
* es decir, a @e a1. El borrado o consulta de un elemento sera sobre @e a1,
* mientras que la insercion de un nuevo elemento se hara despues de
* @e an (final de la cola).
*
* Si n=0 diremos que la cola esta vaia.
*
* El espacio requerido para el almacenamiento es O(n), donde n es el numero
* de elementos de la cola.
*/

template <class T>
class Cola {
	private:
		struct Celda {
			T elemento;        //< Elemento de informacion.
			Celda * siguiente; //< Puntero al siguiente nodo.

							   /**
							   * @brief Constructor por defecto
							   */
			Celda() : siguiente(0) {
			}

			/**
			* @brief Constructor con parametros
			* @param elem Elemento de informacion.
			* @param sig Puntero al siguiente nodo.
			*/
			Celda(const T & elem, Celda * sig) : elemento(elem), siguiente(sig) {
			}
		};

		Celda * primera; //< Puntero al primer nodo de la lista.
		Celda * ultima;  //< Puntero al ultimo nodo de la lista.
		int num_elem;    //< Numero de elementos de la cola.

	public:
		// ---------------  Constructores ----------------
		/**
		* @brief Constructor por defecto
		*/
		Cola() : primera(0), ultima(0), num_elem(0) {
		}

		/**
		* @brief Constructor de copias
		* @param original La cola de la que se hara la copia.
		*/
		Cola(const Cola<T> & original);

		// ------------------ Destructor ------------------
		/**
		* @brief Destructor
		*/
		~Cola();

		// --------------- Otras funciones ---------------
		/**
		* @brief Operador de asignacion
		* @param otra La cola que se va a asignar.
		*/
		Cola& operator= (const Cola<T> & otra);

		/**
		* @brief Comprueba si la cola est� vac�a
		*/
		bool vacia() const {
			return num_elem == 0;
		}

		/**
		* @brief Devuelve el elemento del frente de la cola
		*/
		T& frente() {
			assert(primera != 0);        //Si la cola esta vacia, abortar
			return primera->elemento;  //Devuelve el elemento del frente de la cola
		}

		/**
		* @brief Devuelve el elemento del frente de una cola constante
		*/
		const T & frente() const {
			assert(primera != 0);        //Si la cola esta vacia, abortar
			return primera->elemento;  //Devuelve el elemento del frente de la cola
		}

		/**
		* @brief A�ade un elemento al final de la cola
		* @param elem Elemento que se va a aniadir.
		*/
		void push(const T & elem);

		/**
		* @brief Quita el elemento del frente de la cola
		*/
		void quitar();
		
		/**
		* @brief Devuelve el numero de elementos de la cola
		*/
		int num_elementos() const {
			return num_elem;
		}
};

#include "../src/cola.cpp"
#endif