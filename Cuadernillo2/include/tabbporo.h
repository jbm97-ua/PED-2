//Jose Burgos Miras   48758447B
//tabbporo.h
#ifndef _TABBPORO_H_
#define _TABBPORO_H_
#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>
//#include <queue>
using namespace std;

#include "tporo.h"
#include "tvectorporo.h"



class TNodoABB{
    friend class TABBPoro;

    private:
        TPoro item; //Elemento	del nodo
        TABBPoro iz, de; //Subárbol izquierdo y derecho

    public:
        TNodoABB(); //Constructor por defecto
        TNodoABB(const TNodoABB &); //Constructor de copia
        ~TNodoABB(); //Destructor
        TNodoABB& operator=(const TNodoABB &); //Sobrecarga del operador asignación
};



class TABBPoro{
    friend class TNodoABB;
    friend ostream & operator<< (ostream &, TABBPoro &); //Sobrecarga del operador salida

    private:
        TNodoABB *nodo; //Puntero al nodo
        void Copia(const TABBPoro &); //Metodo que hace una copia 
        void InordenAux(TVectorPoro &, int &) const; //AUXILIAR: Devuelve el recorrido en inorden
        void PreordenAux(TVectorPoro &, int &) const; //AUXILIAR : Devuelve el recorrido en preorden	
        void PostordenAux(TVectorPoro &, int &) const; //AUXILIAR : Devuelve el recorrido en postorden
        
        TPoro Ordenar() const;

    public:
        TABBPoro(); //Constructor por defecto
        TABBPoro(const TABBPoro &); //Constructor de copia
        ~TABBPoro(); //Destructor
        TABBPoro& operator=(const TABBPoro &); //Sobrecarga del operador asignación
        bool operator==(const TABBPoro &) const; //Sobrecarga del operador igualdad
        bool EsVacio() const; //Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
        bool Insertar(const TPoro &); //Inserta el elemento en el árbol
        bool Borrar(const TPoro &); //Borra el elemento en el árbol
        bool Buscar(const TPoro &) const; //Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
        TPoro Raiz() const; //Devuelve el elemento en la raíz del árbol
        int Altura() const; //Devuelve la altura del árbol (la altura de un árbol vacío es 0)
        int Nodos() const; //Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
        int NodosHoja() const; //Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
        TVectorPoro Inorden() const; //Devuelve el recorrido en inorden
        TVectorPoro Preorden() const; //Devuelve el recorrido en preorden
        TVectorPoro Postorden() const; //Devuelve el recorrido en postorden
        TABBPoro Niveles() const; //Devuelve el recorrido en niveles

        TABBPoro operator+(TABBPoro &); //Suma de dos ABB
        TABBPoro operator-(TABBPoro &); //Resta de dos ABB
};

#endif