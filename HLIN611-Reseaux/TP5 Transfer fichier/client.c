#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

// taille du buffer temporaire pour la lecture de fichier. Vous pouvez définir une autre valeur.
#define MAX_BUFFER_SIZE 500

int sendTCP(int socket, const char *buffer, size_t length, unsigned int *nbBytesSent, unsigned int *nbCallSend){
	size_t sent;
	size_t totalSent = 0;
	unsigned int cptrSend = 0;

	while (totalSent < length)	{
		sent = send(socket, buffer + totalSent, length - totalSent, 0);
		cptrSend++;
		if (sent <= 0)		{
			(*nbBytesSent) += totalSent;
			(*nbCallSend) += cptrSend;
			return sent;
		}
		totalSent += sent;
	}
	(*nbBytesSent) += totalSent;
	(*nbCallSend) += cptrSend;

	return 1;
}


int main(int argc, char *argv[]){
	if (argc != 4)	{
		printf("utilisation : client ip_serveur port_serveur nom_fichier\n");
		exit(0);
	}
	// envoyer le nom de fichier (réfléchir aux données à envoyer pour que le nom soit corectement reçu)
	int ds = socket(AF_INET, SOCK_STREAM, 0);
	if (ds == -1)	{
		printf("Client : pb creation socket\n");
		exit(1);
	}
	struct sockaddr_in adrServ;
	adrServ.sin_family = AF_INET;
	adrServ.sin_port = htons(atoi(argv[2]));
	if (inet_pton(AF_INET, argv[1], &(adrServ.sin_addr)) < 1)	{
		perror("client: inet_pton() error ->");
		exit(1);
	}
	int conn = connect(ds, (struct sockaddr *)&adrServ, sizeof(adrServ));
	if (conn < 0)	{
		perror("Client: pb au connect :");
		close(ds);
		exit(1);
	}
	printf("Client : demande de connexion reussie \n\n");




	// Envoie de la taille du nom
	int name_size = strlen(argv[3]) + 1;
	unsigned int nbTotalOctetsEnvoyes = 0;
	unsigned int nbAppelSend = 0;

	int snd = sendTCP(ds, &name_size, sizeof(name_size), &nbTotalOctetsEnvoyes, &nbAppelSend);
	if (snd < 0)		{
		perror("Probleme d'emission taille");
		close(ds);
		exit(1);
	}
	printf("J'ai envoyé la taille du nom du fichier+1 : %d \n", name_size);
	printf("Client : j'ai envoyé au total %d octets avec %d appels à send \n\n", nbTotalOctetsEnvoyes, nbAppelSend);


	// Envoie du nom du fichier
	char *filename = malloc(strlen(argv[3]) +1); 
	filename[0] = '\0';
	strcat(filename, argv[3]);

	snd = sendTCP(ds, filename, name_size, &nbTotalOctetsEnvoyes, &nbAppelSend);
	if (snd < 0)		{
		perror("Probleme d'emission taille");
		close(ds);
		free(filename) ;
		exit(1);
	}
	printf("J'ai envoyé le nom du fichier+1 : %s \n", filename);
	printf("Client : j'ai envoyé au total %d octets avec %d appels à send \n\n", nbTotalOctetsEnvoyes, nbAppelSend);
	free(filename) ;






	// je construis le nom complet (chemin) du fichier que je dois lire
	char *filepath = malloc(strlen(argv[3]) + 16); 		// ./emission/+nom fichier +\0
	filepath[0] = '\0';
	strcat(filepath, "./emission/");
	strcat(filepath, argv[3]);
	printf("Client: je vais envoyer %s\n", filepath);

	// je récupère la taille du fichier. Pourquoi ?
	struct stat attributes;
	if (stat(filepath, &attributes) == -1)	{
		perror("Client : erreur stat");
		free(filepath);
		close(ds);
		exit(1);
	}

	// c'est bon, j'ai obtenu la taille du fichier. Refléchir ce que je dois en fair .
	int file_size = attributes.st_size; 


	// Envoie de la taille du fichier
	snd = sendTCP(ds, &file_size, sizeof(file_size), &nbTotalOctetsEnvoyes, &nbAppelSend);
	if (snd < 0)		{
		perror("Probleme d'emission taille");
		close(ds);
		exit(1);
	}
	printf("J'ai envoyé la taille du fichier+1 : %d \n", file_size);
	printf("Client : j'ai envoyé au total %d octets avec %d appels à send \n\n", nbTotalOctetsEnvoyes, nbAppelSend);




	// pour envoyer le contenu, je dois lire le fichier :// ouverture en lecture
	FILE *file = fopen(filepath, "rb"); 
	if (file == NULL)	{
		perror("Client : erreur ouverture fichier \n");
		free(filepath);
		close(ds);
		exit(1);
	}
	free(filepath); // je n'ai plus besoin de ce tableau dans la suite.


	// je fait une lecture par bloc.
	// je continue à lire tant que je n'ai pas lus le fichier en entier.
	int nbRead = 0 ;
	while(nbRead < file_size)	{
		char buffer[MAX_BUFFER_SIZE];
		size_t read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file);
		// je viens de tenter de lire un bloc d'au maximum MAX_BUFFER_SIZE octets

		if (read == 0)	{
			if (ferror(file) != 0) {
				perror("Client : erreur lors de la lecture du fichier \n");
				fclose(file);
				close(ds);
				exit(1);
			}
			break; // plus rien à lire
		}
		// ici j'ai un bloc de read octets lus et stoqués dans buffer. Que faire de ce bloc d'octets ?


		snd = sendTCP(ds, &buffer, read, &nbTotalOctetsEnvoyes, &nbAppelSend);
		if (snd < 0)		{
			perror("Probleme d'emission taille");
			close(ds);
			exit(1);
		}
		printf("J'ai envoyé un packet du fichier+1 : %ld : %s \n", read, buffer);
		printf("Client : j'ai envoyé au total %d octets avec %d appels à send \n\n", nbTotalOctetsEnvoyes, nbAppelSend);


		nbRead += read;
	}

	// fermeture du fichier
	int resc = fclose(file);
	if (resc < 0) {
		perror("Client : erreur fermeture fichier \n");
		close(ds);
		exit(1);
	}
	printf("Client : j'ai envoye au total : %d octets,  envoyes en %d appels a send \n\n", nbTotalOctetsEnvoyes, nbAppelSend);
	close(ds);
	printf("Client : je termine\n");
}
