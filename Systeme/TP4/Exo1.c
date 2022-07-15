#include <stdio.h>
#include <math.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>
int main(){
/*
for(int i=0 ; i<4 ; i++){
	pid_t nPid;
	if ((nPid = fork())==0){
		printf("un nouveau descendant %d de parent %d ! i=%d\n",getpid(), getppid(),i);
	}else{
		int status;
		wait(&status);
		}//chaque parent attend la fin de ses enfants
}*/

do{
	int i = 5;
	pid_t nPid;
	char commande[100] = {0};

	printf("MonShell ");
    fgets(commande, 100, stdin);

	if(!strcmp (commande, "exit"))
		return 0;

	system(commande);

	if ((nPid = fork())==0){
		system(commande);
		return 0;


	
	

	}else{
		wait(NULL);
		}



}while (1);





/*
	int status;

			pid_t Pid;

			switch(Pid = fork()){

			case -1:
				printf("Il y a une erreur\n");
			break;
			case 0:
				printf("du descendant : valeur de retour du fork() %d\n",Pid);
				printf("du descendant : je suis %d de parent %d\n",getpid(), getppid());

				return 8 ;
			break;
			 default:
        	printf("du parent : valeur de retour du fork() %d\n",Pid);
			printf("du parent: je suis %d de parent %d\n",getpid(), getppid());
			int s = 0;
			pid_t fils = waitpid(Pid,&s,0);
			printf("du parent : mort annoncer de : %d avec le statut %d\n",fils,WEXITSTATUS(s));
       		break;

//chaque parent attend la fin de ses enfants
				}

				
*/




	//printf("petit texte");
	 //execl("/bin/ls" , "-ls","-l" , NULL);
	 // execp("" , "-ls","-l" , NULL);

/*
	int status;
	for(int i=0 ; i<log2(6) ; i++)
		{
			pid_t nPid;

			switch(nPid = fork()){

			case -1:
				printf("Il y a une erreur\n");
			break;
			case 0:
				printf("je suis l'enfants numéro\n");
			break;
			 default:
       // printf("retour fork : %d\n", nPid);
        wait(&status);
        break;
}


}
*/

//exercice 10
	

}