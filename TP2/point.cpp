#include <iostream>
#include <cmath>
#include "point.h"
#include "bmp.h"

using namespace std;

point::point()
{
    x=0;
    y=0;
    couleur = ROUGE;
}

point::point(SHORT abs=0, SHORT ord=0, ULONG c=ROUGE)
{
    x=abs;
    y=ord;
    couleur = c;
}

point::point(point &p)
{
    x=p.x;
    y=p.y;
    couleur = p.couleur;
}

void point::afficher_p()
{
    cout<<x<<" . "<<y<<" . "<<std::hex<<couleur<<endl<<std::dec;
}

void point::translation(SHORT abs, SHORT ord)
{
    x=x+abs; //on ajoute une valeur en abscisse
    y=y+ord; //on ajoute une valeur en ordonnée
}

void point::homothetie(SHORT abs, SHORT ord, SHORT rapport){
    x=abs+(x-abs)*rapport; //on ajoute au nouveau point la différence entre ce point et le point actuel
    y=ord+(y-abs)*rapport; //multiplié par le rapport souhaité
}

void point::rotation(double angle){
    short a=x; //on met l'abscisse du point dans une variable pour ne pas la perdre
    double angle2=angle*(M_PI/180); //conversion en radian
    x=a*cos(angle2)-y*sin(angle2);
    y=a*sin(angle2)+y*cos(angle2);
    //x=a;
}

void point::afficher(Bmp &im, int LARGEUR, int HAUTEUR){
   if((x<LARGEUR)&&(y<HAUTEUR)){ //si le point est dans l'image
        im.setpixel(x,y,ROUGE); //on l'affiche
   }else{
        cout<<"Le point est en dehors de l'image."<<endl; //sinon message d'erreur
   }
}

int point::abscisse(){
    return x; //retourne l'abscisse du point
}

int point::ordonnee(){
    return y; //retourne l'ordonnée du point
}
