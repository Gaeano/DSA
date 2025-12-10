#include <stdio.h>

#define MAX 5

// 1 means edge exists, 0 means none
int graph[MAX][MAX] = {
    {0, 1, 1, 0, 1}, // Person 0: 3 friends
    {1, 0, 1, 0, 0}, // Person 1: 2 friends
    {1, 1, 0, 1, 0}, // Person 2: 3 friends
    {0, 0, 1, 0, 1}, // Person 3: 2 friends
    {1, 0, 0, 1, 0}  // Person 4: 2 friends
};

void findMostPopular() {
    int maxFriends = -1;
    int popularPerson = -1;
    int count = 0;
    
    int i, j;
    
    for (i = 0; i < MAX; i++){
        for (j < 0; j < MAX; j++){
            if (graph[i][j] == 1){
                count++;
                if (count > maxFriends){
                    maxFriends = count;
                    popularPerson = i;
                }
            }
        }
    }

    // YOUR CODE HERE
    // 1. Iterate through each person
    // 2. Count their connections (degree)
    // 3. Keep track of the person with the highest count found so far

    printf("Most Popular: Person %d with %d friends\n", popularPerson, maxFriends);
}

int main() {
    findMostPopular(); 
    // Expected: Person 0 (Since 0 and 2 are tied at 3, but 0 is smaller)
    return 0;
}

