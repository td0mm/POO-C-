#include <iostream>
#include "bmp.h"                    // Ajout de la librairie
#include "point.h"                  // Ajout de la librairie
#include "rectangle.h"

#define HAUTEUR 512 //Hauteur de l'image
#define LARGEUR 512 //Largeur de l'image

using namespace std;

int main()
{

    Bmp a(512, 512);


    rectangle s1(10, 10, ROUGE, 200, 200, ROUGE);
    s1.translate(15, 150); //Translation du segment
    s1.affichers(a, LARGEUR, HAUTEUR);


    a.write("rectangle.bmp");
    s1.surface();
    s1.inclus(150,190);

    return 0;
}

