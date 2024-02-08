#include <stdio.h>

#include "../../include/Fila.h"

FILA * criar_fila(){
    FILA * fila = (FILA *) malloc(sizeof(FILA));
    fila->inicio = NULL;
    fila->fim = NULL;
    return  fila;
}

int tam_fila(FILA * fila){
    NO_FILA * no = fila->inicio;
    int tam = 0;
    while(no != NULL){
        tam++;
        no = no->prox;
    }
    return tam;
}

void imprimir_fila(FILA * fila){
    NO_FILA * no = fila->inicio;
    printf("FILA: \" ");
    while(no != NULL){
        printf("%d ", no->chave);
        no = no->prox;
    }
    printf("\"\n");
}

bool is_empty_fila(FILA * fila){
    if(fila->inicio == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool inserir_fila(FILA * fila, key chave){
    NO_FILA * no = (NO_FILA*) malloc(sizeof(NO_FILA));
    no->chave = chave;
    no->prox = NULL;
    if(is_empty_fila(fila)){
        fila->inicio = no;
    }
    else{
        fila->fim->prox = no;
    }
    fila->fim = no;
    return true;
}

bool remover_fila(FILA * fila, key * chave){
    if(is_empty_fila(fila)){
        return false;
    }
    *chave = fila->inicio->chave;
    NO_FILA * aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if(is_empty_fila(fila)){
        fila->fim = NULL;
    }
    free(aux);
    return true;
}

void destruir_fila(FILA * fila){
    NO_FILA * atual = fila->inicio;
    NO_FILA * aux;
    while(atual != NULL){
        aux = atual;
        atual = atual->prox;
        free(aux);
    }
    free(fila);
}

void reiniciar_fila(FILA * fila){
    NO_FILA * atual = fila->inicio;
    NO_FILA * aux;
    while(atual != NULL){
        aux = atual;
        atual = atual->prox;
        free(aux);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}

void main_Fila(){
    //......
    char* input;
    key chave;
    bool flag;

    printf("--FILA--\n");

    FILA * fila = criar_fila();

    printf("Fila criada\n");

    do{
        printf("> ");
        scanf("%s", input);
        tratar_string(input);

        if(strcmp(input, "imprimir") == 0){
            imprimir_fila(fila);
        }
        else if(strcmp(input, "quantidade") == 0){
            int tam = tam_fila(fila);
            if(tam == 0){
                printf("Nao ha elementos na fila\n");
            }
            else if(tam == 1){
                printf("Ha 1 elemento na fila\n");
            }
            else{
                printf("Ha %d elementos na fila\n", tam);
            }
        }
        else if(strcmp(input, "inserir") == 0){
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d", &chave);

            flag = inserir_fila(fila, chave);

            if(!flag){
                printf("Estouro da fila\n");
            }
            else{
                printf("Elemento inserido com sucesso\n");
            }
        }
        else if(strcmp(input, "remover") == 0){
            flag = remover_fila(fila, &chave);
            if(!flag){
                printf("A fila esta vazia\n");
            }
            else{
                printf("%d\n", chave);
                printf("Elemento removido com sucesso\n");
            }
        }
        else if(strcmp(input, "reiniciar") == 0){
            reiniciar_fila(fila);
            printf("Fila reiniciada com sucesso\n");
        }
    }while(strcmp(input, "sair"));

    destruir_fila(fila);
}