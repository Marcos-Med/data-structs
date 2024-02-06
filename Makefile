APP = app
BIN = bin
INCLUDE = include
OBJ = obj
SRC = src
LIB = lib

CODES = codes
FILES_AUX = files_aux

FLAGS = -O3 -Wall

all: libed  myapps

libed: $(OBJ)/ListSeq.o $(OBJ)/ListSeqOrd.o $(OBJ)/LinkedList.o $(OBJ)/functions_aux.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o
myapps: clean_apps $(BIN)/app

$(OBJ)/%.o: $(SRC)/$(CODES)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APP)/%.c
	gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run:
	echo "Rodando um programa"
	./bin/app
clean:
	Remove-Item -Recurse -Force .\bin\*
	Remove-Item -Recurse -Force .\obj\*
	Remove-Item -Recurse -Force $(LIB)/*
clean_apps:
	Remove-Item -Recurse -Force $(BIN)\*