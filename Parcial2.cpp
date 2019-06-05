#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;	
	
int main() {	
	fstream archivo;
	string linea;
	
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
			    cout << palabra << endl;
			}
	
	}
	archivo.close(); 
}
