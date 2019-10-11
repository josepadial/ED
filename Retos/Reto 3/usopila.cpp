/**
 * @file usopila.cpp
 * @brief Fichero ejemplo de uso de la implementación del TDA Pila
 * @author Jose Antonio Padial Molina
 */

#include <iostream>
#include "pila.h"

using namespace std;

int main(){
	cout << "\n###################################################" << endl;
    cout << "# TDA Pila basado en List de STL usando templates #" << endl;
    cout << "###################################################" << endl;

    Pila<int> p;

    cout << "\nTRABAJANDO CON UNA Pila DE ENTEROS: ";

    for(int i=0; i<10; i++){
    	p.poner(i);
    	cout << "[" << i << "]";
    }

    cout << "\n----------------------------------" << endl;
    cout << "\t- Número de elementos en la Pila de enteros: " << p.num_elementos() << endl;
    cout << "\t- El elemento al top de nuestra Pila de enteros es: " << p.top() << endl;
    cout << "\t- Creando una copia de la Pila de enteros..." << endl;

    Pila<int> p2;
    p2=p;

    p.top() = 22;
    cout << "\t- Elemento al top de la Pila de enteros cambiado, ahora es: " << p.top() << endl;
    cout << "\t- Elemento al top de la copia de la Pila de enteros: " << p2.top() << endl;

    p.quitar();
    cout << "\t- Quitado primer elemento de la Pila de enteros, el nuevo top de la Pila de enteros es: " << p.top() << endl;

    p.limpiar(),
    cout << "\t- Vaciando Pila de enteros..." << endl;

    cout << "\t- Número de elementos en la Pila de enteros: " << p.num_elementos() << endl;

    Pila<float> p3;
    float elemento;

    cout << "\nTRABAJANDO CON UNA Pila DE FLOTANTES: ";

    for (int i=0; i<10; i++) {
        elemento = i / 10.0;
        p3.poner(elemento);
        cout << "[" << elemento << "]";
    }

    cout << "\n----------------------------------" << endl;
    cout << "\t- Número de elementos en la Pila de flotantes: " << p3.num_elementos() << endl;
    cout << "\t- El elemento al top de nuestra Pila de flotantes es: " << p3.top() << endl;
    cout << "\t- Creando una copia de la Pila de flotantes..." << endl;

    Pila<float> p4;
    p4=p3;

    p3.top() = 2.2;
    cout << "\t- Elemento al top de la Pila de flotantes cambiado, ahora es: " << p3.top() << endl;
    cout << "\t- Elemento al top de la copia de la Pila de flotantes: " << p4.top() << endl;

    p3.quitar();
    cout << "\t- Quitado primer elemento de la Pila de flotantes, el nuevo top de la Pila de flotantes es: " << p3.top() << endl;

    p3.limpiar(),
    cout << "\t- Vaciando Pila de flotantes..." << endl;

    cout << "\t- Número de elementos en la Pila de flotantes: " << p3.num_elementos() << endl;

    Pila<char> p5;
    char caracter='a';

    cout << "\nTRABAJANDO CON UNA Pila DE CARACTERES: ";

    for (int i=0; i<10; i++) {
        caracter += 1;
        p5.poner(caracter);
        cout << "[" << caracter << "]";
    }

    cout << "\n----------------------------------" << endl;
    cout << "\t- Número de elementos en la Pila de caracteres: " << p5.num_elementos() << endl;
    cout << "\t- El elemento al top de nuestra Pila de caracteres es: " << p5.top() << endl;
    cout << "\t- Creando una copia de la Pila de caracteres..." << endl;

    Pila<char> p6;
    p6=p5;

    p5.top() = 'p';
    cout << "\t- Elemento al top de la Pila de caracteres cambiado, ahora es: " << p5.top() << endl;
    cout << "\t- Elemento al top de la copia de la Pila de caracteres: " << p6.top() << endl;

    p5.quitar();
    cout << "\t- Quitado primer elemento de la Pila de caracteres, el nuevo top de la Pila de flotantes es: " << p5.top() << endl;

    p5.limpiar(),
    cout << "\t- Vaciando Pila de caracteres..." << endl;

    cout << "\t- Número de elementos en la Pila de caracteres: " << p5.num_elementos() << endl;

    return 0;
}