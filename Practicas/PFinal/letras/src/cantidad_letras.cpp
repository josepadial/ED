/*
	Curso: 2018/2019
	Asignatura: Estructura de datos
	Autores: Jose Antonio Padial Molina
			 Elena Ortiz Moreno
	Practica: Final "Letras"
*/

#include <fstream>
#include <iostream>

#include "diccionario.h"
#include "conjunto_letras.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 4){
		cout << "Los parametros son: " << endl;
		cout << "1.- El fichero con el diccionario" << endl;
		cout << "2.- El fichero con las letras" << endl;
		cout << "3.- El fichero a donde escribir" << endl;
		return 0;
	}

	ifstream f_diccionario(argv[1]);
	ifstream f_letras(argv[2]);
	ofstream f_salida (argv[3]);

	if(!f_diccionario){
		cout << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

	Diccionario diccionario;
	f_diccionario >> diccionario;

	if(!f_letras){
		cout << "No puedo abrir el fichero " << argv[2] << endl;
		return 0;
	}

	Conjunto_letras conjunto;
	f_letras >> conjunto;

	if(!f_salida){
        cout << "No puedo crear el fichero " << argv[3]<<endl;
        return 0;
    }

    f_salida << "#Letra\tFAbs.\tFrel." << endl;

    for (Conjunto_letras::iterator it= conjunto.begin(); it != conjunto.end(); it++){
        Letra l = *it;
        int apariciones = diccionario.getApariciones(tolower(l.caracter));
        double porcentje = apariciones / (diccionario.getTotalLetras()+0.0);

        f_salida << l.caracter << '\t' << apariciones << '\t' << porcentje << endl;
    }

    f_salida.close();
	return 0;
}