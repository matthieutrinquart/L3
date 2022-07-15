
#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

void recursiv(char* path, int prefix) {
    struct dirent *dirent;
    DIR *dir;
    
    for (int i = 0; i < prefix; ++i){
    	printf(" ");
    }
    printf("%s \n", path);

	dir=opendir(path);
    if (dir != NULL) {

    	while ((dirent = readdir(dir)) != NULL) {
    		if (strncmp(dirent->d_name, "..", 2)) {
    			if (strncmp(dirent->d_name, ".", 1)) {
    				recursiv(dirent->d_name, prefix +4);
    				//printf("Printable %s\n", dirent->d_name);
    			}
    		}

    	}

	}
}


void recursiv(char* path, int prefix) {

DIR * dossier;
struct dirent *dirent;
    for (int i = 0; i < prefix; ++i){
    	printf(" ");
    }
    printf("%s\n", path);
dossier =opendir(path);
if(dossier != NULL){

	while ((dirent = readdir(dossier)) != NULL )
	{
		 	if (dirent->d_name[0] != '.') {
    			if (dirent->d_name[1] != '.') {
    				recursiv(dirent->d_name, prefix +4);
    				//printf("Printable %s\n", dirent->d_name);
    			}
    		}
		
	}
	
}



}



int main(int argc, char**argv[]){
	recursiv(".", 0);
/*
	struct stat sb;
if( stat( argv[1], &sb) != -1) // Check the return value of stat
{
	if(S_ISREG(sb.st_mode))
		printf("fichier régulier\n");
	if(S_ISDIR(sb.st_mode))
		printf("répertoire\n");
	if(S_ISLNK(sb.st_mode))
		printf("liens symbolique\n");

	if(isUserW(sb.st_mode)) printf("w"); else printf("_");
	if(isUserR(sb.st_mode)) printf("r"); else printf("_");
	if(isUserX(sb.st_mode)) printf("x"); else printf("_");

	char chaine1[100] = "ls -l ";
	 strcat(chaine1, argv[1]);
	system(chaine1);

}
     */   
}