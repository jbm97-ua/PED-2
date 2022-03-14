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
		//si el de la derecha es cero igualar a null y a cero
		if(this->datos!=NULL){
			delete [] datos;
			this->datos=new TPoro[vporo.Longitud()];
			//Se asigna cada elemento del parametro al puntero datos
			for(long unsigned int i=0; i<vporo.Longitud(); i++){
				this->datos[i]=vporo.datos[i];	
			}
		}
		else{
			this->datos=NULL;
			this->datos=new TPoro[vporo.Longitud()];
			//Se asigna cada elemento del parametro al puntero datos
			for(long unsigned int i=0; i<vporo.Longitud(); i++){
				this->datos[i]=vporo.datos[i];	
			}
		}
	}
	return *this;
}

//Sobrecarga del operador igualdad
bool TVectorPoro::operator==(const TVectorPoro &vporo){
	bool equal=true; //Para comprobar que TODO es igual

	if(this->dimension==vporo.Longitud()){
		for(long int i=0; i<vporo.dimension; i++){
			if(this->datos[i]!=vporo.datos[i]){
				equal=false;
			}
		}
	}
	else{ equal=false; }
	
	return equal;
}

//Sobrecarga del operador desigualdad
bool TVectorPoro::operator!=(const TVectorPoro &vporo){
	return !(*this==vporo); //lo contrario que el operador de igualdad
}

//Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro& TVectorPoro::operator[](int posicion){
	if(posicion>0 && posicion<=this->dimension){
		return this->datos[posicion-1];
	}
	else{
		return this->error;
	}
}

//Sobrecarga del operador corchete (parte DERECHA)
TPoro TVectorPoro::operator[](int posicion) const{
	if(posicion>0 && posicion<=this->dimension){
		return this->datos[posicion-1];
	}
	else{
		return this->error;
	}
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
bool TVectorPoro::Redimensionar(int dimensionParam){
	bool result;
	//vector auxiliar con tamaño que piden (datos)
	TPoro *vAux = new TPoro[this->dimension];
	//TPoro *aux = TVectorPoro(this->datos);???????????
	for(long unsigned int i=0; i<this->dimension; i++){
		vAux[i]=this->datos[i];	
	}

	if(dimensionParam<=0){
		result=false;
	}
	else{ //si dimensionAux>0
		//liberar vector datos (pero reapuntar al auxiliar)
		delete [] this->datos;
		this->datos=NULL;

		if(dimensionParam==this->dimension){
			result=false;
		}
		else if(dimensionParam>this->dimension){
			this->datos = new TPoro[dimensionParam];

			for(long unsigned int i=0; i<this->dimension; i++){
				this->datos[i]=vAux[i];
			}
			for(long unsigned int j=dimension; j<dimensionParam; j++){
				this->datos[j] = TPoro();
			}
			result = true;
		}
		else{ //dimensionAux<this->dimension
			this->datos = new TPoro[dimensionParam];

			for(long unsigned int i=0; i<dimensionParam; i++){
				this->datos[i]=vAux[i];
			}
			result = true;
		}
	}	
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

//HAY QUE PONER const EN REDIMENSIONAR??????

/*
tad01 -> OK
tad02 -> OK
tad03 -> OK
tad04 -> OK
tad05 -> OK {WARNING: ISO C++ forbids converting a string constant to ‘char*’}
tad06 -> Segmantatio fault (¿operator=?)
tad07 -> OK {WARNING: ISO C++ forbids converting a string constant to ‘char*’}
tad08 -> OK {WARNING: ISO C++ forbids converting a string constant to ‘char*’}
*/