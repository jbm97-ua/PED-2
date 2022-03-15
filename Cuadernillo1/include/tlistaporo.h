#ifndef _TLISTAPORO_H_
#define _TLISTAPORO_H_
#include "tporo.h"
#include "tvectorporo.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;


class TListaNodo{
	friend class TListaPosicion;
	friend class TListaPoro;
	private:
		TPoro e; //El elemento del nodo
		TListaNodo *anterior; //El nodo anterior
		TListaNodo *siguiente; //El nodo siguiente

	public:
		TListaNodo(); //Constructor por defecto
		TListaNodo(const TListaNodo &); //Constructor de copia
		~TListaNodo(); //Desctructor
		TListaNodo& operator=(const TListaNodo &); //Sobrecarga del operador asignacion
};



class TListaPosicion{
	friend class TListaNodo;
	friend class TListaPoro;
	private:
		TListaNodo *pos; //Para implementar la POSICION a NODO de la LISTA de TPoro

	public:
		TListaPosicion(); //Constructor por defecto
		TListaPosicion(const TListaPosicion &); //Constructor de copia
		~TListaPosicion(); //Destructor
		TListaPosicion& operator=(const TListaPosicion &); //Sobrecarga del operador asignacion

		bool operator==(const TListaPosicion &); //Sobrecarga del operador igualdad
		TListaPosicion Anterior(); //Devuelve la posicion anterior
		TListaPosicion Siguiente(); //Devuelve la posicion siguiente
		bool EsVacia(); //Devuelve TRUE si la posicion no apunta a una lista, FALSE en caso contrario
};



class TListaPoro{
	friend class TListaNodo;
	friend class TListaPosicion;
	friend ostream& operator<<(ostream &, TListaPoro &); //Sobrecarga del operador SALIDA
	//OSTREAM
	private:
		TListaNodo *primero; //Primer elemento de la lista
		TListaNodo *ultimo; //Ultimo elemento de la lista
		void InsertarEnCabeza(const TPoro &);
		void InsertarEnMedio(const TPoro &);
		void InsertarEnCola(const TPoro &);

	public:
		TListaPoro(); //Constructor por defecto
		TListaPoro(const TListaPoro &); //Constructor de copia
		~TListaPoro(); //Destructor
		TListaPoro& operator=(const TListaPoro &); //Sobrecarga del operador asignación
		
		bool operator==(const TListaPoro &); //Sobrecarga del operador igualdad
		TListaPoro operator+(const TListaPoro &); //Sobrecarga del operador suma
		TListaPoro operator-(const TListaPoro &); //Sobrecarga del operador resta
		bool EsVacia(); //Devuelve true si la lista esta vacia, false en caso contrario
		bool Insertar(const TPoro &); //Inserta el elemento en la lista
		bool Borrar(const TPoro &); //Busca y borra el elemento
		bool Borrar(const TListaPosicion &); //Borra el elemento que ocupa la posición indicada
		TPoro Obtener(const TListaPosicion &); //Obtiene el elemento que ocupa la posición indicada
		bool Buscar(const TPoro &); //Devuelve true si el elemento está en la lista, false en caso contrario
		int Longitud(); //Devuelve la longitud de la lista
		TListaPosicion Primera(); //Devuelve la primera posición en la lista
		TListaPosicion Ultima(); //Devuelve la última posición en la lista
		TListaPoro ExtraerRango(int n1, int n2); //Extraer un rango de nodos de la lista
};

#endif