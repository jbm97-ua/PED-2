//main.cpp

#include<iostream>
#include "tporo.h"
#include "tvectorporo.h"
using namespace std;

int main(){
	TPoro *poro = new TPoro();

	cout << poro->PosicionX() << endl;

	return 0;
}