#ifndef POINT_H
#define POINT_H

///////////////////////////////////////////////////////////
//   header inclus dans tous les fichiers sources        //
///////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>
#include "bmp.h"

using namespace std;

////////////////////////////////////
//Redefinition des types d'entiers//
////////////////////////////////////
typedef unsigned char BYTE;
typedef unsigned long int ULONG;
typedef unsigned short int USHORT;
typedef long LONG;
typedef short SHORT;
typedef char CHAR;


class point
{
protected :
    int x, y;
    ULONG couleur;

public :
    point();
    point(SHORT, SHORT, ULONG);
    point(point &);
    void translation(SHORT, SHORT);
    void rotation(double);
    void homothetie(SHORT, SHORT, SHORT);
    void afficher_p();
    int abscisse();
    int ordonnee();
    void afficher(Bmp &, int, int);
};

#endif //POINT_H
