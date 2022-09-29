#include <stdio.h>
#include "contref.h"

int main(){
    dump();
    printf("\n-------------------------------------\n");
    int *v = malloc2(sizeof(int));
    int *s = malloc2(sizeof(int));
    int *w = malloc2(sizeof(int));
    dump();
    atrib2(v,s);
    atrib2(w,s);
    printf("\n-------------------------------------\n");
    
    dump();
    


    return 0;
}
