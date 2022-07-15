#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "definitions.h"

using namespace std;


int main() 
{

	string ifn, ofn, num;
	string u, v;

	cout<<"Donnez le numéro de l'exercice (entre 1 et 5) :"<<endl;
	cin>>num;
	switch (std::stoi(num.c_str())){
		case 1: 
		{
			cout<<"Exercice 1 - Donnez deux mots"<<endl;
			cin>>u;
			cin>>v;
			cout<<u<<v<<endl;
			cout<<miroir(u)<<endl;
			cout<<miroir(v)<<endl;
			cout<<alternate(u,v)<<endl; 
			break;
		}
		case 2: 
		{
			cout<<"Exercice 2 - Donnez un nom de fichier d'entrée et un nom de fichier de sortie"<<endl;
			cin>>ifn;
			cin>>ofn;
        		ifstream fichier(ifn.c_str(), ios::in);  // on ouvre le fichier en lecture
        		if(fichier)  // si l'ouverture a réussi
        		{       
            			getline(fichier,u);
				cout<<u<<endl;
				getline(fichier,v);
				cout<<v<<endl;
                		fichier.close();  // on ferme le fichier
        		}
        		else  // sinon
                		cerr << "Impossible d'ouvrir le fichier !" << endl;
			ofstream fichierout(ofn.c_str(), ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
        		if(fichierout)  // si l'ouverture a réussi
        		{
				fichierout<<endl<<"Exercice 1.1"<<endl;
				fichierout<<"============"<<endl;
				fichierout<<u<<v<<endl;;
				fichierout<<endl<<"Exercice 1.2"<<endl;
				fichierout<<"============"<<endl;
				fichierout<<miroir(u)<<endl;
				fichierout<<miroir(v)<<endl;
				fichierout<<endl<<"Exercice 1.3"<<endl;
				fichierout<<"============"<<endl;
				fichierout<<alternate(u,v)<<endl;
  	        		fichierout.close();  // on referme le fichier
        		}
        		else  // sinon
                		cerr << "Erreur à l'ouverture !" << endl;
			break;
		}
		case 3: 
		{
			vector<string> bords;	
			cout<<"Exercice 3 - Donnez deux mots"<<endl;
			cin>>u;
			cin>>v;
			if(is_prefix(u,v))
			{
				cout<<u<<" est un préfixe de "<<v<<endl;
				if(is_suffix(u,v))
				{
					cout<<u<<" est aussi un suffixe de "<<v<<" c'est donc un bord de "<<v<<endl;
				}
			} else {
				if(is_suffix(u,v))
				{
					cout<<u<<" est un suffixe de "<<v<<endl;
				} else {
					cout<<u<<" n'est ni préfixe ni suffixe de "<<v<<endl;
				}
			}
			cout<<"Donnez un mot dont on calculera les bords"<<endl;
			cin>>u;
			cout<<"Tous les bords de "<<u<<" sont :"<<endl;
			bords = tous_bords(u);
			for (size_t i = 0 ; i<bords.size() ; i++)
			{
				cout<<bords[i]<<endl;
			}
			break;
		}
		case 4:
		{
			for(size_t i=0; i<10; i++){
				cout<<fibonacci(i)<<endl;
				cout<<fibonacci2(i)<<endl;
				cout<<fibonacci3(i,"b","a")<<endl;
			}
			break; 
		}
		case 5:
		{
			clock_t start, end;
			vector<size_t> pos;
			cout<<"Indiquez le nom du fichier où se trouve le motif, ou le motif directement"<<endl;
			cin>>u;
			ifstream fmotif(u.c_str(),ios::in);
			if(fmotif){
				getline(fmotif,u);
				fmotif.close();
			} 
			cout<<"Indiquez le nom du fichier où se trouve le texte, ou le texte directement"<<endl;
			cin>>v;
			ifstream ftexte(v.c_str(),ios::in);
			if(ftexte){
				getline(ftexte,v);
				ftexte.close();
			} 
			start = clock();
			pos = recherche_naive(u,v);
			end = clock();
    			cout<<"Temps de calcul : "<<((float) end - start)/CLOCKS_PER_SEC<<endl;
			cout<<"Donnez le nom du fichier de résultat"<<endl;
			cin>>u;
			ofstream fresultat(u.c_str(),ios::out);
			if(fresultat)
			{
				for(size_t i = 0; i<pos.size(); i++)
				{
					fresultat<<pos[i]<<endl;
				}
				fresultat.close();		
			}
		}
		default:
			cout<<"Fin du TP1"<<endl;
	}

    return 0;
}
