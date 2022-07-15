#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int tube1[2];
    pid_t f;
pipe(tube1);

char message ;
if((f=fork())>0){

    close(tube1[0]);
    read(tube1[1],&message,sizeof(message));
    printf(&message);
}
while (1)
{
 
}

return 0 ;
}