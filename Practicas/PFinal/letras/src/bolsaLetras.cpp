/*
	Curso: 2018/2019
	Asignatura: Estructura de datos
	Autores: Jose Antonio Padial Molina
			 Elena Ortiz Moreno
	Practica: Final "Letras"
*/

#include "bolsaLetras.h"

void Bolsa_letras::leerConjunto(const Conjunto_letras &cl){
    if(!datos.empty()) datos.clear();
    Conjunto_letras::const_iterator it = cl.begin();
    Letra aux;
    while(it != cl.end()){
        aux = *it;
        for(int i = 0; i < aux.repeticiones; i++){
            datos.push_back(aux);
        }
        it++;
    }
    srand(time(NULL));
}

char Bolsa_letras::extraerLetra(){
    int num = rand()%datos.size();
    char c = datos[num].caracter;
    datos.erase(datos.begin()+num);
    return toupper(c);
}

std::ostream& operator<<(std::ostream &os, const Bolsa_letras &bl){
    for(int i = 0; i < bl.datos.size(); i++){
        os << char(toupper(bl.datos[i].caracter)) << " ";
    }
    os << std::endl;
    return os;
}