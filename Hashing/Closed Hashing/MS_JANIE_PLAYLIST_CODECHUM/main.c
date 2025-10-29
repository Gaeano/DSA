#include<stdio.h>
#include<string.h>
#include "cldi.h"

int main(){
	Song songBook[20]={	{"Someone Like You","Adele","Ballad"},
						{"Yellow Submarine","Beatles","Pop Rock"},
						{"Training Season","Dua Lipa","Pop"},
						{"Let's go back","Jungle","Dance"},
						{"Sway","Michael Buble","Jazz"},
						{"Love Story","Taylor Swift","Country Pop"},
						{"Where is my Husband?","Raye","Jazz"},
						{"Fly me to the moon","Frank Sinatra","Jazz"},
						{"Thinking Out Loud","Ed Sheeran","Ballad"},
						{"Back on 74","Jungle","Dance"},
						{"Mr. Brightside","The Killers","Pop Rock"},
						{"Kirari","Fuji Kaze","J-Pop"},
						{"This is What You Came For","Calvin Harris","Pop"},
						{"Rock with you","SEVENTEEN","K-Pop"},
						{"Symphony no. 8","Beethoven","Classical"},
						{"Defying Gravity","Wicked","Theater"},
						{"Alone","Marshmello","EDM"},
						{"Buwan","Juan Karlos","OPM"},
						{"NO PROBLEMZ","Jungle","Dance"},
						{"Doo Wop'","Lauryn Hill","R&B"}};

	int trav;
	Song temp={"Fly me to the moon","Frank Sinatra","Jazz"};
	Song check={"Everynight","Jungle","Dance"};
	Song delFirst={"Training Season","Dua Lipa","Pop"};
	VirtualHeap VH;

	initDict(&VH);

	for(trav=0;trav<20;trav++){
		insert(&VH,songBook[trav]);
	}

	displayDict(VH);
	printf("\n");

	printf("\nThe song \"%s\" %s in my playlist",check.songName,(search(VH,check))?"exists":"does not exist");
	printf("\nThe song \"%s\" %s in my playlist",temp.songName,(search(VH,temp))?"exists":"does not exist");

	printf("\n\nDeleting song %s",temp.songName);
	deleteMember(&VH,temp);
	printf("\nDeleting song %s",delFirst.songName);
	deleteMember(&VH,delFirst);
	printf("\n\nInserting song %s",check.songName);
	insert(&VH,check);

	printf("\n");
	displayDict(VH);

	return 0;

}