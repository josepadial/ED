#include <iostream>
#include "diccionario.h"
#include <fstream>



/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre 
listas de listas y otro sobre listas
*/
ostream & operator<<(ostream & os,const Diccionario<string,string> & D){
	  list<data<string,string> >::const_iterator it;

		it=D.begin();

		int contador_valido=0;

		while(contador_valido!=D.size()){

				list<string>::const_iterator it_s;

				if((*it).clave.size() > 0){
					os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
					for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();it_s++){
				      os<<(*it_s)<<endl;
			    }
					os<<"**************************************"<<endl;
					contador_valido++;
				}
				it++;

		}
		os<<"FIN"<<endl;
	  
	  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave); 
		    
		    int ns;
		    is>>ns; 
		    is.ignore();//quitamos \n
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);
			      
			      // cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);		      
		    
	  }
	  D=Daux;
	  return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string>&l){		 
	  list<string>::const_iterator it_s;
	  
	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}	


/*Lee un diccioario e imprime datos asociados a una clave. 
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe: 
                  ./usodiccionario < data.txt 
*/
int main(int argc, char * argv[]){

 Diccionario<string,string> D;
 Diccionario<string,string> R;

 ifstream f(argv[1]);
   if (!f){
   		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
   		return 0;
   }

 	f >> D;
 	cout<< "\n\t\t\t\t\tDICCIONARIO" << D;
	R=D;

	string palabra="Sentencia";
	string sentencia;
  	D.borraElUltimoSignificado(palabra);

	cout<<"Introduce una palabra"<<endl;
	getline (cin, sentencia);

 	list<string>l = D.getInfo_Asoc(sentencia);

 	if (l.size()>0) {
 	  	EscribeSigni(l);
 	} else {
		cout << "Palabra no encontrada" << endl;
 	}

	R.borrarUltimaPalabra();


	cout << R << endl;

	char c;
	cin>>c;
	/*Suponemos que todas las claves del diccionario han sido introducidas con mayusculas*/
	c = toupper(c);
	list<string> o;
	cout << "- Palabras con " << c << ":"<< endl;
	o = D.PalabrasPorLetra(c);

	if (o.size()>0)
		EscribeSigni(o);
	else
		cout << "No hay palabras que empiecen por esa letra. " << endl;

  //----------------------------------------------------------------------------

	string s;
	cin>>s;
	list<string> z;
	cout << "- Palabras con la subcadena \"" << s << "\" :"<< endl;
	z = D.PalabrasPorSubcadena(s);

	if (z.size()>0){
		list<string>::const_iterator it_z;
		int j = 1;
		for (it_z=z.begin();it_z!=z.end();++it_z){
				cout<<"\t"<<j<<") "<<*it_z<<endl;
				j++;
		}
	}else{
		cout << "No hay palabras que contengan por esa subcadena. " << endl;
	}

	//----------------------------------------------------------------------------

	string definicion;
	cin.ignore();
	getline(cin,definicion);
	//string palabra;
	cout << "- Palabra con la definicion \"" << definicion << "\" : ";
	palabra = D.PalabraPorDefinicion(definicion);

	if (palabra != "NULL"){
			cout<<palabra<<endl;
	}else
		cout << "No hay palabras que contengan esa definicion explicita. " << endl;

	cout << endl;

	return 0;
}

