#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_aux.h"

typedef int key_cicle;

typedef struct aux 
{
    key chave;
    struct aux * no_prox; 
} ELEMENTO;

typedef struct {
    ELEMENTO * head;
} LISTA_CIRCULAR;

LISTA_CIRCULAR * criar_lista_circular();

int tam_lista_circular(LISTA_CIRCULAR * lista);

void imprimir_lista_circular(LISTA_CIRCULAR * lista);

ELEMENTO * busca_lista_circular(LISTA_CIRCULAR * lista, key chave);

bool inserir_lista_circular(LISTA_CIRCULAR * lista, key chave);

bool remover_lista_circular(LISTA_CIRCULAR * lista, key chave);

void destruir_lista_circular(LISTA_CIRCULAR * lista);

void reiniciar_lista_circular(LISTA_CIRCULAR * lista);

void main_ListaCircular();