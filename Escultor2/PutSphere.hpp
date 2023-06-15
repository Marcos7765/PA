#include "FiguraGeometrica.hpp"

class PutSphere : FiguraGeometrica {
    private:
    int x, y, z, raio, r, g, b, a;
    public:
        PutSphere(int x, int y, int z, int raio, int r, int g, int b, int a);
        ~PutSphere();
        Draw(Sculptor& Sculptor);
}