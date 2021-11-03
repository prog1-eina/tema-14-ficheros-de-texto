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
FICHERO_NIFS_OBJECTS = $(addprefix $(BUILD_DIR)/, 2a-ficheros-nif.o nif.o)
FICHERO_NIFS_ALT_OBJECTS = $(addprefix $(BUILD_DIR)/, 2b-ficheros-nif-sintaxis-alternativa.o nif.o)

################################################################################
## Reglas del fichero «Makefile»

contar: $(SOURCE_DIR)/1-contar.cpp | $(BIN_DIR)
	$(CXX) -g $(SOURCE_DIR)/1-contar.cpp -o $(BIN_DIR)/$@

fichero-nifs: $(FICHERO_NIFS_OBJECTS) | $(BIN_DIR)
	$(CXX) -g $(FICHERO_NIFS_OBJECTS) -o $(BIN_DIR)/$@ 

fichero-nifs-alt: $(FICHERO_NIFS_ALT_OBJECTS) | $(BIN_DIR)
	$(CXX) -g $(FICHERO_NIFS_ALT_OBJECTS) -o $(BIN_DIR)/$@ 

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(BUILD_DIR)/2a-ficheros-nif.o: nif.hpp
$(BUILD_DIR)/2b-ficheros-nif-sintaxis-alternativa.o: nif.hpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
ifeq ($(OS),Windows_NT)
	rmdir /S /Q $(BIN_DIR) $(BUILD_DIR)
else
	rm -f $(OBJECTS) $(TESTING_OBJECTS) $(BIN_DIR)/*
endif
