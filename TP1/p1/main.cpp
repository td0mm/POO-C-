//Roux Arnaud TP4
#include <iostream>

using namespace std;

#define TAILLE 10


class t_pile
{
private:
    int jeton[TAILLE];          // déclaration tableau
    int imax;                   // déclaration imax

public:
    void initialiser();         // initialisation
    void empiler(int);          // empiler jeton
    void depiler();             // dépiler jeton
    int sommet();               // sommet de la pile
    int dernier_jeton();        // dernier jeton de la pile

};

int main()
{
    t_pile p;

    cout << "\n TP1 POO / p1 : Jeu des Tours de Hanoi :\n" << endl;
    p.initialiser();
    cout << "imax = "<< p.sommet() << endl;
    cout << "valeur placee au sommet = " << p.dernier_jeton() << endl;

    cout << "\n empiler 10 :\n" << endl;
    p.empiler(10);                                        // valeur jeton = 10
    cout << "imax = "<< p.sommet() << endl;
    cout << "valeur placee au sommet = " << p.dernier_jeton() << endl;

    cout << "\n empiler 15 :\n" << endl;
    p.empiler(15);
    cout << "imax = "<< p.sommet() << endl;
    cout << "valeur placee au sommet = " << p.dernier_jeton() << endl;

    cout << "\n empiler 20 :\n" << endl;
    p.empiler(20);
    cout << "imax = "<< p.sommet() << endl;
    cout << "valeur placee au sommet = " << p.dernier_jeton() << endl;

    cout << "\n depiler() :\n" << endl;
    p.depiler();
    cout << "imax = "<< p.sommet() << endl;
    cout << "valeur placee au sommet = " << p.dernier_jeton() << endl;
}

void t_pile::initialiser()
{
    int i = 0;

    for (i = 0; i <= TAILLE; i++)
    {
        jeton[i] = 0;               // initialisation du tableau
    }

    imax = -1;


}


void t_pile::empiler(int val)
{
    int i;

    //if (imax >= TAILLE)
    //{
    //    cout < "trop de jetons";    // sécurité
    //}

    //else
    {
        imax ++;
        jeton[imax] = val;          // donne la valeur au jeton ciblé

        for (i = 0; i < TAILLE; i++)
        {
           cout << jeton[i] << " ";
        }

        cout << endl << endl;
    }
}

void t_pile::depiler()
{
    int i;

    if (imax < 0)
    {
        cout << "plus de jetons";   // sécurité
    }

    else
    {
        jeton[imax] = 0;        // place la valeur du jeton ciblé à 0

        for (i = 0; i < TAILLE; i++)
        {

            cout << jeton[i] << " ";

        }
        imax --;

        cout << endl << endl;
    }
}


int t_pile::sommet()
{
    return imax;
}

int t_pile::dernier_jeton()
{
    if (imax == -1)
    {
        cout << "pas de jetons" << endl;       // si initialisation
    }

    else
    {
        return jeton[imax];
    }
}
