#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Nodo{
    private: 
        string dato;
        int rep;
        Nodo *next;
        Nodo *hi;
        Nodo *hd;
        Nodo *ordena;
    public:
        Nodo() {next=NULL;};
        Nodo(string a) {dato=a; next=NULL;};
        void set_dato(string a) {dato=a; };
        void set_next(Nodo *n) {next=n; };
        void set_hi(Nodo *n) {hi=n; };
        void set_hd(Nodo *n) {hd=n; };
        string get_dato() {return dato; };
        void set_rep(int r) {rep = r;};
        int get_rep(){return rep;};
        Nodo *get_next() {return next; };
        Nodo *get_hi() {return hi; };
        Nodo *get_hd() {return hd; };
        bool es_vacio() {return next==NULL;}
};

class Lista{
    private: Nodo *czo;
    public:
            Lista() {czo=new Nodo();};
            Lista(Nodo *n) {czo=n;};
            //~Lista(void);
            void add(string d);
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
};
int Lista::size()
{ 
     if (this->esvacia()) return 0;
     return 1+this->resto()->size();
}
void Lista::impre(void)
{ Nodo *aux;
  aux=czo;
    while(aux->get_next()!=NULL){
         cout<<aux->get_dato()<<endl;
         aux=aux->get_next();
    }
}
void Lista::add(string d)
{  
     Nodo *nuevo=new Nodo(d);
     nuevo->set_next(czo);
     czo=nuevo;
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
       stm << this->cabeza()<<" - "<< this->resto()->toPrint(p) << endl;
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

/*Lista *Lista::copy(void)
{ 
      Lista *aux=new Lista();
      aux->concat(this);
      return aux;
}*/
void Lista::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
/*   if(!(this->esvacia())) {
      if (n>0) this->resto()->tomar(n-1);
      else     czo->set_next(NULL);
   }
*/
   if(this->size()>n){
      this->borrar_last();
      this->tomar(n);
   }
}
Nodo* getNodo(Lista *l, string p){
	if(l->cabeza()->get_dato() == p)
		return l->cabeza();
	else getNodo(l->resto(),p);	
}	
/*
verifica si la palabra ya existe en la lista
bool existe(Lista *l, string p){
	if(l->cabeza()->get_dato() == p)
		return true;
	else getNodo(l->resto(),p);	
}
*/
	
int main() {	
	fstream archivo;
	string linea;
	Nodo *nodo = new Nodo();
	Lista* lista = new Lista(nodo);
	
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
			    // Do something on `word` here...
			    if(lista->esvacia()){
			    	lista->add(palabra);
				}else{
					//recorrer lista y verificar si contiene la palabra
				}
			    cout << palabra << endl;
			    
			}
	
	}
	archivo.close(); 
}
