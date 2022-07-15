#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "AffichageMaisons.h"

#define dcouv 100

void GenererMaisons(int n, int coordMaisons[][2])
{
  for(int i=0;i<n;i++)
  {
    coordMaisons[i][0]=10+rand()%593;
    coordMaisons[i][1]=10+rand()%773;

  }
}

void Initialiser(int n, int a[])
{
  for(int i=0;i<n;i++) a[i]=0;
}

bool Couvre(int i, int j, const int coordMaisons[][2])
{
  return ((sqrt(((coordMaisons[i][0] - coordMaisons[j][0]) * (coordMaisons[i][0] - coordMaisons[j][0])) + ((coordMaisons[i][1] - coordMaisons[j][1]) * (coordMaisons[i][1] - coordMaisons[j][1]))))< dcouv);
}

int ChoixProchaineMaison(int n, const int coordMaisons[][2], const int dejaCouvertes[])
{
  int Mi = 0 ;
  int Max = 0;
  int Mmax = 0;
  for (int i = 0; i < n; ++i)
  {
    Mi = 0;
    for (int j = 0; j < n; ++j)
    {
      if(Couvre(i,j,coordMaisons) && dejaCouvertes[i]==0){

        ++Mi;
      }
    }
    if(Mi > Mmax){

        Mmax = Mi ;
        Max = i;
      }
  }
  return Max;
}

int ChoixEmetteurs(int n, const int coordMaisons[][2], int emetteurs[])
{

  int couv[n];
  int nbEmetteurs = 0 ;
  for (int i = 0; i < n; ++i)
  {
    couv[i] = 0 ;
  }
  int Mcouv = 0 ;

  while(Mcouv < n){

    int maisoncouvrir = ChoixProchaineMaison(n,coordMaisons,couv);
    for (int i = 0; i < n; ++i)
    {
      if(Couvre(maisoncouvrir,i,coordMaisons) && !couv[i]){

        couv[i] = 1;
        ++Mcouv;
      }
    }
    emetteurs[maisoncouvrir] = 1 ;
    nbEmetteurs++;
    
  } 

  return nbEmetteurs;
}

int suivant(int n, int tab[])
{
  int i = 0;
  while (i < n and tab[i] == 1) tab[i++]  = 0;
  if (i == n) return 1;
  tab[i] = 1;
  return 0;
}

int ChoixEmetteursOpt(int n, const int coordMaisons[][2], int emetteurs[])
{
  
  int couv[n];
  int nbEmetteurs = 0 ;
  for (int i = 0; i < n; ++i)
  {
    couv[i] = 0 ;
  }
  int Mcouv = 0 ;

  while(Mcouv < n){

    int maisoncouvrir = ChoixProchaineMaison(n,coordMaisons,couv);
    for (int i = 0; i < n; ++i)
    {
      if(Couvre(maisoncouvrir,i,coordMaisons) && !couv[i]){

        couv[i] = 1;
        ++Mcouv;
      }
    }
    emetteurs[maisoncouvrir] = 1 ;
    nbEmetteurs++;
    
  } 

  return nbEmetteurs;
}

int main(int argc, char** argv)
{
  int n;
  if (argc < 2)
  {
    cout << "Entrer le nombre de maisons: ";
    cin >> n;
  }
  else
  {
    n = atoi(argv[1]);
  }
  
  srand(time(NULL));

  int coordMaisons[n][2]; // coordonnées des maisons dans le plan
  int emetteurs[n];       // numéro des maisons que l'on choisit pour placer des émetteurs

  GenererMaisons(n, coordMaisons);
  AffichageMaisons(n, coordMaisons, "Maisons");
  Initialiser(n, emetteurs);

  int nbEmetteurs = ChoixEmetteurs(n, coordMaisons, emetteurs);
  cout << "Nombre d'émetteurs placés : "<< nbEmetteurs << endl;
  AffichageMaisonsEmetteurs(n, coordMaisons, emetteurs, "Emetteurs");

  int emetteursOpt[n];
  Initialiser(n, emetteursOpt);
  int nbEmetteursOpt = ChoixEmetteursOpt(n, coordMaisons, emetteursOpt);
  cout << "Nombre d'émetteurs optimal : " << nbEmetteursOpt << endl;
  AffichageMaisonsEmetteurs(n, coordMaisons, emetteursOpt, "EmetteursOpt");

  return 0;
}

#undef dcouv
