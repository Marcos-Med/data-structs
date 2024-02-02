#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define MAX 50

typedef int key_ord;

typedef struct {
    key_ord chave;
    //Outras informações pertinentes....
} REGISTRO_ORD;

typedef struct {
    REGISTRO_ORD array[MAX];
    int nroElem;
} LISTA_SEQ_ORD;

LISTA_SEQ_ORD * cria_lista_seq_ord();

int tam_lista_seq_ord(LISTA_SEQ_ORD * lista);

void imprimir_lista_seq_ord(LISTA_SEQ_ORD * lista);

int busca_rec(LISTA_SEQ_ORD * lista, key_ord chave_reg, int init, int end);

int busca_list_seq_bin(LISTA_SEQ_ORD * lista, key_ord chave_reg);

bool inserir_lista_seq_ord(LISTA_SEQ_ORD * lista, key_ord chave_reg);

bool remover_lista_seq_ord(LISTA_SEQ_ORD * lista, key_ord chave_reg);

void reiniciar_lista_seq_ord(LISTA_SEQ_ORD * lista);

void main_ListSeqOrd();
