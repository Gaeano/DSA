#include <stdio.h>

int main (){
    
    short int x = 20;
    
    int masked;
    int gap;
    for (masked = 1<<(sizeof(x)*8-1), gap = 1; masked > 0; masked>>=1, gap++){
        printf("%d", (x & masked) ? 1 :0);
        if (gap%4 == 0 && gap != 0){
            printf(" ");
        }
    }

    
    printf("\n");
    return 0;
}