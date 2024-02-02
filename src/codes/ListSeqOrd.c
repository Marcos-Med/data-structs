#include <stdio.h>
#include "../../include/ListSeqOrd.h"
#include "../../include/functions_aux.h"

LISTA_SEQ_ORD * cria_lista_seq_ord(){
    LISTA_SEQ_ORD * lista = (LISTA_SEQ_ORD*) malloc(sizeof(LISTA_SEQ_ORD));
    lista->nroElem = 0;
    return lista;
}

int tam_lista_seq_ord(LISTA_SEQ_ORD * lista){
    return lista->nroElem;
}

void imprimir_lista_seq_ord(LISTA_SEQ_ORD * lista){
    int tam = tam_lista_seq_ord(lista);
    printf("Lista: \" ");
    for(int i = 0; i < tam; i++){
        printf("%d ", lista->array[i].chave);
    }
    printf("\"\n");
}

int busca_list_seq_bin(LISTA_SEQ_ORD * lista, key_ord chave_reg){
    return busca_rec(lista, chave_reg, 0, tam_lista_seq_ord(lista) - 1);
}

int busca_rec(LISTA_SEQ_ORD * lista, key_ord chave_reg, int init, int end){
    int meio = (init + end)/2;
    if(init <= end){
        if(lista->array[meio].chave == chave_reg){
            return meio;
        }
        else if(lista->array[meio].chave > chave_reg){
            return busca_rec(lista, chave_reg, init, meio - 1);
        }
        else{
            return busca_rec(lista, chave_reg, meio + 1, end);
        }
    }

    return -1;
}

void reiniciar_lista_seq_ord(LISTA_SEQ_ORD * lista){
    lista->nroElem = 0;
}

bool inserir_lista_seq_ord(LISTA_SEQ_ORD * lista, key_ord chave_reg){
    int flag = busca_list_seq_bin(lista, chave_reg);
    if(flag != -1 || tam_lista_seq_ord(lista) == MAX){
        return false;
    }
    int tam = tam_lista_seq_ord(lista);
    int i;
    for(i = tam - 1; lista->array[i].chave > chave_reg; i--){
        lista->array[i + 1].chave = lista->array[i].chave;
    }
    lista->array[i + 1].chave = chave_reg;
    return true;
}

bool remover_lista_seq_ord(LISTA_SEQ_ORD * lista, key_ord chave_reg){
    int flag = busca_list_seq_bin(lista, chave_reg);
    if(flag == -1){
        return false;
    }
    int tam = tam_lista_seq_ord(lista);
    for(int i = flag; i < tam - 1; i++){
        lista->array[i].chave = lista->array[i + 1].chave;
    }
    lista->nroElem--;
    return true;
}

void main_ListSeqOrd(){
    //.....
    char* input;
    key_ord chave;
    int pos;
    bool flag;

    printf("--LISTA SEQUENCIAL ORDENADA--\n");

    LISTA_SEQ_ORD * lista = cria_lista_seq_ord();

    printf("Lista criada\n");

    do{
        printf("> ");
        scanf("%s", input);
        tratar_string(input);

        if(strcmp(input, "busca") == 0){
            printf("Digite o elemento que deseja buscar: ");
            scanf("%d", &chave);
            pos = busca_list_seq_bin(lista, chave);
            if(pos == -1){
                printf("Elemento de chave %d nao existe na lista\n", chave);
            }
            else{
                printf("Elemento de chave %d existe na lista e esta na posicao %d", chave, pos);
            }
        }
        else if(strcmp(input, "imprimir") == 0){
            imprimir_lista_seq_ord(lista);
        }
        else if(strcmp(input, "quantidade") == 0){
            int tam = tam_lista_seq_ord(lista);
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
            flag = inserir_lista_seq_ord(lista, chave);
            if(!flag){
                if(busca_list_seq_bin(lista, chave) != -1){
                    printf("Elemento ja existe na lista\n");
                }
                if(tam_lista_seq_ord(lista) == MAX){
                    printf("A Lista esta cheia\n");
                }
            }
            else{
                printf("Elemento inserido com sucesso\n");
            }
        }
        else if(strcmp(input, "remover") == 0){
            printf("Digite o elemento que deseja retirar: ");
            scanf("%d", &chave);
            flag = remover_lista_seq_ord(lista, chave);
            if(!flag){
                printf("Nao ha este elemento na lista\n");
            }
            else{
                printf("Elemento removido com sucesso\n");
            }
        }
        else if(strcmp(input, "reiniciar") == 0){
            reiniciar_lista_seq_ord(lista);
            printf("Lista reiniciada com sucesso\n");
        }
        

    }while(strcmp(input, "sair"));
}