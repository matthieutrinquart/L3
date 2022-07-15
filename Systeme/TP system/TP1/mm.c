#include "mm.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
mm mm_creer(){

 mm m = (mm)malloc(sizeof(struct mm));
 srand(time(NULL)); 
 //char b[50];
 for(int i = 0 ; i < TAILLE ; ++i)
 {

 	m->secret[i] = (rand() % 9) ;
	printf("%d \n" , m->secret[i]);

 }
 return m ;


}
void mm_detruire(mm jeux){


free(jeux);

}

int mm_test(mm jeu, char* essai){
int bp = 0 ;
int mp = 0;
int test = 0;
++jeu->nbessais;


if((strlen(essai)) != TAILLE)
	{

		return -1;



	}

	for(int i = 0 ; i<TAILLE ; ++i)
{

	if(!isdigit(essai[i]))
	{
		return -1;
	}

}

for(int i = 0 ; i<TAILLE ; ++i)
{

	for(int j = 0 ; j<TAILLE ; ++j)
	{
		if((jeu->secret[i] == (essai[j] - '0')))
		{
			printf("Je suis la \n");
			test = 1 ;

		}

	}

	if((jeu->secret[i] == (essai[i] - '0')))
	{

		++bp;


	}
	else if(test == 1)
	{

		++mp;
	}
	test = 0 ;
}

return ( mp + (TAILLE + 1) *bp );

}

int mm_nbessais(mm jeu){



return jeu->nbessais;
}


