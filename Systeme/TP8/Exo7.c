#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
        pid_t f;
    int tube1[2];
pipe(tube1);
char message = 'c';

if((f=fork())>0){

    close(tube1[1]);
    write(tube1[0] , &message , sizeof(message));
}

while (1)
{
 
}

return 0 ;

}