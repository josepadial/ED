#include "cronologia.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>

using namespace std;

int main(int argc, char * argv[]){

  if (argc==1){
      cout<<"Dime el nombre del ficheros con la cronologia"<<endl;
      cout<<"./bin/pruebacronologia ./datos/*.txt ./datos/*.txt"<<endl;
      return 0;
  }
  if (argc==2 || argc >= 4){
      cout<<"Pon bien los parametros"<<endl;
      cout<<"./bin/pruebacronologia ./datos/*.txt ./datos/*.txt"<<endl;
      return 0;
  }

  ifstream infile;
  Cronologia cronologia1;
  Cronologia cronologia1aux;
  Cronologia cronologia2;
  Cronologia cronologia3;

  infile.open(argv[1]);
  if (infile.is_open()) {
    infile >> cronologia1;
    cout << "\nAsignado la cronologia1 a " << argv[1] << endl;
    infile.close();
  }

  infile.open(argv[2]);
  if (infile.is_open()) {
    infile >> cronologia2;
    cout << "Asignado la cronologia2 a " << argv[2] << endl;
    infile.close();
  }

  Cronologia cronologia4(cronologia1.getFechashistoricas());
  cronologia1aux = cronologia1;

  cout << "\nAsignado las fechas de cronologia1 a cronologia4" << endl;
  cout << "Vamos a probar la sobre carga del operador ==" << endl;

  if(cronologia1aux == cronologia4){
    cout << "\t\tCronologia1 es igual a cronologia4" << endl;
  }
  else{
    cout << "\t\tAlgo a fallado en la sobre carga de ==" << endl;
  }

  cronologia1aux += cronologia2;
  cronologia4 = cronologia4 + cronologia2;

  cout << "\nSumamos la cronologia2 a la cronologia1" << endl;
  cout << "Vamos a probar la sobre carga del operador +=" << endl;
  cout << "Sumamos la cronologia1 a la cronologia4" << endl;
  cout << "Vamos a probar la sobre carga del operador + y =" << endl;
  cout << "Como sabemos que == funciona y cronologia1 y cronologia4 deben ser iguales lo comprobamos" << endl;

  if(cronologia1aux == cronologia4){
    cout << "\t\tCronologia1 es igual a cronologia4" << endl;
  }
  else{
    cout << "\t\tAlgo a fallado en la sobre carga de += o +" << endl;
  }

  int anio;
  int opcion;
  FechaHistorica fec;
  vector<string> eventos;
  cout << "\n\nIntroduzca el anio a consultar: ";
  cin >> anio;
  cout << "1 para la cronologia1 y 2 para la cronologia2: ";
  cin >> opcion;

  if(opcion == 1){
    fec = cronologia1.getFechaHistorica(anio);
    eventos = fec.getEventos();
    cout << "\n\t\tLos eventos para el anio " << anio << " de la cronologia1 son: " << endl;
  }
  else if(opcion == 2){
    fec = cronologia2.getFechaHistorica(anio);
    eventos = fec.getEventos();
    cout << "\n\t\tLos eventos para el anio " << anio << " de la cronologia2 son: " << endl;
  }
  else{
    cout << "Opcion mal elegida" << endl;
    return 0;
  }

  for(int i=0; i<eventos.size(); i++){
    cout << "Evento numero " << (i+1) << " : " << eventos[i] << endl;
  }

  cout << "\nVamos a insertar un acontecimiento en cronologia1" << endl;
  cout << "Introduzca el anio al que le vamos a insertar el evento: ";
  cin >> anio;
  FechaHistorica fec2(anio);

  fec2.insertarAcontecimiento("Primer acontecimiento aniadido");
  cronologia1.addFechaHistorica(fec2);
  cronologia1.addAcontToFechaHistorica(anio, "Segundo acontecimiento aniadido");
  cronologia1.addAcontToFechaHistorica(anio, "Tercer acontecimiento aniadido");

  cout << "\nVamos a comprobar que el año " << anio << " es una fecha historica de cronologia1" << endl;
  if(cronologia1.isFechaHistorica(anio)){
    cout << "\t\tSi lo es" << endl;
  }
  else{
    cout << "\t\tNo lo es" << endl;
  }

  cronologia1.deleteFechaHistorica(anio);

  cout << "\nBorramos el año " << anio << " de la cronologia1 y hacemos la comprobacion anterior" << endl;
  if(cronologia1.isFechaHistorica(anio)){
    cout << "\t\tSi lo es" << endl;
  }
  else{
    cout << "\t\tNo lo es" << endl;
  }

  cout << "\nCreamos dos nuevas FechaHistorica en el año 1902 con diferentes string" << endl;
  cout << "Vamos a comprobar si son iguales" << endl;
  FechaHistorica fec3(1902);
  fec3.insertarAcontecimiento("aaa");
  FechaHistorica fec4(1902);
  fec4.insertarAcontecimiento("bbb");
  if(fec3 == fec4){
    cout << "\t\tSon iguales" << endl;
  }
  else{
    cout << "\t\tNo son iguales" << endl;
  }

  cout << "\nCreamos una nueva FechaHistorica en el año 1902, le insertamos un elemento y a continuacion se lo borramos" << endl;
  cout << "Sumamos los dos ultimas fechas de 1902 y se la asignamos a la primera de 2018, luego se imprime" << endl;
  FechaHistorica fec5(1902);
  fec5.insertarAcontecimiento("ccc");
  fec5.deleteAcontecimiento("ccc");

  fec3 = fec4 + fec5;
  fec3.print();

  return 0;
  
  

   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés


}
