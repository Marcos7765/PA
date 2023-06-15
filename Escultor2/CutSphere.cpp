#include "CutSphere.hpp"

CutSphere::CutSphere(int x, int y, int z, int raio, int r, int g, int b, int a){
    this->x = x;
    this->y = y;
    this->z = z;
    this->raio = raio;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
};

CutSphere::Draw(Sculptor& Sculptor){
    int i=-raio, j=-raio, k=-raio;
    do{
        if(x+i>=0 && x+i<nx){
            j=-raio;
            //otimização: para X fixo a eq. da esfera se torna eq. do círculo y*y + z*z <= r*r - xf*xf = limy2
            //int limy2 = (raio+i)*(raio-i);
            do{
                if(y+j>=0 && y+j< ny){
                    k=-raio;
                    //otimização: y fixo na eq. do círculo se torna eq. de intervalo z*z <= limy2 - y*y = limz2
                    //int limz2 = limy2 - j*j;
                    do{
                        if(z+k>=0 && z+k< nz){
                            if(i*i + j*j +k*k <= raio*raio){
                                Sculptor->v[i][j][j].show = false;
                            }
                        }
                        k++;
                    } 
                    while (k <= raio);
                }
                j++;
            } 
            while (j<=raio);
        }
        i++;
    } 
    while (i<=raio);
}