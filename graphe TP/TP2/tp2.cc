#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include "affichage.cc"
using namespace std;
//typedef struct coord{int abs; int ord;} coord;
void kruskal(int n, int m, int edge[][3], int arbre[][2]){

	int y = 0 ;
	int comp[n];
	int aux = 0 ;


	for(int i = 0 ; i < n; ++i)
  {
  	comp[i] = i ;

  }

  	for(int i  = 0; i< m ; ++i)
	{
		if(comp[edge[i][0]] != comp[edge[i][1]])
		{

			aux = comp[edge[i][0]];
			arbre[y][0] = edge[i][0] ;
			arbre[y][1] = edge[i][1] ;
			++y;

			for(int z = 0 ; z < n ;++z){

				if(comp[z] == aux){

					comp[z] = comp[comp[edge[i][1]]];
				}
			}
		}
	}


	for(int i = 0 ; i < n - 1; ++i)
  {
  	cout << "arbre x = " << arbre[i][0] << "   y = " <<arbre[i][1]<< endl;

  }




}

	
void trie(int m , int edges[][3] ){
	
	int tampon1;
	int tampon2;
	int tampon3;

	int tampon4;
	int tampon5;
	int tampon6;

   for(int i = m-1 ; i > 1; --i)
  {
    for(int j = 0 ; j <= i - 1 ; ++j)
    {
      if(edges[j][2] > edges[j + 1][2])
      {
        tampon1 = edges[j][0];
        tampon2 = edges[j][1];
		tampon3 = edges[j][2];


		tampon4 = edges[j + 1][0];
        tampon5 = edges[j + 1][1];
		tampon6 = edges[j + 1][2];

		edges[j][0] = tampon4;
        edges[j][1] = tampon5;
		edges[j][2] = tampon6;

		edges[j+1][0] = tampon1;
        edges[j+1][1] = tampon2;
		edges[j+1][2] = tampon3;




      }

    }
  }

}

void distances(int n , int m , coord point[] , int edges[][3]){

int t = 0 ;
for(int i = 0 ; i < n ; ++i)
	{
		for(int j = i + 1  ; j < n ; ++j)
		{
			edges[t][0] = i ;
			edges[t][1] = j ;
			edges[t][2] = ((point[j].ord - point[i].ord) * (point[j].ord - point[i].ord) ) +
			 ((point[j].abs - point[i].abs) * (point[j].abs - point[i].abs) ) ;
			++t ;

		}
	}

for(int i = 0 ; i < m ; ++i)
	{


		cout << "Point1 : "<<edges[i][0] << " Point2 : " << edges[i][1] << " Resultat = " << edges[i][2] << endl;

	}

cout << endl << endl << endl ;


}




void pointRandom(int n, coord point[] , int m ,int edges[][3] ){


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

int main()
{
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 
  pointRandom(n , point,m , edge);
  distances(n,m,point,edge);
  trie(m,edge);
  kruskal(n,m,edge,arbre);
  affichageGraphique(n,point ,arbre);

  return EXIT_SUCCESS;
}
