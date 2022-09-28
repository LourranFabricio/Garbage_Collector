#include <stdio.h>
#include <stdlib.h>



//Struct com espaço pro endereço de memória e o contador 
typedef struct Memory{
    int *pointer;
    int counter;
}memory;

memory vetor[50];

int count_memory=0;

int *malloc2(int size){
    int *address = (int*)malloc(size);
    vetor[count_memory].counter = 1;
    vetor[count_memory].pointer = address;
    count_memory++;
    return address;
}

//Os 2 parâmetros são os vetores, ou um valor nulo no segundo parâmetro
void atrib2(int *address1, int *address2){

	for(int i = 0; i < count_memory;i++){
        
        if(vetor[i].pointer == address1 && vetor[i].counter == 1 && address2 == NULL ){
            vetor[i].counter = 0;
        }

        else if(vetor[i].pointer == address1 && vetor[i].counter != 1 && address2 == NULL ){
            vetor[i].counter--;
        }

        else if(vetor[i].pointer == address1){
            vetor[i].counter--;

            if(vetor[i].counter <= 0){
                free(vetor[i].pointer);
            }
        }

        if(vetor[i].pointer == address2){
            vetor[i].counter++;
        }
        printf("\n%d\n",i);
    }
}

void dump(){

    if(count_memory == 0){
        printf("Nenhuma memória alocada\n");
    }

    for(int position = 0; position < count_memory; position++){
        
            printf("[Local de memoria: %d]",vetor[position].pointer);
            printf("[Contador: %d]\n",vetor[position].counter);
    }
}


int main(){

    dump();

    int *v = malloc2(sizeof(int));
    int *w = malloc2(sizeof(int));
    int *q = malloc2(sizeof(int));
    int *s = malloc2(sizeof(int));
    
    atrib2(v,w);
    atrib2(v,q);
    

    dump();
    

    return 0;
}
