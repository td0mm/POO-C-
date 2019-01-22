#include "cercle.h"

//cercle::cercle()
//{
//    point();
//    r=5;
//}

cercle::cercle(SHORT abs=0, SHORT ord=0, ULONG c=ROUGE, float ray=5)
{
    //point(abs, ord, c);
    x=abs;
    y=ord;
    couleur=c;
    r=ray;
}

//cercle::cercle(cercle &p)
//{
//    point(&p)
//    r=p.r;
//}

void cercle::translation(SHORT abs, SHORT ord)
{
    x=x+abs; //on ajoute une valeur en abscisse
    y=y+ord; //on ajoute une valeur en ordonnée
}

void cercle::homothetie(SHORT abs, SHORT ord, SHORT rapport){
    x=abs+(x-abs)*(rapport); //on ajoute au nouveau point la différence entre ce point et le point actuel
    y=ord+(y-abs)*(rapport); //multiplié par le rapport souhaité
    r=r*rapport;
}

void cercle::rotation(double angle){
    short a=x; //on met l'abscisse du point dans une variable pour ne pas la perdre
    double angle2=angle*(M_PI/180); //conversion en radian
    x=a*cos(angle2)-y*sin(angle2);
    y=a*sin(angle2)+y*cos(angle2);
    //x=a;
}

void cercle::afficherc(Bmp &im, int LARGEUR, int HAUTEUR){
   int i, u, v;

   if((x<LARGEUR)&&(y<HAUTEUR)){ //si le point est dans l'image
        for(i=0; i<2*r; i++){
        u=(r-i);
        v=sqrt((r*r)-((u)*(u)));
        im.setpixel((x+u),y+v,ROUGE); //on l'affiche
        im.setpixel((x+u),y-v,ROUGE); //on l'affiche

        im.setpixel((x+v),(y+u),ROUGE); //on l'affiche
        im.setpixel(x-v,(y+u),ROUGE); //on l'affiche
        }

   }else{
        cout<<"Le point est en dehors de l'image."<<endl; //sinon message d'erreur
   }
}
