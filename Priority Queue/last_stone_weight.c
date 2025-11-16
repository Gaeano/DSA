/*
--- LEETCODE --- 
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1


*/

#include <stdio.h>

void swap (int* a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void HeapifyDown(int* stones, int index, int size){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && stones[left] > stones[largest]){
        largest = left;
    }
    if (right < size && stones[right] > stones[largest]){
        largest = right;
    }

     if (largest != index){
        swap(&stones[largest], &stones[index]);
        HeapifyDown(stones, largest, size);
     }
}

void HeapifyUp (int* stones, int index){
    int parent = (index - 1) / 2;

    if (stones[parent] < stones[index]){
        swap(&stones[parent], &stones[index]);
        index = parent;
        HeapifyUp(stones, index);
    }
}
void buildMaxHeap (int* stones, int size){
   int i;
   int parent = (size - 1) / 2;
   for (i = parent; i >= 0; i--){
        HeapifyDown(stones, i, size);
   }
}

int extractMax(int* stones, int* size){
    int max = stones[0];
    (*size)--;
    stones[0] = stones[*size];

    if (*size > 0){
        HeapifyDown(stones, 0, *size);
    }
    return max;
    
}

void insertHeap(int* stones, int* size, int value){
    stones[*size] = value;
    HeapifyUp(stones, *size);
    (*size)++;
}


int lastStoneWeight(int* stones, int stonesSize) {
    int i;
    if (stonesSize == 0){
        return 0;
    }
    if (stonesSize == 1){
        return stones[0];
    }

    buildMaxHeap(stones, stonesSize);
    while (stonesSize > 1){
        int stone1 = extractMax(stones, &stonesSize);
        int stone2 = extractMax(stones, &stonesSize);

        if (stone1 != stone2){
            int difference = stone1 - stone2;
            insertHeap(stones, &stonesSize, difference);
        }
    }

    return stonesSize == 0 ? 0 : stones[0];
}

