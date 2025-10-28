#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20
#define PERSONS 3

typedef struct {
    int id;
    char name[100];
    int earnings; // in millions
    float rating;
} Movie;

typedef struct {
    char name[30];
    int favorites[SIZE]; // 0 - didn't like the movie, 1 - liked the movie
} Person;

// Function prototypes
void displayMovies(Movie movies[]);
void displayFriendsSummary(Person f);
void displaySet(int set[], Movie movies[]);
void unionSet(int A[], int B[], int C[]);
void intersectionSet(int A[], int B[], int C[]);
void differenceSet(int A[], int B[], int C[]);
void analysis(Movie movies[], Person friends[]);
void preferences(Movie movies[], Person friends[]);

int main(void) {
    Movie movies[SIZE] = {
        {0, "Rogue One: A Star Wars Story", 1057, 7.6},
        {1, "The Amazing Spider-Man", 758, 6.3},
        {2, "Pirates of the Caribbean: The Curse of the Black Pearl", 654, 7.2},
        {3, "Avatar: The Way of Water", 2343, 8.1},
        {4, "Justice League", 661, 6.7},
        {5, "Furious 7", 1515, 7.5},
        {6, "Wicked", 752, 8.7},
        {7, "Beauty and the Beast", 1266, 8.2},
        {8, "The Lord of the Rings: The Two Towers", 938, 9.1},
        {9, "Kung Fu Panda 2", 665, 7.9},
        {10, "The Twilight Saga: New Moon", 711, 6.0},
        {11, "Ant-Man and the Wasp", 622, 7.2},
        {12, "Forrest Gump", 678, 9.8},
        {13, "Dune: Part Two", 714, 9.3},
        {14, "2012", 791, 7.6},
        {15, "Barbie", 1447, 8.0},
        {16, "Oppenheimer", 975, 9.1},
        {17, "The Hunger Games: Mockingjay - Part 1", 758, 7.6},
        {18, "Mission: Impossible - Fallout", 824, 7.5},
        {19, "Frozen", 1286, 7.2}
    };

    Person A = {"Hank Garrison",
        {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0}};
    Person B = {"Helen Bernard",
        {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1}};
    Person C = {"Lee Potter",
        {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}};

    Person friends[PERSONS] = {A, B, C};

    printf("=== MY FRIENDS' FAVORITE FILMS! ===\n\n");
    displayMovies(movies);
    printf("\n");

    for (int i = 0; i < PERSONS; i++)
        displayFriendsSummary(friends[i]);

    printf("\n[WHAT DID THEY LIKE?]\n");
    preferences(movies, friends);

    printf("\n[FILM PREFERENCE ANALYSIS]\n");
    analysis(movies, friends);
}

// Function stubs (unchanged)
void displayMovies(Movie movies[]) {
    printf("ID | Movie Title | Earnings (M) | Rating\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d | %-55s | %4d | %.1f\n",
               movies[i].id,
               movies[i].name,
               movies[i].earnings,
               movies[i].rating);
    }
}

void displayFriendsSummary(Person f) {
    printf("Name: %s\n", f.name);
    printf("Favorites: { ");
    for (int i = 0; i < SIZE; i++)
        if (f.favorites[i] == 1)
            printf("%d ", i);
    printf("}\n");
}

void displaySet(int set[], Movie movies[]) {
    for (int i = 0; i < SIZE; i++) {
        if (set[i] == 1)
            printf("> %s\n", movies[i].name);
    }
    printf("\n");
}

void unionSet(int A[], int B[], int C[]) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] | B[i];
    }
}

void intersectionSet(int A[], int B[], int C[]) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] & B[i];
    }
}

void differenceSet(int A[], int B[], int C[]) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] & ~B[i];
    }
}

