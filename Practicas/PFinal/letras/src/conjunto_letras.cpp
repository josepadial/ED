/*
	Curso: 2018/2019
	Asignatura: Estructura de datos
	Autores: Jose Antonio Padial Molina
			 Elena Ortiz Moreno
	Practica: Final "Letras"
*/

#include "conjunto_letras.h"

int Conjunto_letras::puntuacion(string palabra){
	int puntos = 0;

	for (int i=0;i<palabra.size(); i++){
		bool salir = false;

		for (set<Letra>::iterator it = datos.begin(); !salir && it!=datos.end(); ++it ){
			Letra l = *it;
			if (palabra[i] == tolower(l.caracter)){
				puntos  +=  l.puntuacion;
				salir = true;
    		}
		}
	}
	return puntos;
}

istream& operator>>(istream &is, Conjunto_letras &cl){
    string linea;
	getline(is, linea);

	while (is){
		char c;
		int n, p;

		// Obtenemos los valores (char, int, int)
		is >> c >> n >> p;

		// Creamos una nueva letra
		Letra l(c, n, p);

		// Agregamos la letra al conjunto
		cl.datos.insert(l);
	}

	return is;
}

ostream& operator<<(ostream &os, const Conjunto_letras &cl){
    Conjunto_letras::const_iterator it = cl.begin();
    Letra aux;
    os << "#Letra Cantidad Puntos" << std::endl;
    while(it != cl.end()){
        aux = *it;
        os << char(toupper(aux.caracter)) << "\t" << aux.repeticiones << "\t" << aux.puntuacion << std::endl;
        it++;
    }
    return os;
}

Conjunto_letras& Conjunto_letras::operator=(const Conjunto_letras &cl){
    if(this != &cl)
        datos = cl.datos;
    return *this;
}

Letra Conjunto_letras::operator[](int n){
    Letra l;
    
    if(n >= 0 && n < datos.size()){
        iterator it = datos.begin();
        for(int i = 0; it != datos.end() && i < n; i++,it++){}
        l = *it;
    }
    
    return l;
}
