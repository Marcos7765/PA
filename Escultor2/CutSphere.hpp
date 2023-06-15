#include "FiguraGeometrica.hpp"

class CutSphere : FiguraGeometrica {
    private:
    int x, y, z, raio, r, g, b, a;
    public:
        CutSphere(int x, int y, int z, int raio, int r, int g, int b, int a);
        ~CutSphere();
        Draw(Sculptor& Sculptor);
}