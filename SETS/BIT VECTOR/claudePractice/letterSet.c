#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void addElement(int A[], char elem);

void addElement(int A[], char elem){


    int index = toupper(elem) - 'A';

    if (index <= 0){
        A[index] = 1;
    }

}


