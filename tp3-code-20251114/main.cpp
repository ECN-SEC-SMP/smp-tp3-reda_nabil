#include "outils.h"
#include "image.h"
#include "chargesauve.h"
#include "iostream"

int main ()

{
 seuillage("paysage.pgm", 150);
 difference("paysage.pgm", "peppers512x512.pgm");
 
 struct structurant * pv= new struct structurant;
 pv->taille=3;
 pv->posicentreh=1;
 pv->posicentrew=1;
 pv->A[0][0]=1;
 pv->A[1][0]=1;
 pv->A[2][0]=1;
 pv->A[0][1]=1;
 pv->A[0][2]=1;
 pv->A[1][1]=1;
 pv->A[1][2]=1;
 pv->A[2][1]=1;
 pv->A[2][2]=1;
 dilatation("paysage.pgmseuille", pv);
 erosion("paysage.pgmseuille", pv);
 fermeture("paysage.pgmseuille", pv);
 ouverture("paysage.pgmseuille", pv);
 delete pv;
 
 return 0;
}