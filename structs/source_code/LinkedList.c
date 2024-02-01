#include <stdio.h>
#include "../headers/LinkedList.h"
#include "../../files_aux/functions_aux.h"

LISTA_LIGADA * criar_lista_ligada(){
    LISTA_LIGADA * lista = (LISTA_LIGADA *) malloc(sizeof(LISTA_LIGADA));
    lista->first_no = NULL;
    return lista;
}

int tam_lista_ligada(LISTA_LIGADA * lista){
    int tam = 0;
    NO_LISTA * aux = lista->first_no;
    while(aux != NULL){
        tam++;
        aux = aux->next;
    }
    return tam;
}

void imprimir_lista_ligada(LISTA_LIGADA * lista){
    printf("LISTA: \" ");
    NO_LISTA * aux = lista->first_no;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->next;
    }
    printf("\"\n");
}

NO_LISTA * busca_lista_ligada(LISTA_LIGADA * lista, key_list chave){
    NO_LISTA * aux = lista->first_no;
    while(aux != NULL){
        if(aux->chave == chave){
            return aux;
        }
        aux = aux->next;
    }

    return NULL;
}

bool inserir_lista_ligada(LISTA_LIGADA * lista, key_list chave, int pos){
    if(busca_lista_ligada(lista, chave)){
        return false;
    }
    int tam = tam_lista_ligada(lista);
    if(pos < 0 || pos > tam){
        return false;
    }
    NO_LISTA * no = (NO_LISTA *) malloc(sizeof(NO_LISTA));
    no->chave = chave;
    int id = 0;
    NO_LISTA * aux = lista->first_no;
    while(id != pos){
        aux = aux->next;
        id++;
    }
    no->next = aux->next;
    aux->next = no;
    return true;
}

bool remover_lista_ligada(LISTA_LIGADA * lista, key_list chave){
    NO_LISTA * no = busca_lista_ligada(lista, chave);
    if(!no){
        return false;
    }
    NO_LISTA * aux = lista->first_no;
    while(aux->next != no){
        aux = aux->next;
    }
    aux->next = no->next;
    free(no);
    return true;
}

void destruir_lista_ligada(LISTA_LIGADA * lista){
    NO_LISTA *no_atual = lista->first_no;
    NO_LISTA *proximo;

    while (no_atual != NULL) {
        proximo = no_atual->next;
        free(no_atual);
        no_atual = proximo;
    }

    free(lista);
    
}

void reiniciar_lista_ligada(LISTA_LIGADA * lista){
    NO_LISTA *no_atual = lista->first_no;
    NO_LISTA *proximo;

    while (no_atual != NULL) {
        proximo = no_atual->next;
        free(no_atual);
        no_atual = proximo;
    }

    lista->first_no = NULL;
}

void main_ListaLigada(){
    //......
    char* input;
    key_list chave;
    int pos;
    bool flag;
    NO_LISTA * no;

    printf("--LISTA LIGADA--\n");

    LISTA_LIGADA * lista = criar_lista_ligada();

    printf("Lista criada\n");

    do{
        printf("> ");
        scanf("%s", input);
        tratar_string(input);

        if(strcmp(input, "busca") == 0){
            printf("Digite o elemento que deseja buscar: ");
            scanf("%d", &chave);
            no = busca_lista_ligada(lista, chave);
            if(!no){
                printf("Elemento de chave %d nao existe na lista\n", chave);
            }
            else{
                printf("Elemento de chave %d existe na lista\n", chave);
            }
        }
        else if(strcmp(input, "imprimir") == 0){
            imprimir_lista_ligada(lista);
        }
        else if(strcmp(input, "quantidade") == 0){
            int tam = tam_lista_ligada(lista);
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
            printf("Digite a posicao da lista em que deseja inserir: ");
            scanf("%d", &pos);

            flag = inserir_lista_ligada(lista, chave, pos);

            if(!flag){
                if(busca_lista_ligada(lista, chave)){
                    printf("Elemento ja existe na lista\n");
                }
                if(pos < 0 || pos > tam_lista_ligada(lista)){
                    printf("Posicao invalida\n");
                }
            }
            else{
                printf("Elemento inserido com sucesso\n");
            }
        }
        else if(strcmp(input, "remover") == 0){
            printf("Digite o elemento que deseja retirar: ");
            scanf("%d", &chave);
            flag = remover_lista_ligada(lista, chave);
            if(!flag){
                printf("Nao ha este elemento na lista\n");
            }
            else {
                printf("Elemento removido com sucesso\n");
            }
        }
        else if(strcmp(input, "reiniciar") == 0){
            reiniciar_lista_ligada(lista);
            printf("Lista reiniciada com sucesso\n");
        }
    }
    while(strcmp(input, "sair"));

    destruir_lista_ligada(lista);
}