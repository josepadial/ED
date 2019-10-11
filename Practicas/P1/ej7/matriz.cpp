#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

void reservaMemoriaMatriz(int **&M, const int tam){
    M = new int*[tam];
    for(int i = 0; i < tam; i++)
        M[i] = new int[tam] ;
}

// Relleno de matriz con valores aleatorios
void rellenaMatriz(int **&M, const int tam, const int vmax){
    for(int i = 0; i < tam; i++)
        for(int j=0; j < tam; j++)
            M[i][j] = rand() % vmax ;
}

void imprimeMatriz(int **M, const int tam){
    for(int i=0; i < tam; i++){
        for(int j=0; j < tam; j++){
            cout <<  M[i][j] << " ";
        }
        cout << endl;
    }
}

void sintaxis()
{
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño de la matriz (>0)" << endl;
    cerr << "  VMAX: Valor máximo (>0)" << endl;
    cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    // Lectura de parámetros
    if (argc!=3)
        sintaxis();
    int tam=atoi(argv[1]);     // Tamaño del vector
    int vmax=atoi(argv[2]);    // Valor máximo
    if (tam<=0 || vmax<=0)
        sintaxis();

    // Generación de las matrices con valores aleatorios
    int **A ;
    int **B ;
    int **R ;

    reservaMemoriaMatriz(A, tam) ;
    rellenaMatriz(A, tam, vmax) ;
    reservaMemoriaMatriz(B, tam) ;
    rellenaMatriz(B, tam, vmax) ;
    reservaMemoriaMatriz(R, tam) ;

    srand(time(0));            // Inicialización del generador de números pseudoaleatorios

    clock_t tini;    // Anotamos el tiempo de inicio
    tini=clock();

    // Multiplicación de A*B guardada en R
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++){
            R[i][j] = 0;
            for(int k =0 ; k < tam; k++)
                R[i][j]= R[i][j]+A[i][k]*B[k][j];
        }

    clock_t tfin;    // Anotamos el tiempo de finalización
    tfin=clock();

    //imprimeMatriz(R, tam) ;

    // Mostramos resultados
    cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

    // Liberamos memoria dinámica
    for(int i=0; i < tam; i++){
        delete []A[i] ;
        delete []B[i] ;
        delete []R[i] ;
    }

    delete [] A;
    delete [] B;
    delete [] R;
}
