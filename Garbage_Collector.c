#include <stdio.h>
#include <stdlib.h>


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
    printf("%d\n",address);
    return address;
}

void atrib2(int *address1, int *address2){
	for(int i = 0; i < 50;i++){
        
        if(vetor[i].pointer==address1 && vetor[i].counter==1 && address2==NULL ){
            vetor[i].counter=0;
        }
        else if(vetor[i].pointer==address1 && vetor[i].counter!=1 && address2==NULL ){
            vetor[i].counter--;
        }

        else if(vetor[i].pointer==address1){
            vetor[i].counter--;
            if(vetor[i].counter<=0){
                free(vetor[i].pointer);
            }
        }

        if(vetor[i].pointer==address2){
            vetor[i].counter++;
        }
    }
}

void dump(){

    if(vetor==NULL){
        printf("Nenhuma memória alocada");
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
    atrib2(v,w);
    dump();
    

    return 0;
}
