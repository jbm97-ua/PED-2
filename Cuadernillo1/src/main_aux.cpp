#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"
#include "tlistaporo.h"


#include <tporo.h>
#include <tvectorporo.h>
#include <tlistaporo.h>
#include <sstream>

using namespace std;

// ###########
// TESTS TPORO
// ###########

// Boolean tests

int tporotestEqualsAndNotEquals() {
    int punt = 0;

    if (TPoro() == TPoro()) punt++;
    else cerr << "ERROR TEST: TPoro op equals 1" << endl;

    TPoro a = TPoro(0, 1, 0.5);
    TPoro b = TPoro(0, 1, 0.5, (char*)"cadena");
    TPoro c = TPoro(0, 1, 0.5, (char*)"cadena");
    TPoro d = TPoro(-1, 1, 0.5);
    TPoro e = TPoro(0, -1, 0.5);
    TPoro f = TPoro(0, 1, -0.5);

    if (a != b) punt++;
    else cerr << "ERROR TEST: TPoro op not equals 1" << endl;
    if (a == a) punt++;
    else cerr << "ERROR TEST: TPoro op equals 2" << endl;
    if (b == b) punt++;
    else cerr << "ERROR TEST: TPoro op equals 3" << endl;
    if (a != d) punt++;
    else cerr << "ERROR TEST: TPoro op not equals 2" << endl;
    if (a != e) punt++;
    else cerr << "ERROR TEST: TPoro op not equals 3" << endl;
    if (a != f) punt++;
    else cerr << "ERROR TEST: TPoro op not equals 4" << endl;
    return punt;
}

int tporotestIsEmpty() {
    int punt = 0;
    if (TPoro().EsVacio())              punt++;
    else cerr << "ERROR TEST: TPoro.EsVacio() 1" << endl;
    if (!TPoro(1, 2, 1.2).EsVacio())    punt++;
    else cerr << "ERROR TEST: TPoro.EsVacio() 2" << endl;
    return punt;
}

// Getters and setters

int tporotestSetters() {
    int punt = 0;
    TPoro a = TPoro(0, 1, 0.5);
    TPoro b = TPoro(0, 1, 0.5, (char*)"cadena");
    TPoro c = TPoro(-1, 1, 0.5);
    TPoro d = TPoro(0, 1, 0.5);
    TPoro e = TPoro(0, 1, 2.5);

    c.Posicion(0, 1);
    if (a == c) punt++;
    else cerr << "ERROR TEST: setters TPoro.Posicion() 1" << endl;

    d.Color((char*)"cadena");
    if (d == b) punt++;
    else cerr << "ERROR TEST: setters TPoro.Color()" << endl;

    e.Volumen(0.5);
    if (e == a) punt++;
    else cerr << "ERROR TEST: setters TPoro.Color()" << endl;

    e.Posicion(0, 0);
    if (a == e) cerr << "ERROR TEST: setters TPoro.Posicion() 2" << endl;
    else punt++;

    return punt;
}

int tporotestGetters() {
    int punt = 0;
    TPoro a = TPoro(0, 1, 0.5, (char*)"cadena");

    if (a.PosicionX() == 0) punt++;
    else cerr << "ERROR TEST: getters TPoro.PosicionX()" << endl;

    if (a.PosicionY() == 1) punt++;
    else cerr << "ERROR TEST: getters TPoro.PosicionY()" << endl;

    if (a.Volumen() == 0.5) punt++;
    else cerr << "ERROR TEST: getters TPoro.Volumen()" << endl;

    if (strcmp(a.Color(), (char*)"cadena") == 0) punt++;
    else cerr << "ERROR TEST: getters TPoro.Color()" << endl;
    return punt;
}

// Capulladas

int tporotestAmI() {
    int punt = 0;
    TPoro a = TPoro(0, 1, 0.5, (char*)"cadena");
    TPoro b = TPoro(0, 1, 0.5, (char*)"cadena");
    a = a;

    if (a == b) punt++;
    else cerr << "ERROR TEST: tporotestAmI not works" << endl;
    return punt;
}

int tporotestCallingDestructor() {
    int punt = 0;
    
    TPoro a(1, 2, 3.5, (char*)"Ilegales");
    a.~TPoro();
    if (a == TPoro()) punt++;
    else cerr << "ERROR TEST: tporotestCallingDestructor not works in step 1" << endl;

    a.~TPoro();
    if (a == TPoro()) punt++;
    else cerr << "ERROR TEST: tporotestCallingDestructor not works in step 2" << endl;

    /*  
     *  Si hemos tenido un petardazo en el step 2 es porque
     *  no estamos controlando bien el destructor.
     */
    return punt;
}

int tporotestConstInConstructor() {
    int punt = 0;
    const int x = 1, y = 2;
    const double vol = 3.5;
    TPoro a(x, y, vol); // Si esto peta es porque los parámetros no son const
    punt++;
    return punt;
}

