#include <iostream>
#include<QImage>
#include<funcion.h>
using namespace std;

#define fhSize 20 // final height size
#define fwSize 20 // final width size

int main()
{
    string filename = "../LeerImagen/imagen/cuadrado.jpg";
    QImage im (filename.c_str());


    int width = im.width();
    int height = im.height();

    unsigned char **output_img16;

    output_img16 = MemAlloc2D(fhSize, fwSize, 0);

    FILE *inFile;
    fopen_s(&inFile, "../LeerImagen/imagen/cuadrado.jpg", "rb");

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

    for (int h = 0; h < fhSize; h++)
        {
            for (int w = 0; w < fwSize; w++)
            {
                double h_Ori1 = float(fhSize)/ im.height();
                double h_Ori = h/h_Ori1;
                double w_Ori1 = float(fwSize)/im.width();
                double w_Ori = h/w_Ori1;

                if (isInsideBoundary(fhSize, fwSize,fhSize/ im.height(), fwSize/im.width()))
                {
                    output_img16[h][w] = BilinearInterpolation(input_img, height, width, h_Ori, w_Ori);
                }
            }
        }

    int ra[fhSize][fwSize];
    int ga[fhSize][fwSize];
    int ba[fhSize][fwSize];

     for(int indx=0;indx<fhSize;++indx){
        for(int indy=0;indy < fwSize;++indy){
            cout<<indx<<","<<indy<<"Rojo: "<<im.pixelColor(indx,indy).red()<<endl;
            cout<<indx<<","<<indy<<"verde: "<<im.pixelColor(indx,indy).green()<<endl;
            cout<<indx<<","<<indy<<"azul: "<<im.pixelColor(indx,indy).blue()<<endl;

            ra[indx][indy] = im.pixelColor(indx,indy).red();
            ga[indx][indy] = im.pixelColor(indx,indy).green();
            ba[indx][indy] = im.pixelColor(indx,indy).blue();


        }
    }
     MemFree2D(input_img, im.height() > im.width()? im.height() : im.width());
     MemFree2D(output_img16, fhSize > fwSize? fhSize : fwSize);
     fclose(inFile);


    return 0;
};


