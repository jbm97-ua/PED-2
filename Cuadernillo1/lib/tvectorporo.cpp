//Jose Burgos Miras
//tvectorporo.cpp
#include "tvectorporo.h"

//Constructor por defecto
TVectorPoro::TVectorPoro(){
	this->dimension=0;
	this->datos=NULL;
}

//Constructor a partir de una dimension
TVectorPoro::TVectorPoro(int dim){
	if(dim<=0){
		this->dimension=0;
		this->datos=NULL;
	}
	else{
		this->dimension=dim;
		this->datos=new TPoro[dim];
	}
}

//Constructor de copia
TVectorPoro::TVectorPoro(const TVectorPoro &vporo){
	this->dimension=vporo.dimension;
	
	if(vporo.datos!=NULL){
		this->datos=new TPoro[vporo.dimension];
		//Se asigna cada elemento del parametro al puntero datos
		for(long unsigned int i=0; i<vporo.dimension; i++){
			this->datos[i]=vporo.datos[i];	
		}
	}
	else{
		this->datos=NULL;
	}
}

//Destructor
TVectorPoro::~TVectorPoro(){
	if(this->datos!=NULL){
		delete [] this->datos;
		this->datos=NULL;
	}
	dimension=0;
}

//Sobrecarga del operador asignacion
TVectorPoro& TVectorPoro::operator=(const TVectorPoro &vporo){
	if(this!=&vporo){
		this->~TVectorPoro();
		//Se modifica el propio objeto
		this->dimension=vporo.dimension;

		if(this->datos!=NULL){
			this->datos=new TPoro[vporo.Longitud()];
			//Se asigna cada elemento del parametro al puntero datos
			for(long unsigned int i=0; i<vporo.dimension; i++){
				this->datos[i]=vporo.datos[i];	
			}
		}
		else{
			this->datos=NULL;
		}
	}
	return *this;
}

//Sobrecarga del operador igualdad
bool TVectorPoro::operator==(const TVectorPoro &){
	
	return true;
}

//Sobrecarga del operador desigualdad
bool TVectorPoro::operator!=(const TVectorPoro &vporo){
	return !(*this==vporo);
}

//Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro& TVectorPoro::operator[](int posicion){
	if(posicion<0 && posicion<=this->dimension){
		return this->datos[posicion-1];
	}
	else{
		return this->error;
	}
}

//Sobrecarga del operador corchete (parte DERECHA)
TPoro TVectorPoro::operator[](int) const{

	return NULL;
}

//Devuelve la cantidad de posiciones ocupadas (no vacias) en el vector
int TVectorPoro::Cantidad() const{
	int counter=0;
	for(long unsigned int i=0; i<dimension; i++){
		if(this->datos[i].EsVacio()==false){
			counter++;
		}
	}
	return counter;
}

//Rendimensiona el vector
bool TVectorPoro::Redimensionar(int) const{
	//vector auxiliar con tamaño que piden
	//se copia todo lo que se tenia en datos (sin salir de rango)
	//liberar vector datos (pero reapuntar al auxiliar)
	//poner el auxiliar a null (sin hacer delete)
	return true;
}

ostream& operator<<(ostream &os, TVectorPoro &vporo){
	os << "[";
	if(vporo.Longitud()>0){
		for(long unsigned int i=0; i<vporo.Longitud(); i++){
			if(i==0){
				os << i+1 << " " << vporo.datos[i];
			} 
			else{
				os << " " << i+1 << " " << vporo.datos[i];
			}
		}
	}
	os << "]";
	
	return os;
}