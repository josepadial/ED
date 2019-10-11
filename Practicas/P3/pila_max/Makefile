SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/uso_pila_max_vd $(BIN)/uso_pila_max_cola
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/uso_pila_max_vd: $(SRC)/uso_pila_max_vd.cpp $(INC)/pila_max_vd.h $(SRC)/pila_max_vd.cpp
	g++ -std=c++11 -g -w $(SRC)/uso_pila_max_vd.cpp -I$(INC) -o $(BIN)/uso_pila_max_vd

$(BIN)/uso_pila_max_cola: $(SRC)/uso_pila_max_cola.cpp $(INC)/pila_max_cola.h $(SRC)/pila_max_cola.cpp $(INC)/cola.h $(SRC)/cola.cpp
	g++ -std=c++11 -g -w $(SRC)/uso_pila_max_cola.cpp -I$(INC) -o $(BIN)/uso_pila_max_cola


# ************ Limpieza ************
clean :
	rm -rf $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	rm -rf $(BIN)/* doc/datosDox/*
