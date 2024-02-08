#include <stdio.h>
#include <stdbool.h> //Adiciona tipos booleanos
#include <string.h>
#include <stdlib.h>

#include "functions_aux.h"

#define MAX 50

typedef struct 
{
    key chave;
    //Outras informações pertinentes....

} REGISTRO;

typedef struct{
    REGISTRO array[MAX + 1]; //Busca por Sentinela
    int nroElem;
} LISTA_SEQ;

LISTA_SEQ * criar_lista_seq();

int tam_lista_seq(LISTA_SEQ * lista);

void imprimir_lista_seq(LISTA_SEQ * lista);

int busca_list_seq(LISTA_SEQ * lista, key chave_reg);

bool inserir_lista_seq(LISTA_SEQ * lista, key chave_reg, int pos);

bool remover_lista_seq(LISTA_SEQ * lista, key chave_reg);

void reiniciar_lista_seq(LISTA_SEQ * lista);

void main_ListSeq();