int tporotestAssign() {
    int punt = 0;
    TPoro a = TPoro(0, 1, 0.5, (char*)"cadena");
    TPoro b;

    b = a;
    if (a == b) punt++;
    else cerr << "ERROR TEST: TPoro op assing" << endl;
    return punt;
}

int tporotestOutput() {
    int punt = 0;
    TPoro a(0, 1, 0.5, (char*)"verde");
    TPoro b(0, 1, 0.5);
    stringstream ss1;
    ss1 << a;
    string expectedOutput1 = string("(0, 1) 0.50 verde");
    if (expectedOutput1.compare(ss1.str()) == 0) punt++;
    else cerr << "ERROR TEST: tporotestOutput step 1" << endl;
    stringstream ss2;
    ss2 << b;
    string expectedOutput2 = string("(0, 1) 0.50 -");
    if (expectedOutput2.compare(ss2.str()) == 0) punt++;
    else cerr << "ERROR TEST: tporotestOutput step 2" << endl;
    return punt;
}

// ============= //
// Houston TPoro //
// ============= //

int tporoTestBooleanMethods() {
    int punt = 0;
    const int expected = 9;
    punt += tporotestEqualsAndNotEquals();  // 7 puntos
    punt += tporotestIsEmpty();             // 2 puntos
    cout << "tporoTestBooleanMethods" << punt << " / " << expected << endl;
    return punt;
}

int tporoTestGettersAndSetters() {
    int punt = 0;
    const int expected = 8;
    punt += tporotestGetters();     // 4 puntos
    punt += tporotestSetters();     // 4 puntos
    cout << "tporoTestGettersAndSetters" << punt << " / " << expected << endl;
    return punt;
}

int tporoTestCapulladas() {
    int punt = 0;
    const int expected = 7;

    punt += tporotestAmI();     // 1 punto
    punt += tporotestAssign();  // 1 punto
    punt += tporotestConstInConstructor();  // 1 punto
    punt += tporotestCallingDestructor();   // 2 puntos
    punt += tporotestOutput();  // 2 puntos
    cout << "tporoTestCapulladas" << punt << " / " << expected << endl;
    return punt;
}

// #################
// TESTS TVECTORPORO
// #################

// Equals and not equals

int tvporotestEquals() {
    int punt = 0;

    // Compare two empty:
    if (TVectorPoro() == TVectorPoro()) punt++;
    else cerr << "ERROR TESTS: tvporotestEquals not works with empty" << endl;

    // Testing equals:
    TPoro a(1,2,0.5,(char*)"rojo\n");
    TPoro b(1,2,0.5,(char*)"verde\n");
    TPoro c(1,2,0.5,(char*)"azul\n");
    TPoro d(1,2,0.5,(char*)"amarillo\n");

    TVectorPoro vecEq1(3), vecEq2(3);
    vecEq1[1] = a;
    vecEq1[2] = b;
    vecEq1[3] = c;
    vecEq2[1] = a;
    vecEq2[2] = b;
    vecEq2[3] = c;

    if (vecEq1 == vecEq2) punt++;
    else cerr << "ERROR TEST: tvporotestEquals not works with equal vectors" << endl;

    // Testing distinct size:
    TVectorPoro vecDist1_1(3), vecDist1_2(2);
    vecDist1_1[1] = a;
    vecDist1_1[2] = c;
    vecDist1_1[3] = a;
    vecDist1_2[1] = a;
    vecDist1_2[2] = c;

    if (vecDist1_1 == vecDist1_2) cerr << "ERROR TEST: tvporotestEquals not works with distinct size vectors" << endl;
    else punt++;

    TVectorPoro vecDist2_1(2), vecDist2_2(2);
    vecDist2_1[1] = a;
    vecDist2_1[2] = c;
    vecDist2_2[1] = b;
    vecDist2_2[2] = d;
    
    if (vecDist2_1 == vecDist2_2) cerr << "ERROR TEST: tvporotestEquals not works with distinct vectors" << endl;
    else punt++;
    return punt;
}

int tvporotestNotEquals() {
    int punt = 0;

    TPoro empty, a(1, 2, 3.2);
    TVectorPoro tvpA, tvpB(2), tvpC(2), tvpD(2);

    if (tvpA != tvpB) punt++;
    else cerr << "ERROR TEST: tvporotestNotEquals not woks with empties" << endl;

    tvpC[1] = tvpD[1] = empty;
    tvpC[2] = tvpD[2] = a;
    tvpB[1] = a;
    tvpB[2] = empty;

    if (tvpB != tvpC) punt++;
    else cerr << "ERROR TEST: tvporotestNotEquals not works" << endl;

    if(tvpD != tvpC) cerr << "ERROR TEST: tvporotestNotEquals not works with equals" << endl;
    else punt++;

    if(TVectorPoro() != TVectorPoro()) cerr << "ERROR TEST: tveccalTestNotEquals not works with empty equals" << endl;
    else punt++;
    return punt;
}

