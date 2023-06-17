#include "Sculptor.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    
    if (_nx < 1 || _ny < 1 || _nz < 1){
        std::cerr << "Invalid dimension value: (" << _nx << ", " << _ny << ", " << _nz << ")\n";
        std::exit(1);
    }
    
    this->nx = _nx;
    this->ny = _ny;
    this->nz = _nz;

    this->v = new Voxel**[_nx];
    Voxel** vd1 = new Voxel*[_nx*_ny];
    Voxel* vd2 = new Voxel[_nx*_ny*_nz];
    for (int i=0; i<nx; i++){
        
        this->v[i] = vd1 + (i*_ny);

        for (int j=0; j<ny; j++){
        
            this->v[i][j] = vd2 + i*_ny*_nz + j*_nz;

            for (int k=0; k<ny; k++){
        
                this->v[i][j][k] = Voxel{0.0, 0.0, 0.0, 0.0, false};
            }
        }
    }
}

Sculptor::~Sculptor(){
    
    delete[] this->v[0][0];
    delete[] this->v[0];
    delete[] this->v;

};

void Sculptor::writeOFF(const char* filename){

    std::ofstream arquivo(filename, std::ios::out);
    
    if (arquivo.is_open() == false){
        std::cerr << "Couldn't open/create the file.";
        std::exit(1);
    }

    arquivo << "OFF" << std::endl;
    int contagem = 0;
    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                if (v[i][j][k].show == true){
                    //visíveis na borda nn se simplificam (e acessariam um vizinho que não existe)
                    if (i != 0 && i != nx-1 && j != 0 && j != ny-1 && k != 0 && k != nz-1){
                        if ( (v[i][j][k-1].show ==false) || (v[i][j][k+1].show ==false) || (v[i][j-1][k].show ==false) || (v[i][j+1][k].show ==false) || (v[i-1][j][k].show ==false) || (v[i+1][j][k].show ==false)){
                            contagem += 1;
                        }
                    } else {
                        contagem += 1;
                    }
                }
            }
        }
    }
    
    arquivo << contagem*8 << " " << contagem*6 << " " << 0 << std::endl;

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                if (v[i][j][k].show == true){
                    //visíveis na borda nn se simplificam (e acessariam um vizinho que não existe)
                    if (i != 0 && i != nx-1 && j != 0 && j != ny-1 && k != 0 && k != nz-1){


                        if ( (v[i][j][k-1].show ==false) || (v[i][j][k+1].show ==false) || (v[i][j-1][k].show ==false) || (v[i][j+1][k].show ==false) || (v[i-1][j][k].show ==false) || (v[i+1][j][k].show ==false)){
                            arquivo << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                            arquivo << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                            arquivo << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                            arquivo << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                            arquivo << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                            arquivo << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                            arquivo << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                            arquivo << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                        }
                    } else { //caso visível na borda
                        arquivo << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                        arquivo << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                        arquivo << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                        arquivo << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                        arquivo << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                        arquivo << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                        arquivo << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                        arquivo << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                    }
                }
            }
        }
    }

    contagem = 0;
    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                if (v[i][j][k].show == true){
                    //visíveis na borda nn se simplificam (e acessariam um vizinho que não existe)
                    if (i != 0 && i != nx-1 && j != 0 && j != ny-1 && k != 0 && k != nz-1){
                        if ( (v[i][j][k-1].show ==false) || (v[i][j][k+1].show ==false) || (v[i][j-1][k].show ==false) || (v[i][j+1][k].show ==false) || (v[i-1][j][k].show ==false) || (v[i+1][j][k].show ==false)){
                            arquivo << 4 << " " << contagem*8 << " " << contagem*8 +3 << " " << contagem*8 +2 << " " << contagem*8 +1 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 +4 << " " << contagem*8 +5 << " " << contagem*8 +6 << " " << contagem*8 +7 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 << " " << contagem*8 +1 << " " << contagem*8 +5 << " " << contagem*8 +4 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 << " " << contagem*8 +4 << " " << contagem*8 +7 << " " << contagem*8 +3 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 +3 << " " << contagem*8 +7 << " " << contagem*8 +6 << " " << contagem*8 +2 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 +1 << " " << contagem*8 +2 << " " << contagem*8 +6 << " " << contagem*8 +5 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                            contagem += 1;
                        }
                    } else {
                        arquivo << 4 << " " << contagem*8 << " " << contagem*8 +3 << " " << contagem*8 +2 << " " << contagem*8 +1 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 +4 << " " << contagem*8 +5 << " " << contagem*8 +6 << " " << contagem*8 +7 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 << " " << contagem*8 +1 << " " << contagem*8 +5 << " " << contagem*8 +4 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 << " " << contagem*8 +4 << " " << contagem*8 +7 << " " << contagem*8 +3 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 +3 << " " << contagem*8 +7 << " " << contagem*8 +6 << " " << contagem*8 +2 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 +1 << " " << contagem*8 +2 << " " << contagem*8 +6 << " " << contagem*8 +5 << " " << std::fixed << std::setprecision(2) << v[i][j][k].r << " " << std::fixed << std::setprecision(2) << v[i][j][k].g << " " << std::fixed << std::setprecision(2) << v[i][j][k].b << " " << std::fixed << std::setprecision(2) << v[i][j][k].a << std::endl;
                        contagem += 1;
                    }
                }
            }
        }
    }
    arquivo.close();
    
}