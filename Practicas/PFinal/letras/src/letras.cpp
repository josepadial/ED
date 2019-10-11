/*
	Curso: 2018/2019
	Asignatura: Estructura de datos
	Autores: Jose Antonio Padial Molina
			 Elena Ortiz Moreno
	Practica: Final "Letras"
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm> // Utilizado para el sort
#include <utility>

#include "diccionario.h"
#include "bolsaLetras.h"
#include "conjunto_letras.h"

using namespace std;

struct cmp_pal{
    bool operator()(const pair<string,int> &L1 , const pair<string,int> &L2){
        return (L1.first.size() > L2.first.size()) ? true : false;
    }
};

struct cmp_pts{
    bool operator()(const pair<string,int> &L1 , const pair<string,int> &L2){
        return (L1.second > L2.second) ? true : false;
    }
};


int main(int argc, char *argv[])
{
	if(argc != 5){
		cout << "Los parametros son: " << endl;
		cout << "1.- El fichero con el diccionario" << endl;
		cout << "2.- El fichero con las letras" << endl;
		cout << "3.- Numero de letras que se tiene que generar" << endl;
		cout << "4.- Modo de juego, L longitud y P puntuacion" << endl;
		return 0;
	}

	ifstream f_diccionario(argv[1]);
	ifstream f_letras(argv[2]);
	int numero = atoi(argv[3]);
	char modo = argv[4][0];

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

	Bolsa_letras bolsa;
	bolsa.leerConjunto(conjunto);

	if(tolower(modo) != 'p' && tolower(modo) != 'l'){
		cout << "Modo erroneo"<< endl;
		return 0;
	}

	if(tolower(modo) == 'p'){
		cout << "******Puntuacion letras******"<< endl;
		for (Conjunto_letras::iterator it= conjunto.begin(); it != conjunto.end(); it++){
	        Letra l = *it;

	        cout << l.caracter << '\t' << l.puntuacion << endl;
	    }
	}

	char fin;

	do{
		cout << "Las letras son: \n\t";
		srand(time(0));
		vector<Letra> letras;
		vector<Letra> todas_letras;

		for(int i=0; i<bolsa.size(); i++){
			Letra l = bolsa[i];
			todas_letras.push_back(l);
		}

		for(int i=0; i<numero; i++){
			int rnd = rand() % todas_letras.size();

			Letra l = todas_letras[rnd];
			todas_letras.erase(todas_letras.begin()+rnd);
			cout << l.caracter << '\t';
			letras.push_back(l);
		}

		string palabra;

		for(int i=0; i<letras.size(); i++){
			Letra l = letras[i];
			palabra.push_back(tolower(l.caracter));
		}

		bool trampa;
		string palabra_terminal;

		do{
			cout << "\nDime tu solucion: ";
			cin >> palabra_terminal;
			trampa = false;

			if(palabra_terminal.size() > numero){
				cout << "ERES UN TRAMPOSO, HAS METIDO MAS LETRAS DE LO PERMITIDO" << endl;
				trampa = true;
			}
			else{
				for(int i=0; !trampa && i<palabra_terminal.size(); i++){
					char letra = palabra_terminal[i];
					if(palabra.find(letra) == string::npos){
						cout << "ERES UN TRAMPOSO, HAS METIDO UNA LETRA NO PERMITIDA" << endl;
						trampa = true;
					}
				}
			}
		}while(trampa);

		if(!diccionario.count(palabra_terminal)){
			cout << "Esa palabra no existe en el diccionario" << endl;
		}
		else{
			cout << palabra_terminal << "\tPuntuacion: " << conjunto.puntuacion(palabra_terminal) << endl;
		}

		cout << "\nMis soluciones son: " << endl;
		vector<pair<string,int> > resultados;

		for(int i=numero; i>0; i--){
			vector<string> v = diccionario.palabrasLongitud(i);

			for(vector<string>::iterator it = v.begin(); it!=v.end(); ++it){
				string palabra_vector = *it;
				vector<bool> letras_usadas(letras.size(), false);
				int usadas = 0;

				for(int letra_act = 0; letra_act<palabra_vector.size(); letra_act++){
					bool salir = false;
					char letra_actual = palabra_vector[letra_act];

					for(int letra_orig=0; !salir && letra_orig<palabra.size(); letra_orig++){
						if (!letras_usadas[letra_orig] && palabra[letra_orig] == letra_actual){
							letras_usadas[letra_orig] = true;
							usadas++;
							salir = true;
						}
					}
				}
				if (usadas == palabra_vector.size()){
					resultados.push_back(pair<string,int>(palabra_vector,conjunto.puntuacion(palabra_vector)));
				}
			}
		}

		if(resultados.empty()){
			cout << "No se han encontrado palabras con esas letras" << endl;
		}
		else{
			if(tolower(modo) == 'l'){
				sort(resultados.begin(), resultados.end(), cmp_pal());
				int mayor_long = resultados[0].first.size();
				int pos_sig = 1;

				cout << resultados[0].first << "\tPuntuacion: " << resultados[0].second << endl;

				while(resultados[pos_sig].first.size() == mayor_long){
					cout << resultados[pos_sig].first << "\tPuntuacion: " << resultados[pos_sig].second << endl;
					pos_sig++;
				}
			}
			else if(tolower(modo) == 'p'){
				sort(resultados.begin(), resultados.end(), cmp_pts());
				int mayor_long = resultados[0].second;
				int pos_sig = 1;

				cout << resultados[0].first << "\tPuntuacion: " << resultados[0].second << endl;

				while(resultados[pos_sig].second == mayor_long){
					cout << resultados[pos_sig].first << "\tPuntuacion: " << resultados[pos_sig].second << endl;
					pos_sig++;
				}
			}
		}

		cout << "\n¿Quieres seguir jugando[S/N]?";
		cin >> fin;
		cout << endl;
	}while(tolower(fin)!='n');

	return 0;
}