// Test []

int tvporotestCorchete() {
    int punt = 0, expected = 3;
    TVectorPoro vec(2);
    vec[1] = TPoro(20, 7, 19.28, (char*)"Rojo");
    vec[2] = TPoro(25, 7, 19.28, (char*)"Azul");

    if (vec[32] == TPoro()) punt++;
    else cerr << "ERROR TEST: tvporotestCorchete out of bounds not works." << endl;

    if(vec[-351] == TPoro()) punt++;
    else cerr << "ERROR TEST: tvporotestCorchete out of bounds not works." << endl;

    TPoro aux = vec[1];
    vec[1] = vec[2];
    if(vec[1] == aux) cerr << "ERROR TEST: tvporotestCorchete not works." << endl;
    else punt++;

    cout << "tvporotestCorchete: " << punt << " / " << expected << endl;
    return punt;
}

// Test redimensionar

int tvporotestRedimensionar() {
    int punt = 0, expected = 5;

    TVectorPoro vec = TVectorPoro(1);
    TPoro a = TPoro(1, 2, 19.99, (char*)"Rojo");
    TPoro b = TPoro(1, 3, 20.00, (char*)"Verde");
    TPoro c = TPoro(1, 4, 20.01, (char*)"Azul");

    vec[1] = a;
    vec.Redimensionar(2);

    TVectorPoro expected1 = TVectorPoro(2);
    expected1[1] = a;
    expected1[2] = TPoro();

    if(vec == expected1) punt++;
    else cerr << "ERROR TEST: tvporotestRedimensionar not works with expected1" << endl;

    TVectorPoro expected2 = TVectorPoro(3);
    expected2[1] = a;    
    expected2[2] = b;
    expected2[3] = c;
    vec.Redimensionar(3);
    vec[2] = b;
    vec[3] = c;

    if(vec == expected2) punt++;
    else cerr << "ERROR TEST: tvporotestRedimensionar not works with expected2" << endl;

    vec.Redimensionar(1);
    TVectorPoro expected3 = TVectorPoro(1);
    expected3[1] = a;
    if(vec == expected3) punt++;
    else cerr << "ERROR TEST: tvporotestRedimensionar not works with expected3" << endl;
 
    if(vec.Redimensionar(1)) cerr << "ERROR TEST: tvporotestRedimensionar same size." << endl;
    else punt++;

    if(vec.Redimensionar(-32)) cerr << "ERROR TEST: tvporotestRedimensionar negative size." << endl;
    else punt++;

    cout << "tvporotestRedimensionar: " << punt << " / " << expected << endl;
    return punt;
}

// Capulladas

int tvporotestAmI() {
    int punt = 0;
    TVectorPoro a(2), b(2);
    a[1] = TPoro(17, 10, 19.99, (char*)"Azul");
    a[2] = TPoro(23, 2, 19.81, (char*)"Rojo");
    b[1] = TPoro(17, 10, 19.99, (char*)"Azul");
    b[2] = TPoro(23, 2, 19.81, (char*)"Rojo");
    a = a;
    if (a == b) punt++;
    else cerr << "ERROR TEST: tveccalTestAmI not works." << endl;
    return punt;
}

int tvporotestCallingDestructor() {
    int punt = 0;
    TVectorPoro a(5);
    a.~TVectorPoro();
    if(a == TVectorPoro()) punt++;
    else cerr << "ERROR TEST: tvporotestCallingDestructor not works in step 1. " << endl;

    a.~TVectorPoro();   // Si peta aquí es porque no se controla bien el destructor.
    if(a == TVectorPoro()) punt++;
    else cerr << "ERROR TEST: tvporotestCallingDestructor not works in step 2. " << endl;
    return punt;
}

int tvporotestConstInCorchete() {
    int punt = 0;
    const TPoro a(20, 4, 19.90, (char*)"Negro");
    TVectorPoro asdf = TVectorPoro(5);
    asdf[1] = a;
    punt++;
    return punt;
}

int tvporotestOutput() {
    int punt = 0;
    TVectorPoro vec1 = TVectorPoro(3);
    TPoro a1 = TPoro(1, 2, 19.99, (char*)"Rojo");
    TPoro b1 = TPoro(1, 3, 20.00, (char*)"Verde");
    TPoro c1 = TPoro(1, 4, 20.01, (char*)"Azul");
    vec1[1] = a1;
    vec1[2] = b1;
    vec1[3] = c1;

    stringstream ss1;
    ss1 << vec1;

    string expectedOutput1 = string("[1 (1, 2) 19.99 Rojo 2 (1, 3) 20.00 Verde 3 (1, 4) 20.01 Azul]");
    if (expectedOutput1.compare(ss1.str()) == 0) punt++;
    else cerr << "ERROR TEST: tvporotestOutput step 1" << endl;

    TVectorPoro vec2 = TVectorPoro(3);
    TPoro a2 = TPoro(1, 2, 19.99);
    TPoro b2 = TPoro(1, 3, 20.00);
    TPoro c2 = TPoro(1, 4, 20.01);
    vec2[1] = a2;
    vec2[2] = b2;
    vec2[3] = c2;

    stringstream ss2; 
    ss2 << vec2; 
    string expectedOutput2 = string("[1 (1, 2) 19.99 - 2 (1, 3) 20.00 - 3 (1, 4) 20.01 -]");
    if (expectedOutput2.compare(ss2.str()) == 0) punt++;
    else cerr << "ERROR TEST: tvporotestOutput step 2" << endl;
    return punt;
}

