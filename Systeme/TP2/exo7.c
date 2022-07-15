#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void Hexa(char presence[] , int nb_char){

	for (int i = 0; i < nb_char; ++i)
	{

		if(i%2)
			printf(" ");
		else if(presence[i] == '\n')
			printf("\n");
		else
			printf("%c = 0x%x\n",presence[i],presence[i] );
	}




}

int main(){


char presence[1024];
int nb_char = 0 ;
char c;

int fd = open("toto.txt" , O_RDONLY);
if(fd <0){


	printf("Il y a une erreur pour l'ouverture");
}

while(0<read(fd,&c,1)){

		presence[nb_char] = c;
		++nb_char;

}



close(fd);



printf("%d carractère different\n",nb_char );

Hexa(presence , nb_char);


for(int  i = 0 ; i < nb_char ; ++i){


	//printf("%c\n" ,presence[i]);
}



}