#ifndef pile.h
#define TAILLE 10


class t_pile
{
private:
    int jeton[TAILLE];          // déclaration tableau
    int imax;                   // déclaration imax

public:
    t_pile(int x[], int valeur);                   // création de la fonction
    //void initialiser();       // initialisation
    void empiler(int);          // empiler jeton
    void depiler();             // dépiler jeton
    int sommet();               // sommet de la pile
    int dernier_jeton();        // dernier jeton de la pile

};

#endif


