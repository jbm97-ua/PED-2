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
		this->pos=lpos.pos;
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
bool TListaPosicion::EsVacia() const{
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
		//¿¿¿¿¿RESERVAR MEMORIA??????????
		//TPoro poro = new TPoro(i.pos->e);
		this->Insertar(i.pos->e);
		//this->Insertar(i.pos->e);
	}
}
//Destructor
TListaPoro::~TListaPoro(){
	TListaNodo *auxDestructor;
	//Se va eliminando cada elemento del vector eliminando el primero y actualizando...
	//...el siguiente como el nuevo primero
	while(this->primero!=NULL){
		auxDestructor = this->primero->siguiente;
      delete this->primero;
      this->primero = auxDestructor;
	}
}
//Sobrecarga del operador asignacion
TListaPoro& TListaPoro::operator=(const TListaPoro &lporo){
	if(this!=&lporo){
		this->~TListaPoro();
		//Se recorre la lista 'lporo' y se inserta cada poro de esa lista dentro...
		//...de la la lista 'this'
		for(TListaPosicion i = lporo.Primera(); !i.EsVacia(); i = i.Siguiente()){ 
			//¿¿¿¿¿RESERVAR MEMORIA??????
         this->Insertar(i.pos->e);
      }   
	}
	return *this;
}
//Sobrecarga del operador igualdad
bool TListaPoro::operator==(const TListaPoro &lporo){
	bool equal=true;
	/** Se crean dos LPosicion que son inicializadas con la primera posicion de mi lista...
	 ** ...y la primera posicion de la lista que se nos pasa como parametro.
	 ** Para poder ir comparando posicion a posicion si ambas listas son iguales*/
	TListaPosicion myList = this->Primera();
	TListaPosicion otherList = lporo.Primera(); 

	//Si las longitudes de ambas listas son distinas, las listas son diferentes
	if(lporo.Longitud()==this->Longitud()){
		do{
			//Si ambas listas no estan vacias...
			if(!myList.EsVacia() && !otherList.EsVacia()){
				//Se comprueba si el elemento en la misma posicion de cada vector es IGUAL
				if(myList.pos->e != otherList.pos->e){
					equal=false;
				}
				myList=myList.Siguiente(); //myList++
				otherList=otherList.Siguiente(); //otherList++
			}
		}while(!myList.EsVacia()); //Se repetira mientras MI lista no sea vacia
	}
	else{ 
		equal=false; //Longitudes diferentes
	}
	
	return equal;
}
//Sobrecarga del operador suma (devuelve una nueva lista resultado de concatenar dos)
TListaPoro TListaPoro::operator+(const TListaPoro &lporo){
	//Creo la lista que sera devuelta identica a la lista 'this' (constructor de copia)
	TListaPoro *chaining = new TListaPoro(*this);

	//Recorro la lista pasada como parametro e inserto en la lista auxiliar...
	//...todos y cada uno de los nodos (insertar se encarga de ordenarlos)
	for(TListaPosicion i=lporo.Primera(); !i.EsVacia(); i=i.Siguiente()){
		chaining->Insertar(i.pos->e);
	}
	return (*chaining);
}
//Sobrecarga del operador resta (devuelve una nueva lista resultado de la difierencia de dos listas)
TListaPoro TListaPoro::operator-(const TListaPoro &lporo){
	//Creo la lista que sera devuelta identica a la lista 'this' (constructor de copia)
	TListaPoro *filtering = new TListaPoro(*this);

	//Recorro la lista pasada como parametro y elimino de la lista auxiliar...
	//...todos y cada uno de los nodos (borrar se encarga de borrarlos)
	for(TListaPosicion i=lporo.Primera(); !i.EsVacia(); i=i.Siguiente()){
		filtering->Borrar(i.pos->e);
	}
	return (*filtering);
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

	while(!lpos.EsVacia()){
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

	//Si la lista NO es vacia...
	if(primero!=NULL){
		//El siguiente poro del nuevo insertado será el que anterioremente era el primero
		auxCabeza->siguiente=primero;
		//El poro que anteriormente era el primero, tendra como anterior al que se acaba de insertar
		primero->anterior=auxCabeza;
		//Se actualiza el poro insertado como el primero
		primero=auxCabeza; //Se actualiza el primero
	}
	else{
		this->primero=auxCabeza;
		this->ultimo=auxCabeza;
	}
}
//Inserta el elemento en medio de la lista
void TListaPoro::InsertarEnMedio(const TPoro &poro, const TListaPosicion &lpos){
	TListaNodo *auxMedio = new TListaNodo();
	auxMedio->e=poro;
	
	auxMedio->anterior = lpos.Anterior().pos;
	auxMedio->siguiente = lpos.pos;

	(auxMedio->siguiente)->anterior=auxMedio; // 1 -> <- X -> <- 3
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
//Busca y borra el elemento --> https://www.youtube.com/watch?v=mQOtpTlw_7Q&ab_channel=Programaci%C3%B3nDesdeCero
bool TListaPoro::Borrar(const TPoro &lporo){
	TListaNodo *nEliminar;
	TListaNodo *nAuxiliar = this->primero; //Nodo auxliar ubicado al principio de la lista
	
	//Mientras que el nodo auxiliar apunte a algun nodo de la lista...
	while(nAuxiliar!=NULL){
		//Se comprueba si el primer elemento de la lista es igual al elemento que se quiere eliminar
		if(this->primero->e == lporo){
			nEliminar=this->primero; //El punter 'eliminar' apunta el primer nodo de la lista
			this->primero=this->primero->siguiente; //Se actualiza el nuevo 'primero'
			//nAuxiliar=nAuxiliar->siguiente; //Para poder eliminar mas poros iguales al que se desea eliminar
			delete nEliminar; //Se elimina el PORO de la memoria definitivamente
			return true;
		}
		else{
			//Eliminar el nodo intermedio
			if(nAuxiliar->siguiente!=NULL && nAuxiliar->siguiente->e==lporo){
				nEliminar=nAuxiliar->siguiente;
				nAuxiliar->siguiente=nAuxiliar->siguiente->siguiente; //Saltamos el nodo que va a ser eliminado
				delete nEliminar; //Se elimina el PORO  de la memoria definitivamente
				return true;
			}
			else{ //Ni el primero ni el siguiente son el que queremos eliminar
				nAuxiliar=nAuxiliar->siguiente;
			}
		}
	}
	return false;
}
//Borra el elemento que ocupa la posición indicada
bool TListaPoro::Borrar(const TListaPosicion &lporo){
	if(!lporo.EsVacia()){
		return Borrar(lporo.pos->e); //Devuelve true (si se elimina) y false (si no se elimina)
	}
	return false;
}
//Obtiene el elemento que ocupa la posición indicada
TPoro TListaPoro::Obtener(const TListaPosicion &lporo){
	TPoro auxPoro;

	for(TListaPosicion i=Primera(); !i.EsVacia(); i=i.Siguiente()){
		if(i.pos==lporo.pos){
			auxPoro=i.pos->e;
		}
	}

	return auxPoro;
}
//Devuelve true si el elemento está en la lista, false en caso contrario
bool TListaPoro::Buscar(const TPoro &lporo){
	bool found=false;
	for(TListaPosicion i=Primera(); !i.EsVacia(); i=i.Siguiente()){
		if(i.pos->e==lporo){
			found=true;
		}
	}
	return found;
}
//Devuelve la longitud de la lista
int TListaPoro::Longitud() const{
	int length=0;
	for(TListaPosicion i=this->Primera(); !i.EsVacia(); i=i.Siguiente()){
		length++;
	}
	return length;
}
//Devuelve la primera posición en la lista
TListaPosicion TListaPoro::Primera() const{
	TListaPosicion auxPrimera;

	if(this->EsVacia()){
		return auxPrimera;
		
	}
	auxPrimera.pos=primero;

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
	TListaPoro *miLista = new TListaPoro(*this);
	TListaPoro listaRango;
	int counter=1;

	if(n1>n2){
		return listaRango;
	}
	if(n1<=0){
		n1=1;
	}
	if(n2>this->Longitud()){
		n2=this->Longitud();
	}

	for(TListaPosicion i=miLista->Primera(); !i.EsVacia(); i=i.Siguiente()){
		if(n1<=counter && counter<=n2){
			listaRango.Insertar(i.pos->e);
			this->Borrar(i.pos->e);
		}
		counter++;
	}
	miLista->~TListaPoro();

	return listaRango;
}
//Operador de salida
ostream& operator<<(ostream &os, TListaPoro &lporo){
	os << "(";
	for(TListaPosicion i=lporo.Primera(); !i.EsVacia(); i=i.Siguiente()){
		os << lporo.Obtener(i);
		if(i==lporo.Ultima()){
			os << "";
		}
		else{
			os << " ";
		}
	}
	os << ")";
	return os;
}

//	((1, 1) 1.00 - (2, 2) 2.00 - (3, 3) 3.00 -)
//	[1 (1, 2) 3.00 rojo 2 (1, 2) 3.00 rojo 3 (1, 2) 3.00 rojo 4 (1, 2) 3.00 rojo 5 (1, 2) 3.00 rojo]