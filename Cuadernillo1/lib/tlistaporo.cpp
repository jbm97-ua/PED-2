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
TListaPosicion TListaPosicion::Anterior() const{
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
 	primero=NULL;
	ultimo=NULL;
}
//Constructor de copia
TListaPoro::TListaPoro(const TListaPoro &lporo){
	//Si el primero es null es porque inicialmente la lista esta vacia, ..
	//...por tanto al hacer el for con insertar, asignara el primer elemento...
	//...a 'primero'
	this->primero=NULL;

	for(TListaPosicion i=lporo.Primera(); !i.EsVacia(); i=i.Siguiente()){
		this->Insertar(i.pos->e);
	}
}
//Destructor
TListaPoro::~TListaPoro(){
	/**
	 * HACER
	 * */
}
//Sobrecarga del operador asignacion
TListaPoro& TListaPoro::operator=(const TListaPoro &lporo){
	if(this!=&lporo){
		this->~TListaPoro();
		/**
		 * HACER BUCLE FOR ASIGNANDO
		 * */
	}
	return *this;
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
bool TListaPoro::EsVacia() const{
	bool empty=false;

	if(this->primero==NULL){
		empty=true;
	}

	return empty;
}
//Inserta el elemento en la lista
bool TListaPoro::Insertar(const TPoro &lporo){
	TListaPosicion lpos;

	if(EsVacia()){
		InsertarEnCabeza(lporo);
		return true;
	}
	lpos=this->Primera();

	while(!EsVacia()){
		if(lpos.pos->e == lporo){ //Si el poro a insertar ya existe, no se inserta
			return false;
		}
		if(lpos.pos->e.Volumen() >= lporo.Volumen()){
			if(Primera()==lpos){
				InsertarEnCabeza(lporo);
			}
			else{
				InsertarEnMedio(lporo,lpos); //siguiente?
			}
			return true;
		}
		lpos=lpos.Siguiente();
	}
	InsertarEnCola(lporo);
	return true;
}
//Inserta el elemento al principio de la lista
void TListaPoro::InsertarEnCabeza(const TPoro &poro){
	TListaNodo *auxCabeza = new TListaNodo();
	//El poro de 'aux' es el que nos pasan como parametro
	auxCabeza->e=poro;
	//El siguiente poro del nuevo insertado será el que anterioremente era el primero
	auxCabeza->siguiente=primero;
	//El poro que anteriormente era el primero, tendra como anterior al que se acaba de insertar
	primero->anterior=auxCabeza;
	//Se actualiza el poro insertado como el primero
	primero=auxCabeza; //Se actualiza el primero
}
//Inserta el elemento en medio de la lista
void TListaPoro::InsertarEnMedio(const TPoro &poro, const TListaPosicion &lpos){
	TListaNodo *auxMedio = new TListaNodo();
	auxMedio->e=poro;
	
	auxMedio->anterior = lpos.Anterior().pos;
	auxMedio->siguiente = lpos.pos;

	(auxMedio->siguiente)->anterior=auxMedio;
	(auxMedio->anterior)->siguiente=auxMedio;
}
//Inserta el elemento en la cola de la lista
void TListaPoro::InsertarEnCola(const TPoro &poro){
	TListaNodo *auxCola = new TListaNodo();
	//El poro de 'aux' es el que nos pasan como parametro
	auxCola->e=poro; //Ahora mismo NULL <-- poro --> NULL
	//El anterior poro del nuevo insertado será el que anterioremente era el ultimo
	auxCola->anterior=ultimo; //Ahora mismo | anterior <-- ULTIMO --> NULL | ULTIMO <-- poro --> NULL |
	//El poro que anteriormente era el ultimo, tendra como siguiente al que se acaba de insertar
	ultimo->siguiente=auxCola; //Ahora mismo | anterior <-- ULTIMO --> poro | ULTIMO <-- poro --> NULL |
	//Se actualiza el poro insertado como el ultimo
	ultimo=auxCola; //Se actualiza el ultimo
}
//Busca y borra el elemento
//https://www.youtube.com/watch?v=mQOtpTlw_7Q&ab_channel=Programaci%C3%B3nDesdeCero

bool TListaPoro::Borrar(const TPoro &lporo){
	/**
	 * HACER
	 * */
	return false;
}
//Borra el elemento que ocupa la posición indicada
bool TListaPoro::Borrar(const TListaPosicion &lporo){
	/**
	 * HACER
	 * */
	return false;
}
//Obtiene el elemento que ocupa la posición indicada
TPoro TListaPoro::Obtener(const TListaPosicion &lporo){
	TPoro auxPoro;

	for(TListaPosicion i=Primera(); !i.EsVacia(); i.Siguiente()){
		if(i.pos==lporo.pos){
			auxPoro=i.pos->e;
		}
	}

	return auxPoro;
}
//Devuelve true si el elemento está en la lista, false en caso contrario
bool TListaPoro::Buscar(const TPoro &lporo){
	bool found=false;

	for(TListaPosicion i=Primera(); !
	i.EsVacia(); i=i.Siguiente()){
		if(i.pos->e==lporo){
			found=true;
		}
	}

	return found;
}
//Devuelve la longitud de la lista
int TListaPoro::Longitud(){
	int length=0;
	
	for(TListaPosicion i=this->Primera(); !i.EsVacia(); i=i.Siguiente()){
		length++;
	}

	return length;
}
//Devuelve la primera posición en la lista
TListaPosicion TListaPoro::Primera() const{
	TListaPosicion auxPrimera;

	if(!this->EsVacia()){
		auxPrimera.pos=this->primero;
	}

	return auxPrimera;
}
//Devuelve la última posición en la lista
TListaPosicion TListaPoro::Ultima(){
	TListaPosicion auxUltima;

	if(!this->EsVacia()){
		auxUltima.pos=this->ultimo;
	}
	
	return auxUltima;
}
//Extraer un rango de nodos de la lista
TListaPoro TListaPoro::ExtraerRango(int n1, int n2){
	/**
	 * HACER
	 * */
}
ostream& operator<<(ostream &os, TListaPoro &lporo){
	/**
	 * HACER
	 * */
	return os;
}