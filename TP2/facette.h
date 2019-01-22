#ifndef FACETTE_H
#define FACETTE_H

///////////////////////////////////////////////////////////
//   header inclus dans tous les fichiers sources        //
///////////////////////////////////////////////////////////
#include "bmp.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>
#include "point.h"
#include "cercle.h"
#include "segment.h"


class facette: public point{
private :
    int x, y, x2, y2, x3, y3, x4, y4;
    ULONG couleur1, couleur2, couleur3, couleur4;

public :
    facette();
    facette(SHORT, SHORT, ULONG, SHORT, SHORT, ULONG, SHORT, SHORT, ULONG, SHORT, SHORT, ULONG);
    facette(facette &);
    void translation(SHORT, SHORT, SHORT , SHORT, SHORT , SHORT, SHORT , SHORT);
    void rotation(double);
    void homothetie(SHORT, SHORT, SHORT);
    void afficherf(Bmp &, int, int);
};

#endif //FACETTE_H
