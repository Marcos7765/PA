#include "Sculptor.hpp"
#include <iostream>
#include <cstdlib>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    
    if (_nx < 1 || _ny < 1 || _nz < 1){
        std::cerr << "Invalid dimension value: (" << _nx << ", " << _ny << ", " << _nz << ")\n";
        std::exit(1);
    }
    
    this->nx = _nx;
    this->ny = _ny;
    this->nz = _nz;
    
    this->v = new Voxel**[_nx];
    for (int i=0; i<nx; i++){
        
        this->v[i] = new Voxel*[_ny];

        for (int j=0; j<ny; j++){
        
            this->v[i][j] = new Voxel[_nz];

            for (int k=0; k<ny; k++){
        
                this->v[i][j][k] = Voxel{0.0, 0.0, 0.0, 0.0, false};
            }
        }
    }

    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}

Sculptor::~Sculptor(){
    
    for (int i=0; i<nx; i++){

        for (int j=0; j<ny; j++){
        
            delete[] this->v[i][j];
        }
        delete[] this->v[i];
    }
    delete[] this->v;

};

void Sculptor::setColor(float r, float g, float b, float a){
    if (r > 1 || g > 1 || b > 1 || a > 1 || r < 0 || g < 0 || b < 0 || a < 0){
        std::cerr << "Invalid color value: (" << r << ", " << g << ", " << b << ", " << a << ")\n";
        return; // Não se deseja sair daqui para evitar que se perca o progresso
    }
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

//a função não dá erro para coordenadas inválidas, somente as ignora.
void Sculptor::putVoxel(int x, int y, int z){
    if (x >= 0 && y >= 0 && z >= 0 && x < nx && y < ny && z < nz){
    v[x][y][z] = Voxel{r, g, b, a, true};
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    if (x >= 0 && y >= 0 && z >= 0 && x < nx && y < ny && z < nz){
    v[x][y][z].show = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){}

void Sculptor::writeOFF(const char* filename){}