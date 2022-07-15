#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
	int fifo = mkfifo("fifoEcrivain", S_IRWXU|S_IRGRP|S_IWGRP|S_IROTH);

	int in = open("fifoEcrivain", O_WRONLY);
	while ( 1 ) {
		char* buffer[1000];
		read(0, buffer, 1000); //lis le message et le met dans le buffer

		write(in, buffer, 1000); //envois le message dans la fifo
		printf("Le message a bien été envoyé !%d\n",buffer);

	}
}