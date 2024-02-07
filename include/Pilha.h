#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int key_stack;

typedef struct aux{
    key_stack chave;
    struct aux * next;
} NO_STACK;

typedef struct {
    NO_STACK * topo;
} PILHA;

PILHA * criar_pilha();

int tam_pilha(PILHA * pilha);

void imprimir_pilha(PILHA * pilha);

bool is_empty_pilha(PILHA * pilha);

bool push_pilha(PILHA * pilha, key_stack chave);

bool pop_pilha(PILHA * pilha, key_stack * chave);

void destruir_pilha(PILHA * pilha);

void reiniciar_pilha(PILHA * pilha);

void main_Pilha();