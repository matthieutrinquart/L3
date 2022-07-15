#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>


typedef struct{
uint32_t tailleMax; // taille du tableau qui stocke
uint32_t tete; // indice de tête
uint32_t taille; // taille de la file d’attente
void **tab; // tableau contenant la queue
pthread_mutex_t *mutex;
pthread_cond_t *condNonPlein;
pthread_cond_t *condNonVide;
} queue;


queue* queueCreer(uint32_t tailleMax){
queue *q=malloc(sizeof(queue));
q->tailleMax=tailleMax;
q->tete=0;
q->taille=0;
q->tab=(void**) malloc(tailleMax*sizeof(void*));
q->mutex=malloc(sizeof(pthread_mutex_t));
pthread_mutex_init(q->mutex, NULL);
q->condNonPlein=malloc(sizeof(pthread_cond_t));
pthread_cond_init(q->condNonPlein,NULL);
q->condNonVide=malloc(sizeof(pthread_cond_t));
pthread_cond_init(q->condNonVide,NULL);
return q;
}




queue* queueAjouter(queue *q, void *o){
pthread_mutex_lock(q->mutex); // Section Critique
while(q->taille==q->tailleMax){ // queue pleine !
pthread_cond_wait(q->condNonPlein, q->mutex);
// débloque le mutex et attend un signal
} // la queue n’est pas pleine : on peut ajouter
uint32_t pos=(q->tete+q->taille)%q->tailleMax;
q->tab[pos]=o; // ajout
q->taille++;
if(q->taille==1) // plus vide : je débloque tous
pthread_cond_broadcast(q->condNonVide);
pthread_mutex_unlock(q->mutex); // fin de SC
return q;
}




void * queueRetirer(queue *q){
pthread_mutex_lock(q->mutex); // Section Critique
while(q->taille==0){ // queue vide !
pthread_cond_wait(q->condNonVide, q->mutex);
// débloque le mutex et attend un signal
} // la queue n’est pas vide : on peut retirer
void *o=q->tab[q->tete];
q->tab[q->tete]=NULL;
q->tete=(q->tete+1)%q->tailleMax;
q->taille--;
if(q->taille==q->tailleMax-1) // plus plein
pthread_cond_broadcast(q->condNonPlein);
pthread_mutex_unlock(q->mutex); // fin de SC
return o;
}


typedef struct{queue *q; int n;} argument;
/** Producteur ajoutant n entiers dans la queue */
void * prod(void* a){
for(int i=0; i<((argument*)a)->n; i++){
int j=rand()%1000; // entier aléatoire [0,1000[
int *pj=malloc(sizeof(int));
*pj=j;
queueAjouter(((argument*)a)->q,(void *)pj);
printf("%d ajouté;\n",*pj);
}
return NULL;
}

/** Consommateur retirant n entiers de la queue */
void * cons(void* a){
for(int i=0; i<((argument*)a)->n; i++){
int *pi=(int *)queueRetirer(((argument*)a)->q);
printf("%d retiré;\n",*pi);
free(pi);
}
return NULL;
}

queue *q; // une seule queue
int main(int argc, char * argv[]){
    srand(time(NULL)); // initialisation de rand
    q=queueCreer(atoi(argv[1])); // à faire varier ..
    argument ac;ac.q=q;ac.n=100; // nb retraits
    pthread_t tidc,tidp; /* id des threads */
    for(int i=0;i<3;i++){ // 3 conso
    if (0 != pthread_create(&tidc, NULL, cons, &ac)){
        printf("création du thread impossible !\n");
        exit(1);
    }
    } // 3 conso *100

    argument ap;ap.q=q;ap.n=75; // nb retraits
    for(int i=0;i<4;i++){ // 4 prod
    if (0 != pthread_create(&tidp, NULL, prod, &ap)){
        printf("création du thread impossible !\n");
        exit(1);
    }
    } // 4 prod * 75
    void* res;
    pthread_join (tidc, &res); // on attend un cons
    printf("fin du main \n");
    return 0;
}

