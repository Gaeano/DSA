
#include <stdio.h>
#include <stdlib.h>

// -------------------- NODE STRUCT --------------------
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// -------------------- FUNCTION PROTOTYPES --------------------
Node* createNode(int value);

void preorderRec(Node *root);
void inorderRec(Node *root);
void postorderRec(Node *root);

void preorderIter(Node *root);   // requires stack
void inorderIter(Node *root);    // requires stack
void postorderIter(Node *root);

void levelOrder(Node *root);     // requires queue

// Stack and queue structures will be provided below
// -----------------------------------------------------------


// -------------------- STACK FOR ITERATIVE DFS --------------------
typedef struct {
    Node* items[50];
    int top;
} Stack;

void initStack(Stack *s);
int isEmptyStack(Stack *s);
void push(Stack *s, Node *n);
Node* pop(Stack *s);


// -------------------- QUEUE FOR LEVEL ORDER --------------------
typedef struct {
    Node* items[50];
    int front, rear;
} Queue;

void initQueue(Queue *q);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, Node *n);
Node* dequeue(Queue *q);


// -------------------- MAIN FUNCTION --------------------
int main() {
    // Build the given tree manually
    Node *root = createNode(1);
    root->left = createNode(7);
    root->right = createNode(9);

    root->left->left = createNode(2);
    root->left->right = createNode(6);

    root->left->right->left = createNode(5);
    root->left->right->right = createNode(11);

    root->right->right = createNode(10);
    root->right->right->left = createNode(8);

    // -------------------- CALL YOUR TRAVERSALS --------------------
    printf("Preorder (Recursive): ");
    preorderRec(root);
    
    printf("\nPreorder (Iterative): ");
    preorderIter(root);
    printf("\n");

    printf("\nInorder (Recursive): ");
    inorderRec(root);
    
    printf("\nInorder (Iterative): ");
    inorderIter(root);
    printf("\n");

    printf("\nPostorder (Recursive): ");
    postorderRec(root);
    
    printf("\nPostorder (Iterative): ");
    postorderIter(root);
    printf("\n");

    printf("\nLevel-order: ");
    levelOrder(root);

    return 0;
}


// -------------------- TODO: FUNCTION DEFINITIONS --------------------

// 1. createNode()
// Create a new node with the given value.
// Set left and right pointers to NULL.
Node* createNode(int value) {
    Node* newNode = malloc (sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;


    return newNode;

    // TODO
}


// 2. preorderRec()
// Print: root → left → right
void preorderRec(Node *root) {
    // TODO

    if (root == NULL){
        return;
    }

    printf("%d ", root->data);
    preorderRec(root->left);
    preorderRec(root->right);
}


// 3. inorderRec()
// Print: left → root → right
void inorderRec(Node *root) {
    // TODO
    if (root == NULL){
        return;
    }

    inorderRec(root->left);
    printf("%d ", root->data);
    inorderRec(root->right);
}


// 4. postorderRec()
// Print: left → right → root
void postorderRec(Node *root) {
    // TODO
    if (root == NULL){
        return;
    }

    postorderRec(root->left);
    postorderRec(root->right);
    printf("%d ", root->data);
}


// 5. Stack functions
void initStack(Stack *s) {
    // TODO
    s->top = 0;
}

int isEmptyStack(Stack *s) {
    // TODO
    return (s->top == 0) ? 1 : 0;
}

void push(Stack *s, Node *n) {
    // TODO
    if (s->top < 50){
        s->items[s->top] = n;
        s->top++;
    }
}

Node* pop(Stack *s) {
    // TODO
    Node* toReturn;
    if (!isEmptyStack(s)){
        toReturn = s->items[s->top-1];
        s->top--;
    }
    return toReturn;
}


// 6. Queue functions
void initQueue(Queue *q) {
    // TODO
    q->front = 0;
    q->rear = 0;
}

int isEmptyQueue(Queue *q) {
    // TODO
    return(q->rear == q->front) ? 1 : 0;
}

void enqueue(Queue *q, Node *n) {
    // TODO
    if (((q->rear + 1) % 50) != q->front){
        q->items[q->rear] = n;
        q->rear = (q->rear + 1) % 50;
    }
}

Node* dequeue(Queue *q) {
    // TODO
    Node * toReturn;
    if (!isEmptyQueue(q)){
        if (q->rear == q->front){
            toReturn = q->items[q->front];
            q->front = 0;
            q->rear = 0;
        } else {
            toReturn = q->items[q->front];
            q->front = (q->front + 1) % 50;
        }
        
    }

    return toReturn;
}


// 7. preorderIter()
// Use stack; push right child first.
void preorderIter(Node *root) {
    Stack s;
    initStack(&s);

    push(&s, root);

    while (!isEmptyStack(&s)){
        Node* current = pop(&s);
        printf("%d ", current->data);

        if (current->right != NULL){
            push(&s, current->right);
        }

        if (current->left != NULL){
            push(&s, current->left);
        }
    }

    // TODO
}


// 8. inorderIter()
// Use stack; simulate leftmost descent.
void inorderIter(Node *root) {
    Stack s;
    Node* temp = root;
    initStack(&s);
    while (temp != NULL || !isEmptyStack(&s)){
        while (temp !=NULL){
            push(&s, temp);
            temp = temp->left;
        }

        temp = pop(&s);
        printf("%d ", temp->data);
        temp = temp->right;
    }
    // TODO
}

// 9. postorderIter()
// Use 2 stacks
void postorderIter(Node *root) {
    Stack s1, s2;
    initStack(&s1);
    initStack(&s2);
    push(&s1, root);

    while (!isEmptyStack(&s1)){
        Node* current = pop(&s1);
        push(&s2, current);

        if (current->left != NULL){
            push(&s1, current->left);
        }

        if (current->right != NULL){
            push(&s1, current->right);
        }
    }


    while (!isEmptyStack(&s2)){
        Node* current = pop(&s2);

        printf("%d ", current->data);
    }
    // TODO
}


// 10. levelOrder()
// Use queue; same as BFS.
void levelOrder(Node *root) {
    // TODO
    if (root == NULL){
        return;
    }
    Queue q;
    
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmptyQueue(&q)){
        Node * current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left != NULL){
            enqueue(&q, current->left);
        }

        if (current->right != NULL){
            enqueue(&q, current->right);
        }
    }
    

}





