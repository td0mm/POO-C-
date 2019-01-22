#include <iostream>
//program 2
//ROUX ARNAUD

using namespace std;

int main()
{
    int entier = 0;

    cout << "Exo2 C++ :\n" << endl;

    cin >> entier;

    int &r = entier;        //référence à : entier
    int *p = &entier;       //pointeur sur entier

    cout << "reference :\n\t\tvariable : " << r << "\n\t\tadresse : " << &r << "\n\t\tvaleur pointee : " << r << endl;
    cout << "pointeur ::\n\t\tvariable : " << *p << "\n\t\tadresse : " << p << "\n\t\tvaleur pointee : " << *p << endl;

    cout <<"\n\n\n\nvérification :  adresse entier " << &entier << endl;


    return 0;
}
