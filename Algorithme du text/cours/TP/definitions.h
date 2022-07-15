#ifndef DEFIN
#define DEFIN
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string miroir(string u);
string alternate(string u, string v);
bool is_prefix(string u, string v);
bool is_suffix(string u, string v);
vector<string> tous_bords(string u);
string fibonacci(size_t n);
string fibonacci2(size_t n);
string fibonacci3(size_t n, string motun, string motdeux);
vector<size_t> recherche_naive(string m,string t);
//void rechercheNaif(string motif, string texte);

#endif
