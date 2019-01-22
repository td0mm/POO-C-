#include "bmp.h"
#include <iostream>


using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//Bmp(w,h, color): constructeur affectant la mémoire pour une image w*h de couleur de fond color//
//////////////////////////////////////////////////////////////////////////////////////////////////

Bmp::Bmp(SHORT w,SHORT h, ULONG couleur_fond)
{
    width=w;
    height=h;
    length=3*width*height;
    couleur=couleur_fond;
    pixel=new BYTE[length];
    for (LONG i=0; i<length; i+=3)
    {
        pixel[i]   =   255&couleur;       //B
        pixel[i+1] =   255&(couleur>>8);  //V
        pixel[i+2] =   255&(couleur>>16); //R
    }
}

////////////////////////////////////////////////////////////////
//destructeur de Bmp: libère la memoire occupée par les pixels//
////////////////////////////////////////////////////////////////
Bmp::~Bmp(void)
{
    if(pixel)
        delete [] pixel;
}

////////////////////////////////////////////////////////////////
//affecte la couleur 'color' au pixel de coordonnees (X,Y)    //
////////////////////////////////////////////////////////////////
void Bmp:: setpixel(SHORT X,SHORT Y,ULONG color)
{
    assert((X<width)&&(Y<height));

    BYTE R, G, B;
    LONG ind=3*(Y*width+X);

    R = (BYTE)(255&(color>>16));
    G = (BYTE)(255&(color>>8));
    B = (BYTE)(255&color);
    pixel[ind]  =	  B;	//B
    pixel[ind+1]=    G;    //G
    pixel[ind+2]=    R;	//R
    return;
}
//////////////////////////////////////////////////////////////
//retourne la couleur du pixel de coordonnees (X,Y) //
//////////////////////////////////////////////////////////////
ULONG Bmp::getpixel(SHORT X,SHORT Y)
{
    ULONG couleur;
    BYTE R,G,B;

    assert((Y<height)&&(X<width));

    LONG ind=3*(Y*width+X);

    R = pixel[ind+2];	//R
    G = pixel[ind+1];	//G
    B = pixel[ind];		//B

    couleur = 0;
    couleur = couleur|(R<<16);
    couleur = couleur|(G<<8);
    couleur = couleur|B;

    return couleur;
};
/////////////////////////////////////////////////////////////////////
//write(nom): écrit les données dans le fichier 'nom' (Bmp binaire)//
/////////////////////////////////////////////////////////////////////
void Bmp::write(CHAR * nom)
{
    ofstream out(nom,ios::binary);
    BYTE temp[4];

    //tester si le fichier est ouvert
    out.seekp(0,ios::end);
    if (out.tellp()<0)
    {
        out.close();
        throw("erreur d'ouverture de fichier");
        cout << "erreur d'ouverture de fichier"<<endl;
    }

    //ecriture de l'en-tête
    /* En tête fichier*/

    BYTE Sig[2];
    Sig[0]                 ='B';
    Sig[1]                 ='M';
    ULONG TailleFichier    =length+0x36; //En 24 bits! En 8 bits(v4.0): hauteur*largeur+0x36+1024
    ULONG Inconnu          =0;
    ULONG OffsetImage      =0x36; //taille des en-têtes
    ULONG taille           =40;

    out.write((char*)Sig, 2);
    convert(temp,TailleFichier);
    out.write((char*)temp, 4);
    convert(temp,Inconnu);
    out.write((char*)temp, 4);
    convert(temp,OffsetImage);
    out.write((char*)temp, 4);
    convert(temp,taille);
    out.write((char*)temp, 4);

    /* En-Tête BMP*/
    USHORT plan                       = 1;
    USHORT bpp                        = 24;
    ULONG  compression                = 0;
    ULONG  tailleimage                = 3*width*height;
    ULONG  resol_horz                 = 0;
    ULONG  resol_vert                 = 0;
    ULONG  nb_couleurs                = 0;
    ULONG  nb_couleurs_importantes    = 0;

    convert(temp,(USHORT)width);
    out.write((char*)temp, 4);
    convert(temp,(USHORT)height);
    out.write((char*)temp, 4);
    convert(temp,plan);
    out.write((char*)temp, 2);
    convert(temp,bpp);
    out.write((char*)temp, 2);
    convert(temp,compression);
    out.write((char*)temp, 4);
    convert(temp,tailleimage);
    out.write((char*)temp, 4);
    convert(temp,resol_horz);
    out.write((char*)temp, 4);
    convert(temp,resol_vert);
    out.write((char*)temp, 4);
    convert(temp,nb_couleurs);
    out.write((char*)temp, 4);
    convert(temp,nb_couleurs_importantes);
    out.write((char*)temp, 4);

    /*ecriture des valeurs des pixels*/
    out.write((char *)pixel,length);
    out.close();

    return;
}
////////////////////////////////////////////////
//diff(a,b): retourne la distance entre a et b//
////////////////////////////////////////////////
inline SHORT diff(ULONG a,ULONG b)
{
    return a>b?a-b:b-a;
}


void Bmp::line(SHORT I1,SHORT J1,SHORT I2,SHORT J2,ULONG color)
{

    SHORT dI,dJ,incrI,incrJ,currentI,currentJ,dPi,dPj,dPij,P;


    //Algorithme de Bresenham (1962)
    dI=diff(I1,I2);
    dJ=diff(J1,J2);
    currentI=I1;
    currentJ=J1;
    incrI=(I2>I1?1:-1);
    incrJ=(J2>J1?1:-1);


    if (dJ>=dI)	//|tan(theta)|<=1
    {
        dPj=dI<<1;
        dPij=dPj-(dJ<<1);
        P=dPj-dJ;

        for(; dJ>=0; dJ--)
        {
            setpixel(currentI,currentJ,color);
            if(P>0)
            {
                currentI+=incrI;
                currentJ+=incrJ;
                P+=dPij;
            }
            else
            {
                currentJ+=incrJ;
                P+=dPj;
            }
        }
    }
    else 		//|tan(theta)|>1
    {
        dPi=dJ<<1;
        dPij=dPi-(dI<<1);
        P=dPi-dI;

        for(; dI>=0; dI--)
        {
            setpixel(currentI,currentJ,color);
            if(P>0)
            {
                currentJ+=incrJ;
                currentI+=incrI;
                P+=dPij;
            }
            else
            {
                currentI+=incrI;
                P+=dPi;
            }
        }
    }

    return;
}

//////////////////////////////////////////////////////////
// Les fonctions privées                                //
//////////////////////////////////////////////////////////

void Bmp:: convert(BYTE *temp, ULONG Champ)
{
    BYTE  *ptr;
    ULONG *ptr_u;

    ptr_u=&Champ;
    ptr = (BYTE*)ptr_u;

    temp[0]= *ptr;
    temp[1]= *(ptr+1);
    temp[2]= *(ptr+2);
    temp[3]= *(ptr+3);
}
void Bmp:: convert(BYTE *temp, USHORT Champ)
{
    BYTE  *ptr;
    USHORT *ptr_u;

    ptr_u=&Champ;
    ptr = (BYTE*)ptr_u;

    temp[0]= *ptr;
    temp[1]= *(ptr+1);
}
