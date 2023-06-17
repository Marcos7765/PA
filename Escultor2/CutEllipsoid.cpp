#include "CutEllipsoid.hpp"
#include "Voxel.hpp"
#include <iostream>

CutEllipsoid::CutEllipsoid(int x, int y, int z, int rx, int ry, int rz){
    this->x = x;
    this->y = y;
    this->z = z;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
};

void CutEllipsoid::Draw(Sculptor& Sculptor){
    int i=-rx, j=-ry, k=-rz;
    if( rx == 0 || ry == 0 || rz == 0){
        std::cerr << "Sem elipsóides degeneradas :(";
        return;
    }
    do{
        if(x+i>=0 && x+i<Sculptor.nx){
            j=-ry;
            //otimização: para X fixo a eq. da elipsoide se torna eq. da elipse y*y/ry*ry + z*z/rz*rz <= 1 - xf*xf/rx*rx = limy2
            //int limy2 = 1 - (i*i)/(rx*rx);
            do{
                if(y+j>=0 && y+j<Sculptor.ny){
                    k=-rz;
                    //otimização: y fixo na eq. do elipse se torna eq. de intervalo z*z <= (limy2 - yf*yf/ry*ry)*rz*rz = limz2*rz*rz
                    //int limz2 = limy2 - (j*j)/(ry*ry);
                    do{
                        if(z+k>=0 && z+k<Sculptor.nz){
                            if(((i*i)/(float)(rx*rx)) + ((k*k)/(float)(rz*rz)) + ((j*j)/(float)(ry*ry)) <= 1){
                                Sculptor.v[x+i][y+j][z+k].show = false;
                                }
                        }
                        k++;
                    } 
                    while (k<=rz);
                }
                j++;
            } 
            while (j<=ry);
        }
        i++;
    } 
    while (i<=rx);
}