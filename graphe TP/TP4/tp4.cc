#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>

using namespace std;

const int N=1400;
const int M=(N*(N-1))/2;
  
typedef struct coord{int abs; int ord;} coord;

void pointRandom(int n,coord point[]);
float distance(coord p1,coord p2);
void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m);
void voisins2arete(int n,vector<int>voisin[],int arete[][2]);
void affichageGraphique(int n,int m,coord point[],int arete[][2],string name);
bool existe(int n,int dis[],bool traite[],int &x);
void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]);
int construireArbre(int n,int arbre[][2],int pere[]);


bool existe(int n,int dis[],bool traite[],int &x) {

        int distMin = -1;
        for (int i = 0; i < n; ++i){
                if ((! traite[i]) && (dis[i] < distMin || distMin <0) {
                        distMin = dis[i];
                        x = i;
                }
        }


if (distMin <0){

  return false
}
else{

  traite[x]=true;
  return true;
}
}

void pointRandom(int n,coord point[]){


	srand(time(NULL));
	for(int i = 0 ; i < n ; ++i)
	{

		int x= rand()%612 ;
		int y= rand()%792 ;


		point[i].abs = x;
		point[i].ord = y;
		
		cout << point[i].abs << " ";
		cout << point[i].ord << endl;
	}

	//distances(n ,m , point , edges);


}

float distance(coord p1,coord p2) {

  int absI =p1.abs;
  int ordI = p1.ord;

  int absJ = p2.abs;
  int ordJ = p2.ord;

  float distance = 
    (absJ - absI)*(absJ - absI)
    + 
    (ordJ - ordI)*(ordJ - ordI);

  return sqrt(distance);

}

void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m)
{
  float dist;
  m = 0;
  for(int i = 0 ; i< n -1; ++i){
    for(int j = i +1 ; j< n ; ++j){ 
  
      if((dist = distance(point[i],point[j])) < dmax){
        voisin[i].push_back(j);
        voisin[j].push_back(i);
        m++;

      }

    }
}

}

void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]){


float dist[n];
bool traite[n];
for (int i = 0; i < n ; i++)
{
  dis[i] = INT32_MAX;
  traite[i] = false;
}
int racine = 0;
pere[racine] = racine;
dis[racine] = 0;

int sommetCourant;
while(existe(n,dist,traite,sommetCourant)){
  for (int i = 0; i < voisin[sommetCourant].size; i++)
  {
    if(!traite[voisin[sommetCourant].at(i)] &&
     dist[voisin[sommetCourant].at(i)] > dist[sommetCourant] + 
     distance(point[sommetCourant],point[voisin[sommetCourant].at(i)]))
    {

      pere[voisin[sommetCourant].at(i)] = sommetCourant;
      dis[voisin[sommetCourant].at(i)] = distance(point[sommetCourant],point[voisin[sommetCourant].at(i)]);



    }
  }
  



}


}

int main()
{
  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n; 
  int dmax=50;                     // La distance jusqu'a laquelle on relie deux points.
  coord point[N];                  // Les coordonnees des points.
  vector<int> voisin[N];           // Les listes de voisins.          
  int arbre[N-1][2];               // Les aretes de l'arbre de Dijkstra.
  int pere[N];                     // La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'aretes
  int arete[M][2];                 // Les aretes du graphe
  return EXIT_SUCCESS;
}
