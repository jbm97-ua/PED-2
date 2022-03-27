//Jose Burgos Miras
//tporo.h (declaracion de la clase)
#ifndef _TPORO_H_
#define _TPORO_H_
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

class TPoro{
	friend ostream& operator<<(ostream &, const TPoro &); //Sobrecarga del operador SALIDA

	private:
		int x; //Coordenada x de la posicion
		int y; //Coordenada y de la posicion
		double volumen; //Volumen
		char* color;

	public:
		TPoro(); //Constructor por defecto
		TPoro(int, int, double); //Constructor a partir de una posicion y un volumen
		TPoro(int, int, double, const char *); //Constructor desde de una posicion, un volumen y un color
		TPoro(const TPoro &); //Constructor de copia
		~TPoro(); //Destructor
		TPoro& operator=(const TPoro &); //Sobrecarga del operador asignacion
		bool operator==(const TPoro &); //Sobrecarga del operador igualdad
		bool operator!=(const TPoro &); //Sobrecarga del operador desigualdad
		//Modifica la posición
		void Posicion(int a, int b){ x=a; y=b; }
		// Modifica el volumen
		void Volumen(double vol){ volumen=vol; }
		void Color(const char *col); //Modifica el color
		//Devuelve la coordenada x de la posición
		int PosicionX() const{ return x; }
		//Devuelve la coordenada y de la posición
		int PosicionY() const{ return y; } 
		//Devuelve el volumen
		double Volumen() const{ return volumen; }
		//Devuelve el color
		char* Color() const{ return color; }
		bool EsVacio() const; //Devuelve cierto si el poro está vacío
};

#endif