// =================== //
// Houston TVectorPoro //
// =================== //

int tvporoTestBooleanMethods() {
    int punt = 0;
    const int expected = 8;
    punt += tvporotestEquals();  // 4 puntos
    punt += tvporotestNotEquals();     // 4 puntos
    cout << "tvporoTestBooleanMethods" << punt << " / " << expected << endl;
    return punt;
}

int tvporoTestCapulladas() {
    int punt = 0, expected = 6;
    punt += tvporotestAmI();               // 1 punto
    punt += tvporotestCallingDestructor(); // 2 puntos
    punt += tvporotestConstInCorchete();   // 1 punto
    punt += tvporotestOutput();             // 2 puntos
    cout << "tvporoTestCapulladas" << punt << " / " << expected << endl;
    return punt;
}

// #################
// TESTS TLISTAPORO
// #################

// Insert and delete

int tlporotestInsert() {
    int punt = 0;
    TListaPoro aList;
    TPoro unPoro = TPoro(20, 4, 19.90, (char*)"Un poro");
    if (aList.Insertar(unPoro)) {
        punt++;
        if (!aList.EsVacia()) {
            punt++;
            if (aList.Longitud() == 1) punt++;
            else cerr << "ERROR TEST: tlporotestInsert() not works well: aList length expected is 1, but received " << aList.Longitud() << "." << endl;
        } else cerr << "ERROR TEST: tlporotestInsert() not works well: aList is NULL." << endl;
    } else cerr << "ERROR TEST: tlporotestInsert() not works." << endl;
    return punt;
}

int tlporotestMultipleInsert() {
    int punt = 0;
    TListaPoro aList;
    TPoro unPoro = TPoro(20, 4, 19.90, (char*)"Poro 1");
    TPoro dosPoros = TPoro(10, 2, 32.90, (char*)"Poro 2");

    aList.Insertar(unPoro);
    aList.Insertar(dosPoros);

    if (aList.Longitud() == 2) punt++;
    else cerr << "ERROR TEST: tlporotestMultipleInsert not works" << endl;
    //std::cerr << aList << std::endl << std::flush;
    return punt;
}

int tlporotestDelete() {
    int punt = 0;
    TListaPoro lista;

    TPoro uno = TPoro(20, 4, 19.90, (char*)"Poro 1");
    TPoro cuatro = TPoro(9, 10, 20.18, (char*)"Poro 4");
    TPoro dos = TPoro(17, 10, 19.99, (char*)"Poro 2");
    TPoro tres = TPoro(17, 10, 19.99, (char*)"Poro 3");

    lista.Insertar(TPoro(20, 4, 19.90, (char*)"Poro 1"));
    lista.Insertar(TPoro(9, 10, 20.18, (char*)"Poro 2"));
    lista.Insertar(TPoro(17, 10, 19.99, (char*)"Poro 3"));
    if (lista.Borrar(TPoro(17, 10, 19.99, (char*)"Poro 3"))) punt++;
    else cerr << "ERROR TEST: tlporotestDelete() not works in case 1. " << endl;

    lista.Insertar(TPoro(17, 10, 19.99, (char*)"Poro 3"));
    TListaPosicion pos = TListaPosicion();
    pos = lista.Primera();
    if (lista.Borrar(pos)) punt++;
    else cerr << "ERROR TEST: tlcaltestDelete not works in case 2. " << endl;

    lista.Insertar(TPoro(20, 4, 19.90, (char*)"Poro 1"));
    lista.Insertar(TPoro(17, 10, 19.99, (char*)"Poro 4"));
    pos = lista.Primera();
    if (lista.Borrar(pos)) punt++;
    else cerr << "ERROR TEST: tlporotestDelete has broken in case 3. " << endl;

    if (lista.Longitud() == 3) punt++;
    else cerr << "ERROR TEST: tlporotestDelete not works in case 4. " << endl;

    TListaPoro lista2;
    TPoro cinco = TPoro(0, 0, 30, (char*) "Poro 5");
    lista2.Insertar(uno);
    lista2.Insertar(dos);
    lista2.Insertar(tres);
    lista2.Insertar(cuatro);
    lista2.Insertar(cinco);
    TListaPoro expectedInLista2;
    expectedInLista2.Insertar(tres);
    expectedInLista2.Insertar(cuatro);
    expectedInLista2.Insertar(cinco);
    int counter = 0;
    for (TListaPosicion it = lista2.Primera(); !it.EsVacia(); it = it.Siguiente(), counter++)
        if (counter < 2) lista2.Borrar(it);

    if (lista2.Longitud() == 3) punt++;
    else cerr << "ERROR TEST: tlporotestDelete not works in case 5. " << endl;

    if (lista2 == expectedInLista2) punt++;
    else cerr << "ERROR TEST: tlporotestDelete not works in case 6. " << endl;
    return punt;
}

