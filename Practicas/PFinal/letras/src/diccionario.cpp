/*
	Curso: 2018/2019
	Asignatura: Estructura de datos
	Autores: Jose Antonio Padial Molina
			 Elena Ortiz Moreno
	Practica: Final "Letras"
*/

#include "diccionario.h"

istream& operator>>(istream &is, Diccionario &dic){
    string aux;

    while(getline(is,aux)){
        dic.datos.insert(aux);
    }
    return is;
}

ostream& operator<<(ostream &os, const Diccionario &dic){
    Diccionario::const_iterator it = dic.begin();

    while(it != dic.end()){
        os << *it << endl;
        it++;
    }
    return os;
}

int Diccionario::getApariciones(const char c){
	int apariciones=0;
	iterator it = begin();
    
    while(it != end()){
        string aux = *it;
        for(int i = 0; i < aux.size(); i++){
            if(aux.at(i) == c){
                apariciones++;
            }
        }
        it++;
    }
    
    return apariciones;
}

int Diccionario::getTotalLetras(){
	int apariciones=0;
	iterator it = begin();
    
    while(it != end()){
        string aux = *it;
        apariciones += aux.size();
        it++;
    }
    
    return apariciones;
}

vector<string> Diccionario::palabrasLongitud(int longitud){
	vector<string> palabras;

	for (iterator it_dic = begin(); it_dic != end(); ++it_dic){
		if ((*it_dic).size() == longitud)
			palabras.push_back(*it_dic);
	}
	return palabras;
}

vector<string> Diccionario::palabrasCon(const string &p){
    iterator it = begin();
    vector<string> v;
    string aux;
    while(it != end()){
        aux = *it;
        if(aux.find(p) != -1)
            v.push_back(aux);
        it++;
    }
    return v;
}

Diccionario& Diccionario::operator=(const Diccionario &dic){
    if(this != &dic)
        datos = dic.datos;
    return *this;
}

string Diccionario::operator[](int n){
    string s = "";
    
    if(n >= 0 && n < datos.size()){
        iterator it = datos.begin();
        for(int i = 0; it != datos.end() && i < n; i++,it++){}
        s = *it;
    }
    
    return s;
}