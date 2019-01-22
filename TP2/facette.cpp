#include "facette.h"

facette::facette()
{
    x=0;
    y=0;
    couleur = ROUGE;
    x2=0;
    y2=0;
    couleur2 = ROUGE;
    x3=0;
    y3=0;
    couleur3 = ROUGE;
    x4=0;
    y4=0;
    couleur4 = ROUGE;
}

facette::facette(SHORT abs=0, SHORT ord=0, ULONG c=ROUGE, SHORT abs2=0, SHORT ord2=0, ULONG c2=ROUGE, SHORT abs3=0, SHORT ord3=0, ULONG c3=ROUGE, SHORT abs4=0, SHORT ord4=0, ULONG c4=ROUGE)
{
    //point(abs, ord, c);
    x=abs;
    y=ord;
    couleur=c;
    x2=abs2;
    y2=ord2;
    couleur2=c2;
    x3=abs3;
    y3=ord3;
    couleur3 = c3;
    x4=abs4;
    y4=ord4;
    couleur4 = c4;
}

facette::facette(facette &f)
{
    //point(&p);
    x=f.x;
    y=f.y;
    couleur = f.couleur;
    x2=f.x2;
    y2=f.y2;
    couleur2 = f.couleur2;
    x3=f.x3;
    y3=f.y3;
    couleur3 = f.couleur3;
    x4=f.x4;
    y4=f.y4;
    couleur4 = f.couleur4;
}

void facette::translation(SHORT abs, SHORT ord, SHORT abs2, SHORT ord2, SHORT abs3, SHORT ord3, SHORT abs4, SHORT ord4)
{
    x=x+abs; //on ajoute une valeur en abscisse
    y=y+ord; //on ajoute une valeur en ordonnée
    x2=x2+abs2; //on ajoute une valeur en abscisse
    y2=y2+ord2; //on ajoute une valeur en ordonnée
    x3=x3+abs3; //on ajoute une valeur en abscisse
    y3=y3+ord3; //on ajoute une valeur en ordonnée
    x4=x4+abs4; //on ajoute une valeur en abscisse
    y4=y4+ord4; //on ajoute une valeur en ordonnée

}

void facette::homothetie(SHORT abs, SHORT ord,  SHORT rapport){
    x=abs+(x-abs)*rapport; //on ajoute au nouveau point la différence entre ce point et le point actuel
    y=ord+(y-abs)*rapport; //multiplié par le rapport souhaité
    x2=abs+(x2-abs)*rapport; //on ajoute au nouveau point la différence entre ce point et le point actuel
    y2=ord+(y2-abs)*rapport; //multiplié par le rapport souhaité
    x3=abs+(x3-abs)*rapport; //on ajoute au nouveau point la différence entre ce point et le point actuel
    y3=ord+(y3-abs)*rapport; //multiplié par le rapport souhaité
    x4=abs+(x4-abs)*rapport; //on ajoute au nouveau point la différence entre ce point et le point actuel
    y4=ord+(y4-abs)*rapport; //multiplié par le rapport souhaité

}

void facette::rotation(double angle){
    short a=x; //on met l'abscisse du point dans une variable pour ne pas la perdre
    short a2=x2; //on met l'abscisse du point dans une variable pour ne pas la perdre
    double angle2=angle*(M_PI/180); //conversion en radian
    x=a*cos(angle2)-y*sin(angle2);
    y=a*sin(angle2)+y*cos(angle2);
    x2=a2*cos(angle2)-y2*sin(angle2);
    y2=a2*sin(angle2)+y2*cos(angle2);
    //x=a;
}

void facette::afficherf(Bmp &im, int LARGEUR, int HAUTEUR){

    //int i;
   if(((x<LARGEUR)&&(y<HAUTEUR))&&((x2<LARGEUR)&&(y2<HAUTEUR))&&((x3<LARGEUR)&&(y3<HAUTEUR))&&((x4<LARGEUR)&&(y4<HAUTEUR))){ //si le point est dans l'image
        im.line(x, y, x2, y2, ROUGE);
        im.line(x2, y2, x3, y3, ROUGE);
        im.line(x3, y3, x4, y4, ROUGE);
        im.line(x4, y4, x, y, ROUGE);

//        for(i=0; i<x; i++){
//            im.line(x+i, y, x4+i, y4, ROUGE);
//        }

   }else{
        cout<<"Le point est en dehors de l'image."<<endl; //sinon message d'erreur
   }
}
