#include "PutVoxel.hpp"

PutVoxel::PutVoxel(int x, int y, int z, int r, int g, int b, int a){
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
};

PutVoxel::Draw(Sculptor& Sculptor){
    Sculptor->v[x][y][z] = Voxel(r, g, b, a, true);
}