// Booleanos

int tlporotestOpAsig() {
    int punt = 0;
    TListaPoro lista1, lista2;
    lista1.Insertar(TPoro(20, 4, 19.90, (char*)"Poro 1"));
    lista1.Insertar(TPoro(9, 10, 20.18, (char*)"Poro 2"));
    lista2 = lista1;

    if (&lista1 != &lista2) punt++;
    else cerr << "ERROR TEST: tlporotestOpAsig lista1 and lista2 are the same." << endl;

    if (lista1 == lista2) punt++;
    else cerr << "ERROR TEST: tlporotestOpAsig lista1 and lista2 are equials." << endl;
    return punt;
}

int tlporotestEsVacia() {
    int punt = 0;
    TListaPoro listaVacia; 
    if (listaVacia.EsVacia()) punt++;
    else cerr << "ERROR TEST: tlporotestEsVacia not works with empty list. " << endl;

    TListaPoro listaNoVacia;
    listaNoVacia.Insertar(TPoro(20, 4, 19.90, (char*)"Poro 1"));
    if (!listaNoVacia.EsVacia()) punt++;
    else cerr << "ERROR TEST: tlporotestEsVacia not works with non-empty list. " << endl;
    return punt;
}
/*
int tlporoTestBuscar() { // 3 puntos
    int punt = 0;
    TListaPoro lista;
    TListaPosicion item1, item2;
    lista.Insertar(TPoro(20, 4, 19.90, (char*)"Poro 1"));
    item1 = lista.Primera();
    lista.Insertar(TPoro(9, 10, 20.18, (char*)"Poro 2"));
    item2 = lista.Ultima();
    if(!lista.Buscar(TListaPosicion()) punt++;
    else cerr << "ERROR TEST: tlporoTestBuscar not works. " << endl;
    if(lista.Buscar(item2)) punt++;
    else cerr << "ERROR TEST: tlporoTestBuscar not works. " << endl;
    if(lista.Buscar(item1)) punt++;
    else cerr << "ERROR TEST: tlporoTestBuscar not works. " << endl;
    return punt;
}*/

int tlporoTestOperatorEquals() { // 3 puntos
    int punt = 0;

    TListaPoro lista;
    TPoro uno = TPoro(20, 4, 19.90, (char*)"Poro 1");
    TPoro dos = TPoro(17, 10, 19.99, (char*)"Poro 2");
    TPoro tres = TPoro(9, 10, 20.18, (char*)"Poro 3");

    TListaPoro lista2;
    lista.Insertar(uno);
    lista.Insertar(dos);
    lista.Insertar(tres);
    lista2.Insertar(uno);
    lista2.Insertar(dos);
    lista2.Insertar(tres);

    if(lista == lista2) punt++;
    else cerr << "ERROR TEST: tlporoTestOperatorEquals not works with equals." << endl;

    TListaPoro lista3;
    TPoro cuatro = TPoro(20, 4, 19.91, (char*)"Poro 4");
    lista3.Insertar(cuatro);
    lista3.Insertar(dos);
    lista3.Insertar(tres);

    if(lista == lista3) cerr << "ERROR TEST: tlporoTestOperatorEquals not works with not equals." << endl;
    else punt++;

    TListaPoro lista4;
    lista4.Insertar(uno);
    lista4.Insertar(dos);
    lista4.Insertar(tres);
    lista4.Insertar(cuatro);

    if(lista == lista4) cerr << "ERROR TEST: tlporoTestOperatorEquals not works with distinct size lists." << endl;
    else punt++;
    return punt;
}

// Getters and setters

int tlporoTestLongitud() {   // 4 puntos
    int punt = 0;
    TListaPoro listaVacia;
    if(listaVacia.Longitud() == 0) punt++;
    else cerr << "ERROR TEST: tlporoTestLongitud not works with empty list. " << endl;

    TListaPoro listaNoVacia;
    TPoro poro = TPoro(20, 4, 19.90, (char*)"Poro 1");
    listaNoVacia.Insertar(poro);
    if(listaNoVacia.Longitud() == 1) punt++;
    else cerr << "ERROR TEST: tlporoTestLongitud not works with non-empty list. " << endl;

    listaNoVacia.Insertar(poro);
    if(listaNoVacia.Longitud() == 1) punt++;
    else cerr << "ERROR TEST: tlporoTestLongitud not works because TListaCalendario.Insertar() 1 not works. " << endl;

    TPoro cal2 = TPoro(9, 10, 20.18, (char*)"Poro 2");
    listaNoVacia.Insertar(cal2);
    if(listaNoVacia.Longitud() == 2) punt++;
    else cerr << "ERROR TEST: tlporoTestLongitud not works because TListaCalendario.Insertar() 2 not works. " << endl;
    return punt;
}

