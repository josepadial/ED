/*
	Curso: 2018/2019
	Asignatura: Estructura de datos
	Autores: Jose Antonio Padial Molina
			 Elena Ortiz Moreno
	Practica: Final "Letras"
*/

#ifndef _Diccionario_h_
#define _Diccionario_h_

#include <set>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/**
 * @brief TDA Diccionario
 * @details Almacena las palabras de un fichero de texto e itera sobre ellas
 *
 */
class Diccionario{
	private:
	 	set<string> datos;
	public:
	 	/**
		 * @brief Construye un diccionario vacio.
		 */
		Diccionario(){}

		/**
		 * @brief Construye un diccionario por copia.
		 */
	    Diccionario(const Diccionario& otro){datos=otro.datos;}

	    /**
		 * @brief Detructor.
		 */
	    ~Diccionario(){datos.clear();}

	    /**
		 * @brief Devuelve el numero de palabras en el Diccionario.
		 * @return Tamanio del set datos.
		 */
	    unsigned int size()const{return datos.size();}

	    /**
		 * @brief Obtiene todas las palabras en el diccionario de un longitud dada
		 * @param longitud: la longitud de las palabras de salida
		 * @return un vector con las palabras de longitud especifica en el parametro de entrada
		 */
	    vector<string> palabrasLongitud(int longitud);

	    /**
		 * @brief Obtiene todas las palabras en el diccionario que contengan un String pasado.
		 * @param String con lo que debe contener la palabra.
		 * @return un vector con las palabras de con ese String especifico en el parametro de entrada
		 */
	    vector<string> palabrasCon(const string &p);

	    /**
		 * @brief Indica si una palabra esta en el diccionario o no.
		 * @param palabra: la palabra que se quiere buscar.
		 * @return True si la palabra esta en el diccionario y False en caso contrario.
		 */
	    bool count(const string& val)const{return datos.count(val);}

	    /**
		 * @brief Indica el numero de apariciones de una letra.
		 * @param c letra a buscar.
		 * @return Un entero indicando el numero de apariciones.
		 */
		int getApariciones(const char c);

		/**
		 * @brief Cuenta el total de letras de un diccionario.
		 * @return Entero con el total de letras.
		 */
		int getTotalLetras();

		/**
		 * @brief Limpia el set.
		 */
	    void clear(){datos.clear();}

		/**
		 * @brief Comprueba si esta vacio el set.
		 * @return True si esta vacio false si hay datos.
		 */	    
	    bool empty()const{return datos.empty();}

	    /**
		 * @brief Elimina un valor del set.
		 * @param Valor a eliminar.
		 * @return True si esta vacio false si hay datos.
		 */	
	    unsigned int erase(const string &val){return datos.erase(val);}

	    /**
		 * @brief Inserta un elemento en el set
		 * @param Valor a insetar
		 * @return Pair con la posicion de inserccion y un bool si lo ha logrado o no.
		 */	
	    pair<set<string>::iterator,bool> insert(const string &val){return datos.insert(val);}
	    
	    /**
		 * @brief Intercambia los valores de dos diccionarios
		 * @param Diccionario
		 */	
	    void swap(Diccionario &dic){datos.swap(dic.datos);}

	    /**
		 * @brief Buscar un string en una determinada posicion
		 * @param Posicion a buscar
		 */	
	    string at(int n){return this->operator[](n);}

		/**
		 * @brief Sobrecarga del operador =
		 */		    
	    Diccionario& operator=(const Diccionario &dic);

	    /**
		 * @brief Sobrecarga del operador []
		 */
	    string operator[](int n);

	    /**
		 * @brief Flujo de entrada
		 */
	    friend istream& operator>>(istream &is, Diccionario &dic);

	    /**
		 * @brief Flujo de salida
		 */
	    friend ostream& operator<<(ostream &os, const Diccionario &dic);
    	
    	/**
		 * @brief Class iterator
		 * @details Se hace para poder iterar sobre los elementos de tipo Conjunto_letras
		 */
    	class iterator{
		    private:
		        set<string>::iterator it;
		    public:
		        iterator(){}
		        iterator(const set<string>::iterator& otro):it(otro){}
		        iterator(const iterator& otro):it(otro.it){}
		        ~iterator(){}
		        iterator& operator=(const set<string>::iterator& otro){it=otro;return *this;}
		        iterator& operator=(const iterator& otro){it=otro.it;return *this;}
		        string operator*()const{return *it;}
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
		        set<string>::const_iterator const_it;
		    public:
		        const_iterator(){}
		        const_iterator(const set<string>::const_iterator& otro):const_it(otro){}
		        const_iterator(const const_iterator& otro):const_it(otro.const_it){}
		        ~const_iterator(){}
		        const_iterator& operator=(const set<string>::const_iterator& otro){const_it = otro;return *this;}
		        const_iterator& operator=(const const_iterator& otro){const_it = otro.const_it;return *this;}
		        const string operator*()const{return *const_it;}
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