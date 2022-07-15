#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <stack> 
#include <fstream>
#include <algorithm>
#include "affichage.cc"
using namespace std;
//typedef struct coord{int abs; int ord;};



//a modifier
void parcoursLargeurV2(int n,vector<int> voisins[], int niveau[], int ordre[], int pere[]){


queue<int> fileTraitement;
fileTraitement.push(0);
for(int i = 0 ; i < n ;++i)
  pere[i]=-2;
pere[0] = -1;

int cptOrdre = 0;

while(!fileTraitement.empty()){

  ordre[fileTraitement.front()] = cptOrdre;
  cptOrdre++;
  if(pere[fileTraitement.front()]== -1)
    niveau[fileTraitement.front()] = 0;
  else
    niveau[fileTraitement.front()] = niveau[pere[fileTraitement.front()]] + 1;
  for(int i = 0 ; i < voisins[fileTraitement.front()].size() ; ++i)
  {
    if(pere[voisins[fileTraitement.front()].at(i)] != -2){

      pere[voisins[fileTraitement.front()].at(i)] = fileTraitement.front();
      fileTraitement.push(voisins[fileTraitement.front()].at(i));
    }


  }
  fileTraitement.pop();
  
}
}


void parcoursLongueurV2(int n,vector<int> voisins[], int niveau[], int ordre[], int pere[])
{

stack<int> pileTraitement;
pileTraitement.push(0);
for(int i = 0 ; i < n ;++i)
  pere[i]=-2;
pere[0] = -2;

int cptOrdre = 0;

while(!pileTraitement.empty()){

  int sommetCourant = pileTraitement.top() ;
  pileTraitement.pop();
  ordre[sommetCourant] = cptOrdre;
  cptOrdre++;
  if(pere[sommetCourant]== -1)
    niveau[sommetCourant] = 0;
  else
    niveau[sommetCourant] = niveau[pere[sommetCourant]] + 1;
  for(int i = 0 ; i < voisins[sommetCourant].size() ; ++i)
  {
    if(pere[voisins[sommetCourant].at(i)] != -2){

      pere[voisins[sommetCourant].at(i)] = sommetCourant;
      pileTraitement.push(voisins[sommetCourant].at(i));
    }


  }
  
}
cout << endl<< endl<< endl<< endl;
cout << "parcourV2 :"<< endl;
    for (int j = 0; j < n ; ++j)
    {

      cout << "point = "<< j << endl;
      cout << "pere = "<< pere[j] << endl;
       cout << "ordre = "<< ordre[j] << endl;
        cout << "niveau = "<< niveau[j] << endl;
    }
}
/*
void parcoursLargeur(int n,vector<int> voisins[], int niveau[], int ordre[], int pere[]){

int dv[n];
vector<int> AT ;
int r = 0 ;
for (int i = 0; i < n; ++i)
{
  dv[i] = 0;

  
}
dv[r]= 1;
niveau[r]= 0;
ordre[r]= 1;
pere[r]= r;

AT.push_back(r); ;
int t = 2;
int k = 0 ;
while(!AT.empty()){
  int v = AT.back();
  AT.pop_back();
    for (int i = 0; i < (int)voisins[v].size(); ++i)
    {
      if(dv[i] == 0)
      {
        cout << "je suis la";

        dv[i] = 1;
        AT.push_back(i);
        ordre[i] = t;
        ++t;
        pere[i] = v;
        niveau[i] = niveau[v] + 1;
      }
    }
++k;
  }
    for (int j = 0; j < n ; ++j)
    {

      cout << "point = "<< j << endl;
      cout << "pere = "<< pere[j] << endl;
       cout << "ordre = "<< ordre[j] << endl;
        cout << "niveau = "<< niveau[j] << endl;
    }
    
    
}
*/

void pointrand(coord point[], int n){

    srand(time(NULL));
  for(int i = 0 ; i < n ; ++i)
  {

    int x= rand()%612 ;
    int y= rand()%792 ;


    point[i].abs = x;
    point[i].ord = y;
    
   // cout << point[i].abs << " ";
   // cout << point[i].ord << endl;
  }

}

void voisinsRandom(int n, int m, vector<int>voisins[])
{
  int x,y;
  for(int i=0;i<m;i++)
  {
    do
    {
      x=rand()%n;
      y=rand()%n;
    }
    while(x==y || find(voisins[x].begin(),voisins[x].end(),y)!=voisins[x].end());
    {
    voisins[x].push_back(y);
    voisins[y].push_back(x);
    }

   // cout << voisins[0].back() << endl;
   // cout << voisins[1].back() << endl;
  }

      for (int i = 0; i < (int)voisins->size(); ++i)
    {

      cout << voisins[i][0] << "     " << voisins[i][1] << endl;
    }

     cout <<  endl << endl<< endl;

}

void ecritureNiveaux(int n, int niveau[]){


    
    int Taille[n];
    int vraiTaille[n+ 1];
        for(int i=0;i<n + 1;i++){
            Taille[i] = 0 ;
        }

        for(int i=0;i<=n + 1;i++){
            vraiTaille[i] = 0 ;
        }

    for(int i=0;i<n;i++){
        for(int x=0;x<n;x++)
            {
                if(niveau[i]==niveau[x])
                {
                    Taille[niveau[i]]++;
                     

                } 
            } 


    }
        for(int i=0;i<n;i++){
            if(Taille[i] != 1 && Taille[i] != 0)
                Taille[i] = sqrt(Taille[i]);

        }

    for(int i=0;i<n;i++){
        for(int b=1;b<=n ;b++){
            if(Taille[i] == b )
            {  
                ++vraiTaille[b];
            }

    }
    }
        for(int i=0;i<=n  ;i++)
            cout <<  vraiTaille[i + 1]<< " composante de taille " << i << endl;
  
}


int main()
{
  int n;                                    // Le nombre de sommets.
  int m;                                    // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets: ";
  cin >> n;
  cout << "Entrer le nombre d'aretes: ";
  cin >> m;
  vector<int> voisins[n];                   // Les listes des voisins. 
  int pere[n];                              // L'arbre en largeur.
  int ordre[n];                             // L'ordre de parcours.
  int niveau[n];                            // Le niveau du point.
  coord point[n] ;
  pointrand(point ,n);

  voisinsRandom(n,m,voisins);
  //parcoursLargeur(n,voisins,niveau,ordre,pere);
    parcoursLargeurV2(n,voisins,niveau,ordre,pere);
        parcoursLongueurV2(n,voisins,niveau,ordre,pere);
 // affichageGraphique(n,point , niveau);
  return EXIT_SUCCESS;
}
