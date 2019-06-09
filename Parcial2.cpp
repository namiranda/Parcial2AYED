#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Nodo{
    private: 
        string dato;
        int rep;
        Nodo *next;
        Nodo *izq;
        Nodo *der;
        Nodo *ordena;
    public:
        Nodo() {rep = 0; next=NULL;};
        Nodo(string a) {dato=a; next=NULL; rep=0;};
        void set_dato(string a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        void set_izq(Nodo *n) {izq=n; };
        void set_der(Nodo *n) {der=n; };
        string get_dato() {return dato; };
        void set_rep() {rep = rep+1;};
        int get_rep(){return rep;};
        Nodo *get_next() {return next; };
        Nodo *&get_izq() {return izq; };
        Nodo *&get_der() {return der; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    private: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            void add(Nodo* nuevo);
            bool esvacia(void);
            Nodo* cabeza(void);
            Lista *resto(void);
            string toPrint(string p);   
            int suma(int i);
            void impre(void);
            int suma2(void);
            int size();
            void borrar(void); //borra la cabeza
            void borrar_last();//borra el ultimo
            void concat(Lista *l1);
            Lista *copy(void);
            void tomar(int n);
            Nodo* last();
            void ordenaInsercion(Nodo* nuevo);
            
};
int Lista::size()
{ 
     if (this->esvacia()) return 0;
     return 1+this->resto()->size();
}
void Lista::impre(void)
{ Nodo *aux;
  aux=czo;
    while(aux->get_next()->get_next()!=NULL){
         cout<<aux->get_next()->get_dato()<< " -  repeticiones: "<< aux->get_next()->get_rep()<<endl;
         aux=aux->get_next();
    }
}
void Lista::add(Nodo* nuevo)
{  
     nuevo->set_next(czo);
     czo=nuevo;
}

Nodo* Lista::last(void){
		if(czo->get_next()==NULL) return czo;
		else resto()->last();
}

bool Lista::esvacia(void)
{   
    return czo->es_vacio();
}
Nodo *Lista::cabeza(void)
{ 
  return czo;
}

Lista *Lista::resto(void)
{ 
      Lista *l=new Lista(czo->get_next());
      return (l);
}

string Lista::toPrint(string p)
{ 
     if (this->esvacia()) {
        return p;
     } else {
       std::ostringstream stm;
       stm << this->cabeza()->get_dato()<<" - "<< this->resto()->toPrint(p) << endl;
      //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
       return stm.str();
     }
}


void Lista::borrar(void)
{ //borra el nodo cabeza
  if(esvacia()){
  } else {
         Nodo *tmp=czo;
         czo=czo->get_next();
         delete tmp;
  }
}
void Lista::borrar_last()
{ // borra el ultimo nodo
   if(!this->esvacia()){
      if((czo->get_next())->get_next()==NULL){
         delete czo->get_next();
         czo->set_next(NULL);
      }
      else this->resto()->borrar_last(); 
   }  
}	
void Lista::ordenaInsercion(Nodo* nuevo){
	string palabra = nuevo->get_dato();
	Nodo* aux = this->cabeza();
	
	if(aux == NULL || aux->get_dato() > palabra){ //Si es el ultimo nodo o esta vacia
		nuevo->set_next(aux);
		aux = nuevo;
	}else {
		while(aux->get_next()!=NULL && aux->get_next()->get_dato() < palabra){
			aux = aux->get_next();
		}
		nuevo->set_next(aux->get_next());
		aux->set_next(nuevo);
	}		
}

class arbol{
    Nodo* raiz, q;
    Nodo* ArbolBusq(string x, Nodo* &nuevo);
    void rid(Nodo* aux);
    void ird(Nodo* aux);
    void idr(Nodo* aux);
    void show(Nodo* aux, int n);
    void borrar(Nodo* &p, string x);
    void bor(Nodo* &d);
    void mh(Nodo* aux);
    string menor(Nodo* aux);
    bool esta(Nodo* aux, string x);
public:
    arbol(){raiz=NULL;};
    ~arbol(){};
    Nodo* CreaArbolBus(string x);
    void RID(){ rid(raiz); }
    void IRD(){ ird(raiz); }
    void IDR(){ idr(raiz); }
    void VerArbol(){ show(raiz,0); }
    void Borrar(string x){ borrar(raiz,x);}
    void MostrarHojas(){mh(raiz);}
    string Menor(){return menor(raiz);}
    bool Esta(string x){return esta(raiz,x);}
};


bool arbol::esta(Nodo* aux, string x)
{ if(aux==NULL) return false;
  else if(x>aux->get_dato()) return esta(aux->get_der(),x);
  else if(x<aux->get_dato()) return esta(aux->get_izq(),x);
  return true;

}

void arbol::mh(Nodo* aux)
{  if(aux!=NULL){
        mh(aux->get_izq());
        if(aux->get_izq()==NULL && aux->get_der()==NULL)cout<<"\n"<<aux->get_dato();
        mh(aux->get_der());
   }   
}

string arbol::menor(Nodo* aux)
{  if(aux->get_izq()==NULL)return aux->get_dato();
   return menor(aux->get_izq());
}


Nodo* arbol::CreaArbolBus(string x)
{ return ArbolBusq(x,raiz);
}
Nodo* arbol::ArbolBusq(string x, Nodo* &nuevo)
{
  if(nuevo==NULL){
      nuevo= new Nodo();
      nuevo->set_dato(x); nuevo->set_der(NULL); nuevo->set_izq(NULL);
      return nuevo;
  }
  if(x > nuevo->get_dato()) return ArbolBusq(x, nuevo->get_der());
  if(x < nuevo->get_dato()) return ArbolBusq(x, nuevo->get_izq());
}
void arbol::ird(Nodo* aux)
{  if(aux!=NULL){
        ird(aux->get_izq());
        cout<<"\n"<<aux->get_dato();
        ird(aux->get_der());
   }
}
void arbol::rid(Nodo* aux)
{  if(aux!=NULL){
        cout<<"\n"<<aux->get_dato();
        rid(aux->get_izq());
        rid(aux->get_der());
   }
}
void arbol::idr(Nodo* aux)
{  if(aux!=NULL){
        idr(aux->get_izq());
        idr(aux->get_der());
        cout<<"\n"<<aux->get_dato();
   }
}
void arbol::show(Nodo* aux, int n)
{ int i;
   if(aux!=NULL){                      //OjO este es un recorrido dri
       show(aux->get_der(), n+1);
       for(i=1; i<=n; i++) cout<<"     ";
       cout<<aux->get_dato()<<"\n";
       show(aux->get_izq(), n+1);
   }
}

void sumarRepeticion(Lista *l, string p){
	if(l->cabeza()->get_dato().compare(p) == 0){
		l->cabeza()->set_rep();
		return ;
	}else {
		sumarRepeticion(l->resto(),p);		
	}
}

	
int main() {	
	fstream archivo;
	string linea;
	Lista* lista = new Lista();
	arbol T;
	Nodo* czo = lista->cabeza(); 
	
	archivo.open("texto.txt", ios::in); //abre archivo en modo lectura
		
	if(archivo.fail()){
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){ // mientras no sea el final del archivo
		getline(archivo, linea);
		string palabra;
		istringstream iss(linea, istringstream::in);

			while( iss >> palabra )     
			{
				if(!T.Esta(palabra)){
					lista->ordenaInsercion(T.CreaArbolBus(palabra));
					//T.VerArbol();
					//cout<<lista->size();
					//cout <<"--------------------------------------------------------------" << endl;
				}
				else {
					sumarRepeticion(lista, palabra);
				}
			}
	}
	archivo.close(); 	
	lista->impre(); //no imprime la ultima palabra
	cout << lista->last()->get_dato() <<" - repeticiones " << lista->last()->get_rep() <<  endl;
	T.IRD();
}
