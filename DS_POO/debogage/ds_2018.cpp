#include <cstdlib>
#include <iostream>
using namespace std;

typedef unsigned int uint;

class ma_classe{
      private:
          int x,y;
      public:
          void afficher(){cout<<"x= "<<x<<endl<<"y= "<<y<<endl;};
          void set_coord(uint val_x, uint val_y){x=val_x, y=val_y;};
          ma_classe(uint val_x, uint val_y){x=val_x; y=val_y;};

}

/*class ma_fille:public ma_classe{
      private:
          uint color;
      public:
          ma_fille(){x=0;y=0;color=0;};
};*/


int main(){
    ma_classe p;
    //ma_fille f;

    p.set_coord(-10,20);
    p.afficher();
    //f.afficher();

    system("pause");
    return 0;
}

