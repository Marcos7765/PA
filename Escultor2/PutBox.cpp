#include "PutBox.hpp"
#include "Voxel.hpp"
#include "Sculptor.hpp"

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a){
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->x1 = x1;
    this->y1 = y1;
    this->z1 = z1;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
};

void PutBox::Draw(Sculptor& Sculptor){
    //dessa forma se pode desenhar caixas 'degeneradas' como quadrados, linhas e pontos. a checagem é feita aqui para poupar tempo
    int i=x0, j=y0, k=z0;
    do{
        if(i>=0 && i< Sculptor.nx){
            j=y0;
            do{
                if(j>=0 && j<Sculptor.ny){
                    k=z0;
                    do{
                        if(k>=0 && k<Sculptor.nz){
                        Sculptor.v[i][j][k] = Voxel{r, g, b, a, true};
                        }
                        (z1 >= z0) ? k++ : k--; 
                    } 
                    while ((z1 >= z0) ? k <= z1 : k >= z1);
                
                }
                (y1 >= y0) ? j++ : j--;
            } 
            while ((y1 >= y0) ? j<=y1 : j>=y1);
        }
        (x1 >= x0) ? i++ : i--;
    } 
    while ((x1 >= x0) ? i<=x1 : i>=x1);
}