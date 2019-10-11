#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

set<int> disjuntos3(const set<int>& c1, const set<int>& c2, const set<int>& c3){
  set<int>::iterator p,q,r;
  set<int> solucion;
  //Recorro el primer conjunto
  for(p=c1.begin();p!=c1.end();++p){
    if(!c2.count(*p) && !c3.count(*p)){ //Si no esta ni en el segundo ni tercer conjunto lo aniado
      solucion.insert(*p);//inserto en solucion
    }
  }
  //Recorro el segundo conjunto
  for(q=c2.begin();q!=c2.end();++q){
    if(!c1.count(*q) && !c3.count(*q)){//Si no esta ni en el primer ni tercer conjunto lo aniado
      solucion.insert(*q);//inserto en solucion
    }
  }
  //Recorro el tercer conjunto
  for(r=c3.begin();r!=c3.end();++r){
    if(!c1.count(*r) && !c2.count(*r)){//Si no esta ni en el segundo ni primer conjunto lo aniado
      solucion.insert(*r);//inserto en solucion
    }
  }
  return solucion;
}

set<int> interseccion3Separado(const set<int>& s1, const set<int>& s2, const set<int>& s3) {
  set<int> solucion3;
  set<int>::iterator p,q,r;
  //Recorro el primer conjunto
  for (p = s1.begin(); p != s1.end(); p++) {
    if (s2.count(*p)  && !s3.count(*p) ) {//Si esta en el segundo pero no en el tercer conjunto lo aniado
      solucion3.insert(*p);
    }
  }
  //Recorro el segundo conjunto
  for (q = s2.begin(); q != s2.end(); q++) {
    if (s3.count(*q)  && !s1.count(*q) ) {//Si esta en el tercer pero no en el primero conjunto lo aniado
      solucion3.insert(*q);
    }
  }
  //Recorro el tercer conjunto
  for (r = s3.begin(); r != s3.end(); r++) {
    if (s1.count(*r)  && !s2.count(*r) ) {//Si esta en el primer pero no en el segundo conjunto lo aniado
      solucion3.insert(*r);
    }
  }
  return solucion3;
}


int main(){
  
  set<int> c1,c2,c3;
  
  InicializarSemilla();
  
  /**/
  for (int i=0;i<10;i++)
    c1.insert(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  for (int j=0;j<10;j++)
    c2.insert(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  for (int z=0;z<10;z++)
    c3.insert(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  /**/
  /** /
  c1.insert(1);
  c1.insert(2);
  c1.insert(4);
  c1.insert(5);
  c1.insert(8);

  c2.insert(4);
  c2.insert(5);
  c2.insert(6);
  c2.insert(9);

  c3.insert(3);
  c3.insert(4);
  c3.insert(7);
  c3.insert(8);
  c3.insert(9);
  /**/

  cout<<endl<<c1<<endl;
  cout<<endl<<c2<<endl;
  cout<<endl<<c3<<endl;

  set<int> disjunto;
  disjunto = disjuntos3(c1,c2,c3);
  cout << "La unión disjunta de los conjuntos anteriore es " << disjunto << endl;

  set<int> interdisjunto;
  interdisjunto = interseccion3Separado(c1,c2,c3);
  cout << "La interseccion disjunta de los conjuntos anteriore es " << interdisjunto << endl;
  
}  