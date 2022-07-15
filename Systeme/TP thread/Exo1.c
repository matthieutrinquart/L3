#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *crible(void *arg)
{

    int *in = (int *)arg;
    int p;
    if (read(in[0], &p, sizeof(int)) != sizeof(int))
    {
        close(in[0]);
        exit(0);
    }

    printf("%d ", p);

    int out[2];

    if (pipe(out) == -1)
    {
        perror("Probleme de pipe");
        exit(1);
    }

    pthread_t tid;
    int s = pthread_create(&tid, NULL, crible, &out);

    if (s != 0)
    {
        printf("création impossible du thread \n");
        exit(4);
    }
    int i;
    while (read(in[0], &i, sizeof(int)) == sizeof(int))
    {
        if (i % p)
        {
            write(out[1], &i, sizeof(int));
        }
    }

    close(in[0]);
    close(out[1]);
    pthread_join(tid, NULL);
    printf("JOIN");
    exit(0);
}
int main(int argc, char *argv[])
{
    int borne = atoi(argv[1]);
    if (argc != 2)
    {
        fprintf(stderr, "Syntaxe : crible n\n");
        exit(1);
    }

    else if ((borne = atoi(argv[1])) < 2)
    {
        fprintf(stderr, "Syntaxe : crible n ; avec n entier > 2\n");
        exit(2);
    }

    int tube[2];
    if (pipe(tube) == -1)
    {
        perror("Problème de pipe");
        exit(1);
    }

    pthread_t fils;
    if (pthread_create(&fils, NULL, crible, &tube))
    {

        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    for (int i = 2; i <= borne; ++i)
    {
        write(tube[1], (void *)&i, sizeof(int));
    }
    close(tube[1]);

    void *res;
    pthread_join(fils, &res);
}