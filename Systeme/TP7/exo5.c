#include<stdio.h>
#include<signal.h>
#include<errno.h>
/*
void gst (int sig){

    printf("Bien recu le signal %d\n",sig);
}
*/
int main(){

//struct sigaction action;
//action.sa_handler = gst ;
//sigaction(SIGINT , &action ,NULL);
printf("je suis la");
errno = 0 ;
int tab[2];
tab[0] = 1 ;
tab[1] = 1 ;
printf("je suis la");
tab[2] = 1 ;
printf(stderr , "%d" , strerror(errno));


}