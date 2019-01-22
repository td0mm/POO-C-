#include <iostream>
#include "bmp.h"
#include "point.h"
#include "cercle.h"
#include "segment.h"
#include "facette.h"

#define HAUTEUR 512 //hauteur de l'image
#define LARGEUR 512 //largeur de l'image

int main()
{
    //short x, y;

    Bmp im(LARGEUR, HAUTEUR, NOIR); //on veut une image de taille 512x512 avec un fond noir
    //point pt1;//constructeur par défaut
    //pt1.afficher_p();
    //point pt2(250, 250, ROUGE); //constructeur avec paramètre
    cercle c1(200, 200, ROUGE, 50);
    //pt2.afficher_p();
    //point pt3(pt2); //constructeur par recopie
    //pt3.afficher_p();
    //pt2.afficher(im, LARGEUR, HAUTEUR); //affichage du point
    //.translation(50, 0); //translation du point
    //pt2.afficher(im, LARGEUR, HAUTEUR); //affichage du point
    //pt3.homothetie(70, 70, 6); //on effectue une homothétie

    //c1.afficherc(im, LARGEUR, HAUTEUR);
    //pt2.rotation(40);
    //pt2.afficher(im, LARGEUR, HAUTEUR); //affichage du point
    c1.rotation(20);
    c1.afficherc(im, LARGEUR, HAUTEUR);
    c1.translation(100, -50);
    c1.afficherc(im, LARGEUR, HAUTEUR);
    c1.homothetie(50, 50, 2);
    c1.afficherc(im, LARGEUR, HAUTEUR);

    //segment s1(40, 15, ROUGE, 60, 30, ROUGE);
    //s1.affichers(im, LARGEUR, HAUTEUR);
    //s1.translation(30, 0, 30, 0);
    //s1.rotation(90);
    //s1.homothetie(10, 10, 3);
    //s1.affichers(im, LARGEUR, HAUTEUR);

    //facette f1(10, 10, ROUGE, 20, 10, ROUGE, 20, 20, ROUGE, 10, 20, ROUGE);
    //f1.afficherf(im, LARGEUR, HAUTEUR);
    //f1.translation(20, 20, 20, 20, 20, 20, 20, 20);
    //f1.homothetie(5, 5, 5);
    //f1.afficherf(im, LARGEUR, HAUTEUR);
    //f1.translation(20, 20, 20, 20, 20, 20, 20, 20);
    //x=pt2.abscisse(); //renvoie l'abscisse du point
    //y=pt2.ordonnee(); //renvoie l'ordonnée du point
    //Bmp im(512, 512, NOIR); //on veut une image de taille 512x512 avec un fond noir
    //pt2.afficher(im); //affichage du point
    //pt2.afficher(im); //affichage du point
    im.write ("image1.bmp"); //l'image s'appelle image1

    return 0;
}
