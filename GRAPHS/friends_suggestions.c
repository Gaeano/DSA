#include <stdio.h>

#define MAX 5

// 1 means friends, 0 means not friends
int graph[MAX][MAX] = {
    {0, 1, 0, 0, 1}, // Person 0 is friends with 1 and 4
    {1, 0, 1, 0, 0}, // Person 1 is friends with 0 and 2
    {0, 1, 0, 1, 0}, // Person 2 is friends with 1 and 3
    {0, 0, 1, 0, 1}, // Person 3 is friends with 2 and 4
    {1, 0, 0, 1, 0}  // Person 4 is friends with 0 and 3
};

void suggestFriends(int personID) {
    printf("Suggested friends for Person %d: ", personID);
    
    // TODO: Iterate through all users
    // Hint: Find users who are connected to 'personID's' friends
    // but are NOT already friends with 'personID' (and are not 'personID' themselves).
    
    int foundSuggestion = 0;
    int i, j;
    
    for (i = 0; i < MAX; i++){
        if (i != personID && graph[i][personID] == 1){
            for (j = 0; j < MAX ; j++){
                if ( j != personID && graph[j][i] == 1 && graph[j][personID] == 0 ){
                    printf("%d ", j);
                    foundSuggestion = 1;
                }
            }
        }
    }
    
    // YOUR CODE HERE
    // Loop i from 0 to MAX
    //    If i is a direct friend of personID...
    //       Loop j from 0 to MAX
    //          If j is friend of i...
    //             AND j is NOT friend of personID...
    //             AND j is NOT personID...
    //                 Print j
    
    if (!foundSuggestion) {
        printf("None");
    }
    printf("\n");
}

int main() {
    suggestFriends(0); // Expected: 2, 3
    suggestFriends(1); // Expected: 3, 4
    return 0;
}

