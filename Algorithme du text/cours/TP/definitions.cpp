#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


string miroir(string u)
{
	string mir = u;
	size_t i;
	for (i=0;i<u.length();i++)
	{
		mir[i] = u[u.length()-i-1];
	}
	return mir;
}

string alternate(string u, string v)
{
	string resultat = u+v;
	size_t i = 0,j = 0, k=0;
	while(k<u.length() + v.length())
	{
		if (i<u.length())
		{
			resultat[k] = u[i];
			k++;
			i++;
		}	
		if (j<v.length())
		{
			resultat[k] = v[j];
			k++;
			j++;
		}	

	}
	return resultat;
}

bool is_prefix(string u, string v)
{
	if (u.length() > v.length())
		return false;
	else
	{
		size_t i=0;
		while (u[i] == v[i])	
			i++;
		return !(i<u.length());
	}
	return false;
}

bool is_suffix(string u, string v)
{
	if (u.length() > v.length())
		return false;
	else
	{
		size_t i=0;

		while (u[u.length()-i] == v[v.length()-i])	
			i++;
		return !(i<u.length());
	}
	return false;
}

std::vector<std::string> tous_bords(string u)
{
	size_t i;
	std::vector<std::string> resultat;
	for(i=0;i<u.length();i++)
	{
		string pref = u.substr(0,i);
		if (is_suffix(pref,u)){
			resultat.push_back(pref);
		}
	}
	return resultat;
}

string fibonacci(size_t n) // itérative
{
	string resultat="", mota ="a", motb = "b";
	switch (n)
	{
		case 0: break;
		case 1: resultat = motb; break;
		case 2: resultat = mota; break;
	}
	while (n>2)
	{
		resultat = mota+motb;
		motb = mota;
		mota = resultat;
		n--;
	}
	return resultat;
}

string fibonacci2(size_t n) // récursive non optimisée
{
        switch (n)
        {
                case 0: return "";
                case 1: return "b"; 
                case 2: return "a"; 
        }
        return fibonacci2(n-1)+fibonacci2(n-2);
}

string fibonacci3(size_t n, string motun, string motdeux){// Récursive terminale
        switch (n)
        {
                case 0: return ""; 
                case 1: return motun;
                case 2: return motdeux;
        }
        return fibonacci3(n-1,motdeux,motdeux+motun);
}

vector<size_t> recherche_naive(string m,string t)
{
	size_t i,j;
	vector<size_t> resultat;
	for (i=0;i<t.length()-m.length()+1;i++)
	{
		j=0;
		while(t[i+j]==m[j] && j<m.length()) j++;
		if (j==m.length())
		{
			resultat.push_back(i);
		}
	}
	return resultat;
}

