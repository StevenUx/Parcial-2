#include <iostream>
#include<QImage>
using namespace std;
int main()
{
    string filename ="../LeerImagen/imagen/circulo.jpg";
    QImage im (filename.c_str());

    for(int indx=0;indx<im.width();++indx){
        for(int indy=0;indy < im.height();++indy){
            cout<<indx<<","<<indy<<"Rojo: "<<im.pixelColor(indx,indy).red()<<endl;
            cout<<indx<<","<<indy<<"verde: "<<im.pixelColor(indx,indy).green()<<endl;
            cout<<indx<<","<<indy<<"azul: "<<im.pixelColor(indx,indy).blue()<<endl;

        }
    }

    return 0;
};

