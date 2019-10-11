SRC = ./src
BIN = ./bin
INC = ./include
OBJ = ./obj
CXX = g++

all: clean $(BIN)/testdiccionario $(BIN)/cantidad_letras $(BIN)/letras documentacion

cl: $(BIN)/cantidad_letras
td: $(BIN)/testdiccionario
lt: $(BIN)/letras

# generador de letras

$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(OBJ)/diccionario.o $(OBJ)/conjunto_letras.o
	@printf "%s\n" "Compilando cantidad_letras"
	@$(CXX) $(OBJ)/cantidad_letras.o $(OBJ)/diccionario.o $(OBJ)/conjunto_letras.o -o $(BIN)/cantidad_letras

$(OBJ)/cantidad_letras.o: $(SRC)/cantidad_letras.cpp
	@printf "%s\n" "Compilando cantidad_letras.o"
	@$(CXX) -c $(SRC)/cantidad_letras.cpp -I$(INC) -o $(OBJ)/cantidad_letras.o

######################################################################################

# testdiccionario

$(BIN)/testdiccionario: $(OBJ)/diccionario.o $(OBJ)/testdiccionario.o
	@printf "%s\n" "Compilando testdiccionario"
	@$(CXX) $(OBJ)/testdiccionario.o $(OBJ)/diccionario.o -o $(BIN)/testdiccionario

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp
	@printf "%s\n" "Compilando testdiccionario.o"
	@$(CXX) -c $(SRC)/testdiccionario.cpp -I$(INC) -o $(OBJ)/testdiccionario.o

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp
	@printf "%s\n" "Compilando diccionario.o"
	@$(CXX) -c $(SRC)/diccionario.cpp -I$(INC) -o $(OBJ)/diccionario.o

######################################################################################

# conjunto de letras

$(BIN)/letras: $(OBJ)/letras.o $(OBJ)/conjunto_letras.o $(OBJ)/diccionario.o $(OBJ)/bolsaLetras.o
	@printf "%s\n" "Compilando letras"
	@$(CXX) $(OBJ)/letras.o $(OBJ)/conjunto_letras.o $(OBJ)/diccionario.o $(OBJ)/bolsaLetras.o -o $(BIN)/letras

$(OBJ)/letras.o: $(SRC)/letras.cpp
	@printf "%s\n" "Compilando letras.o"
	@$(CXX) -c $(SRC)/letras.cpp -I$(INC) -o $(OBJ)/letras.o

$(OBJ)/conjunto_letras.o: $(SRC)/conjunto_letras.cpp
	@printf "%s\n" "Compilando conjunto_letras.o"
	@$(CXX) -c $(SRC)/conjunto_letras.cpp -I$(INC) -o $(OBJ)/conjunto_letras.o

######################################################################################

# bolsa de letras

$(OBJ)/bolsaLetras.o: $(SRC)/bolsaLetras.cpp
	@printf "%s\n" "Compilando bolsaLetras.o"
	@$(CXX) -c $(SRC)/bolsaLetras.cpp -I$(INC) -o $(OBJ)/bolsaLetras.o

######################################################################################

# ************ Generación de documentacion **************
documentacion:
	@printf "%s\n" "Generando Doxygen"
	@doxygen doc/doxys/Doxyfile

# ************ LIMPIEZA **************
clean:
	@printf "%s\n" "Limpiando en bin/ y en obj/"
	@rm -rf $(BIN)/* $(OBJ)/*

mrproper:
	@printf "%s\n" "Limpiando en bin/ , en obj/ y en doxygen"
	@rm -rf $(BIN)/* $(OBJ)/* ./doc/datosDox/*