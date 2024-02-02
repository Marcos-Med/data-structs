#include <stdio.h>

#include "../include/functions_aux.h"
#include "../include/ArvoreBin.h"
#include "../include/ArvoreBinSearch.h"
#include "../include/AVL.h"
#include "../include/Deque.h"
#include "../include/Fila.h"
#include "../include/LinkedList.h"
#include "../include/ListSeq.h"
#include "../include/ListSeqOrd.h"
#include "../include/Pilha.h"

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