void preferences(Movie movies[], Person friends[]) {
    int SameSet[SIZE];
    int atLeastOne[SIZE];
    int moviesTheyAllLiked1[SIZE]; //intersection must match
    int moviesTheyAllLiked2[SIZE];
    int moviesTwoOfThemLiked1[SIZE]; // only two like movies
    int moviesTwoOfThemLiked2[SIZE];
    int moviesTwoOfThemLiked3[SIZE];
    int moviesTwoOfThemLiked4[SIZE];
    int moviesTwoOfThemLikedFINAL[SIZE];
    int differenceBetweenTwo[SIZE];
    int moviesOnlyOneLiked1[SIZE];
    int moviesOnlyOneLiked2[SIZE];
    int moviesOnlyOneLiked3[SIZE];
    int moviesOnlyOneLiked4[SIZE];
    int moviesOnlyOneLikedFINAL[SIZE];

    
    int i, j;
   
    unionSet(friends[0].favorites, friends[1].favorites, SameSet);

    unionSet(SameSet, friends[2].favorites, atLeastOne);
   
    
    printf("\nMovies at least one of them liked:\n"); //union?
    //TODO
    displaySet(atLeastOne, movies);

    printf("\nMovies they all liked: \n");//union
    //TODO
 
    intersectionSet(friends[0].favorites, friends[1].favorites, moviesTheyAllLiked1);
    intersectionSet(moviesTheyAllLiked1, friends[2].favorites, moviesTheyAllLiked2);
    displaySet(moviesTheyAllLiked2, movies);

    printf("\nMovies at least two of them liked: \n");
 
    intersectionSet(friends[0].favorites, friends[1].favorites, moviesTwoOfThemLiked1);
    intersectionSet(friends[1].favorites, friends[2].favorites, moviesTwoOfThemLiked2);
    intersectionSet(friends[0].favorites, friends[2].favorites, moviesTwoOfThemLiked3);

    unionSet(moviesTwoOfThemLiked1, moviesTwoOfThemLiked2, moviesTwoOfThemLiked4);
    unionSet(moviesTwoOfThemLiked3, moviesTwoOfThemLiked4, moviesTwoOfThemLikedFINAL);
    differenceSet(moviesTwoOfThemLikedFINAL, moviesTheyAllLiked2, moviesTwoOfThemLikedFINAL);

    displaySet(moviesTwoOfThemLikedFINAL, movies);
    //TODO
    printf("\nMovies only one of them liked:\n"); //

    //TODO
      int onlyA[SIZE], onlyB[SIZE], onlyC[SIZE];
        int notB[SIZE], notC[SIZE], notA[SIZE];

        // Create complement sets
        for (int i = 0; i < SIZE; i++) {
            notA[i] = !friends[0].favorites[i];
            notB[i] = !friends[1].favorites[i];
            notC[i] = !friends[2].favorites[i];
        }


        intersectionSet(friends[0].favorites, notB, moviesOnlyOneLiked1);
        intersectionSet(moviesOnlyOneLiked1, notC, onlyA);

        intersectionSet(friends[1].favorites, notA, moviesOnlyOneLiked2);
        intersectionSet(moviesOnlyOneLiked2, notC, onlyB);

        intersectionSet(friends[2].favorites, notA, moviesOnlyOneLiked3);
        intersectionSet(moviesOnlyOneLiked3, notB, onlyC);

        unionSet(onlyA, onlyB, moviesOnlyOneLiked4);
        unionSet(moviesOnlyOneLiked4, onlyC, moviesOnlyOneLikedFINAL);

        displaySet(moviesOnlyOneLikedFINAL, movies);


}

void analysis(Movie movies[], Person friends[]) {
     int moviesTheyAllLiked1[SIZE]; //intersection must match
    int moviesTheyAllLiked2[SIZE];

    intersectionSet(friends[0].favorites, friends[1].favorites, moviesTheyAllLiked1);
    intersectionSet(moviesTheyAllLiked1, friends[2].favorites, moviesTheyAllLiked2);

    // ---- Certified Fan Favorites ----
    printf("\n------ CERTIFIED FAN FAVORITES ------\n");
    printf("(At least 2 liked it, rating > 7, earnings > 800M)\n");

    //TODO
    int moviesTwoOfThemLiked1[SIZE]; // only two like movies
    int moviesTwoOfThemLiked2[SIZE];
    int moviesTwoOfThemLiked3[SIZE];
    int moviesTwoOfThemLiked4[SIZE];
    int moviesTwoOfThemLikedFINAL[SIZE];

    intersectionSet(friends[0].favorites, friends[1].favorites, moviesTwoOfThemLiked1);
    intersectionSet(friends[1].favorites, friends[2].favorites, moviesTwoOfThemLiked2);
    intersectionSet(friends[0].favorites, friends[2].favorites, moviesTwoOfThemLiked3);
    unionSet(moviesTwoOfThemLiked1, moviesTwoOfThemLiked2, moviesTwoOfThemLiked4);

    unionSet(moviesTwoOfThemLiked3, moviesTwoOfThemLiked4, moviesTwoOfThemLikedFINAL);
    
    int atLeast2LikedWithCriteria[SIZE] = {0};

    int i;
    for (i = 0; i < SIZE ; i++){
        if(moviesTwoOfThemLikedFINAL[i] == 1 && movies[i].rating > 7.0 && movies[i].earnings > 800){
            atLeast2LikedWithCriteria[i] = 1;
        }
    }

    displaySet(atLeast2LikedWithCriteria, movies);




    // ---- Underrated Gems ----
    int atLeast2LikedWithCriteria2[SIZE] = {0};
    int atMost2Liked[SIZE];

    for (i = 0; i < SIZE; i++) {
        atMost2Liked[i] = !moviesTheyAllLiked2[i];  // NOT (all 3 liked)
    }

    printf("------ UNDERRATED GEMS ------\n");
    printf("(At most 2 liked it, rating > 8.5, earnings < 750M)\n");

    for (i = 0; i < SIZE ; i++){
        if(atMost2Liked[i] == 1 && movies[i].rating > 8.5 && movies[i].earnings < 750){
            atLeast2LikedWithCriteria2[i] = 1;
        }
    }

    displaySet(atLeast2LikedWithCriteria2, movies);

    //TODO

}
