#ifndef CERCLE_H
#define CERCLE_H

//////////////////////////////////////////////////////////
//   header inclus dans tous les fichiers sources        //
///////////////////////////////////////////////////////////
#include "bmp.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>
#include "point.h"


class cercle: public point{
private :
    float r;

public :
    //cercle();
    cercle(SHORT abs, SHORT ord, ULONG c, float ray);
    //cercle(cercle &);
    void translation(SHORT, SHORT);
    void rotation(double);
    void homothetie(SHORT, SHORT, SHORT);
    void afficherc(Bmp &, int, int);
};

#endif //CERCLE_H
