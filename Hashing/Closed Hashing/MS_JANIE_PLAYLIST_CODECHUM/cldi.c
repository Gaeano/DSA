#include<stdio.h>
#include<string.h>
#include "cldi.h"

String genreTable[16] = {
    "Ballad", "Pop Rock", "Pop", "R&B", "Rock", "Country Pop", "J-Pop", "K-Pop",
    "Classical", "Theater", "EDM", "OPM", "Reggae","Dance", "Jazz",  "Indie"
};

//Write your functions here...
int hash(String genre){
    int i;
    for (i = 0; i < 16; i++){
        if (strcmp(genreTable[i], genre) == 0){
            return i;
        }
        
    }
}

int allocSpace(VirtualHeap* VH){
    int retval = VH->avail;

    if (retval != -1 && retval < MAX){
        VH->avail = VH->H[retval].next;
    }

    return retval;
}

void insert(VirtualHeap *VH,Song song){
    int hashCode = hash(song.genre);

    if (strcmp(VH->H[hashCode].elem.genre, "Empty") == 0 || strcmp(VH->H[hashCode].elem.songName, "Deleted") == 0){
        //add to head
        VH->H[hashCode].elem = song;
       

    } else {
        int availIndex = allocSpace(VH);    
        int * trav;
        
        if(availIndex != -1){
            for (trav = &VH->H[hashCode].next; *trav != -1; trav = &VH->H[*trav].next){

            }
               
            *trav = availIndex;
            VH->H[availIndex].elem = song;
            VH->H[availIndex].next = -1;
               
        }

        
        
    }
}

void dealloc ( VirtualHeap* VH, int index){
    if (index != -1 && index < MAX){
        VH->H[index].next = VH->avail;
        VH->avail = index;

    }
}

void deleteMember(VirtualHeap *VH,Song song){
    int hashCode = hash(song.genre);

    if (strcmp(VH->H[hashCode].elem.songName, song.songName) == 0){
        strcpy(VH->H[hashCode].elem.genre , "Deleted");
        //if the deleted elem is in the head move the link to the primary storage
        
        if (VH->H[hashCode].next != -1){
            int linkOfHead = VH->H[hashCode].next;
            VH->H[hashCode].elem = VH->H[linkOfHead].elem;
            VH->H[hashCode].next = VH->H[linkOfHead].next;
            dealloc(VH, linkOfHead);
        } 
        
       
    } else {
        int* trav;
        int found = 0;
        for(trav = &VH->H[hashCode].next; *trav != -1 && found == 0; trav = &VH->H[*trav].next){
            if (strcmp(VH->H[*trav].elem.songName, song.songName) == 0){
                int del = *trav;
                *trav = VH->H[del].next;
                strcpy(VH->H[del].elem.songName , "Deleted");
                dealloc(VH, del);
                found = 1;
            }
        }
    }
}

int search(VirtualHeap VH,Song song){
    int hashCode = hash(song.genre);
    int found = 0;

    if (strcmp(VH.H[hashCode].elem.songName, song.songName) == 0){
        found = 1;
    } else {
        int trav;
        for (trav = VH.H[hashCode].next; trav != -1 && found == 0; trav = VH.H[trav].next){
            if (strcmp(VH.H[trav].elem.songName, song.songName) == 0){
                found = 1;
            }
        }
    }

    return found;
}