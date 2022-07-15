#include <iostream>
#include <string>

#include "matrice.h"

using namespace std;

int valeur(int** E, int i, int j)
{
  if(i >= 0 && j >=0)
    return E[i][j];
  
  if(j == -1)
    return (i+1);
  if(i == -1)
    return (j+1);

}

int min(int a, int b, int c)
{
  if(a < b){


    if(a<c){

      return a;

    }
    else{

      return c;

    }
  }
  else{

        if(b<c){

      return b;
    }

    else{

      return c;

    }


  }
}

int distanceEdition(string s1, string s2, int** E)
{
  int n1 = s1.size();
  int n2 = s2.size();
int e;
  for (int i = 0; i < n1 ; i++)
  {
    for (int j = 0; j < n2; j++)
    {
      if(s1[i]==s2[j]){
        e = 0 ;

      }
      else
      {
        e = 1;
      }
      
     int a = valeur(E,i-1, j)+1;
     int b = valeur(E,i, j-1)+1;
     int c = valeur(E,i-1, j-1)+e;

      E[i][j] = min(a,b,c);
      
    
    }
   
  }
  
  
  

  return E[n1-1][n2-1];
}

string alignement(string& s1, string& s2, int** E)
{
  int i = s1.size()-1;
  int j = s2.size()-1;
  string aligne = "                                                                                 ";

  int o = 0;

  while(i >= 0 && j >=0){

    if(valeur(E,i, j) == valeur(E,i-1, j-1) && s1[i]== s2[j]){

      if(i<=j)
        aligne.insert(i,"|");
      else
        aligne.insert(j,"|");
      
      i = i-1;
      j = j-1;


      ++o;
    }
    else if(valeur(E,i, j) == (valeur(E,i-1, j-1) + 1)){

      if(i<=j)
        aligne.insert(i,"R");
      else
        aligne.insert(j,"R");
      

      i = i-1;
      j = j-1;

      ++o;

    }
    else if(valeur(E,i, j) ==(valeur(E,i-1, j)+ 1)){
      if(i<=j)
        aligne.insert(i,"S");
      else
        aligne.insert(j,"S");

      i = i-1;
      s2.insert(j+1,"_");


      ++o;

    }
    else if(valeur(E,i, j) == (valeur(E,i, j-1) + 1)){

      if(i<=j)
        aligne.insert(i,"I");
      else
        aligne.insert(j,"I");

      j = j-1;
      s1.insert(i+1,"_");

      ++o;

    }


  }

    while(i >= 0){
      s2.insert(0,"_");
      i = i-1;

    }
    while(j >= 0){
      s1.insert(0,"_");
      j = j-1;

    }
    for(unsigned int i=0; i< aligne.size(); ++i)  
   {
      if(aligne[i] == ' ')  
      {
          aligne.erase(i,1);  
      }
   }


  
  return aligne;
}

int main(int argc, char** argv)
{

  string s1, s2;
  int** E;
  if (argc < 3)
  {
    cout << "Entrer la première chaîne de caractère : ";
    getline(cin, s1);
    cout << "Entrer la seconde chaîne de caractère : ";
    getline(cin, s2);
  }
  else
  {
    s1 = argv[1];
    s2 = argv[2];
  }

  E = matrice<int>(s1.size(), s2.size());
  int d = distanceEdition(s1, s2, E);
  cout << d << endl;
  
  // Décommenter si besoin, pour débugguer :
   //afficheMatrice(s1.size(), s2.size(), E);
  
  string aligne = alignement(s1, s2, E);
  cout << s1 << endl << aligne << endl << s2 << endl;

  delete E;
  return 0;
}
