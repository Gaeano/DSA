#ifndef CLDI_H
#define CLDI_H

#define MAX 32

#include<stdio.h>
#include<string.h>


typedef char String[30];

typedef struct{
	String songName;
	String singer;
	String genre;
}Song;

typedef struct{
	Song elem;
	int next;
}Heapspace;

typedef struct{
	Heapspace H[MAX];
	int avail;
}VirtualHeap;


void initDict(VirtualHeap *VH);

void insert(VirtualHeap *VH,Song song);
void deleteMember(VirtualHeap *VH,Song song);
int search(VirtualHeap VH,Song song);

int hash(String genre);
void displayDict(VirtualHeap VH);

#endif // CLDI_H