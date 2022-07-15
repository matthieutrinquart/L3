

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){


char presence[256];

int nb_char = 0 ;
char c;

int fd = open("toto.txt" , O_RDONLY);



int fd2 = open("titi.txt" , O_RDWR | O_CREAT , S_IRWXU);
if(fd <0){


	printf("Il y a une erreur pour l'ouverture");
}

while(0<read(fd,&c,1)){

		presence[nb_char] = c;
		++nb_char;
}

close(fd);


write(fd2 , presence , nb_char);


close(fd2)
printf("%d carractère different\n",nb_char );



}