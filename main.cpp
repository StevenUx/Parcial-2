#include <iostream>
#include<QImage>
#include<funcion.h>
using namespace std;

int main()
{
    string filename ="../LeerImagen/imagen/circulo.jpg";
    QImage im (filename.c_str());


    int width = im.width();
    int height = im.height();

    unsigned char **output_img16;

    output_img16 = MemAlloc2D(16, 16, 0);

    FILE *inFile;
    fopen_s(&inFile, "../LeerImagen/imagen/circulo.jpg", "rb");

    if (inFile == NULL)
    {
        cout << "input image error";
        return 0;
    }

    unsigned char **input_img;

    input_img = MemAlloc2D(im.width(), im.height(), 0);

    for (int h = 0; h < height; h++)
    {
        fread(input_img[h], sizeof(unsigned char), im.width(), inFile);
    }

    for (int h = 0; h < 16; h++)
        {
            for (int w = 0; w < 16; w++)
            {
                double h_Ori = h/(16/ im.height());
                double w_Ori = w/(16/im.width());
                if (isInsideBoundary(16, 16,16/ im.height(), 16/im.width()))
                {
                    output_img16[h][w] = BilinearInterpolation(input_img, height, width, h_Ori, w_Ori);
                }
            }
        }

        MemFree2D(input_img, im.height() > im.width()? im.height() : im.width());
        MemFree2D(output_img16, 16);
        fclose(inFile);

     for(int indx=0;indx<im.width();++indx){
        for(int indy=0;indy < im.height();++indy){
            cout<<indx<<","<<indy<<"Rojo: "<<im.pixelColor(indx,indy).red()<<endl;
            cout<<indx<<","<<indy<<"verde: "<<im.pixelColor(indx,indy).green()<<endl;
            cout<<indx<<","<<indy<<"azul: "<<im.pixelColor(indx,indy).blue()<<endl;

        }
    }


    return 0;
};

