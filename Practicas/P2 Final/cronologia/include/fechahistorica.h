/**
  * @file fechahistorica.h
  * @brief Fichero cabecera del TDA FechaHistorica
  * @author Jose Antonio Padial Molina
  */

#ifndef _FECHAHISTORICA_H_
#define _FECHAHISTORICA_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

/**
* @brief Tipo Abstracto de Datos para una fecha historica
* Una instancia del TDA fechahistorica.cpp en la que representamos mediante un vector de strings, los sucesos que tuvieron lugar ese año (
* El objeto está compuesto por un entero que representa la fecha del evento (Negativos para años antes de Cristo)
*/

class FechaHistorica{
	private:
		vector<string> acontecimientos;
		int fecha;
	public:
		/**
	    * @brief Constructor por defecto.
	    * Contructor por defecto. Crea una Lista de eventos vacía.
	    */
	    FechaHistorica();

	    /**
		* @brief Constructor de fecha historica
		* @param fecha año de la fecha historica
		*/
	    FechaHistorica(int fecha);

	    /**
		* @brief Constructor de fechas historica
		* @param fecha año de la feha historica
		* @param aconts acontecimientos de la fecha historica
		*/
		FechaHistorica(int fecha, const vector<string>& aconts);

	    /**
	    * @brief Constructor de copia
	    * @param otra lista que queremos copiar
	    */
	    FechaHistorica(const FechaHistorica &otra);

	    /**
	    * @brief Destructor
	    * Destructor: destruye automaticamente la basura.
	    */
	    ~FechaHistorica();

	    /**
	    * @brief Consulta la fecha de la lista de eventos constante
	    * @return Devuelve la fecha de los eventos de la lista
	    */
	    int getFecha() const;

	    /**
	    * @brief Consulta la fecha de la lista de eventos
	    * @return Devuelve la fecha de los eventos de la lista
	    */
	    int getFecha();

	    /**
	    * @brief Muestra el titulo de un evento constante.
	    * @param pos celda que contiene el evento
	    * @return Devuelve el string que contiene.
	    *
	    */
	    string getEvento(int pos) const;

	    /**
	    * @brief Muestra el titulo de un evento.
	    * @param pos celda que contiene el evento
	    * @return Devuelve el string que contiene.
	    *
	    */
	    string getEvento(int pos);

	    /**
	    * @brief Consulta los eventos de toda una fecha
	    * @return devuelve la lista de eventos en un vector de strings.
	    */
	    vector<string> getEventos();

	    /**
		* @brief Sustituye el año de la fecha historica por el facilitado por parametro
		* @param fecha año de la fecha historica
		*/
		void setFecha(int fecha);

		/**
		* @brief Cambia el vector de acontecimientos por uno nuevo
		* @param aconts vector de los nuevos acontecimientos a establecer
		*/
		void setAcontecimientos(const vector<string> aconts);

		/**
	    * @brief Inserta un nuevo año a la cronología
	    * @param evento que se quiere insertar
	    * @return Añade al objeto implícito un año nuevo en la posición correspondiente.
	    * @pre el año ya ha sido definido.
	    */
	    void insertarAcontecimiento(string evento);

	    /**
		* @brief Elimina un acontecimiento de la fecha historica dado el string del acontecimiento
		* @param acont string del acontecimiento a eliminar
		*/
		void deleteAcontecimiento(const string& acont);

		/**
		* @brief Elimina un acontecimiento de la fecha historica dada la posicion del acontecimiento
		* @param pos posicion del acontecimiento a eliminar
		*/
		void deleteAcontecimiento(int pos);

		/**
		* @brief Devuelve el numero de acontecimientos de la fecha historica constante
		* @return Numero de acontecimientos de la fecha historica
		*/
		int numeroDeAcontecimientos() const;

		/**
		* @brief Devuelve el numero de acontecimientos de la fecha historica
		* @return Numero de acontecimientos de la fecha historica
		*/
		int numeroDeAcontecimientos();

		/**
		* @brief Devuelve si el acontecimiento dado esta en la fecha historica
		* @param acont string del acontecimiento a consultar
		* @return True si el acontecimiento está en la fecha historica
		*/
		bool esAcontecimiento(string acont);

	    /**
		* @brief Asigna a la fecha historica un nuevo año y unos acontecimientos dados por parametros
		* @param fecha año de la fecha historica 
		* @param aconts acontecimientos de la fecha historica
		*/
		void asignar(int fecha, vector<string> aconts);
		
		/**
		* @brief Operador de asignacion de fechas histoicas
		* @param fechahst fecha historica a asignar
		* @return Referencia a la fecha historica asignada
		*/
		FechaHistorica& operator=(const FechaHistorica& fechaHst);

		/**
		* @brief Compara dos fechas historicas (deben ser iguales el año y los acontecimientos en el mismo orden)
		* @param fecha fecha historica a comparar
		* @return True si las fechas historicas son iguales
		*/
		bool comparar(FechaHistorica fecha);

		/**
		* @brief Muestra por pantalla una fecha historica
		*/
		void print();

		/**
		* @brief Suma de dos fechas historicas
		* @param fechahst fecha historica a sumar
		* @return Fecha historica resultante de la suma
		*/
		FechaHistorica operator+(const FechaHistorica& fechahst);

		/**
		* @brief Operador suma y asignacion de fechas historicas
		* @param fechahst fecha historica a añadir
		*/
		void operator += (const FechaHistorica fechahst);

		/**
		* @brief Operador de igualdad de fechas historicas (dos fechas historicas son iguales si coinciden el año y los acontecimientos)
		* @param fecha fecha historica a comparar
		* @return True si las fechas historicas son iguales
		*/
		bool operator ==(const FechaHistorica &fecha);

		/**
		* @brief Operador de desigualdad de fechas historicas (dos fechas historicas son distintas si no coinciden el año o los acontecimientos)
		* @param fecha fecha historica a comparar
		* @return True si las fechas historicas son ditintas
		*/
		bool operator !=(const FechaHistorica &fecha);

		/**
		* @brief Operador flujo de salida de una fecha historica
		* @param os flujo de salida
		* @param fecha fecha historica a imprimir
		* @return Referencia al flujo de salida
		*/
		friend ostream& operator<< (ostream& os, const FechaHistorica& fecha);

		/**
		* @brief Operador flujo de entrada de una fecha historica
		* @param is flujo de entrada
		* @param fecha fecha historica a leer
		* @return Referencia al flujo de entrada
		*/
		friend istream& operator>> (istream& is, FechaHistorica& fecha);

		/**
		* @brief Operador menor que para fecha historica (una fecha es menor que otra si el año de la fecha historica es anterior al de la otra)
		* @param fechahst fecha historica a comparar
		* @return True si la fecha historica es menor a la pasada por parametro
		*/
		bool operator<(const FechaHistorica& fechaHst);

		/**
		* @brief Operador mayor que para fecha historica (una fecha es mayor que otra si el año de la fecha historica es posterior al de la otra)
		* @param fechahst fecha historica a comparar
		* @return True si la fecha historica es mayor a la pasada por parametro
		*/
		bool operator>(const FechaHistorica& fechaHst);
};

#endif