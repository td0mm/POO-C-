#ifndef SEGMENT_H
#define SEGMENT_H

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


class segment: public point{
protected :
    int x2, y2;
    ULONG couleur2;

public :
    segment();
    segment(SHORT, SHORT, ULONG, SHORT, SHORT, ULONG);
    segment(segment &);
    void translation(SHORT, SHORT, SHORT , SHORT );
    void rotation(double);
    void homothetie(SHORT, SHORT, SHORT);
    void affichers(Bmp &, int, int);
};

#endif //SEGMENT_H
