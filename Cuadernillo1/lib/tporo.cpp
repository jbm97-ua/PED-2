//Jose Burgos Miras
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
TPoro::TPoro(int a, int b, double vol, char* orig){ 
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
bool TPoro::operator==(const TPoro &){ 
	return true;
}

//Sobrecarga del operador desigualdad
bool TPoro::operator!=(const TPoro &){ 
	return false;
}

//Modifica el color
void TPoro::Color(char *col){
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

ostream& operator<<(ostream &os, TPoro &poro){
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