#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "functions_aux.h"

typedef struct aux{
    key chave;
    struct aux * prox;
} NO_FILA;

typedef struct {
    NO_FILA * inicio;
    NO_FILA * fim;
} FILA;

FILA * criar_fila();

int tam_fila(FILA * fila);

bool is_empty_fila(FILA * fila);

void imprimir_fila(FILA * fila);

bool inserir_fila(FILA * fila, key chave);

bool remover_fila(FILA * fila, key * chave);

void destruir_fila(FILA * fila);

void reiniciar_fila(FILA * fila);

void main_Fila();