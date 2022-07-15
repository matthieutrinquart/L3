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
        present[i]= 0;
    
    int compte = 0;
    char c;
    //int i = 0;
    while(0<read(f,&c,1)){

            present[c]++;
    }
    printf("%d\n",compte);

    close(f);

    for (size_t i = 0; i < 256; i++)
    {   
        if(present[i])
            printf("%c : %d\n",i, present[i]);
    }
    
    return 0;
}