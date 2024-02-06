#include <stdio.h>

#include "../../include/ListaCircular.h"
#include "../../include/functions_aux.h"

LISTA_CIRCULAR * criar_lista_circular(){
    LISTA_CIRCULAR * lista = (LISTA_CIRCULAR*) malloc(sizeof(LISTA_CIRCULAR));
    ELEMENTO * cabeca = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    lista->head = cabeca;
    lista->head->no_prox = lista->head;
    return lista;
}

int tam_lista_circular(LISTA_CIRCULAR * lista){
    ELEMENTO * aux = lista->head->no_prox;
    int tam = 0;
    while(aux != lista->head){
        tam++;
        aux = aux->no_prox;
    }
    return tam;
}

void imprimir_lista_circular(LISTA_CIRCULAR * lista){
    ELEMENTO * aux = lista->head->no_prox;
    printf("LISTA: \" ");
    while(aux != lista->head){
        printf("%d ", aux->chave);
        aux = aux->no_prox;
    }
    printf("\"\n");
}

ELEMENTO * busca_lista_circular(LISTA_CIRCULAR * lista, key_cicle chave){
    lista->head->chave = chave;
    ELEMENTO * aux = lista->head->no_prox;
    while(aux->chave < chave){
        aux = aux->no_prox;
    }
    if(aux != lista->head && aux->chave == chave){
        return aux;
    }
    else{
        return NULL;
    }
}

bool inserir_lista_circular(LISTA_CIRCULAR * lista, key_cicle chave){
    ELEMENTO * aux = busca_lista_circular(lista, chave);
    if(aux != NULL){
        return false;
    }
    aux = lista->head->no_prox;
    ELEMENTO * ant = lista->head;
    while(aux->chave < chave){
        ant = aux;
        aux = aux->no_prox;
    }
    ELEMENTO * no = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    no->chave = chave;
    no->no_prox = ant->no_prox;
    ant->no_prox = no;
    return true;
}

bool remover_lista_circular(LISTA_CIRCULAR * lista, key_cicle chave){
    ELEMENTO * aux = busca_lista_circular(lista, chave);
    if(aux == NULL){
        return false;
    }
    ELEMENTO * ant = lista->head;
    while(ant->no_prox != aux){
        ant = ant->no_prox;
    }
    ant->no_prox = aux->no_prox;
    free(aux);
    return true;
}

void destruir_lista_circular(LISTA_CIRCULAR * lista){
    ELEMENTO * no = lista->head->no_prox;
    ELEMENTO * dell;
    while(no != lista->head){
        dell = no;
        no = no->no_prox;
        free(dell);
    }
    free(no);
    free(lista);
}

void reiniciar_lista_circular(LISTA_CIRCULAR * lista){
    ELEMENTO * no = lista->head->no_prox;
    ELEMENTO * dell;
    while(no != lista->head){
        dell = no;
        no = no->no_prox;
        free(dell);
    }
    no->no_prox = no;
}

void main_ListaCircular(){
    //......
    char* input;
    key_cicle chave;
    ELEMENTO * pos;
    bool flag;
    printf("--LISTA LIGADA CIRCULAR COM CABECA E ORDENADA--\n");

    LISTA_CIRCULAR * lista = criar_lista_circular();

    printf("Lista criada\n");

    do{
        printf("> ");
        scanf("%s", input);
        tratar_string(input);

        if(strcmp(input, "busca") == 0){
            printf("Digite o elemento que deseja buscar: ");
            scanf("%d", &chave);
            if(pos == NULL){
                printf("Elemento de chave %d nao existe na lista\n", chave);
            }
            else{
                printf("Elemento de chave %d existe na lista\n", chave);
            }            
        }
        else if(strcmp(input, "imprimir") == 0){
            imprimir_lista_circular(lista);
        }
        else if(strcmp(input, "quantidade") == 0){
            int tam = tam_lista_circular(lista);
            if(tam == 0){
                printf("Nao ha elementos na lista\n");
            }
            else if(tam == 1){
                printf("Ha 1 elemento na lista\n");
            }
            else{
                printf("Ha %d elementos na lista\n", tam);
            }
        }
        else if(strcmp(input, "inserir") == 0){
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d", &chave);
            
            flag = inserir_lista_circular(lista, chave);
            if(!flag){
                printf("Elemento ja existe na lista\n");
            }
            else{
                printf("Elemento inserido com sucesso\n");
            }
        }
        else if(strcmp(input, "remover") == 0){
            printf("Digite o elemento que deseja retirar: ");
            scanf("%d", &chave);
            flag = remover_lista_circular(lista, chave);
            if(!flag){
                printf("Nao ha este elemento na lista\n");
            }
            else{
                printf("Elemento removido com sucesso\n");
            }
        }
        else if(strcmp(input, "reiniciar") == 0){
            reiniciar_lista_circular(lista);
            printf("Lista reiniciada com sucesso\n");
        }
    }while(strcmp(input, "sair"));

    destruir_lista_circular(lista);
}
