#include "Sculptor.hpp"
#include <iostream>

int main(){
    
    Sculptor teste = Sculptor(50, 50, 50);
    
    teste.setColor(1.0,0.0,0.0,1.0);
    
    teste.putBox(49,38,28,39,49,38);

    teste.setColor(0.0,0.0,1.0,1.0);

    teste.putEllipsoid(10,5,10, 10, 5, 8);

    teste.setColor(0.0,1.0,0.0,1.0);

    teste.putSphere(40,20,20, 7);

    teste.putVoxel(49,0,0);
    
    teste.putVoxel(49,1,0);
    
    teste.cutVoxel(49,1,0);

    teste.cutBox(37,43,23,17,23,17);

    teste.cutEllipsoid(43,33,43,4, 8, 3);

    teste.cutSphere(10,3,10,3);

    teste.writeOFF("exemplo.off");
    return 0;
}