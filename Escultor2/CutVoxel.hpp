#include "FiguraGeometrica.hpp"
#include "Sculptor.hpp"

/* WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment. */

/**
 * @class CutVoxel
 * @brief Represents a voxel that is cut from a Sculptor.
 * 
 * The CutVoxel class inherits from the FiguraGeometrica class and provides
 * functionality to cut a voxel from a Sculptor object. A voxel is a small
 * three-dimensional cube element in a grid.
 */
class CutVoxel : public FiguraGeometrica {
    private:
        int x;  /**< The x-coordinate of the voxel to cut. */
        int y;  /**< The y-coordinate of the voxel to cut. */
        int z;  /**< The z-coordinate of the voxel to cut. */
    
    public:
        /**
         * @brief Constructs a CutVoxel object with the specified parameters.
         * @param x The x-coordinate of the voxel to cut.
         * @param y The y-coordinate of the voxel to cut.
         * @param z The z-coordinate of the voxel to cut.
         */
        CutVoxel(int x, int y, int z);
        
        /**
         * @brief Destroys the CutVoxel object.
         * 
         * This is the destructor of the CutVoxel class. It is responsible for
         * releasing any resources held by the object.
         * 
         * @note Since CutVoxel doesn't own any resources directly, this destructor
         * doesn't perform any specific cleanup.
         */
        ~CutVoxel();
        
        /**
         * @brief Cuts the voxel from the specified Sculptor object.
         * @param Sculptor The Sculptor object from which to cut the voxel.
         * 
         * The Draw function is used to cut the voxel at the specified coordinates
         * from the Sculptor object. It modifies the voxels grid of the Sculptor.
         */
        void Draw(Sculptor& Sculptor);
};
