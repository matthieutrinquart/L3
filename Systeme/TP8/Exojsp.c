#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>




int parcours(char* rep, int indent) {
    struct dirent *entree;
    DIR *repCourant = opendir(rep);
    if (repCourant==NULL)
    {
 		fprintf(stderr, "%s impossible d'ouvrir le répértoire \n", rep);	
 		return -1;
 	    }
 	char*chemin = (char *) malloc(1024);
 	struct stat etat;
 	while((entree=readdir(repCourant)) !=NULL ){
 		strcat(strcat(strcpy(chemin,rep),"/"),entree->d_name);
 		if(lstat(chemin,&etat)<0){
 			fprintf(stderr, "impossible d'ouvrir le fichier : %s\n", chemin);
 		}
 		if(S_ISDIR(etat.st_mode) && strcmp(entree->d_name, ".") && strcmp(entree->d_name, "..") ){
 			for (int i = 0; i < indent-1; ++i)
 			{
 				printf("    ");
 			}
 			printf("|__");
 			printf("%s\n",chemin );
 			parcours(chemin,indent+1);
 		}
 	}


free(chemin);
closedir(repCourant);
return 0;
}

int main(int argc, char const *argv[]){
	parcours("../../", 1);
        
}