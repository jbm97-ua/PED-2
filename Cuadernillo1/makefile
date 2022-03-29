.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tporo.o tvectorporo.o tlistaporo.o 
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

all:    src/main.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/main.cpp $(OBJ) -o main

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

doc:
	doxygen

clean:
	rm -f $(OBJ)
	
	#l 	-> listar
	#b 11   -> breakpoint line 11
	#r      -> run
	#n      -> next (ejecuta el metodo)
	#s      -> step (se mete en el metodo linea a linea)
	#p [var]-> muestra valor de pantalla
	#d [var]->muestra el valor en todo momento 
	#q	->salir
	
	#valgrind 
