#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "pila_max_vd.h"

using namespace std;

int main() {
	srand(time(NULL));
	Pila_max_vd<int> p1;
	Pila_max_vd<int> p2;
	Pila_max_vd<double> p3;
	Pila_max_vd<char> p4;

	cout << "Aniadimos a la pila uno 13 elementos del 0 al 50 int" << endl;
	for (int i=0; i<12; ++i){
		p1.push(rand()%50);
	}

	cout << "Aniadimos a la pila dos 10 elementos del 0 al 100 int" << endl;
	for (int i=0; i<10; ++i){
		p2.push(rand()%100);
	}

	cout << "Aniadimos a la pila tres 10 elementos 0 al 10 double" << endl;
	for (int i=0; i<10; ++i){
		p3.push((double)(rand()%1000)/100);
	}

	cout << "Aniadimos a la pila cuatro 10 elementos char de A a Z" << endl;
	for (int i=0; i<10; ++i){
		p4.push(65+rand()%(91-65));
	}

	cout << "\nHacemos un pop a la pila dos" << endl;
	p2.pop();

	cout << "\nComprobamos si la pila dos maximo es menor que pila uno maximo" << endl;
	if(p1 > p2)
		cout << "Pila uno es mayor comprobado >" << endl;
	else
		cout << "Pila uno es menor comprobado >" << endl;
	cout << "\nComprobamos si la pila dos maximo es mayor que pila uno maximo" << endl;
	if(p1 < p2)
		cout << "Pila dos es mayor comprobado <" << endl;
	else
		cout << "Pila dos es menor comprobado <" << endl;

	cout << "\nEl maximo valor de pila uno es : " << p1.max() << endl;
	cout << "El maximo valor de pila dos es : " << p2.max() << endl;
	cout << "El maximo valor de pila tres es : " << p3.max() << endl;
	cout << "El maximo valor de pila cuatro es : " << p4.max() << endl;

	cout << "\nLimpiamos la pila 3" << endl;
	p3.clear();
	if(p3.empty())
		cout << "La pila 3 esta limpia" << endl;
	else
		cout << "La pila 3 no se ha podido limpiar" << endl;
	
	cout << "\nAsignamos los valores de la pila dos a la pila uno" << endl;
	p1 = p2;
	if(p1 == p2)
		cout << "Funciona bien la sobrecarga de ==" << endl;
	else
		cout << "Algo pasa que no funciona bien ==" << endl;
	if(p1 != p2)
		cout << "Algo pasa que no funciona bien !=" << endl;
	else
		cout << "Funciona bien la sobrecarga de !=" << endl;

	return 0;
}