int tlporoTestFirst() {  // 1 punto
    int punt = 0;

    TListaPoro lista;
    TPoro uno = TPoro(20, 4, 19.90, (char*)"Poro 1");
    TPoro dos = TPoro(17, 10, 19.99, (char*)"Poro 2");
    TPoro tres = TPoro(9, 10, 20.18, (char*)"Poro 3");
    
    lista.Insertar(tres);
    lista.Insertar(dos);
    lista.Insertar(uno);

    if(uno == lista.Obtener(lista.Primera())) punt++;
    else cerr << "ERROR TEST: tlporoTestFirst not works." << endl;
    return punt;
}

int tlporoTestLast() {  // 1 punto
    int punt = 0;

    TListaPoro lista;
    TPoro uno = TPoro(20, 4, 19.90, (char*)"Poro 1");
    TPoro dos = TPoro(17, 10, 19.99, (char*)"Poro 2");
    TPoro tres = TPoro(9, 10, 20.18, (char*)"Poro 3");

    lista.Insertar(uno);
    lista.Insertar(tres);
    lista.Insertar(dos);

    if(tres == lista.Obtener(lista.Ultima())) punt++;
    else cerr << "ERROR TEST: tlporoTestLast not works." << endl;
    return punt;
}

int tlporoTestExtraerRango() {   // 12 puntos
    int punt = 0;
    TListaPoro lista, subLista1, expected1;
    TPoro uno = TPoro(23, 2, 19.81, (char*)"Poro 1");
    TPoro dos = TPoro(20, 4, 19.90, (char*)"Poro 2");
    TPoro tres = TPoro(17, 10, 19.99, (char*)"Poro 3");
    TPoro cuatro = TPoro(11, 3, 20.04, (char*)"Poro 4");
    TPoro cinco = TPoro(9, 10, 20.18, (char*)"Poro 5");
    lista.Insertar(tres);
    lista.Insertar(uno);
    lista.Insertar(cinco);
    lista.Insertar(cuatro);
    lista.Insertar(dos);
    cerr << lista << endl;
    subLista1.Insertar(dos);
    subLista1.Insertar(tres);
    subLista1.Insertar(cuatro);
    expected1.Insertar(uno);
    expected1.Insertar(cinco);

    if(subLista1 == lista.ExtraerRango(2, 4)) punt++; 
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 1. " << endl;

    cerr << lista << endl;
    
    if(expected1 == lista) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 1, step 2." << endl;

    lista.Insertar(tres);
    lista.Insertar(dos);
    lista.Insertar(cuatro);
    TListaPoro subLista2, expected2;
    subLista2.Insertar(dos);
    subLista2.Insertar(uno);
    expected2.Insertar(cuatro);
    expected2.Insertar(cinco);
    expected2.Insertar(tres);

    if(subLista2 == lista.ExtraerRango(-50, 2)) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 2. " << endl;

    if(expected2 == lista) punt ++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 2, step 2." << endl;

    lista.Insertar(dos);
    lista.Insertar(uno);
    if(subLista2 == lista.ExtraerRango(0, 2)) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 3. " << endl;

    if(expected2 == lista) punt ++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 3, step 2." << endl;

    lista.Insertar(dos);
    lista.Insertar(uno);
    TListaPoro subLista3, expected3;
    subLista3.Insertar(cinco);
    subLista3.Insertar(tres);
    subLista3.Insertar(cuatro);
    expected3.Insertar(uno);
    expected3.Insertar(dos);

    if(subLista3 == lista.ExtraerRango(3, 10)) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 4. " << endl;

    if(expected3 == lista) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 4, step 2." << endl;

    lista.Insertar(cinco);
    lista.Insertar(tres);
    lista.Insertar(cuatro);

    if(TListaPoro() == lista.ExtraerRango(8, 1)) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 5. " << endl;

    if(lista.Longitud() == 5) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 5, step 2." << endl;

    TListaPoro subLista4, expected4;
    subLista4.Insertar(cinco);
    subLista4.Insertar(tres);
    subLista4.Insertar(cuatro);
    expected4.Insertar(uno);
    expected4.Insertar(dos);

    const int fucking = 3;
    const int test = 10;
    if(subLista4 == lista.ExtraerRango(fucking, test)) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 6. " << endl;

    if(expected4 == lista) punt++;
    else cerr << "ERROR TEST: tlporoTestExtraerRango not works in case 6, step 2." << endl;
    return punt;
}

