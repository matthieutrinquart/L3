#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/** Fonction principale de la version console du jeu Mastermind
 */  


int appart(int c , char presence[],int nb_char){

	int o = 1 ;

	for(int i = 0 ; i < nb_char ; ++i){

		if( c == presence[i]){

			o = 0 ;
		}

	}

	return o ;
}
int main(){


char presence[256];

int nb_char = 0 ;
char c;

int fd = open("toto.txt" , O_RDONLY);
if(fd <0){


	printf("Il y a une erreur pour l'ouverture");
}

while(0<read(fd,&c,1)){


	if(appart(c,presence,nb_char) && c != '\n'){


		presence[nb_char] = c;
		++nb_char;
	}
}

close(fd);

printf("%d carractère different\n",nb_char );

for(int  i = 0 ; i < nb_char ; ++i){


	printf("%c \n" ,presence[i]);
}

}