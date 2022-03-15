//Jose Burgos Miras
//tlistaporo.cpp
#include "tlistaporo.h"

//Constructor por defecto
TListaNodo::TListaNodo():e(){
	anterior=NULL;
	siguiente=NULL;
}
//Constructor de copia
TListaNodo::TListaNodo(const TListaNodo &origen):e(origen.e){
	anterior=NULL;
	siguiente=NULL;
}
//Destructor
TListaNodo::~TListaNodo(){
	anterior=NULL;
	siguiente=NULL;
}
//Sobrecarga del operador asignacion
TListaNodo& TListaNodo::operator=(const TListaNodo &lnodo){
	if(this!=&lnodo){
		this->~TListaNodo();

		anterior=lnodo.anterior;
		siguiente=lnodo.siguiente;
		e=lnodo.e;
	}
	return *this;
}




//Constructor por defecto
TListaPosicion::TListaPosicion(){
	pos=NULL; //No hay que hacer 'new'
}
//Constructor de copia
TListaPosicion::TListaPosicion(const TListaPosicion &lpos){
	pos=lpos.pos; //NO hay que hacer 'new'
}
//Destructor
TListaPosicion::~TListaPosicion(){
	pos=NULL;
}
//Sobrecarga del operador asignacion
TListaPosicion& TListaPosicion::operator=(const TListaPosicion &lpos){
	if(this!=&lpos){
		//La llamada al destructor es inncesaria...
		//...porque hace pos=NULL y luego pos=lpos.pos
		pos=lpos.pos;
	}
	return *this;
}
//Sobrecarga del operador igualdad
bool TListaPosicion::operator==(const TListaPosicion &lpos){
	//PONER CONST ALFINAL
	bool equal=false;
	if(this->pos==lpos.pos){
		equal=true;
	}
	return equal;
}
//Devuelve la posicion anterior
TListaPosicion TListaPosicion::Anterior(){
	TListaPosicion auxAnterior;

	if(this->pos->anterior!=NULL){
		auxAnterior.pos=this->pos->anterior;
	}

	return auxAnterior;
}
//Devuelve la posicion siguiente
TListaPosicion TListaPosicion::Siguiente(){
	TListaPosicion auxSiguiente;

	if(this->pos->siguiente!=NULL){
		auxSiguiente.pos=this->pos->siguiente;
	}

	return auxSiguiente;
}
//Devuelve TRUE si la posicion no apunta a una lista, FALSE en caso contrario
bool TListaPosicion::EsVacia(){
	bool empty=false;

	if(this->pos==NULL){
		empty=true;
	}

	return empty;
}




//Constructor por defecto
TListaPoro::TListaPoro(){

}
//Constructor de copia
TListaPoro::TListaPoro(const TListaPoro &lporo){

}
//Destructor
TListaPoro::TListaPoro(){

}
//Sobrecarga del operador asignacion
TListaPoro& TListaPoro::operator=(const TListaPoro &lporo){

}
//Sobrecarga del operador igualdad
bool TListaPoro::operator==(const TListaPoro &lporo){
	/**
	 * HACER3
	 * */
	return false;
}
//Sobrecarga del operador suma
TListaPoro TListaPoro::operator+(const TListaPoro &lporo){
	/**
	 * HACER
	 * */
}
//Sobrecarga del operador resta
TListaPoro TListaPoro::operator-(const TListaPoro &lporo){
	/**
	 * HACER
	 * */
}
//Devuelve true si la lista esta vacia, false en caso contrario
bool TListaPoro::EsVacia(){
	/**
	 * HACER
	 * */
	return false;
}
//Inserta el elemento en la lista
bool TListaPoro::Insertar(const TPoro &lporo){
	/**
	 * HACER
	 * */
	return false;
}
//Busca y borra el elemento
bool TListaPoro::Borrar(const TPoro &lporo){
	/**
	 * HACER
	 * */
	return false;
}
//Borra el elemento que ocupa la posición indicada
bool TListaPoro::Borrar(const TListaPosicion &lporo){

	return false;
}
//Obtiene el elemento que ocupa la posición indicada
TPoro TListaPoro::Obtener(const TListaPosicion &lporo){
	/**
	 * HACER
	 * */
}
//Devuelve true si el elemento está en la lista, false en caso contrario
bool TListaPoro::Buscar(const TPoro &lporo){
	/**
	 *  HACER
	 * */
	return false;
}
//Devuelve la longitud de la lista
int TListaPoro::Longitud() const{
	/**
	 * HACER
	 * */
}
//Devuelve la primera posición en la lista
TListaPosicion TListaPoro::Primera(){
	/**
	 * HACER
	 * */
}
//Devuelve la última posición en la lista
TListaPosicion TListaPoro::Ultima(){
	/**
	 * HACER
	 * */
}
//Extraer un rango de nodos de la lista
TListaPoro TListaPoro::ExtraerRango(int n1, int n2){
	/**
	 * HACER
	 * */
}