//Jose Burgos Miras
//tvectorporo.cpp
#include "tvectorporo.h"

//Constructor por defecto
TVectorPoro::TVectorPoro(){

}

//Constructor a partir de una dimension
TVectorPoro::TVectorPoro(int){

}

//Constructor de copia
TVectorPoro::TVectorPoro(const TVectorPoro &){

}

//Destructor
TVectorPoro::~TVectorPoro(){

}

//Sobrecarga del operador asignacion
TVectorPoro& TVectorPoro::operator=(const TVectorPoro &){

	return null;
}

//Sobrecarga del operador igualdad
bool TVectorPoro::operator==(const TVectorPoro &){

	return true;
}

//Sobrecarga del operador desigualdad
bool TVectorPoro::operator!=(const TVectorPoro &){

	return true;
}

//Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro& TVectorPoro::operator[](int){

	return null;
}

//Sobrecarga del operador corchete (parte DERECHA)
TPoro TVectorPoro::operator[](int) const{

	return null;
}

//Devuelve la cantidad de posiciones ocupadas (no vacias) en el vector
int TVectorPoro::Cantidad() const{

	return 1;
}

//Rendimensiona el vector
bool TVectorPoro::Redimensionar(int) const{

	return true;
}

ostream& operator<<(ostream &os, TVectorPoro &vporo){
	
	return os;
}