#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void crible(int* in) {
	if ( -1 == close(in[1]) ) {
		perror("probleme de close");
		exit(3);
	}

	int p;
	if ( read(in[0], &p, sizeof(int)) != sizeof(int) ) {
		close(in[0]);
		return;
	}

	printf("%d ", p);
	fflush(stdout);

	int out[2];

	if ( pipe(out) == -1 ) {
		perror("Probleme de pipe");
		exit(1);
	}

	pid_t fils;
	fils = fork();

	switch(fils) {
		case -1: 
			perror("Probleme de fork");
			exit(2);
		case 0:
			close(in[0]);
			crible(out);
			exit(0);
		default:
			close(out[0]);
			int i;
			while ( read(in[0], &i, sizeof(int)) == sizeof(int) ) {
				if ( i % p ) {
					write(out[1], &i, sizeof(int));
				}
			}

			close(in[0]);
			close(out[1]);

			wait(0);
			exit(0);
	}
}


int main(int argc, char *argv[]) {
	int borne;
	if ( argc != 2 ) {
		fprintf(stderr, "Syntaxe : crible n\n" );
		exit(1);
	}

	else if ( (borne = atoi(argv[1])) < 2 ) {
		fprintf(stderr, "Syntaxe : crible n ; avec n entier > 2\n" );
		exit(2);
	}

	int tube[2];
	pid_t fils;
	if ( pipe(tube) == -1 ) {
		perror("Problème de pipe");
		exit(1);
	}

	switch( fils = fork() ) {
		case -1:
			perror("Problème de fork");
			exit(1);
		case 0:
			crible(tube);
			exit(0);
		default:
			close(tube[0]);
			for ( int i = 2 ; i <= borne ; i++ ) {
				write(tube[1], &i, sizeof(int));
			} 
			close(tube[1]);
			wait(0); //si synchro, le 1er attend le second;

			return 0;
	}
}