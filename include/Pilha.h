#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "functions_aux.h"

typedef struct aux{
    key chave;
    struct aux * next;
} NO_STACK;

typedef struct {
    NO_STACK * topo;
} PILHA;

PILHA * criar_pilha();

int tam_pilha(PILHA * pilha);

void imprimir_pilha(PILHA * pilha);

bool is_empty_pilha(PILHA * pilha);

bool push_pilha(PILHA * pilha, key chave);

bool pop_pilha(PILHA * pilha, key * chave);

void destruir_pilha(PILHA * pilha);

void reiniciar_pilha(PILHA * pilha);

void main_Pilha();