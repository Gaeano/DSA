#include<stdio.h>
#include<string.h>
#include "cldi.h"


void initDict(VirtualHeap *VH)
{
	int i,Lim,Half;
	Lim=MAX-1;
	Half=MAX/2;
	for(i=0 ; i<Half ; i++){
		strcpy(VH->H[i].elem.genre,"Empty");
        VH->H[i].elem.songName[0] = '\0';
        VH->H[i].elem.singer[0] = '\0';
		VH->H[i].next=-1;
	}


	for(; i<Lim ; i++){
		VH->H[i].next=i+1;
	}

	VH->H[i].next=-1;
	VH->avail=16;
}


void displayDict(VirtualHeap VH){

	int trav,cntr,set,LIM;
	set=1;
	LIM=MAX/2;

	printf("Playlist of Janie Sabado");
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	printf("\n  %3s   %30s   %-15s   %-13s","Ndx","Song Name","Singer","Genre");
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	for(trav=0;trav<LIM;trav++){
		if(strcmp(VH.H[trav].elem.genre,"Empty")==0){
			printf("\n  %3d.  %30s - %-15s | %-13s",trav+1,"---","---","---");
			//printf("%5d",VH.H[trav].next);
		}else{
			printf("\n  %3d.  %30s - %-15s | %-13s",trav+1,VH.H[trav].elem.songName,VH.H[trav].elem.singer,VH.H[trav].elem.genre);
			//printf("%5d",VH.H[trav].next);
            cntr = VH.H[trav].next;
            while(cntr != -1){
                printf("\n        %30s - %-15s | %-13s",VH.H[cntr].elem.songName, VH.H[cntr].elem.singer, VH.H[cntr].elem.genre);
                //printf("%5d",VH.H[cntr].next);
				cntr = VH.H[cntr].next;
            }
		}

		printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	}

}