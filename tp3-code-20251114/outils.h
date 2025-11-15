#include "image.h"
using namespace std;
#include <string>
typedef unsigned int t_MatEnt2[TMAX][TMAX]; 

const int TMAX = 800;
struct structurant
{   
	
    int posicentreh;//popsi du centre
    int posicentrew;//position du centre
    int taille; //taille carré
	t_MatEnt2 A{};
};
void seuillage(string NomImage, unsigned int s);
void difference(string NomImage1, string NomImage2);
void dilatation(string NomImage1, structurant *p );

