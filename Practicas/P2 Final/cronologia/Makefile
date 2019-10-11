SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(OBJ)/fechahistorica.o: $(SRC)/fechahistorica.cpp
	g++ -std=c++11 -g -w -c $(SRC)/fechahistorica.cpp -o $(OBJ)/fechahistorica.o -I$(INC)

$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o
	g++ -std=c++11 -g -w $(OBJ)/pruebacronologia.o  $(OBJ)/fechahistorica.o $(OBJ)/cronologia.o -o $(BIN)/pruebacronologia

$(OBJ)/pruebacronologia.o: $(SRC)/pruebacronologia.cpp
	g++ -std=c++11 -g -w -c $(SRC)/pruebacronologia.cpp -o $(OBJ)/pruebacronologia.o -I$(INC)

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp
	g++ -std=c++11 -g -w -c $(SRC)/cronologia.cpp -o $(OBJ)/cronologia.o -I$(INC)



# ************ Limpieza ************
clean :
	rm -rf $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	rm -rf $(BIN)/* doc/datosDox/*
