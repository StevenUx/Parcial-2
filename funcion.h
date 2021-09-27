#ifndef FUNCION_H
#define FUNCION_H

void MemFree2D(unsigned char **Mem, int nHeight)
{
    for (int n = 0; n < nHeight; n++)
    {
        delete[] Mem[n];
    }
    delete[] Mem;
}

unsigned char** MemAlloc2D(int nHeight, int nWidth, unsigned char nInitVal)
{
    unsigned char** rtn = new unsigned char*[nHeight];
    for (int n = 0; n < nHeight; n++)
    {
        rtn[n] = new unsigned char[nWidth];
        memset(rtn[n], nInitVal, sizeof(unsigned char) * nWidth);
    }
    return rtn;
}

bool isInsideBoundary(int nHeight, int nWidth, double h, double w)
{
    if (h >= 0 && w >= 0 && h < nHeight && w < nWidth)
    {
        return true;
    }
    else return false;
}
unsigned char BilinearInterpolation(unsigned char** In, int nHeight_Ori, int nWidth_Ori, double h_Cvt, double w_Cvt)
{
    unsigned char r1, r2, r3, r4;
    unsigned char return_value;
    int h1, w1, h2, w2, h3, w3, h4, w4;

    h1 = int(h_Cvt); w1 = int(w_Cvt);
    h2 = h1; w2 = w1 + 1;
    h3 = h1 + 1; w3 = w1;
    h4 = h1 + 1; w4 = w1 + 1;

    if (h1 == nHeight_Ori - 1 && w1 == nWidth_Ori - 1)
        return 0;
    else if (h1 == nHeight_Ori - 1 && w1 != nWidth_Ori - 1)
        return 0;
    else if (h1 != nHeight_Ori - 1 && w1 == nWidth_Ori - 1)
        return 0;
    else
    {
        r1 = In[h1][w1];
        r2 = In[h2][w2];
        r3 = In[h3][w3];
        r4 = In[h4][w4];

        return_value = (h3 - h_Cvt)*((w2 - w_Cvt)*r1 + (w_Cvt - w1)*r2) + (h_Cvt - h1)*((w2 - w_Cvt)*r3 + (w_Cvt - w1)*r4);
        return return_value;
    }
}

#endif // FUNCION_H
