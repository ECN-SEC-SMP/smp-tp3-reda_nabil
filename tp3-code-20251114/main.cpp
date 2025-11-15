#include "outils.h"
#include "image.h"
#include "chargesauve.h"
#include "iostream"

int main ()

{
 seuillage("paysage.pgm", 150);
 difference("paysage.pgm", "peppers512x512.pgm");
}