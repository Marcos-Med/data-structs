#include <stdio.h>

#include "files_aux/functions_aux.h"
#include "structs/headers/ListSeq.h"
#include "structs/headers/ArvoreBin.h"
#include "structs/headers/ArvoreBinSearch.h"
#include "structs/headers/AVL.h"
#include "structs/headers/Deque.h"
#include "structs/headers/Fila.h"
#include "structs/headers/LinkedList.h"
#include "structs/headers/ListSeqOrd.h"
#include "structs/headers/Pilha.h"

int main(){

    int opcion;

    printf("----------------\n");
    printf("Estrutura de Dados\n");
    printf("----------------\n");

    do{
        imprimir_opcoes();
        printf("Digite alguma opcao: ");
        scanf("%d\n", &opcion);

        switch (opcion)
        {
        case 0:
            //Lista Sequencial
            main_ListSeq();
            break;

        case 1:
            //Lista Sequencial Ordenada
            break;

        case 2:
            //Lista Ligada
            break;

        case 3:
            //Pilha
            break;

        case 4:
            //Fila
            break;

        case 5:
            //Deque
            break;

        case 6:
            //Arvore Binaria
            break;

        case 7:
            //Arvore Binaria de Busca
            break;

        case 8:
            //Arvore AVL
            break;

        case 9:
            //Sair
            break;

        default:
            printf("Opcao Invalida\n");
            break;
        }

    }while(opcion != 9);

    return 0;
}