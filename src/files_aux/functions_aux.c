#include <stdio.h>
#include "../../include/functions_aux.h"


void imprimir_opcoes(){
    printf("0 - Lista Sequencial\n");
    printf("1 - Lista Sequencial Ordenada\n");
    printf("2 - Lista Ligada\n");
    printf("3 - Pilha\n");
    printf("4 - Fila\n");
    printf("5 - Deque\n");
    printf("6 - Arvore Binaria\n");
    printf("7 - Arvore Binaria de Busca\n");
    printf("8 - Arvore AVL\n");
    printf("9 - Sair\n");
}

void tratar_string(char string[]){
    int i;
    char * aux = (char *) malloc(sizeof(char) * (strlen(string) - 1));
    for(i = 0; string[i] != '\n'; i++){
        aux[i] = tolower(string[i]);
    }
    aux[i] = '\0';
}