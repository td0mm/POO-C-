#include "segment.h"

segment::segment()
{
    x=0;
    y=0;
    couleur = ROUGE;
    x2=0;
    y2=0;
    couleur2 = ROUGE;
}

segment::segment(SHORT abs=0, SHORT ord=0, ULONG c=ROUGE, SHORT abs2=0, SHORT ord2=0, ULONG c2=ROUGE)
{
    //point(abs, ord, c);
    x=abs;
    y=ord;
    couleur=c;
    x2=abs2;
    y2=ord2;
    couleur2=c2;
}

segment::segment(segment &s)
{
    //point(&p);
    x=s.x;
    y=s.y;
    couleur = s.couleur;
    x2=s.x2;
    y2=s.y2;
    couleur2 = s.couleur2;
}

void segment::translation(SHORT abs, SHORT ord, SHORT abs2, SHORT ord2)
{
    x=x+abs; //on ajoute une valeur en abscisse
    y=y+ord; //on ajoute une valeur en ordonnée
    x2=x2+abs2; //on ajoute une valeur en abscisse
    y2=y2+ord2; //on ajoute une valeur en ordonnée
}

void segment::homothetie(SHORT abs, SHORT ord,  SHORT rapport){
    x=abs+(x-abs)*rapport; //on ajoute au nouveau point la différence entre ce point et le point actuel
    y=ord+(y-abs)*rapport; //multiplié par le rapport souhaité
    x2=abs+(x2-abs)*rapport; //on ajoute au nouveau point la différence entre ce point et le point actuel
    y2=ord+(y2-abs)*rapport; //multiplié par le rapport souhaité
}

void segment::rotation(double angle){
    short a=x; //on met l'abscisse du point dans une variable pour ne pas la perdre
    short a2=x2; //on met l'abscisse du point dans une variable pour ne pas la perdre
    double angle2=angle*(M_PI/180); //conversion en radian
    x=a*cos(angle2)-y*sin(angle2);
    y=a*sin(angle2)+y*cos(angle2);
    x2=a2*cos(angle2)-y2*sin(angle2);
    y2=a2*sin(angle2)+y2*cos(angle2);
    //x=a;
}

void segment::affichers(Bmp &im, int LARGEUR, int HAUTEUR){

   if(((x<LARGEUR)&&(y<HAUTEUR))&&((x2<LARGEUR)&&(y2<HAUTEUR))){ //si le point est dans l'image
        im.line(x, y, x2, y2, ROUGE);
   }else{
        cout<<"Le point est en dehors de l'image."<<endl; //sinon message d'erreur
   }
}
