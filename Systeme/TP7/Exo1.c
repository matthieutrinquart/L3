#include<stdio.h>
#include<signal.h>

void gst (int sig){

    printf("Bien recu le signal %d\n",sig);
    action.sa_handler = SIG_DFL;
}

int main(){

struct sigaction action;
action.sa_handler = gst ;
sigaction(SIGINT , &action ,NULL);

printf("Le processus boucle sans fin !\n");
while(1);
}