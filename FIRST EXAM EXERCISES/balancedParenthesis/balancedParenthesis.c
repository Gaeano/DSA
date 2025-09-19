#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
typedef struct{
    char *string;
    int top;
}Stack;


void initStack(Stack *s);
bool checkValid(char* s);
void push(Stack* s, char x);
void pop(Stack* s);
char peek(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack* s);

void initStack(Stack *s){
    s->top = -1;
}

// bool isFull(Stack *s){
//     return s->top == MAX;
// }

bool isEmpty(Stack *s){
    return s->top == -1;
}

void push(Stack* s, char x){
    // if (!isFull(s)){
        s->top++;
        s->string[s->top] = x;
    // }
}

void pop(Stack* s){
    if(!isEmpty(s)){
        s->top--;
    }
}

char peek(Stack *s){
    return s->string[s->top];
}

bool checkValid(char* s){
    Stack* stak = malloc (sizeof(Stack));
    initStack(stak);
    int len = strlen(s);
    stak->string = malloc (len * sizeof(char));
    int i;

    for (i = 0; i < len; i++){
        char data = s[i];
        if (data == '(' || data == '{' || data == '['){
            push(stak, data);
        } else {
            if (isEmpty(stak)){
                return false;
            } 
            char dataz = peek(stak);
            if (data == ')' && dataz != '(' || data == ']' && dataz != '[' || data == '}' && dataz != '{'){
                return false;
            }
            pop(stak);
        }
    }
    bool valid = isEmpty(stak);
    free(stak->string);
    free(stak);
    return valid;
}

int main (){
    char pare[MAX];

    printf("Enter a parenthesis: ");
    scanf("%[^\n]s", pare);

    bool ans = checkValid(pare);

    if(ans){
        printf("Balanced\n");
    } else {
        printf("Not Balanced");
    }

    return 0;
}


