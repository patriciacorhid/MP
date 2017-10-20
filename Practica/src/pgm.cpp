/**
  * @file 
  * @brief Fichero con las definiciones para la E/S de imágenes PGM 
  *
  * Permite la E/S de archivos de tipos PGM
  *
  */

#include <fstream>
#include <string>
#include "pgm.h"
using namespace std;


TipoImagen LeerTipo(ifstream& f)
{
  char c1,c2;
  TipoImagen res= IMG_DESCONOCIDO;

  if (f) {
    f >> c1 >> c2;
    if (f && c1=='P')
      switch (c2) {
        case '5': res= IMG_PGM_BINARIO; break;
        case '2': res= IMG_PGM_TEXTO; break;
        default: res= IMG_DESCONOCIDO;
      }
  }
  return res;
}


// _____________________________________________________________________________

char SaltarSeparadores (ifstream& f)
{
  char c;
  do {
    c= f.get();
  } while (isspace(c));
  f.putback(c);
  return c;
}

// _____________________________________________________________________________

bool LeerCabecera (ifstream& f, int& filas, int& columnas)
{
    int maxvalor;

    while (SaltarSeparadores(f)=='#')
      f.ignore(10000,'\n');

    f >> columnas >> filas >> maxvalor;
    
    if (f && filas>0 && filas <5000 && columnas >0 && columnas<5000) {
        f.get(); // Saltamos separador
        return true;
    }
    else return false;
}

// _____________________________________________________________________________

TipoImagen infoPGM(const char nombre[], int& filas, int& columnas)
{
  ifstream f(nombre);
  TipoImagen tipo;
  filas=columnas=0;

  tipo=LeerTipo(f);
  if (tipo!=IMG_DESCONOCIDO)
    if (!LeerCabecera(f,filas,columnas)) {
      tipo=IMG_DESCONOCIDO;
    }

  return tipo;
}

// _____________________________________________________________________________

bool leerPGMBinario (const char nombre[], unsigned char datos[], int& filas, int& columnas)
{
  ifstream f(nombre);
  bool exito= false;
  filas=0;
  columnas=0;
  
	if (LeerTipo(f)==IMG_PGM_BINARIO)
	 if (LeerCabecera (f, filas, columnas))
		if (f.read(reinterpret_cast<char *>(datos),filas*columnas))
	  		exito= true;
  
 	return exito;
}

// ______________________________________________________________________________

bool leerPGMTexto (const char nombre[], unsigned char datos[], int& filas, int& columnas)
{
  ifstream f(nombre);
  bool exito= false;
  filas=0;
  columnas=0;
  int aux;
  	if(f){
		if (LeerTipo(f)==IMG_PGM_TEXTO)
		 if (LeerCabecera (f, filas, columnas))
			for(int i=0; i<filas*columnas; i++){
				f >> aux;
				datos[i]= (unsigned char) aux;
			}
	}
	exito=static_cast<bool>(f);
  
 	return exito;
}

// _____________________________________________________________________________

bool escribirPGMBinario (const char nombre[], const unsigned char datos[], int filas, int columnas)
{
  ofstream f(nombre);
  bool exito= false;
  
  if (f) {
    f << "P5" << endl;
    f << columnas << ' ' << filas << endl;
    f << 255 << endl;
    f.write(reinterpret_cast<const char *>(datos),filas*columnas);
    if (!static_cast<bool>(f)) 
    	exito=false;
    else
    	exito = true;
  }
  return exito;
}

// _____________________________________________________________________________

bool escribirPGMTexto (const char nombre[], const unsigned char datos[], int filas, int columnas)
{
  ofstream f(nombre);
  bool exito= false;
  int aux;
  
  if (f) {
    f << "P2" << endl;
    f << columnas << ' ' << filas << endl;
    f << 255 << endl;
   	
	for(int i=0; i<filas*columnas; i++){
		aux=datos[i];
		f << aux << " ";
	}

    if (!static_cast<bool>(f)) 
    	exito=false;
    else
    	exito = true;
    
    f.close();
  }

  return exito;
}

