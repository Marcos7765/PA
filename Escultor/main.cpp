#include "Sculptor.hpp"
#include <iostream>

int main(){
    
    Sculptor teste = Sculptor(50, 50, 50);
    
    teste.setColor(1.0,0.0,0.0,1.0);
    
    teste.putBox(49,40,49,45,49,40);

    teste.setColor(0.0,0.0,1.0,1.0);

    teste.putEllipsoid(10,5,10, 10, 5, 8);

    teste.setColor(0.0,1.0,0.0,1.0);

    teste.putSphere(40,20,20, 7);
    
    //teste.putSphere(5,5,5,1);

    teste.writeOFF("exemplo.off");
    return 0;
}