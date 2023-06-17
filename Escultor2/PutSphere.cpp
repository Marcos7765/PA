#include "PutSphere.hpp"
#include "Voxel.hpp"
#include "Sculptor.hpp"

PutSphere::PutSphere(int x, int y, int z, int raio, float r, float g, float b, float a){
    this->x = x;
    this->y = y;
    this->z = z;
    this->raio = raio;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
};

void PutSphere::Draw(Sculptor& Sculptor){
    int i=-raio, j=-raio, k=-raio;
    do{
        if(x+i>=0 && x+i<Sculptor.nx){
            j=-raio;
            //otimização: para X fixo a eq. da esfera se torna eq. do círculo y*y + z*z <= r*r - xf*xf = limy2
            //int limy2 = (raio+i)*(raio-i);
            do{
                if(y+j>=0 && y+j<Sculptor.ny){
                    k=-raio;
                    //otimização: y fixo na eq. do círculo se torna eq. de intervalo z*z <= limy2 - y*y = limz2
                    //int limz2 = limy2 - j*j;
                    do{
                        if(z+k>=0 && z+k<Sculptor.nz){
                            if(i*i + j*j +k*k <= raio*raio){
                                Sculptor.v[x+i][y+j][z+k] = Voxel{r, g, b, a, true};
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