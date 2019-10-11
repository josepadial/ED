#include <iostream>
#include <conjunto_reales.h>
using namespace std;


void ListarConjunto(const Conjunto_Reales& c)
{
  cout << "Conjunto de " << c.size() << " elementos:" << endl;
  for (int i=0;i<c.size();++i)
    cout << "  Elemento: " << c.Elemento(i) << endl;
}

void Dif1(Conjunto_Reales c, Conjunto_Reales d, Conjunto_Reales& aux){
	for(int i=0; i<c.size(); i++){
		if(!d.Pertenece(c.Elemento(i))){
			aux.Insertar(c.Elemento(i));
		}
	}
}

void Dif2(Conjunto_Reales c, Conjunto_Reales d, Conjunto_Reales& aux2){
	Dif1(c,d,aux2);
	Dif1(d,c,aux2);
}

void Dif3(Conjunto_Reales c, Conjunto_Reales d, Conjunto_Reales f, Conjunto_Reales& aux3){
	for(int i=0; i<c.size(); i++){
		if(!d.Pertenece(c.Elemento(i)) && !f.Pertenece(c.Elemento(i))){
			aux3.Insertar(c.Elemento(i));
		}
	}
	for(int i=0; i<d.size(); i++){
		if(!c.Pertenece(d.Elemento(i)) && !f.Pertenece(d.Elemento(i))){
			aux3.Insertar(d.Elemento(i));
		}
	}
	for(int i=0; i<f.size(); i++){
		if(!c.Pertenece(f.Elemento(i)) && !d.Pertenece(f.Elemento(i))){
			aux3.Insertar(f.Elemento(i));
		}
	}
}

void Dif4(Conjunto_Reales c, Conjunto_Reales d, Conjunto_Reales f, Conjunto_Reales& aux4){
	for(int i=0; i<c.size(); i++){
		if(d.Pertenece(c.Elemento(i)) && !f.Pertenece(c.Elemento(i))){
			aux4.Insertar(c.Elemento(i));
		}
	}
	for(int i=0; i<d.size(); i++){
		if(c.Pertenece(d.Elemento(i)) && !f.Pertenece(d.Elemento(i))){
			aux4.Insertar(d.Elemento(i));
		}
	}
	for(int i=0; i<f.size(); i++){
		if(c.Pertenece(f.Elemento(i)) && !d.Pertenece(f.Elemento(i))){
			aux4.Insertar(f.Elemento(i));
		}
	}
	for(int i=0; i<f.size(); i++){
		if(d.Pertenece(f.Elemento(i)) && !c.Pertenece(f.Elemento(i))){
			aux4.Insertar(f.Elemento(i));
		}
	}
}

int main()
{
  Conjunto_Reales c, d, inter, aux, aux2, aux3, aux4, f;
  
  for (int i=0;i<10;++i) c.Insertar(i);
  for (int i=0;i<10;i+=2) c.Borrar(i);   

  ListarConjunto(c);

  for (int i=0;i<10;++i) d.Insertar(i);
  for (int i=0;i<10;i+=3) d.Borrar(i);   

  ListarConjunto(d);

	for (int i=0;i<10;++i) f.Insertar(i);
  for (int i=0;i<10;i+=4) f.Borrar(i);   

  ListarConjunto(f);

  for (int i=0;i<c.size();++i)
      if (d.Pertenece(c.Elemento(i)))
          inter.Insertar(c.Elemento(i));
  
  ListarConjunto(inter);

/*            DIF 1           Si c y no d                  */	
	Dif1(c,d,aux);
	ListarConjunto(aux);

/*            DIF 2   Si en c y en d pero no comun         */	
	Dif2(c,d,aux2);
	ListarConjunto(aux2);

/*            DIF 3   Si en c,d,f pero no en comun         */	
	Dif3(c,d,f,aux3);
	ListarConjunto(aux3);

/*            DIF 4   Lo comun de c y d, c y f, f y d      */	
	Dif4(c,d,f,aux4);
	ListarConjunto(aux4);

}