int tlporoTestSalida() { // 2 puntos

    // TODO: REVISAR
    int punt = 0;
    TListaPoro lista;
    TPoro cuatro = TPoro(23, 2, 1981, (char*)"23F");
    TPoro uno = TPoro(20, 4, 1990, (char*)"Celtas Cortos");
    TPoro dos = TPoro(17, 10, 1999, (char*)"Jordi said hello world");
    TPoro cinco = TPoro(11, 3, 2004, (char*)"Jueves");
    TPoro tres = TPoro(9, 10, 2018, (char*)"Meri");
    lista.Insertar(uno);
    lista.Insertar(dos);
    lista.Insertar(tres);
    lista.Insertar(cuatro);
    lista.Insertar(cinco);

    string expectedString = "((23, 2) 1981.00 23F (20, 4) 1990.00 Celtas Cortos (17, 10) 1999.00 Jordi said hello world (11, 3) 2004.00 Jueves (9, 10) 2018.00 Meri)";

    stringstream testOutput;
    testOutput << lista;

    if(expectedString.compare(testOutput.str()) == 0) punt++;
    else cerr << "ERROR TEST: tlporoTestSalida not works. " << endl;
    return punt;
}

// Aritmethical operators

int tlporoTestOpSuma() { // 2 punto
    int punt = 0;
    TListaPoro lista1, lista2, lista3;
    TPoro uno = TPoro(23, 2, 19.81, (char*)"Poro 1");
    TPoro dos = TPoro(20, 4, 19.90, (char*)"Poro 2");
    TPoro tres = TPoro(17, 10, 19.99, (char*)"Poro 3");
    TPoro cuatro = TPoro(11, 3, 20.04, (char*)"Poro 4");
    TPoro cinco = TPoro(9, 10, 20.18, (char*)"Poro 5");

    lista1.Insertar(cuatro);
    lista1.Insertar(uno);
    lista2.Insertar(uno);
    lista2.Insertar(cinco);
    lista2.Insertar(dos);
    lista3.Insertar(uno);
    lista3.Insertar(dos);
    lista3.Insertar(cuatro);
    lista3.Insertar(cinco);

    TListaPoro resu;
    resu = lista1 + lista2;
    if(lista3 == lista1 + lista2) punt++;
    else cerr << "ERROR TEST: tlcalTestOpSuma not works." << endl;
    
    if(lista3 == resu) punt++;
    else cerr << "ERROR TEST: tlcalTestOpSuma your operator= not works." << endl;
    return punt;
}

int tlporoTestOpResta() {    // 2 puntos
    int punt = 0;
    TListaPoro lista1, lista2, lista3;
    TPoro uno = TPoro(23, 2, 19.81, (char*)"Poro 1");
    TPoro dos = TPoro(20, 4, 19.90, (char*)"Poro 2");
    TPoro tres = TPoro(17, 10, 19.99, (char*)"Poro 3");
    TPoro cuatro = TPoro(11, 3, 20.04, (char*)"Poro 4");
    TPoro cinco = TPoro(9, 10, 20.18, (char*)"Poro 5");

    lista2.Insertar(cuatro);
    lista2.Insertar(uno);

    lista1.Insertar(uno);
    lista1.Insertar(dos);
    lista1.Insertar(tres);

    lista3.Insertar(dos);
    lista3.Insertar(tres);

    TListaPoro resu;
    resu = lista1 - lista2;

    if(lista3 == lista1 - lista2) punt++;
    else cerr << "ERROR TEST: tlcalTestOpResta not works." << endl;

    if(lista3 == resu) punt++;
    else cerr << "ERROR TEST: tlcalTestOpResta your operator= not works." << endl;
    return punt;
}

// Capulladas

int tlporoTestDobleDestroy() {   // 2 puntos
    int punt = 0;

    TPoro uno = TPoro(14, 2, 1946, (char*)"ENIAC");
    TListaPoro lista;
    lista.Insertar(uno);
    lista.~TListaPoro();

    if(lista.EsVacia())  punt++;
    else cerr << "ERROR TEST: tlcalTestDobleDestroy not works." << endl;

    lista.~TListaPoro();
    punt++;
    return punt;
}
/*
int tlporoTestDestroyInternalPointer() {
    int punt = 0;

    TPoro uno = new TPoro(14, 2, 1946, (char)"ENIAC");
    TPoro unoNonPointer = TPoro(14, 2, 1946, (char*)"ENIAC");
    TListaPoro lista;
    TListaPoro listaCopy;
    lista.Insertar(*uno);
    listaCopy.Insertar(unoNonPointer);

    delete uno;

    if(lista == listaCopy) punt++;
    else cerr << "ERROR TEST: tlcalTestDestroyInternalPointer estamos jodíos, cabrón." << endl;
    return punt;
}*/

