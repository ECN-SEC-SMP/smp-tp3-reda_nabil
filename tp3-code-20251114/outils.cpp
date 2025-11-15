using namespace std;
#include <string>
#include "outils.h"
#include "chargesauve.h"
#include "iostream"
#include <cmath>

void seuillage(string NomImage, unsigned int s)
{bool Ok;
struct t_Image * p= new struct t_Image;
loadPgm(NomImage,p,Ok);

for (int i=0; i<p->w; i++)
{  for (int j=0;j<p->h; j++)
 { if(p->im[j][i]<s)

{ p->im[j][i]=0;}
else
{p->im[j][i]=255;}} 
}

string newname=NomImage+"seuillée";
savePgm(newname,p);
delete p;
p=nullptr;

}

void difference(string NomImage1, string NomImage2) 

{bool Ok;
struct t_Image * p= new struct t_Image;
struct t_Image * pt= new struct t_Image;
struct t_Image * diff= new struct t_Image;

loadPgm(NomImage1,p,Ok);
loadPgm(NomImage2,pt,Ok);
diff->w = p->w;
diff->h = p->h;

for (int i=0; i<p->w; i++)
{  for (int j=0;j<p->h; j++)
{diff->im[j][i]=abs(int(p->im[j][i])-int(pt->im[j][i]));}

}
string newname=NomImage1+"diff";
savePgm(newname,diff);
delete p;
p=nullptr;
delete pt;
pt=nullptr;
delete diff;
diff=nullptr;

}
void dilatation(string NomImage1, structurant *p)
{bool Ok;
struct t_Image * pt= new struct t_Image;
loadPgm(NomImage1,pt,Ok);
for ()
for (int i=0; i<p->taille; i++)
{  for (int j=0;j<p->taille; j++)
{}


 
}}





 



