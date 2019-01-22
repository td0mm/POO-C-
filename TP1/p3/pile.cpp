#include <iostream>
#include "pile.h"

using namespace std;


/*void t_pile::initialiser()
{
    int i = 0;

    for (i = 0; i < TAILLE; i++)
    {
        jeton[i] = 0;               // initialisation du tableau
    }

    imax = -1;


}*/

t_pile::t_pile(int x[], int valeur)
{
    imax = -1;
    int i = 0;

    for (i = 0; i < valeur; i++)
    {
        jeton[i] = x[i];       // initialisation du tableau
        imax ++;
    }

}


void t_pile::empiler(int val)
{
    int i;

    if (imax >= TAILLE)
    {
        cout < "trop de jetons";    // sécurité
    }

    else
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
