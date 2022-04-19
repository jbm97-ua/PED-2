//Jose Burgos Miras - 48758447B
//tabbporo.cpp

#include "tabbporo.h"

//Constructor por defecto
TNodoABB::TNodoABB():item(), iz(), de(){
	//Constructor que llama a los constructores de TPoro para item
	//y TABBPoro para iz y de
}
//Constructor de copia
TNodoABB::TNodoABB(const TNodoABB &orig):item(orig.item), iz(orig.iz), de(orig.de){
	//Constructor que llama a los constructores de TPoro para item
	//y TABBPoro para iz y de
}
//Destructor
TNodoABB::~TNodoABB(){
	//Destructor vacio porque hay una composicion (no hay ninguna variable mas)
	//Invoca a los diferentes destructores correspondientes
}
//Sobrecarga del operador asignación
TNodoABB& TNodoABB::operator=(const TNodoABB &nodo){
	if(this!=&nodo){
		this->~TNodoABB();

		this->item=nodo.item;
		this->de=nodo.de;
		this->iz=nodo.iz;
	}
	return *this;
}



//Constructor por defecto
TABBPoro::TABBPoro(){ this->nodo=NULL; }
//Metodo que hace una copia 
void TABBPoro::Copia(const TABBPoro &abb){
	if(abb.nodo!=NULL){
		TNodoABB *auxNodo = new TNodoABB;
		auxNodo->item=abb.nodo->item;
		this->nodo=auxNodo;
		(this->nodo->iz).Copia(abb.nodo->iz);
		(this->nodo->de).Copia(abb.nodo->de);
	}
	else{ this->nodo=NULL; }
}
//Constructor de copia
TABBPoro::TABBPoro(const TABBPoro &abb){
	this->nodo=NULL;
	Copia(abb);
}
//Destructor
TABBPoro::~TABBPoro(){
	TNodoABB *auxNodo = new TNodoABB(); // ? Quitar??

	if(!this->EsVacio()){
		do{
			auxNodo=this->nodo; // ? Quitar??
			this->nodo->de.~TABBPoro();
			this->nodo->iz.~TABBPoro();

			delete this->nodo;
			this->nodo=NULL;
		}while(!this->EsVacio());
	}

	// ? ¿ESTA BIEN PONER LO SIGUIENTE?
	/*if(this->nodo=NULL){
		delete this->nodo;
		this->nodo=NULL;
	}*/
	// ? //////////////////////////////
}
//Sobrecarga del operador asignación
TABBPoro& TABBPoro::operator=(const TABBPoro &abb){
	this->~TABBPoro();
	this->Copia(abb);

	return *this;
}
//Sobrecarga del operador igualdad
bool TABBPoro::operator==(const TABBPoro &) const{
	// !HACER...
	return false;
}
//Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TABBPoro::EsVacio() const{
	bool empty=false;

	if(this->nodo==NULL){
		empty=true;
	}

	return empty;
}
//Inserta el elemento en el árbol
bool TABBPoro::Insertar(const TPoro &){
	// !HACER...
	return false;
}
//Borra el elemento en el árbol
bool TABBPoro::Borrar(const TPoro &){
	// !HACER...
	return false;
}
//Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TABBPoro::Buscar(const TPoro &) const{ 
	// !HACER...
	return false;
}
//Devuelve el elemento en la raíz del árbol
TPoro TABBPoro::Raiz() const{
	TPoro poro;

	if(!this->EsVacio()){
		poro = this->nodo->item;
	}

	return poro;
}
//Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TABBPoro::Altura() const{
	int arbIz, arbDer, arbAux;

	if(!this->EsVacio()){
		arbDer=(this->nodo->de).Altura();
		arbIz=(this->nodo->iz).Altura();

		if(arbIz<arbDer){ arbAux=1+arbDer; }
		else{ arbAux=1+arbIz; }

		return arbAux;
	}
	else{ return 0; }
}
//Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TABBPoro::Nodos() const{
	// !HACER...
	return 0;
}
//Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TABBPoro::NodosHoja() const{
	// !HACER...
	return 0;
} 
//AUXILIAR: Devuelve el recorrido en inorden
void TABBPoro::InordenAux(TVectorPoro &inNodos, int &position) const{ //IRD
	//Si no es un nodo hoja
	if(this->EsVacio()!=false){
		//Se recorren las ramas izquierdas al maximo
		this->nodo->iz.InordenAux(inNodos, position); 
		//Cuando se hayan recorrido las ramas izquierdas al máximo se almacena el nodo 
		inNodos[position]=this->Raiz(); //Cuando
		position++;
		//Se recorren las ramas derechas (hsata que haya una izquierda o sea un nodo hoja)
		this->nodo->de.InordenAux(inNodos, position);
	}
}
//Devuelve el recorrido en inorden
TVectorPoro TABBPoro::Inorden() const{ 
	int position = 1; //Posición en el vector que almacena el recorrido
	TVectorPoro inNodos(this->Nodos()); //Vector del tamaño adecuado para almacenar todos los nodos
	
	InordenAux(inNodos, position);
	
	return inNodos;
}
void TABBPoro::PreordenAux(TVectorPoro &preNodos, int &position) const{ //RID
	//Si no es un nodo hoja
	if(this->EsVacio()!=false){
		//Se almacena el nodo 
		preNodos[position]=this->Raiz(); //Cuando
		position++;
		//Se accede a la rama izquierda
		this->nodo->iz.PreordenAux(preNodos, position); 
		//Se accede a la rama derecha
		this->nodo->de.PreordenAux(preNodos, position);
	}
}
//Devuelve el recorrido en preorden
TVectorPoro TABBPoro::Preorden() const{
	int position = 1; //Posición en el vector que almacena el recorrido
	TVectorPoro preNodos(this->Nodos()); //Vector del tamaño adecuado para almacenar todos los nodos
	
	PreordenAux(preNodos, position);
	
	return preNodos;
}
void TABBPoro::PostordenAux(TVectorPoro &postNodos, int &position) const{ //IDR
	//Si no es un nodo hoja
	if(this->EsVacio()!=false){
		//Se accede a la rama izquierda
		this->nodo->iz.PreordenAux(postNodos, position); 
		//Se accede a la rama derecha
		this->nodo->de.PreordenAux(postNodos, position);
		//Se almacena el nodo 
		postNodos[position]=this->Raiz(); //Cuando
		position++;
	}
}
//Devuelve el recorrido en postorden
TVectorPoro TABBPoro::Postorden() const{
	int position = 1; //Posición en el vector que almacena el recorrido
	TVectorPoro postNodos(this->Nodos()); //Vector del tamaño adecuado para almacenar todos los nodos
	
	PostordenAux(postNodos, position);
	
	return postNodos;
}
//Devuelve el recorrido en niveles 
TABBPoro TABBPoro::Niveles() const{
	TABBPoro a;
	// !HACER...
	return a;
}
//Suma de dos ABB
TABBPoro TABBPoro::operator+(TABBPoro &){
	TABBPoro a;
	// !HACER...
	return a;
}
//Resta de dos ABB
TABBPoro TABBPoro::operator-(TABBPoro &){
	TABBPoro a;
	// !HACER...
	return a;
}
ostream& operator<<(ostream &os, const TABBPoro &abb){
	os << abb.Niveles();
   return os;
}
//El arbolbinario se diferencia del arbol binario de busqueda en las inserciones
//En los apuntes de teoría hay mucho hecho ya

//Las inserciones hacen los new
//Los de borrar eliminan los new

// ! d
// ? d
// TODO d
// * d