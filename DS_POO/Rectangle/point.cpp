#include <iostream>
#include <cmath>
#include "point.h"
#include "bmp.h"

using namespace std;

point::point() //Constructeur par défaut
{
    x=0;    //Donne par défaut au point 0 en abscisse
    y=0;    //Donne par défaut au point 0 en ordonnée
    couleur = ROUGE; //Donne par défaut au point la couleur rouge
}

point::point(SHORT abs=0, SHORT ord=0, ULONG c=ROUGE) //Constructeur avec paramètres
{
    /*Si aucun paramètre n'est choisit, les paramètres par défaut sont les mêmes
    que pour le constructeur par défaut : 0 en abscisse, 0 en ordonnée et la couleur rouge*/
    x=abs; //Donne en abscisse du point le paramètre abs
    y=ord; //Donne en ordonnée du point le paramètre ord
    couleur = c; //Donne au point la couleur c
}

point::point(point &p)  //Constructeur par recopie
{
    x=p.x; //Recopie l'abscisse d'un point et l'attribue au nouveau point
    y=p.y; //Recopie l'ordonnée d'un point et l'attribue au nouveau point
    couleur = p.couleur; //Recopie la couleur d'un point et l'attribue au nouveau point
}

void point::afficher_p() //Affiche les caractéristiques du point sur la console
{
    //Cette fonction sert surtout pour débuguer quand l'image n'était pas encore créée
    cout<<x<<" . "<<y<<" . "<<std::hex<<couleur<<endl<<std::dec;
    //Pour afficher la couleur, on passe en héxadécimal, puis on repasse à la fin en décimal
}

void point::translation(SHORT abs, SHORT ord) //Translation d'un point
{
    x=x+abs; //On ajoute une valeur à l'ancienne abscisse
    y=y+ord; //On ajoute une valeur à l'ancienne ordonnée
}

void point::homothetie(SHORT abs, SHORT ord, SHORT rapport) //Homothétie d'un point
{
    x=abs+(x-abs)*rapport; //On ajoute au nouveau point la différence entre ce point et le point actuel
    y=ord+(y-abs)*rapport; //multiplié par le rapport souhaité
}

void point::rotation(double angle) //Rotation d'un point
{
    short a=x; //On met l'abscisse du point dans une variable pour ne pas la perdre
    double angle2=angle*(M_PI/180); //Conversion en radian
    x=a*cos(angle2)-y*sin(angle2); //Nouvelle abscisse du point
    y=a*sin(angle2)+y*cos(angle2); //Nouvelle ordonnée du point
}

void point::afficher(Bmp &im, int LARGEUR, int HAUTEUR) //Affiche un point sur l'image
{
    if((x<LARGEUR)&&(y<HAUTEUR))  /*Si l'abscisse du point est inférieure à la largeur de l'image et si
    l'ordonnée du point est inférieure à la hauteur de l'image, c'est-à-dire si le point est dans l'image.*/
    {
        im.setpixel(x,y,ROUGE); //On affiche le point
    }
    else
    {
        cout<<"Le point est en dehors de l'image."<<endl; //Sinon message d'erreur
    }
}

int point::abscisse() //Retourne l'abscisse du point
{
    return x; //retourne l'abscisse du point
}

int point::ordonnee() //Retourne l'ordonnée du point
{
    return y; //retourne l'ordonnée du point
}

void point::set_x( SHORT abs) //Fixe l'abcisse du point
{
    x=abs; //Nouvelle abscisse du point
}

void point::set_y(SHORT ord) //Fixe l'ordonnée du point
{
    y=ord; //Nouvelle ordonnée du point
}

void point::set_c(ULONG c) //Fixe la couleur du point
{
    couleur=c; //Nouvelle couleur du point
}
