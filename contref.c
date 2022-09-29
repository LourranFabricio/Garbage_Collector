#include "contref.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct memory{
    int counter;
    int *address;
    struct memory *prox;
}memory;

memory *list = NULL;


void *malloc2(int size){

    
    memory *aux = malloc(sizeof(memory)); //Aloca a memória do tamanho do struct
    memory *aux2 = malloc(sizeof(memory)); //Auxiliar para inserir no fim
    aux->address = (int*)malloc(size); //O endereço do struct recebe o malloc solicitado na main
    aux->counter = 1; //A cada malloc feito, aquele endereço terá 1 no contador de referência
    aux->prox = NULL;

    if(list != NULL){
     aux->prox = list;
    }

    list = aux;
    //printf("Ponteiro:%d\n", aux->address);
    return list->address; //Retorna o endereço do malloc
}

void dump(){
    memory *aux = list;

    if(list == NULL){ //Se a lista for vazia a memória não foi alocada
        printf("Nenhuma memória alocada\n");
    }

    while(aux!= NULL){ //Enquanto a lista não for vazia, printa  a memória alocada
        printf("{Endereço: %p | contador: %d}\n",aux->address,aux->counter);
        aux = aux->prox;
    }
}

memory* elementRemove(memory *list, int *address_){
    memory *aux;

    if(list==NULL){
        return list;
    }

    else if(list->address != address_){ //Se o endereço que for dado free for diferente 
                                       //do que está no struct, entra em recursão
        list->prox = elementRemove(list->prox,address_);
        return list;
    }

    else{
        aux = list;
        list = list->prox;
        free(aux);
        list= elementRemove(list,address_);
        return list;
    }
}

void atrib2(int *address1, int *address2){
    memory *aux = list;

    while(aux != NULL){

        if(aux->address == address1){ //Vai decrementar o contador do primeiro ponteiro passado
            aux->counter -= 1;
        
            if(aux->counter == 0){ //Se o contador for igual a 0, será dado free na alocação
                list = elementRemove(list,address1);
            }
            
        }

        if(aux->address == address2){ //No segundo ponteiro será incrementado 1 no contador
            aux->counter += 1;
        }
        aux = aux->prox; //Passa para o próximo nó
    }

}
