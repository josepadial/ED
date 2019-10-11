/*
	Curso: 2018/2019
	Asignatura: Estructura de datos
	Autores: Jose Antonio Padial Molina
			 Elena Ortiz Moreno
	Practica: Final "Letras"
*/

#ifndef __CONJUNTO_LETRAS_H__
#define __CONJUNTO_LETRAS_H__

#include <iostream>
#include <set>

using namespace std;

/**
 * @brief TDA Letra
 * @details almacena un caracter, la cantidad de veces que aparece en la bolsa y su puntuacion.
 */
struct Letra{
    char caracter;
    unsigned int repeticiones;
    unsigned int puntuacion;

    /**
	 * @brief Construye una Letra vacia.
	 */
    Letra():caracter('\0'),repeticiones(0),puntuacion(0){}

    /**
	 * @brief Construye una Letra con datos.
	 * @param Char caracter, unsigned int repeticiones y unsigned int puntuacion.
	 */
    Letra(char c, unsigned int cnt, unsigned int ptn):caracter(c),repeticiones(cnt),puntuacion(ptn){}

    /**
	 * @brief Sobrecarga del operador <.
	 */
    bool operator<(const Letra &l)const{return caracter < l.caracter;}
};

/**
 * @brief TDA Conjunto Letras
 * @details se llena desde un fichero
 */
class Conjunto_letras{
	private:
		set<Letra> datos;
	public:
		/**
		 * @brief Construye un diccionario vacio.
		 */
		Conjunto_letras(){}

		/**
		 * @brief Construye un diccionario por copia.
		 * @param Un Conjunto de letras de tipo Conjunto_letras.
		 */
	    Conjunto_letras(const Conjunto_letras& otro){datos=otro.datos;}

	    /**
		 * @brief Detructor.
		 */
	    ~Conjunto_letras(){datos.clear();}

	    /**
	     * @brief Obtiene la puntuación de una palabra.
	     * @param Un String donde le pasamos la palabra a consultar.
	     * @return Un entero con la suma de las puntuaciones de las letras de la palabra.
	     */
	    int puntuacion(string palabra);

	    /**
		 * @brief Limpia el set donde estan los datos.
		 */
	    void clear(){datos.clear();}

	    /**
		 * @brief Indica si una letra esta en el Conjunto de letras o no.
		 * @param Una letra de tipo Letra.
		 * @return True si la letra esta en el Conjunto de letras y false en caso contrario.
		 */
	    unsigned int count(const Letra& val)const{return datos.count(val);}

	    /**
		 * @brief Comprueba si esta vacio el set.
		 * @return True si esta vacio false si hay datos.
		 */
	    bool empty()const{return datos.empty();}

	    /**
		 * @brief Elimina un valor del set.
		 * @param Valor a eliminar.
		 * @return True si lo ha borrado y false si no.
		 */
	    unsigned int erase(const Letra &val){return datos.erase(val);}

	    /**
		 * @brief Inserta un elemento en el set
		 * @param Valor a insetar
		 * @return Pair con la posicion de inserccion y un bool si lo ha logrado o no.
		 */
	    pair<set<Letra>::iterator,bool> insert(const Letra &val){return datos.insert(val);}
	    
		/**
		 * @brief Devuelve el numero de letras en el Conjunto de letras.
		 * @return Tamanio del set datos.
		 */
	    unsigned int size()const{return datos.size();}

	    /**
		 * @brief Intercambia los valores de dos Conjuntos de letras
		 * @param Otro Conjunto de letras.
		 */	
	    void swap(Conjunto_letras &cl){datos.swap(cl.datos);}

	    /**
		 * @brief Buscar una Letra en una determinada posicion.
		 * @param Posicion a buscar.
		 * @return Valor de la posicon a buscar en el Set.
		 */
	    Letra at(int n){return this->operator[](n);}
	    
	    /**
		 * @brief Sobrecarga del operador =
		 */
	    Conjunto_letras& operator=(const Conjunto_letras &cl);

	    /**
		 * @brief Sobrecarga del operador []
		 */
	    Letra operator[](int n);

		/**
		 * @brief Flujo de entrada
		 */	    
	    friend istream& operator>>(istream &is, Conjunto_letras &cl);

	    /**
		 * @brief Flujo de salida
		 */
	    friend ostream& operator<<(ostream &os, const Conjunto_letras &cl);
	    
	    /**
		 * @brief Class iterator
		 * @details Se hace para poder iterar sobre los elementos de tipo Conjunto_letras
		 */
	    class iterator{
		    private:
		        set<Letra>::iterator it;
		    public:
		        iterator(){}
		        iterator(const set<Letra>::iterator& otro):it(otro){}
		        iterator(const iterator& otro):it(otro.it){}
		        ~iterator(){}
		        iterator& operator=(const set<Letra>::iterator& otro){it=otro;return *this;}
		        iterator& operator=(const iterator& otro){it=otro.it;return *this;}
		        const Letra& operator*()const{return *it;}
		        iterator& operator++(){++it;return *this;}
		        iterator& operator--(){--it;return *this;}
		        iterator& operator++(int){it++;return *this;}
		        iterator& operator--(int){it--;return *this;}
		        bool operator!=(const iterator& otro){return it != otro.it;}
		        bool operator==(const iterator& otro){return it == otro.it;}
	    };
	    
	    /**
		 * @brief Class const_iterator
		 * @details Se hace para poder iterar sobre los elementos de tipo Conjunto_letras que sean constantes
		 */
	    class const_iterator{
		    private:
		        set<Letra>::const_iterator const_it;
		    public:
		        const_iterator(){}
		        const_iterator(const set<Letra>::const_iterator& otro):const_it(otro){}
		        const_iterator(const const_iterator& otro):const_it(otro.const_it){}
		        ~const_iterator(){}
		        const_iterator& operator=(const set<Letra>::const_iterator& otro){const_it = otro;return *this;}
		        const_iterator& operator=(const const_iterator& otro){const_it = otro.const_it;return *this;}
		        const Letra& operator*()const{return *const_it;}
		        const_iterator& operator++(){++const_it;return *this;}
		        const_iterator& operator--(){--const_it;return *this;}
		        const_iterator& operator++(int){const_it++;return *this;}
		        const_iterator& operator--(int){const_it--;return *this;}
		        bool operator!=(const const_iterator& otro){return const_it != otro.const_it;}
		        bool operator==(const const_iterator& otro){return const_it == otro.const_it;}
	    };
	    
	    iterator begin(){iterator i = datos.begin();return i;}
	    iterator end(){iterator i = datos.end();return i;}
	    const_iterator begin()const{const_iterator i = datos.begin();return i;}
	    const_iterator end()const{const_iterator i = datos.end();return i;}
};

#endif