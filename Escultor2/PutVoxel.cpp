#include "PutVoxel.hpp"
#include "Voxel.hpp"
#include "Sculptor.hpp"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a){
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
};

void PutVoxel::Draw(Sculptor& Sculptor){
    if (x>=0 && x<Sculptor.nx && y>=0 && y<Sculptor.ny && z>=0 && z<Sculptor.nz){
    Sculptor.v[x][y][z] = Voxel{r, g, b, a, true};
    }
}