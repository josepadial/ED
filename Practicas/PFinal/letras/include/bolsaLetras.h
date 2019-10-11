/*
	Curso: 2018/2019
	Asignatura: Estructura de datos
	Autores: Jose Antonio Padial Molina
			 Elena Ortiz Moreno
	Practica: Final "Letras"
*/

#ifndef _bolsa_letras_h_
#define _bolsa_letras_h_

#include "conjunto_letras.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
 * @brief TDA BolsaLetras
 * @details Almacena las letras repetidas tantas veces como indica su vaor en repeticiones
 */
class Bolsa_letras{
private:
    vector<Letra> datos;
public:
	/**
	 * @brief Construye un diccionario vacio.
	 */
    Bolsa_letras(){}
    
    /**
	 * @brief Lee un conjunto de letras.
	 * @param Un Conjunto de letras de tipo Conjunto_letras.
	 */
    void leerConjunto(const Conjunto_letras &cl);
    
    /**
	 * @brief Limpia el vector de datos.
	 */
    void clear(){datos.clear();}
    
    /**
	 * @brief Extrae una letra.
	 * @return Un char con la letra.
	 */
    char extraerLetra();
    
    /**
	 * @brief Introduce una letra en el vector.
	 */
    void introducirLetra(const Letra &l){datos.push_back(l);}
    
    /**
	 * @brief Indica el tamanio del vector.
	 * @return Tamanio del vector.
	 */
    unsigned int size()const{return datos.size();}
    
    /**
	 * @brief Sobrecarga del operador =
	 */
    Letra operator[](int n)const{return datos[n];}
    
    /**
	 * @brief Sobrecarga del operador =
	 */
    Bolsa_letras& operator=(const Bolsa_letras &otra){datos=otra.datos;return *this;}
    
    /**
	 * @brief Flujo de salida
	 */
    friend ostream& operator<<(ostream &os, const Bolsa_letras &bl);
};

#endif