#include <iostream>
//program 1
//ROUX ARNAUD

using namespace std;

int remplitA(int *A );
int afficheA(int *A);

int main()
{
    int A[10];      //tableau dimension 10

    cout << "Exo1 C++ :\n" << endl;

    remplitA(A);
    afficheA(A);

    //référence vers case 5 du tableau :
    int &r = A[5];

    cout << r << endl;  //affiche la référence r :  A[5]

    r++;    //incrémente r => A[5] = A[5]+1

    cout << "r++ :" << endl;
    cout << r << endl;  //affiche la référence r :  A[5]

    int *p = &A[7];     // création du pointeur p=7
    p++;                // incrémentation du pointeur : p=8
    (*p)++;             // incrémentation de la valeur pointé : A[p=7+1] = A[p=7+1] +1


    cout << endl;
    afficheA(A);

    return 0;
}

int remplitA(int *A ){

    int i;
    int valeur=0;



    for (i=0; i<10; i++)
    {
        cin >> A[i];    //l'utilisateur rentre la valeur dans la case A[i]
    }
}


int afficheA(int *A){

int i;

    for (i=0; i<10; i++)
    {
        cout << "A[" << i << "] = " << A[i] << endl;    //la console affiche la case A[i]
    }

}

