#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int tricompte(int * in){

	if ( -1 == close(in[1]) ) {
		perror("probleme de close");
		exit(3);
	}
    int tube[2];
    float min;
    pipe(tube);
    	if ( read(in[0], &min, sizeof(int)) != sizeof(int) ) {
		close(in[0]);
		return;
	}
    pid_t f;
    f = fork();


    	switch(f) {
		case -1: 
			perror("Probleme de fork");
			exit(2);
		case 0:
			close(in[0]);
        tricompte(tube);
			exit(0);
		default:
	close(tube[0]);
        float T[3];
        int p=0;
        while((read(in[0],T[p],sizeof(float))) == sizeof(float)){

            ++p;
        }

        float min = T[0];
        for (size_t i = 0; i < p-1; i++)
        {
            if (min > T[i])
            {
                min = T[i];
            }
            
            
        }

        int compt = 0;
        for (size_t i = 0; i < p-1; i++)
        {
            if (T[i]==min)
            {
                ++compt;
            }
            else{

            }
            
        }
        for (size_t i = 0; i < p-1; i++)
        {
            if (T[i]!=min)
            {
                write(tube[1],&T[i],sizeof(float));
            }
            
        }
        printf("%f:%d",min,compt);
        
        
      
			close(in[0]);
			close(tube[1]);

			wait(0);
			exit(0);  
    }





}
int main(){


int n = 3;
float T[n];
FILE* f = fopen("test.bin","r");
for(int i = 0 ; i<n-1;++i){

    fread(&T[i],sizeof(float),1,f);

}

int tube[2];
pipe(tube);
    pid_t fo;
switch( fo = fork() ) {
		case -1:
			perror("Problème de fork");
			exit(1);
		case 0:
    tricompte(tube);
    		exit(0);
		default:
 for (int i = 0; i < n-1; i++)
    {
        write(tube[1],&T[i],sizeof(float));
    }
    

			close(tube[1]);
			wait(0); //si synchro, le 1er attend le second;

			return 0;
	}
}