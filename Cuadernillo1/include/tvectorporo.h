//Jose Burgos Miras   48758447B
//tvectorporo.h
#ifndef _TVECTORPORO_H_
#define _TVECTORPORO_H_
#include "tporo.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

class TVectorPoro{
	friend ostream& operator<<(ostream &, const TVectorPoro &); //Sobrecarga del operador SALIDA

	private:
		int dimension; //Dimension del vector
		TPoro *datos;  //Datos del vector
		TPoro error;  //Para cuando haya error en el operator[]

	public:
		TVectorPoro(); //Constructor por defecto
		TVectorPoro(int); //Constructor a partir de una dimension
		TVectorPoro(const TVectorPoro &); //Constructor de copia
		~TVectorPoro(); //Destructor
		TVectorPoro& operator=(const TVectorPoro &); //Sobrecarga del operador asignacion
		bool operator==(const TVectorPoro &); //Sobrecarga del operador igualdad
		bool operator!=(const TVectorPoro &); //Sobrecarga del operador desigualdad
		TPoro& operator[](int); //Sobrecarga del operador corchete (parte IZQUIERDA)
		TPoro operator[](int) const; //Sobrecarga del operador corchete (parte DERECHA)
		int Longitud() const{ return dimension; } //Devuelve la longitud del vector (dimension)
		int Cantidad() const; //Devuelve la cantidad de posiciones ocupadas (no vacias) en el vector
		bool Redimensionar(const int); //Rendimensiona el vector
};

#endif

//const en 4º destructor -> (TPoro(const TPoro &);)