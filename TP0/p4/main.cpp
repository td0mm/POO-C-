#include <iostream>
//ROUX ARNAUD

using namespace std;

#define taille 5                                // taille max

float moyenne(float *tab);
float moyenne(int *tab2);

int main()
{
    float tab[taille] = {8.5,12.5,9.0,16.2};    // remplissage du tableau de réels => moyenne de 9.24
    moyenne(tab);                               // calcul moyenne réel
    int tab2[taille] = {12,8,14,6,10};          // remplissage du tableau d'entiers => moyenne de 10
    moyenne(tab2);                              // calcul moyenne entiere
}


float moyenne(float *tab)
{
    int i;
    float moy, result;
    moy=0;
    result=0;
    for(i = 0; i<taille; i++)
    {
        moy = tab[i] + moy;
    }

    result = moy/taille;

    cout << "moyenne float: " << result << endl;
}

float moyenne(int *tab2)
{
    int i;
    int moy, result;
    moy=0;
    result=0;
    for(i = 0; i<taille; i++)
    {
        moy = tab2[i] + moy;
    }

    result = moy/taille;

    cout << "moyenne entiere: " << result << endl;

}
