    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include "STUDTYPE.h"
    #ifndef STACK_H
    #define STACK_H
    #define MAX 10



    //array
    typedef struct stack{
        StudPtr arr[MAX];
        int top;
    }stackArr;
    //linked list
    typedef struct Node{
        StudPtr data;
        struct Node* next;
    }Node;

    typedef struct stackList{
        Node* head;
        int size;
    }stackList;

    typedef struct{
        stackArr* SA;
        stackList* SL;
    }Stack;

    void initStack(Stack **s){
        *s = (Stack*) malloc (sizeof(Stack));
        if(*s == NULL){
            printf("memory alloc failed");
            exit(1);
        } else {
            (*s)->SA = (stackArr*) malloc (sizeof(stackArr));
            (*s)->SL = (stackList*) malloc (sizeof(stackList));
        }


    }

    // array
    void ArrInitialize(Stack* s){
        s->SA->top = -1;
    }

    bool ArrIsFull(Stack * s){
        return s->SA->top == MAX - 1;
    }

    bool ArrIsEmpty(Stack * s){
        return s->SA->top == -1;
    }

    void ArrPush(Stack * s, StudPtr data){
        if(!ArrIsFull(s)){
            s->SA->top++;
            s->SA->arr[s->SA->top] = data;
        }
    }

    void ArrPop(Stack * s){
        if (!ArrIsEmpty(s)){
            s->SA->top--;
        }
    }

    StudPtr ArrTop (Stack * s){
        if(!ArrIsEmpty(s)){
            return s->SA->arr[s->SA->top];
        } else {
            printf("Stack is empty !");
            exit(1);
        }
        //i will fix later 
    }

    void ArrPeek(Stack * s){
        printf("Name: %s %s Course: %s Year Level: %d", s->SA->arr[s->SA->top]->name.FName, s->SA->arr[s->SA->top]->name.LName, s->SA->arr[s->SA->top]->Course, s->SA->arr[s->SA->top]->YrLvl);
    }

    //linked list
    Node* createNewNode(StudPtr data){
        Node* newNode = (Node*) malloc (sizeof(Node));
        if (newNode == NULL){
            printf("Memory alloc failed");
            exit(1); //not wat ms wants ill fix this latur
        } 
            newNode->data = data;
            newNode->next = NULL;
            return newNode;
    
    }


    void LlInitialize(Stack * s){
        s->SL->head = NULL;
        s->SL->size = 0;
    }

    bool LLisFull(Stack * s){
        return s->SL->size == MAX;
    }

    bool LLisEmpty(Stack * s){
        return s->SL->size == 0;
    }

    void LLpush(Stack * s, StudPtr data){
        if(!LLisFull(s)){
            // s->top++; //change
            Node* newNode = createNewNode(data);
            Node* head = s->SL->head;

            if (s->SL->head == NULL){
                s->SL->head = newNode;
                s->SL->size++;
            } else {
                newNode->next = s->SL->head;
                s->SL->head = newNode;
                s->SL->size++;;
            }
        }
    }

    void LLpop(Stack * s){
        if (!LLisEmpty(s)){
            Node* temp = s->SL->head;
            s->SL->head = s->SL->head->next;
        s->SL->size--;
        }
    }

    StudPtr LLtop (Stack * s){
        if(!LLisEmpty(s)){
            return s->SL->head->data;
        }
        exit(1);
    }

    void LLpeek(Stack * s){
        printf("Top: %s %s Course: %s YrLvl: %d", s->SL->head->data->name.FName, s->SL->head->data->name.LName, s->SL->head->data->Course, s->SL->head->data->YrLvl);
    }


    bool checkUniqueArrayS(Stack* s, StudPtr data){
        StudPtr topArr = ArrTop(s);
        return strcmp(topArr->name.LName, data->name.LName) != 0;
    }

    bool checkUniqueLLS(Stack* s, StudPtr data){
        StudPtr topList = LLtop(s);
        return strcmp(topList->name.LName, data->name.LName) != 0;
    }


    void pushUnique(Stack* s, StudPtr data){
            
            Stack temp, temp2;
            stackList tempList = (*s->SL);
            stackArr tempArr = (*s->SA);
            temp.SL = NULL; //for the array
            temp2.SA = NULL; //for the linked list
            for (temp.SA = &tempArr; !ArrIsEmpty(&temp) && checkUniqueArrayS(&temp, data) ; ArrPop(&temp)){}
            
            if(ArrIsEmpty(&temp)){
                ArrPush(s, data);
            } else {
                printf("%s data is not unique, could not add to Array Stack\n", data->name.LName);
            }


            for(temp2.SL = &tempList; !LLisEmpty(&temp2) && checkUniqueLLS(&temp2, data); LLpop(&temp2)){}

            if(LLisEmpty(&temp2)){
                LLpush(s, data);
            } else {
                printf("%s data is not unique, could not add to Linked List Stack\n", data->name.LName);
            }
            
    }   


    void displayStack(Stack * S){
        Stack temp, temp2;
        temp = (*S);
        temp2 = (*S);
        stackArr tempArr = (*S->SA);
        stackList tempList = (*S->SL);
        temp.SL = NULL;
        temp2.SA = NULL;
        temp.SA = &tempArr;
        temp2.SL = &tempList;
        printf("%-15s %-15s %-10s %-5s\n", "First Name", "Last Name", "Course", "Yr");
        printf("-------------------------------------------------------\n");
        printf("ARRAY STACK\n");
            while(!ArrIsEmpty(&temp)){
                StudPtr data = ArrTop(&temp);
                printf("%-15s %-15s %-10s %-5d\n",
                    data->name.FName,
                    data->name.LName,
                    data->Course,
                    data->YrLvl);
                ArrPop(&temp);
            }
            printf("-------------------------------\n");

            
        printf("Linked List STACK\n");
        for (Node* cur = temp2.SL->head; cur != NULL; cur = cur->next){
            printf("%-15s %-15s %-10s %-5d\n",
                cur->data->name.FName,
                cur->data->name.LName,
                cur->data->Course,
                cur->data->YrLvl);
        }

            printf("-------------------------------\n");
    }


    void popUnique(Stack *s, StudPtr data){
            Stack* temp = (Stack*) malloc (sizeof(Stack));
            if(temp == NULL){
                printf("memory alloc failed");
                exit(1);
            }
            temp->SA = (stackArr*) malloc (sizeof(stackArr));
            ArrInitialize(temp);

            while(!ArrIsEmpty(s) && checkUniqueArrayS(s, data)){
                StudPtr tempData = ArrTop(s);
                ArrPush(temp, tempData);
                ArrPop(s);
            }

            if(!ArrIsEmpty(s)){ //if its not empty, data is found u pop the data
                ArrPop(s);
                while( !ArrIsEmpty(temp)){
                    StudPtr giveMeBackMyData = ArrTop(temp);
                    ArrPush(s, giveMeBackMyData);
                    ArrPop(temp);
                }
                printf("data %s successfully popped in Array Stack\n", data->name.LName);
            } else { //data is not found
                printf("data does not exist in the Array Stack\n");
            }
        //linked list

            Stack *temp2 = (Stack*) malloc (sizeof(Stack));
            if(temp2 == NULL){
                printf("memory alloc failed");
                exit(1);
            }
            temp2->SL = (stackList*) malloc (sizeof(stackList));
            LlInitialize(temp2);
            while(!LLisEmpty(s)&& checkUniqueLLS(s, data)){
                StudPtr holdMyData = LLtop(s);
                LLpush(temp2, holdMyData);
                LLpop(s);
            }

            if(!LLisEmpty(s)){
                LLpop(s);

                while(!LLisEmpty(temp2)){
                    StudPtr canIHaveMyDataBack = LLtop(temp2);
                    LLpush(s, canIHaveMyDataBack);
                    LLpop(temp2);
                }
            
                printf("data %s successfully popped in Linked List Stack\n\n", data->name.LName);
            } else {
                printf("data does not exist in the Linked Stack\n");
            }

    }

    #endif  