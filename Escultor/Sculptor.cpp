#include "Sculptor.hpp"
#include <iostream>
#include <fstream>
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

    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}

Sculptor::~Sculptor(){
    
    delete[] this->v[0][0];
    delete[] this->v[0];
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
    //dessa forma se pode desenhar caixas 'degeneradas' como quadrados, linhas e pontos. a checagem é feita aqui para poupar tempo
    int i=x0, j=y0, k=z0;
    do{
        if(i>=0 && i< nx){
            j=y0;
            do{
                if(j>=0 && j< ny){
                    k=z0;
                    do{
                        if(k>=0 && k<nz){
                        putVoxel(i,j,k);
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

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    //dessa forma se pode apagar caixas 'degeneradas' como quadrados, linhas e pontos. a checagem é feita aqui para poupar tempo
    int i=x0, j=y0, k=z0;
    do{
        if(i>=0 && i< nx){
            j=y0;
            do{
                if(j>=0 && j< ny){
                    k=z0;
                    do{
                        if(k>=0 && k<nz){
                        cutVoxel(i,j,k);
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

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    //iterando sobre [-radius, radius] para não desl. a eq. da esfera
    int i=-radius, j=-radius, k=-radius;
    do{
        if(xcenter+i>=0 && xcenter+i<nx){
            j=-radius;
            //otimização: para X fixo a eq. da esfera se torna eq. do círculo y*y + z*z <= r*r - xf*xf = limy2
            //int limy2 = (radius+i)*(radius-i);
            do{
                if(ycenter+j>=0 && ycenter+j< ny){
                    k=-radius;
                    //otimização: y fixo na eq. do círculo se torna eq. de intervalo z*z <= limy2 - y*y = limz2
                    //int limz2 = limy2 - j*j;
                    do{
                        if(zcenter+k>=0 && zcenter+k< nz){
                            if(i*i + j*j +k*k <= radius*radius){putVoxel(xcenter+i,ycenter+j,zcenter+k);}
                        }
                        k++;
                    } 
                    while (k <= radius);
                }
                j++;
            } 
            while (j<=radius);
        }
        i++;
    } 
    while (i<=radius);
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int i=-radius, j=-radius, k=-radius;
    do{
        if(xcenter+i>=0 && xcenter+i<nx){
            j=-radius;
            //otimização: para X fixo a eq. da esfera se torna eq. do círculo y*y + z*z <= r*r - xf*xf = limy2
            //int limy2 = (radius+i)*(radius-i);
            do{
                if(ycenter+j>=0 && ycenter+j< ny){
                    k=-radius;
                    //otimização: y fixo na eq. do círculo se torna eq. de intervalo z*z <= limy2 - y*y = limz2
                    //int limz2 = limy2 - j*j;
                    do{
                        if(zcenter+k>=0 && zcenter+k< nz){
                            if(i*i + j*j +k*k <= radius*radius){cutVoxel(xcenter+i,ycenter+j,zcenter+k);}
                        }
                        k++;
                    } 
                    while (k <= radius);
                }
                j++;
            } 
            while (j<=radius);
        }
        i++;
    } 
    while (i<=radius);
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int i=-rx, j=-ry, k=-rz;
    if( rx == 0 || ry == 0 || rz == 0){
        std::cerr << "Sem elipsóides degeneradas :(";
        return;
    }
    do{
        if(xcenter+i>=0 && xcenter+i< nx){
            j=-ry;
            //otimização: para X fixo a eq. da elipsoide se torna eq. da elipse y*y/ry*ry + z*z/rz*rz <= 1 - xf*xf/rx*rx = limy2
            //int limy2 = 1 - (i*i)/(rx*rx);
            do{
                if(ycenter+j>=0 && ycenter+j< ny){
                    k=-rz;
                    //otimização: y fixo na eq. do elipse se torna eq. de intervalo z*z <= (limy2 - yf*yf/ry*ry)*rz*rz = limz2*rz*rz
                    //int limz2 = limy2 - (j*j)/(ry*ry);
                    do{
                        if(zcenter+k>=0 && zcenter+k< nz){
                            if(((i*i)/(float)(rx*rx)) + ((k*k)/(float)(rz*rz)) + ((j*j)/(float)(ry*ry)) <= 1){putVoxel(xcenter+i,ycenter+j,zcenter+k);}
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

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int i=-rx, j=-ry, k=-rz;
    if( rx == 0 || ry == 0 || rz == 0){
        std::cerr << "Sem elipsóides degeneradas :(";
        return;
    }
    do{
        if(xcenter+i>=0 && xcenter+i< nx){
            j=-ry;
            //otimização: para X fixo a eq. da elipsoide se torna eq. da elipse y*y/ry*ry + z*z/rz*rz <= 1 - xf*xf/rx*rx = limy2
            //int limy2 = 1 - (i*i)/(rx*rx);
            do{
                if(ycenter+j>=0 && ycenter+j< ny){
                    k=-rz;
                    //otimização: y fixo na eq. do elipse se torna eq. de intervalo z*z <= (limy2 - yf*yf/ry*ry)*rz*rz = limz2*rz*rz
                    //int limz2 = limy2 - (j*j)/(ry*ry);
                    do{
                        if(zcenter+k>=0 && zcenter+k< nz){
                            if(((i*i)/(float)(rx*rx)) + ((k*k)/(float)(rz*rz)) + ((j*j)/(float)(ry*ry)) <= 1){cutVoxel(xcenter+i,ycenter+j,zcenter+k);}
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
                            arquivo << 4 << " " << contagem*8 << " " << contagem*8 +3 << " " << contagem*8 +2 << " " << contagem*8 +1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 +4 << " " << contagem*8 +5 << " " << contagem*8 +6 << " " << contagem*8 +7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 << " " << contagem*8 +1 << " " << contagem*8 +5 << " " << contagem*8 +4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 << " " << contagem*8 +4 << " " << contagem*8 +7 << " " << contagem*8 +3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 +3 << " " << contagem*8 +7 << " " << contagem*8 +6 << " " << contagem*8 +2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                            arquivo << 4 << " " << contagem*8 +1 << " " << contagem*8 +2 << " " << contagem*8 +6 << " " << contagem*8 +5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                            contagem += 1;
                        }
                    } else {
                        arquivo << 4 << " " << contagem*8 << " " << contagem*8 +3 << " " << contagem*8 +2 << " " << contagem*8 +1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 +4 << " " << contagem*8 +5 << " " << contagem*8 +6 << " " << contagem*8 +7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 << " " << contagem*8 +1 << " " << contagem*8 +5 << " " << contagem*8 +4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 << " " << contagem*8 +4 << " " << contagem*8 +7 << " " << contagem*8 +3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 +3 << " " << contagem*8 +7 << " " << contagem*8 +6 << " " << contagem*8 +2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        arquivo << 4 << " " << contagem*8 +1 << " " << contagem*8 +2 << " " << contagem*8 +6 << " " << contagem*8 +5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                        contagem += 1;
                    }
                }
            }
        }
    }
    arquivo.close();
    
}