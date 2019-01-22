#include <iostream>
#include "pile.h"

using namespace std;

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