int tlporoTestOpAsigCapulladas() { // 2 puntos
    int punt = 0;

    TPoro uno = TPoro(14, 2, 1946, (char*)"ENIAC");
    TListaPoro lista, otherLista;
    lista.Insertar(uno);
    otherLista.Insertar(uno);
    otherLista = lista;

    if(otherLista == lista) punt++;
    else cerr << "ERROR TEST: tlcalTestOpAsig not works in case 1." << endl;
    
    TListaPoro newList;
    newList.Insertar(uno);
    newList = newList;
    TListaPoro expectedList;
    expectedList.Insertar(TPoro(14, 2, 1946, (char*)"ENIAC"));

    if(newList == expectedList) punt++;
    else cerr << "ERROR TEST: tlcalTestOpAsig not works in case 2." << endl;
    return punt;
}

// ================== //
// Houston TListaPoro //
// ================== //

int tlporoTestBooleanMethods() {
    int punt = 0; 
    const int expected = 10;
    punt += tlporotestOpAsig();         //  2 puntos
    punt += tlporotestEsVacia();        //  2 puntos
    //punt += tlporoTestBuscar();         //  3 puntos
    punt += tlporoTestOperatorEquals(); //  3 puntos
    cout << "tlporoTestBooleanMethods" << punt << " / " << expected << endl;
    return punt;
}

int tlporoTestInsertAndDelete() {
    int punt = 0;
    const int expected = 10;
    punt += tlporotestInsert();     // 3 puntos
    punt += tlporotestMultipleInsert();
    punt += tlporotestDelete();     // 6 puntos
    cout << "tlporoTestInsertAndDelete" << punt << " / " << expected << endl;
    return punt;
}

int tlporoTestGettersAndSetters() { // 19 puntos
    int punt = 0;
    int expected = 19;

    punt += tlporoTestLongitud();        //  4 puntos
    punt += tlporoTestFirst();           //  1 punto
    punt += tlporoTestLast();            //  1 punto
    punt += tlporoTestExtraerRango();    // 12 puntos
    punt += tlporoTestSalida();          //  1 punto 

    cout << "tlporoTestGettersAndSetters: " << punt << " / " << expected << endl;
    return punt;
}

int tlporoTestAritmethicalOperators() {  // 4 puntos
    int punt = 0;
    int expected = 4;

    punt += tlporoTestOpSuma();          // 2 puntos
    punt += tlporoTestOpResta();         // 2 puntos

    cout << "tlporoTestAritmethicalOperators: " << punt << " / " << expected << endl;
    return punt;
}

int tlporoTestCapulladas() { // 5 puntos
    int punt = 0;
    int expected = 5;

    punt += tlporoTestDobleDestroy();            // 2 puntos
    //punt += tlporoTestDestroyInternalPointer();  // 1 punto
    punt += tlporoTestOpAsigCapulladas();        // 2 puntos

    cout << "tlporoTestCapulladas: " << punt << " / " << expected << endl;
    return punt;
}

// ###########
// MAINS TESTS
// ###########

int mainTPoro() {
    cout << endl << "$ RUNNING TEST TPORO:" << endl
            << "------------------------"<< endl;
    
    int punt = 0;
    int expected = 24;

    punt += tporoTestBooleanMethods();      // 9 puntos
    punt += tporoTestGettersAndSetters();   // 8 puntos
    punt += tporoTestCapulladas();          // 7 puntos

    cout << "TOTAL TPORO: " << punt << " / " << expected << endl;
    return punt;
}

int mainTVectorPoro() {
    cout << endl << "$ RUNNING TEST TVECTORPORO:" << endl
            << "------------------------"<< endl;
    
    int punt = 0;
    int expected = 22;

    punt += tvporoTestBooleanMethods();     // 8 Points
    punt += tvporotestCorchete();           // 3 puntos
    punt += tvporotestRedimensionar();      // 5 puntos
    punt += tvporoTestCapulladas();         // 6 puntos

    cout << "TOTAL TVECTORPORO: " << punt << " / " << expected << endl;
    return punt;
}

int mainTListaPoro() {
    cout << endl << "$ RUNNING TEST TLISTAPORO:" << endl
            << "------------------------"<< endl;
    
    int punt = 0;
    int expected = 48;

    punt += tlporoTestInsertAndDelete();         // 10 puntos
    punt += tlporoTestBooleanMethods();          // 10 puntos
    punt += tlporoTestGettersAndSetters();       // 19 puntos
    punt += tlporoTestAritmethicalOperators();   //  4 puntos
    punt += tlporoTestCapulladas();              //  5 puntos

    cout << "TOTAL TLISTAPORO: " << punt << " / " << expected << endl;
    return punt;
}

int main() {
    cout << endl << "##### RUNNING TEST JORDI: #####" << endl
            << "$ Points x test pack:" << endl;
    int punt = 0;
    const int expected = 94;
    punt += mainTPoro();        // 24 puntos
    punt += mainTVectorPoro();  // 22 puntos
    punt += mainTListaPoro();   // 38 puntos

    cout << "========================" << endl;
    cout << " TOTAL TESTS: " << punt << " / " << expected << endl;
    cout << "========================" << endl;
    cout << "##### END TESTS JORDI #####" << endl;
    return 0;
}