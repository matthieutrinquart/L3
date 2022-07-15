#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {

	int in = open("fifoEcrivain", O_RDONLY);
	while ( 1 ) {
		char* buffer[1000];
		read(in, buffer, 1000); //lis le message et le met dans le buffer

		write(1, buffer, 1000); //envois le message dans la fifo
		printf("Message reçu !%c\n",buffer);

	}

}