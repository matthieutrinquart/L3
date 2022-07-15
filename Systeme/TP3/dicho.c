#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char**argv,char** arge){

    char mot = 'M';
    int f = open(argv[1],O_RDONLY);
    if(f == -1)
        printf("erreur");
    
    
    int fin = lseek(f,0,SEEK_END);
    int debut = 0;
    char c;
    int milieux ,i;

    do{
        milieux = (debut+fin)/2;
       i = lseek(f,milieux,SEEK_SET);
       read(f,&c,1);
       if(mot < c){
           fin = milieux;


       }
       else{
           debut = milieux;

       }



    }while(debut < fin && c != mot);

    printf("%c\n%d\n",c,milieux);

    close(f);
    return 0;
}