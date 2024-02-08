#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "functions_aux.h"

typedef struct aux{
    key chave;
    struct aux * ant;
    struct aux * prox;
} NO_DEQUE;

typedef struct{
    NO_DEQUE * head;
} DEQUE;

DEQUE * criar_deque();

int tam_deque(DEQUE * deque);

void imprimir_deque(DEQUE * deque);

bool inserir_deque_Ini(DEQUE * deque, key chave);

bool inserir_deque_Fim(DEQUE * deque, key chave);

bool remover_deque_Ini(DEQUE * deque, key * chave);

bool remover_deque_Fim(DEQUE * deque, key * chave);

void destruir_deque(DEQUE * deque);

void reiniciar_deque(DEQUE * deque);

void main_Deque();