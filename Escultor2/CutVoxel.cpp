#include "CutVoxel.hpp"

CutVoxel::CutVoxel(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
};

void CutVoxel::Draw(Sculptor& Sculptor){
    if (x>=0 && x<Sculptor.nx && y>=0 && y<Sculptor.ny && z>=0 && z<Sculptor.nz){
    Sculptor.v[x][y][z].show = false;
    }   
}