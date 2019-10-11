/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA FechaHistorica
  * @author Jose Antonio Padial Molina
  */

#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include "fechahistorica.h"
#include <istream>
#include <iostream>

using namespace std;

class Cronologia{
	private:
		vector<FechaHistorica> fechaHisto;

		/**
		* @brief Ordena la Cronologia por fecha creciente
		*/
		void order();

		/**
		* @brief Intercanbia la posicion de dos fechas historicas en el vector de fechas historicas de la Cronologia
		* @param fch1 fecha a intercambiar
		* @param fch2 fecha a intercambiar
		*/
		void swap(FechaHistorica& fch1, FechaHistorica& fch2);
	public:
		/**
	    * @brief Constructor sin parámetros.
	    * Constructor sin parámetros. Crea una creonología vacía.
	    */
	    Cronologia();

	    /**
		* @brief Constructor de Cronologia dado un conjunto de fechas historicas
		* @param fechashistoricas conjunto de fechas historicas
		*/
		Cronologia(const vector<FechaHistorica>& fechashistoricas);

	    /**
	    * @brief Destructor de la clase.
	    * Destructor de la clase. Elimina los objetos de tipo cronología.
	    */
	    ~Cronologia();

	    /**
		* @brief Operador de suma para Cronologias
		* @param crnlg Cronologia sumar
		* @return fecha historica resultante de la suma de las fechas historicas
		*/
		Cronologia operator+(const Cronologia& crnlg);

		/**
		* @brief Devuelve un vector con las fechas historicas de la Cronologia
		* @return Vector con las fechas historicas de la Cronologia
		*/
		vector<FechaHistorica> getFechashistoricas();

		/**
		* @brief Añade una fecha historica a la Cronologia
		* @param fchhst fecha historica a añadir
		*/
		void addFechaHistorica(FechaHistorica fchhst);

		/**
		* @brief Devuelve la posicion de una fecha historica en el vector de Cronologia dado el año
		* @param fecha año de la fecha historica a consultar
		* @return Posicion de la fecha historica del año dado en la Cronologia
		*/
		int binarySearch(int fecha);

		/**
		* @brief Añade un acontecimiento a una fecha historica de la Cronologia dado el año
		* @param fecha año de la fecha historica a la que añadir el acontecimiento
		* @param acontecimiento acontecimiento a añadir
		*/
		void addAcontToFechaHistorica(int fecha, string acontecimiento);

		/**
		* @brief Elimina una fecha historica de la Cronologia dada el año de la FechaHistorica
		* @param fecha año de la fecha historica a eliminar
		*/
		void deleteFechaHistorica(int fecha);

		/**
		* @brief Devuelve si el año facilitado coincide con el de alguna fecha historica incluida en la Cronologia
		* @param fecha año de la fecha historica a consultar
		* @return True si el año facilitado coincide con el de alguna fecha historica de la Cronologia
		*/
		bool isFechaHistorica(int fecha);

		/**
		* @brief Devuelve una fecha de la Cronologia dadoo el año
		* @param fecha año de la fecha historica a obtener
		* @return fecha historica de la Cronologia que coincide con el año facilitado
		*/
		FechaHistorica getFechaHistorica(int fecha);

		/**
		* @brief Operador flujo de salida de una Cronologia
		* @param os flujo de dalida
		* @param crnlg Cronologia a imprimir
		* @return Referencia al flujo de salida
		*/
		friend ostream& operator << (ostream& os, const Cronologia& crnlg);

		/**
		* @brief Operador flujo de entrada de una Cronologia
		* @param is flujo de entrada
		* @param crnlg Cronologia a leer
		* @return Referencia al flujo de entrada
		*/
		friend istream& operator >> (istream& is, Cronologia& crnlg);

		/**
		* @brief Sustituye el vector de fechas historicas de la Cronologia por el facilitado por parametro
		* @param fechashistoricas vector de fechas historicas a asignar a la Cronologia
		*/
		void setCronologia(const vector<FechaHistorica>& fechashistoricas);

		/**
		* @brief Asigna el vector de acontecimientos facilitado por parametro a la fecha historica de la Cronologia que coincide con el año facilitado por parametro
		* @param fecha año de la fecha historica de la Cronologia a modificar
		* @param FechaHistorica vector de acontecimientos que asignar a la fecha historica a modificar
		*/
		void setFechaHistorica(int fecha, const vector<string>& FechaHistorica);

		/**
		* @brief Operador de igualdad de Cronologia (dos Cronologias son iguales si todas sus fechas historicas son iguales)
		* @param crnlg Cronologia a comparar
		* @return True si las dos Cronologias son iguales
		*/
		bool operator ==(const Cronologia &crnlg);

		/**
		* @brief Operador de desigualdad de Cronologia (dos Cronologias son distintas si alguna de sus fechas historicas son distintas)
		* @param crnlg Cronologia a comparar
		* @return True si las dos Cronologias son distintas
		*/
		bool operator !=(const Cronologia &crnlg);

		/**
		* @brief Operador suma y asignación de dos Cronologias
		* @param crnlg Cronologia a añadir
		*/
		void operator += (const Cronologia crnlg);
};

#endif