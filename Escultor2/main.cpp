#include "Sculptor.hpp"
#include "PutVoxel.hpp"
#include "PutBox.hpp"
#include "PutSphere.hpp"
#include "PutEllipsoid.hpp"
#include "CutVoxel.hpp"
#include "CutBox.hpp"
#include "CutSphere.hpp"
#include "CutEllipsoid.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

void parser(std::vector<FiguraGeometrica*>& lista, std::string arqNome, int* nx, int* ny, int* nz){
    std::ifstream arquivo(arqNome, std::ios::in);
    if (!arquivo.is_open()){
        std::cout << "Não pude abrir o arquivo :(" << std::endl;
        exit(1);
    }
    std::string linha;
    std::getline(arquivo, linha);
    
    std::istringstream info(linha);
    std::string obj;
    

    if (!(info >> obj)){
        std::cout << "Entrada inválida: a 1a linha deve ser no formato \"dim <nx> <ny> <nz>\"" << std::endl;
        exit(1);
    }

    info >> *nx >> *ny >> *nz;

    while (std::getline(arquivo, linha)){    
        //sobrescrevendo info a cada leitura
        std::istringstream info(linha);
        if (!(info >> obj)){
            std::cout << "Uma linha vazia foi encontrada. " << obj <<std::endl;
            continue;
        }
        else {
            if (obj=="putvoxel"){
                int x, y, z;
                float r, g, b, a;
                //nn tem checagem se algum parâmetro estiver errado/faltando
                info >> x >> y >> z >> r >> g >> b >> a;
                lista.push_back(new PutVoxel(x, y, z, r, g, b, a));
                continue;
            }
            if (obj=="cutvoxel"){
                int x, y, z;
                info >> x >> y >> z;
                lista.push_back(new CutVoxel(x, y, z));
                continue;
            }
            if (obj=="putbox"){
                int x0, x1, y0, y1, z0, z1;
                float r, g, b, a;
                info >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                lista.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                continue;
            }
            if (obj=="cutbox"){
                int x0, x1, y0, y1, z0, z1;
                info >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                lista.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                continue;
            }
            if (obj=="putsphere"){
                int x, y, z, raio;
                float r, g, b, a;
                info >> x >> y >> z >> raio >> r >> g >> b >> a;
                lista.push_back(new PutSphere(x, y, z, raio, r, g, b, a));
                continue;
            }
            if (obj=="cutsphere"){
                int x, y, z, raio;
                info >> x >> y >> z >> raio;
                lista.push_back(new CutSphere(x, y, z, raio));
                continue;
            }
            if (obj=="putellipsoid"){
                int x, y, z, rx, ry, rz;
                float r, g, b, a;
                info >> x >> y >> z >> rx >> ry >> rz >> r >> g >> b >> a;
                lista.push_back(new PutEllipsoid(x, y, z, rx, ry, rz, r, g, b, a));
                continue;
            }
            if (obj=="cutellipsoid"){
                int x, y, z, rx, ry, rz;
                info >> x >> y >> z >> rx >> ry >> rz;
                lista.push_back(new CutEllipsoid(x, y, z, rx, ry, rz));
                continue;
            }
            std::cout << "Palavra não reconhecida: " << obj << std::endl;
        }
    }
    arquivo.close(); 
}

int main(){
    
    std::vector<FiguraGeometrica*> lItens;

    int* nx = new int;
    int* ny = new int;
    int* nz = new int;

    parser(lItens, "exemplo", nx, ny, nz);

    Sculptor teste = Sculptor(*nx, *ny, *nz);
 
    for (FiguraGeometrica* fig : lItens){        
        (*fig).Draw(teste);
        delete fig;
    }
    teste.writeOFF("exemplo.off");
    delete nx;
    delete ny;
    delete nz;
    return 0;
}