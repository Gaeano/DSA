#include <stdio.h>
#include <stdlib.h>

#define MAX 31

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct node {
    int key;           // index in array
    int val;           // element value
    struct node* link;
} *LIST;

typedef LIST Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);

/*********************************/
/*          YOUR TASKS           */
/*********************************/
void insert(Dictionary D, int data, int index);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int hash(int elem);

int main(void) {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int returnSize;
    int* result = twoSum(nums, n, target, &returnSize);

    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    free(nums);
    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/
void insert(Dictionary D, int data, int index) {
    // TODO: Implementation here
    int hashCode = hash(data);
    LIST newNode = malloc (sizeof(struct node));
        newNode->key = index;
        newNode->val = data;
        newNode->link = NULL;

    if (D[hashCode] == NULL){
        D[hashCode] = newNode;
    } else {
        LIST trav;
        
        for (trav = D[hashCode]; trav->link != NULL; trav = trav->link){
            
        }
        trav->link = newNode;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // TODO: Implementation here
    Dictionary D;
    initDict(D);
    *returnSize = 0;
    int found = 0;
    

    for (int i = 0;i < numsSize; i++){
        int complement = target - nums[i];
        int hashCode = hash(complement);

        LIST trav;
        for (trav = D[hashCode] ; trav != NULL && found == 0; trav = trav->link){
            if (trav->val == complement){
              int* result = malloc (2 * sizeof(int));
                result[0] = trav->key;
                result[1] = i;
                *returnSize = 2;
                found = 1;
              return result;
            }
        }
            
          insert(D, nums[i], i);  


    }
    return NULL;
}

int hash(int elem) {
    // TODO: Implementation here
     int h = elem % MAX;
    return (h < 0) ? h + MAX : h;  
}