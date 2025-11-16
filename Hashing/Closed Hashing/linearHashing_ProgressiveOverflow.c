#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BookNode {
    long long isbn;
    char title[100];
    char author[50];
    int year;
    struct BookNode* next;  // Overflow chain
} BookNode;

typedef struct Bucket {
    BookNode* head;  // Primary page
    int count;       // Number of books in this bucket
} Bucket;

typedef struct LinearHashTable {
    Bucket* buckets;
    int N;           // Current number of buckets
    int level;       // Current level (N = 2^level * N0)
    int split;       // Next bucket to split (0 to N-1)
    int N0;          // Initial number of buckets
    int totalBooks;
} LinearHashTable;
