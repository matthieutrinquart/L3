#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int appart(int c , char presence[],int nb_char){

	int o = 0 ;

	for(int i = 0 ; i < nb_char ; ++i){

		if( c == presence[i]){

			o = 1 ;
		}

	}

	return o ;
}


int main(){


char presence[1024];
int doublon[1024];

for (int i = 0; i < 1024; ++i)
{
	doublon[i] = 0;
}
int idoublon = 0 ;
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


for (int i = 0; i < nb_char; ++i)
{

		if(appart(presence[i] , presence , nb_char)){

		++doublon[i];
		

	}
}

close(fd);

printf("%d carractère different\n",nb_char );

for(int  i = 0 ; i < nb_char ; ++i){


	printf("%c = %d \n" ,presence[i], doublon[i]);
}

}