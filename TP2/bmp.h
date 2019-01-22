#ifndef BMP_H
#define BMP_H

///////////////////////////////////////////////////////////
//   header inclus dans tous les fichiers sources        //
///////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>
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

////////////////////////////////////
//Definition des couleurs de base
////////////////////////////////////
const ULONG ROUGE =0x00FF0000;
const ULONG BLEU  =0x000000FF;
const ULONG VERT  =0x0000FF00;
const ULONG JAUNE =0x00FFFF00;
const ULONG ROSE  =0x00FF00FF;
const ULONG CYAN  =0x0000FFFF;
const ULONG NOIR  =0x00000000;
const ULONG BLANC =0x00FFFFFF;

//////////////////////////////////////////////////////////////////
//              Definition de la classe Bmp                     //
//         Représente un fichier image au format Bmp            //
//////////////////////////////////////////////////////////////////
class Bmp
{
public:
    //Bmp(w,h, color): constructeur affectant la mémoire pour une image w*h de couleur de fond coul
    Bmp(SHORT,SHORT, ULONG coul=NOIR);
    ~Bmp(void);
    //Récupérer les attributs privés
    SHORT getW()
    {
        return width;
    };
    SHORT getH()
    {
        return height;
    };
    //affecte la couleur 'color' au pixel de coordonnees (X,Y)
    void setpixel(SHORT X,SHORT Y,ULONG color);
    //retourne la couleur d'un pixel
    ULONG getpixel(SHORT X,SHORT Y);
    //trace une ligne à partir de deux points
    void line(SHORT,SHORT,SHORT,SHORT,ULONG color);
    //Ecriture de l'image dans un fichier
    void write(CHAR *);
private:
    SHORT width;	    //largeur
    SHORT height;	    //hauteur
    LONG  length;	    //nombre d'octets de 'pixel' (3*largeur*hauteur)
    ULONG couleur;	//Couleur de fond de l'image
    BYTE * pixel;	    //tableau des pixels
    void convert(BYTE *, ULONG );
    void convert(BYTE *, USHORT);
};
#endif //BMP_H
