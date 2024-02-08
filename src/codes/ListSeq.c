#include <stdio.h>
#include "../../include/ListSeq.h"

LISTA_SEQ * criar_lista_seq(){
    LISTA_SEQ * lista = (LISTA_SEQ *) malloc(sizeof(LISTA_SEQ));
    lista->nroElem = 0;
    return lista;
}

int tam_lista_seq(LISTA_SEQ * lista){
    return lista->nroElem;
}

void imprimir_lista_seq(LISTA_SEQ * lista){
    printf("LISTA: \" ");
    int tam = tam_lista_seq(lista);
    for(int i = 0; i < tam; i++){
        printf("%d ", lista->array[i].chave);
    }
    printf(" \"\n");
}

int busca_list_seq(LISTA_SEQ * lista, key chave_reg){
    int tam = tam_lista_seq(lista);
    int i = 0;
    lista->array[tam].chave = chave_reg;
    while(lista->array[i].chave != chave_reg){
        i++;
    }
    if(i == tam){
        return -1;//Não existe
    }
    else{
        return i;//Existe
    }
}

bool inserir_lista_seq(LISTA_SEQ * lista, key chave_reg, int pos){
    if(tam_lista_seq(lista) >= MAX || (pos < 0 || pos > tam_lista_seq(lista))){
        return false;
    }
    if(busca_list_seq(lista, chave_reg) != -1){
        return false;
    }

    int tam = tam_lista_seq(lista);

    for(int i = tam; i > pos; i--){
        lista->array[i].chave = lista->array[i-1].chave;
    }

    lista->array[pos].chave = chave_reg;
    lista->nroElem++;
    return true;
}

bool remover_lista_seq(LISTA_SEQ * lista, key chave_reg){
    int pos = busca_list_seq(lista, chave_reg);
    int tam = tam_lista_seq(lista);
    if(pos == -1){
        return false;
    }
    for(int i = pos; i < tam - 1; i++){
        lista->array[i].chave = lista->array[i + 1].chave;
    }
    lista->nroElem--;
    return true;
}

void reiniciar_lista_seq(LISTA_SEQ * lista){
    lista->nroElem = 0;
}

void main_ListSeq(){
    //......
    char* input;
    key chave;
    int pos;
    bool flag;

    printf("--LISTA SEQUENCIAL--\n");

    LISTA_SEQ * lista = criar_lista_seq();

    printf("Lista criada\n");

    do{
        printf("> ");
        scanf("%s", input);
        tratar_string(input);

        if(strcmp(input, "busca") == 0){
            printf("Digite o elemento que deseja buscar: ");
            scanf("%d", &chave);
            pos = busca_list_seq(lista, chave);
            if(pos == -1){
                printf("Elemento de chave %d nao existe na lista\n", chave);
            }
            else{
                printf("Elemento de chave %d existe na lista e esta na posicao %d\n", chave, pos);
            }
        }
        else if(strcmp(input, "imprimir") == 0){
            imprimir_lista_seq(lista);
        }
        else if(strcmp(input, "quantidade") == 0){
            if(tam_lista_seq(lista) == 0){
                printf("Nao ha elementos na lista\n");
            }
            else if(tam_lista_seq(lista) == 1){
                printf("Ha 1 elemento na lista\n");
            }
            else{
                printf("Ha %d elementos na lista\n", tam_lista_seq(lista));
            }
        }
        else if(strcmp(input, "inserir") == 0){
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d", &chave);
            printf("Digite a posicao da lista em que deseja inserir: ");
            scanf("%d", &pos);
            
            flag = inserir_lista_seq(lista, chave, pos);

            if(!flag){
                if(busca_list_seq(lista, chave) != -1){
                    printf("Elemento ja existe na lista\n");
                }
                if(tam_lista_seq(lista) >= MAX){
                    printf("A Lista esta cheia\n");
                }
                if(pos < 0 || pos > tam_lista_seq(lista)){
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
            flag = remover_lista_seq(lista, chave);
            if(!flag){
                printf("Nao ha este elemento na lista\n");
            }
            else{
                printf("Elemento removido com sucesso\n");
            }
        }
        else if(strcmp(input, "reiniciar") == 0){
            reiniciar_lista_seq(lista);
            printf("Lista reiniciada com sucesso\n");
        }

    }while(strcmp(input, "sair"));
}