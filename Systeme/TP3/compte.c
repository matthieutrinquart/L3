#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char**argv,char** arge){

    int f = open(argv[1],O_RDONLY);
    if(f == -1)
        printf("erreur");
    
    

    int present[256];
    for(int i = 0 ; i<256;++i)
        present[i] = 0;
    
    int compte = 0;
    char c;
    while(0<read(f,&c,1)){
        if(!present[(int)c]){

            present[(int)c] = 1;
            printf("%c\n",c);
            //printf((int)c);
            
            compte++;
        }
    }
    printf("%d\n",compte);

    close(f);
    return 0;
}