#include <stdio.h>
#include <stdlib.h>


#define MAX 10
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


typedef struct{
    Node* arr[10];
    int top;
}Stack;

void initS(Stack * s){
    s->top = -1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

int isFull(Stack* s){
    return s->top == MAX;
}

void push(Stack* s, Node* data){
    if (!isFull(s)){
        s->arr[s->top+1] = data;
        s->top++;
    }
}

Node* pop(Stack* s){
    Node* retVal;
    
    if (!isEmpty(s)){
        retVal = s->arr[s->top];
        s->top--;
        return retVal;
    }
}



Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// TODO: Implement this function
int kthSmallest(Node* root, int k) {
    // Your code here
    int i = 0;
    if (root == NULL){
        return -1;
    }
    
    int arr[10];
    int count = 0;
    Stack s;
    initS(&s);
    Node* temp = root;
    while(temp != NULL || !isEmpty(&s)){
        while(temp != NULL){
            push(&s, temp);
            temp = temp->left;
        }
        
        temp = pop(&s);
        arr[count] = temp->data;
        // printf("adding %d to count :%d\n", temp->data, count);
        count++;
        temp = temp->right;
    }
    
    int min = arr[k - 1];
    
    
    return min;
    
}

int main() {
    // Test case: BST with values [3,1,4,null,2]
    //       3
    //      / \
    //     1   4
    //      \
    //       2
    
    //1 2 3 4
    Node* root = createNode(3);
    root->left = createNode(1);
    root->right = createNode(4);
    root->left->right = createNode(2);
    
    printf("2nd smallest: %d\n", kthSmallest(root, 2));
    printf("3rd smallest: %d\n", kthSmallest(root, 3));
    
    return 0;
}