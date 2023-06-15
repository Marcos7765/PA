#include "FiguraGeometrica.hpp"

class PutVoxel : FiguraGeometrica {
    private:
    int x, y, z, r, g, b, a;
    public:
        PutVoxel(int x, int y, int z, int r, int g, int b, int a);
        ~PutVoxel();
        Draw(Sculptor& Sculptor);
}