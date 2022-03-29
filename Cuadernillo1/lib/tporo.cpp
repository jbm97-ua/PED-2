//Jose Burgos Miras  48758447B
//tporo.cpp
#include "tporo.h"

//Constructor por defecto
TPoro::TPoro(){
	this->x=0;
	this->y=0;
	this->volumen=0;
	this->color=NULL;
}
//Constructor a partir de una posicion y un volumen
TPoro::TPoro(int a, int b, double vol){
	this->x=a;
	this->y=b;
	this->volumen=vol;
	this->color=NULL;
}
//Constructor desde de una posicion, un volumen y un color
TPoro::TPoro(int a, int b, double vol, const char* orig){ 
	this->x=a;
	this->y=b;
	this->volumen=vol;	
	
	if(orig!=NULL){
		this->color=new char[strlen(orig)+1];
		strcpy(this->color, orig);
	}
	else{
		this->color=NULL;
	}
}
//CONSTRUCTOR DE COPIA
TPoro::TPoro(const TPoro &poro){ // (const -> para que no se modifique orig)
	this->x=poro.x;
	this->y=poro.y;
	this->volumen=poro.volumen;
	if(poro.color!=NULL){
		this->color=new char[strlen(poro.color)+1];
		strcpy(this->color, poro.color);
	}
	else{
		this->color=NULL;
	}
}
//DESTRUCTOR
TPoro::~TPoro(){
	this->x=0;
	this->y=0;
	this->volumen=0;
	if(this->color!=NULL){
		delete this->color;
		this->color=NULL;
	}
}
//Sobrecarga del operador asignacion
TPoro& TPoro::operator=(const TPoro &poro){ //por referencia para conseguir rapidez
	if(this!=&poro){
		this->~TPoro(); //Con this-> se referencia al objeto de la izquierda (y nos lo cargamos)
		
		//Se modifica el propio objeto:
		this->x=poro.x;
		this->y=poro.y;
		this->volumen=poro.volumen;
		if(poro.color!=NULL){
			this->color=new char[strlen(poro.color)+1];
			strcpy(this->color, poro.color);
		}
		else{
			this->color=NULL;
		}
	}

	return *this; //Se devuelve el objeto que ha sido modificado
}
//Sobrecarga del operador igualdad
bool TPoro::operator==(const TPoro &poro){ 
	bool equal=false;

	if(x==poro.x && y==poro.y && volumen==poro.volumen){
		//Si el color de ambos es nulo...
		if(this->color==NULL && poro.color==NULL){
			equal=true;
		}
		if(this->color!=NULL && poro.color!=NULL){ //Si no es nulo...
			if(strcmp(this->color, poro.color)==0){ //Si son iguales
				equal=true;
			}
		}
	}
	return equal;
}
//Sobrecarga del operador desigualdad
bool TPoro::operator!=(const TPoro &poro){
	bool diferent=false;

	if(this->x!=poro.x || this->y!=poro.y || this->volumen!=poro.volumen || this->color!=poro.color){
		diferent=true;
	}

	return diferent;
}
//Modifica el color
void TPoro::Color(const char *col){
	if(col!=NULL){
		this->color=new char[strlen(col)+1];
		strcpy(this->color, col);
	}
	else{
		this->color=NULL;
	}
}
//Devuelve cierto si el poro está vacío
bool TPoro::EsVacio() const{
	bool empty=false;

	if(this->x==0 && this->y==0 && this->volumen==0 && this->color==NULL){
		empty=true;
	}

	return empty;
}
//Ostream
ostream& operator<<(ostream &os, const TPoro &poro){
	if(!poro.EsVacio()){
		os.setf(ios::fixed);
		os.precision( 2 );
		os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" ";
		if(poro.color!=NULL)
			os<<poro.color;
		else
			os<<"-";
	}
	else{
		os << "()";
	}
	
	return os;
}

/*
tad01 -> OK
tad02 -> OK
tad03 -> OK {WARNING: ISO C++ forbids converting a string constant to ‘char*’}
tad04 -> OK
tad05 -> OK
tad06 -> OK {WARNING: ISO C++ forbids converting a string constant to ‘char*’}
tad07 -> OK {WARNING: ISO C++ forbids converting a string constant to ‘char*’}
tad08 -> OK {WARNING: ISO C++ forbids converting a string constant to ‘char*’}
tad09 -> OK {WARNING: ISO C++ forbids converting a string constant to ‘char*’}
tad10 -> OK
*/