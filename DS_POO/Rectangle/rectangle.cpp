#include "rectangle.h"

rectangle::rectangle() //Constructeur par défaut
{
    x=0; //Donne par défaut au point 1 0 en abscisse
    y=0; //Donne par défaut au point 1 0 en ordonnée
    couleur = ROUGE; //Donne par défaut au point 1 la couleur rouge
    x2=0; //Donne par défaut au point 2 0 en abscisse
    y2=0; //Donne par défaut au point 2 0 en ordonnée
    couleur2 = ROUGE; //Donne par défaut au point 2 la couleur rouge
}

rectangle::rectangle(SHORT abs=0, SHORT ord=0, ULONG c=ROUGE, SHORT abs2=0, SHORT ord2=0, ULONG c2=ROUGE) //Constructeur avec paramètres
{
/*Si aucun paramètre n'est choisit, les paramètres par défaut sont les mêmes
que pour le constructeur par défaut : 0 en abscisse, 0 en ordonnée et la couleur rouge pour les deux points.*/
    x=abs; //Donne en abscisse du point 1 le paramètre abs
    y=ord; //Donne en ordonnée du point 1 le paramètre ord
    couleur=c; //Donne au point 1 la couleur c
    x2=abs2; //Donne en abscisse du point 2 le paramètre abs2
    y2=ord2; //Donne en ordonnée du point 2 le paramètre ord2
    couleur2=c2; //Donne au point 2 la couleur c2
}

rectangle::rectangle(rectangle &s) //Constructeur par recopie
{
    x=s.x; //Recopie l'abscisse d'un point 1 et l'attribue au nouveau point 1
    y=s.y; //Recopie l'ordonnée d'un point 1 et l'attribue au nouveau point 1
    couleur = s.couleur; //Recopie la couleur d'un point 1 et l'attribue au nouveau point 1
    x2=s.x2; //Recopie l'abscisse d'un point 2 et l'attribue au nouveau point 2
    y2=s.y2; //Recopie l'ordonnée d'un point 2 et l'attribue au nouveau point 2
    couleur2 = s.couleur2; //Recopie la couleur d'un point 2 et l'attribue au nouveau point 2
}


void rectangle::affichers(Bmp &im, int LARGEUR, int HAUTEUR) //Affichage du segment sur l'image
{

    if(((x<LARGEUR)&&(y<HAUTEUR))&&((x2<LARGEUR)&&(y2<HAUTEUR)))  /*Si les abscisses des points 1 et 2 sont inférieures
    à la largeur de l'image et si les ordonnées des points 1 et 2 sont inférieures à la hauteur de l'image, c'est-à-dire
    si les points sont dans l'image.*/
    {
        im.line(x, y, x, y2, ROUGE); //On trace le segment
        im.line(x, y, x2, y, ROUGE); //On trace le segment
        im.line(x, y2, x2, y2, ROUGE); //On trace le segment
        im.line(x2, y2, x2, y, ROUGE); //On trace le segment


        //im.line(x, y, x2, y2, ROUGE); //On trace le segment
    }
    else
    {
        cout<<"Le point est en dehors de l'image."<<endl; //Sinon message d'erreur
    }
}

void rectangle::surface(){

    int s = 0;

    s = (x2-x)*(y2-y);

    cout<<"surface : "<<endl;
    cout<< s <<endl;
    cout<<"\n\n"<<endl;

}

void rectangle::translate(SHORT abs, SHORT ord) //Translation d'un rectangle
{
    x=x+abs; //On ajoute une valeur à l'ancienne abscisse du point 1
    y=y+ord; //On ajoute une valeur à l'ancienne ordonnée du point 1
    x2=x2+abs; //On ajoute une valeur à l'ancienne abscisse du point 2
    y2=y2+ord; //On ajoute une valeur à l'ancienne ordonnée du point 2

}


void rectangle::inclus(SHORT abs,SHORT ord){

    if( (abs<x2) && (abs > x) && (ord<y2) && (ord>y)  ){

        cout<<"le point : "<<endl;
        cout<< "("<< abs <<","<< ord <<") est a l'interieur du triangle\n\n\n" <<endl;
    }

}
