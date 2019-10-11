#include "guiatlf.h"
#include <fstream>

int main(int argc , char * argv[]){
  ifstream f1(argv[1]);
  ifstream f2(argv[2]);
  if (!f1){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }
  if (!f2){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
  }

 Guia_Tlf g;
  Guia_Tlf g2;

  f1>>g;
  f2>>g2;
  
  if(g != g2)
  cout << "Son distintas" << endl << endl;
  
  cout << g << endl << endl;
  cout << g2 << endl << endl;
  
  Guia_Tlf g3=g2-g;
  cout << g3 << endl << endl;
  
  Guia_Tlf g4=g+g3;
  cout << g4 << endl << endl;
  
 cout<<"La guia insertada "<<g<<endl;
 cin.clear();
 cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;
 while (getline(cin,n)){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.gettelefono(n);
	   if (tlf==""){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else
	    cout<<"El telefono es "<<tlf<<endl;
	   cout<<"[Pulse CTRL+D para finalizar] Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }
 cin.clear();
 cout<<"Dime el nombre que quieres borrar"<<endl;

 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Dime el nombre que quieres borrar"<<endl;
 }

 cout<<"Dime el nombre que quieres borrar"<<endl;

 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar"<<endl;
 }

 cin.clear();
 Guia_Tlf otraguia;
 cout<<"Introduce otra guia ([Pulse CTRL+D para finalizar])"<<endl;
 cin>>otraguia; cin.clear();

 Guia_Tlf un = g+otraguia;
 Guia_Tlf dif = g-otraguia;
 cout<<endl<<"La union de las dos guias: "<<un<<endl;

 cout<<endl<<"La diferencia de las dos guias:"<<dif<<endl;

 cout<<endl<<"Dime un nombre para establecer los previos"<<endl;
 cin>>n;
 string tlf= g.gettelefono(n);
 Guia_Tlf p = g.previos(n,tlf);
 cout<<endl<<"Los nombre previos: "<<p<<endl;


 cout<<"Listando la guia con iteradores:"<<endl;
 Guia_Tlf::iterator it;
 for (it=g.begin(); it!=g.end(); ++it)
     cout<<*it<<endl;
   

}