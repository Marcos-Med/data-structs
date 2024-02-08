#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "functions_aux.h"

typedef int key_list;

typedef struct aux{
    key chave;
    struct aux * next;
} NO_LISTA;

typedef struct{
    NO_LISTA * first_no;
    //Outros campos....
} LISTA_LIGADA;

LISTA_LIGADA * criar_lista_ligada();

int tam_lista_ligada(LISTA_LIGADA * lista);

void imprimir_lista_ligada(LISTA_LIGADA * lista);

NO_LISTA * busca_lista_ligada(LISTA_LIGADA * lista, key chave);

bool inserir_lista_ligada(LISTA_LIGADA * lista, key chave, int pos);

bool remover_lista_ligada(LISTA_LIGADA * lista, key chave);

void destruir_lista_ligada(LISTA_LIGADA * lista);

void reiniciar_lista_ligada(LISTA_LIGADA * lista);

void main_ListaLigada();
