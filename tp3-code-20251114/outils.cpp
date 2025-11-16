using namespace std;
#include <string>
#include "outils.h"
#include "chargesauve.h"
#include "iostream"
#include <cmath>

void seuillage(string NomImage, unsigned int s)//seuillage de l'image
{bool Ok;//variable de controle
struct t_Image * p= new struct t_Image;//allocation dynamique de l'image
loadPgm(NomImage,p,Ok);//chargement de l'image

for (int i=0; i<p->w; i++)//parcours de la largeur
{  for (int j=0;j<p->h; j++)//parcours de la hauteur
 { if(p->im[j][i]<s)//comparaison avec le seuil

{ p->im[j][i]=0;}//mise a zero si inferieur au seuil
else
{p->im[j][i]=255;}} //mise a 255 si superieur ou egal au seuil
}

string newname=NomImage+"seuille";//nom de l'image seuillée
savePgm(newname,p);//sauvegarde de l'image seuillée
delete p;//liberation de la memoire
p=nullptr;

}

void difference(string NomImage1, string NomImage2) //fonction de difference entre deux images

{bool Ok;//variable de controle
struct t_Image * p= new struct t_Image;//allocation dynamique de la premiere image
struct t_Image * pt= new struct t_Image;//allocation dynamique de la deuxieme image
struct t_Image * diff= new struct t_Image;//allocation dynamique de l'image difference

loadPgm(NomImage1,p,Ok);//chargement de la premiere image
loadPgm(NomImage2,pt,Ok);//chargement de la deuxieme image
diff->w = p->w;//largeur de l'image difference
diff->h = p->h;//hauteur de l'image difference

for (int i=0; i<p->w; i++)//parcours de la largeur
{  for (int j=0;j<p->h; j++)//parcours de la hauteur
{diff->im[j][i]=abs(int(p->im[j][i])-int(pt->im[j][i]));}//calcul de la difference absolue

}
string newname=NomImage1+"diff";//nom de l'image difference
savePgm(newname,diff);//sauvegarde de l'image difference
delete p;//liberation de la memoire
p=nullptr;
delete pt;//liberation de la memoire
pt=nullptr;
delete diff;//liberation de la memoire
diff=nullptr;

}
void dilatation(string NomImage1, structurant *p) //fonction de dilatation

{bool Ok;//variable de controle
struct t_Image *pt = new struct t_Image;//allocation dynamique de l'image originale
struct t_Image *pt1 = new struct t_Image;//allocation dynamique de l'image dilatée

loadPgm(NomImage1, pt, Ok);//chargement de l'image originale

loadPgm(NomImage1, pt1, Ok);//chargement de l'image dilatée
for (int i = 0; i < pt1->h; i++) //initialisation de l'image dilatée a  noir
{
    for (int j = 0; j < pt1->w; j++) 
      {pt1->im[i][j] = 0;}
}

for (int i = 0; i < pt->h; i++) //parcours de l'image originale
{
    for (int j = 0; j < pt->w; j++) 
{   if (pt->im[i][j] == 255) //si le pixel est blanc
{
    for (int t = 0; t < p->taille; t++) //parcours du structurant
{     for (int y = 0; y < p->taille; y++) 
      {if (p->A[t][y] == 1) //si le pixel du structurant est blanc
        {int out_i = i + (t - p->posicentreh);//calcule de la position relative du pixel dans l'image dilatée
         int out_j = j + (y - p->posicentrew);//calcul de la position relative du pixel dans l'image dilatée

       if (out_i >= 0 && out_i < pt1->h && out_j >= 0 && out_j < pt1->w) //vérification des limites de l'image
             {pt1->im[out_i][out_j] = 255;}//mise a blanc du pixel dans l'image dilatée
}}}}}}

string newname = NomImage1 + "dilated";
savePgm(newname, pt1);

delete pt;
delete pt1;
}


void erosion(string NomImage1, structurant *p) //fonction d'erosion

{bool Ok;//variable de controle
struct t_Image *pt = new struct t_Image;//allocation dynamique de l'image originale
struct t_Image *pt1 = new struct t_Image;//allocation dynamique de l'image erodee

loadPgm(NomImage1, pt, Ok);//chargement de l'image originale

loadPgm(NomImage1, pt1, Ok);//chargement de l'image erodee
for (int i = 0; i < pt1->h; i++) //initialisation de l'image erodee a blanc
  {for (int j = 0; j < pt1->w; j++) 
       {pt1->im[i][j] = 255;}
                                }

for (int i = 0; i < pt->h; i++) //parcours de l'image originale
     {for (int j = 0; j < pt->w; j++) 
         {if (pt->im[i][j] == 0) //si le pixel est noir
       {for (int t = 0; t < p->taille; t++) //parcours du structurant
          {for (int y = 0; y < p->taille; y++) 
             {if (p->A[t][y] == 1) //si le pixel du structurant est blanc
                {int out_i = i + (t - p->posicentreh);//calcule de la position relative du pixel dans l'image erodee
                 int out_j = j + (y - p->posicentrew);//calcul de la position relative du pixel dans l'image erodee

              if (out_i >= 0 && out_i < pt1->h && out_j >= 0 && out_j < pt1->w) 
                       {pt1->im[out_i][out_j] = 0;}//mise a noir du pixel dans l'image erodee
}}}}}}

string newname = NomImage1 + "eroded";
savePgm(newname, pt1);



delete pt;
delete pt1;
}

void fermeture(string NomImage1, structurant *p)

{
    dilatation(NomImage1,p);//appel de la dilatation
    erosion(NomImage1 + "dilated",p);//appel de l'erosion
   

}
void ouverture(string NomImage1, structurant *p)

{
    erosion(NomImage1,p);//appel de l'erosion
    dilatation(NomImage1 + "eroded",p);//appel de la dilatation
    

}