#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <cmath>
using namespace std;

void ecritureTailles(int n,int m, int comp[])
{

    
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
                if(comp[i]==comp[x])
                {
                    Taille[comp[i]]++;
                     

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

void composante(int n,int m,int edge[][2] , int comp[])
{
	int aux ;

	for(int i  = 0; i< n ; ++i)
	{
		comp[i] = i;

	}
		for(int j = 0 ; j < m ;++j)
		{
			int x = edge[j][0];
			int y = edge[j][1];

			if(comp[x] != comp[y])
			{
				aux = comp[x] ;
			

				for (int i = 0; i < n ; ++i)
				{
					if(comp[i] == aux)
					{
						comp[i] = comp[y]; 
					}
				}
		
			}
	}

for(int i  = 0; i< n ; ++i)
{
	cout << i  << " fais parti de la composante de " << comp[i] << endl;
}
cout << endl << endl << endl ;



}
/*
void composanteopti(int n,int m,int edge[][2] , int comp[])
{

    vector<int> vect;
	int aux ;

	for(int i  = 0; i< n ; ++i)
	{
        comp[i] = i;

	}
	for(int i  = 0; i< n ; ++i)
	{
        for(int j = 0 ; j < n ;++j)
		{


            if(comp[i] == comp[j])
                vect.push_back(i);

        }

    }
		for(int j = 0 ; j < m ;++j)
		{
			int x = edge[j][0];
			int y = edge[j][1];

			if(comp[x] != comp[y])
			{
				aux = comp[x] ;
			

				for (int i = 0; i < n ; ++i)
				{
					if(comp[i] == aux)
					{
						comp[i] = comp[y]; 
					}
				}
		
			}
	}

for(int i  = 0; i< n ; ++i)
{
	cout << i  << " fais parti de la composante de " << comp[i] << endl;
}
cout << endl << endl << endl ;



}
*/

void grapheRandom(int n, int m , int edge[][2])
{cout << endl << endl << endl ;
	srand(time(NULL));
	for(int i = 0 ; i < m ; ++i)
	{

		int x= rand()%n ;
		int y= rand()%n ;


		edge[i][0] = x;
		edge[i][1] = y;
		
		cout << edge[i][0] << +" ";
		cout << edge[i][1] << endl;
	}

cout << endl << endl << endl ;

}
int main()
{ 
  int n;     // Nombre de sommets.	
  int m;     // Nombre d'aretes.	
  cout << "Entrer le nombre de sommets:";
  cin >> n;
  cout << "Entrer le nombre d'aretes:";
  cin >> m;
  int edge[m][2];    // Tableau des aretes.
    int comp[n];       // comp[i] est le numero de la composante contenant i.
  grapheRandom(n , m , edge);
composante(n,m,edge,comp);
ecritureTailles(n,m,comp);

  return EXIT_SUCCESS;
}

