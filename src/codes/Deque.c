#include <stdio.h>
#include "../../include/Deque.h"

void opcoes_deque(){
    printf("1- No inicio do deque (Inserir ou Remover)\n");
    printf("2- No fim do deque(Inserir ou Remover)\n");
}

DEQUE * criar_deque(){
    DEQUE * deque = (DEQUE *) malloc(sizeof(DEQUE));
    NO_DEQUE * cabeca = (NO_DEQUE *) malloc(sizeof(NO_DEQUE));
    deque->head = cabeca;
    deque->head->ant = deque->head;
    deque->head->prox = deque->head;
    return deque;
}

int tam_deque(DEQUE * deque){
    NO_DEQUE * no = deque->head->prox;
    int tam = 0;
    while(no != deque->head){
        tam++;
        no = no->prox;
    }
    return tam;
}

void imprimir_deque(DEQUE * deque){
    NO_DEQUE * no = deque->head->prox;
    printf("DEQUE: \" ");
    while(no != deque->head){
        printf("%d ", no->chave);
    }
    printf("\"\n");
}

bool inserir_deque_Ini(DEQUE * deque, key chave){
    NO_DEQUE * no = (NO_DEQUE*) malloc(sizeof(NO_DEQUE));
    no->chave = chave;
    no->prox = deque->head->prox;
    no->ant = deque->head;
    deque->head->prox->ant = no;
    deque->head->prox = no;
    return true;
}

bool inserir_deque_Fim(DEQUE * deque, key chave){
    NO_DEQUE * no = (NO_DEQUE*) malloc(sizeof(NO_DEQUE));
    no->chave = chave;
    no->prox = deque->head;
    no->ant = deque->head->ant;
    deque->head->ant->prox = no;
    deque->head->ant = no;
    return true;
}

bool remover_deque_Ini(DEQUE * deque, key * chave){
    if(deque->head->prox == deque->head){
        return false;
    }
    NO_DEQUE * apagar = deque->head->prox;
    deque->head->prox = deque->head->prox->prox;
    deque->head->prox->ant = deque->head;
    free(apagar);
    return true;
}

bool remover_deque_Fim(DEQUE * deque, key * chave){
    if(deque->head->ant = deque->head){
        return false;
    }
    NO_DEQUE * apagar = deque->head->ant;
    deque->head->ant = deque->head->ant->ant;
    deque->head->ant->prox = deque->head;
    free(apagar);
    return true;
}

void destruir_deque(DEQUE * deque){
    NO_DEQUE * no;
    NO_DEQUE * atual = deque->head->ant;
    while(atual != deque->head){
        no = atual;
        atual = atual->ant;
        free(no);
    }
    free(atual);
    free(deque);
}

void reiniciar_deque(DEQUE * deque){
    NO_DEQUE * no;
    NO_DEQUE * atual = deque->head->ant;
    while(atual != deque->head){
        no = atual;
        atual = atual->ant;
        free(no);
    }
    deque->head->ant = deque->head;
    deque->head->prox = deque->head;
}

void main_Deque(){
    //.....
    char* input;
    key chave;
    bool flag;
    int opc;
    
    printf("--DEQUE--\n");

    DEQUE * deque = criar_deque();

    printf("Deque criado\n");

    do{
        printf("> ");
        scanf("%s", input);
        tratar_string(input);

        if(strcmp(input, "imprimir") == 0){
            imprimir_deque(deque);
        }
        else if(strcmp(input, "quantidade") == 0){
            int tam = tam_deque(deque);
            if(tam == 0){
                printf("Nao ha elementos no deque\n");
            }
            else if(tam == 1){
                printf("Ha 1 elemento no deque\n");
            }
            else{
                printf("Ha %d elementos no deque\n", tam);
            }
        }
        else if(strcmp(input, "inserir") == 0){
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d", &chave);
            opcoes_deque();
            printf("Digite alguma opcao: ");
            scanf("%d", &opc);
            if(opc != 1 && opc != 2){
                printf("Opcao invalida\n");
            }
            else{
                if(opc == 1){
                    inserir_deque_Ini(deque, chave);
                }
                else{
                    inserir_deque_Fim(deque, chave);
                }
                printf("Elemento inserido com sucesso\n");
            }
            
        }
        else if(strcmp(input, "remover") == 0){
            opcoes_deque();
            printf("Digite alguma opcao: ");
            scanf("%d", &opc);
            if(opc != 1 && opc != 2){
                printf("Opcao invalida\n");
            }
            else{
                if(opc == 1){
                   flag = remover_deque_Ini(deque, &chave);
                }
                else{
                   flag = remover_deque_Fim(deque, &chave);
                }
                
                if(!flag){
                    printf("O deque esta vazio\n");
                }
                else{
                    printf("%d\n", chave);
                    printf("Elemento removido com sucesso\n");
                }
            }
        }
        else if(strcmp(input, "reiniciar") == 0){
            reiniciar_deque(deque);
            printf("Deque reiniciado com sucesso\n");
        }
    }while(strcmp(input, "sair"));

    destruir_deque(deque);
}