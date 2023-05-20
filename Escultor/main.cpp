#include "Sculptor.hpp"
#include <iostream>

int main(){
    
    Sculptor teste = Sculptor(10, 10, 10);
    teste.setColor(1.0,0.0,0.0,1.0);
    
    teste.putEllipsoid(5,5,5, 1, 2, 1);
    
    //teste.putSphere(5,5,5,1);

    teste.writeOFF("marreco.off");
    return 0;
}