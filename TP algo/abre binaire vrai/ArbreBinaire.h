#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

typedef struct noeud {
  int val;
  noeud* pere;
  noeud* filsG;
  noeud* filsD;
} noeud;

typedef struct ArbreBinaire {
  noeud* racine;
} ArbreBinaire;

ArbreBinaire* ArbreVide();
noeud* creerNoeud(int valeur);
void dessinArbre(ArbreBinaire* arbre, string name);
void affichageGraphique(ArbreBinaire* arbre);