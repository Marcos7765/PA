#include "FiguraGeometrica.hpp"

class CutVoxel : FiguraGeometrica {
    private:
    int x, y, z;
    public:
        cutVoxel(int x, int y, int z, int r, int g, int b, int a);
        ~CutVoxel();
        Draw(Sculptor& Sculptor);
}