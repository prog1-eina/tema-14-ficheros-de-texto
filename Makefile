################################################################################
## Fichero «Makefile» para los programas:
## «contar», «ficheros-nif» y «ficheros-nif-sintaxis-alternativa»
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS
SOURCE_DIR = .
NIFS_DIR = ../tema-11-registros/
BUILD_DIR = build
BIN_DIR = bin

VPATH = $(SOURCE_DIR) $(NIFS_DIR)

## COMPILADOR Y OPCIONES DE COMPILACIÓN:
CXX = g++
CXXFLAGS = -g -Wall -Wextra -I$(NIFS_DIR)


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):
OBJECTS = $(addprefix $(BUILD_DIR)/, 2-ficheros-nif.o nif.o)

################################################################################
## Reglas del fichero «Makefile»

contar: $(SOURCE_DIR)/1-contar.cpp | $(BIN_DIR)
	$(CXX) -g -o $(BIN_DIR)/$@ $^

fichero-nifs: $(OBJECTS) | $(BIN_DIR)
	$(CXX) -g -o $(BIN_DIR)/$@ $^

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(BUILD_DIR)/2-ficheros-nif.o: nif.hpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
else
	rm -f $(OBJECTS) $(BIN_DIR)/*
endif
