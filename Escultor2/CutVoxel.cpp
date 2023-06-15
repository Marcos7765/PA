#include "CutVoxel.hpp"

CutVoxel::CutVoxel(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
};

CutVoxel::Draw(Sculptor& Sculptor){
    Sculptor->v[x][y][z].show = false;
}