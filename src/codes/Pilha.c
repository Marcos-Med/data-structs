#include <stdio.h>
#include "../../include/Pilha.h"

PILHA * criar_pilha(){
    PILHA * pilha = (PILHA*) malloc(sizeof(PILHA));
    pilha->topo = NULL;
    return pilha;
}

int tam_pilha(PILHA * pilha){
    NO_STACK * aux = pilha->topo;
    int tam = 0;
    while(aux != NULL){
        tam++;
        aux = aux->next;
    }
    return tam;
}

void imprimir_pilha(PILHA * pilha){
    NO_STACK * aux = pilha->topo;
    printf("PILHA: \" ");
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->next;
    }
    printf("\"\n");
}

bool is_empty_pilha(PILHA * pilha){
    if(pilha->topo == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool push_pilha(PILHA * pilha, key chave){
    NO_STACK * no = (NO_STACK*) malloc(sizeof(NO_STACK));
    no->chave = chave;
    no->next = pilha->topo;
    pilha->topo = no;
    return true;
}

bool pop_pilha(PILHA * pilha, key * chave){
    if(is_empty_pilha(pilha)){
        return false;
    }
    *chave = pilha->topo->chave;
    NO_STACK * aux = pilha->topo;
    pilha->topo = pilha->topo->next;
    free(aux);
    return true;
}


void destruir_pilha(PILHA * pilha){
    NO_STACK * aux;
    NO_STACK * atual = pilha->topo;
    while(atual != NULL){
        aux = atual;
        atual = atual->next;
        free(aux);
    }
    free(pilha);
}

void reiniciar_pilha(PILHA * pilha){
    NO_STACK * aux;
    NO_STACK  * atual = pilha->topo;
    while(atual != NULL){
        aux = atual;
        atual = atual->next;
        free(aux);
    }
    pilha->topo = NULL;
}

void main_Pilha(){
    //......
    char* input;
    key chave;
    bool flag;

    printf("--PILHA--\n");

    PILHA * pilha = criar_pilha();

    printf("Pilha criada\n");

    do{
        printf("> ");
        scanf("%s", input);
        tratar_string(input);

        if(strcmp(input, "imprimir") == 0){
            imprimir_pilha(pilha);
        }
        else if(strcmp(input, "quantidade") == 0){
            int tam = tam_pilha(pilha);
            if(tam == 0){
                printf("Nao ha elementos na pilha\n");
            }
            else if(tam == 1){
                printf("Ha 1 elemento na pilha\n");
            }
            else{
                printf("Ha %d elementos na pilha\n", tam);
            }
        }
        else if(strcmp(input, "inserir") == 0){
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d", &chave);

            flag = push_pilha(pilha, chave);

            if(!flag){
                printf("Estouro de pilha\n");
            }
            else{
                printf("Elemento inserido com sucesso\n");
            }
        }
        else if(strcmp(input, "remover") == 0){
            flag = pop_pilha(pilha, &chave);
            if(!flag){
                printf("A pilha esta vazia\n");
            }
            else{
                printf("%d\n", chave);
                printf("Elemento removido com sucesso\n");
            }
        }
        else if(strcmp(input, "reiniciar") == 0){
            reiniciar_pilha(pilha);
            printf("Pilha reiniciada com sucesso\n");
        }

    }while(strcmp(input, "sair"));

    destruir_pilha(pilha);

}
