#include "image.h"
using namespace std;
#include <string>



struct structurant
{   
	
    int posicentreh;//position height du centre
    int posicentrew;//position width du centre
    int taille; //taille du structurant
	t_MatEnt A{};//matrice du structurant
};
void seuillage(string NomImage, unsigned int s);
void difference(string NomImage1, string NomImage2);
void dilatation(string NomImage1, structurant *p );
void erosion(string NomImage1, structurant *p);
void fermeture(string NomImage1, structurant *p);
void ouverture(string NomImage1, structurant *p);
