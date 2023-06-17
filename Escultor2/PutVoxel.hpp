#include "FiguraGeometrica.hpp"
#include "Sculptor.hpp"

/*WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment.*/
/**
 * @class PutVoxel
 * @brief Represents a voxel that is placed in a Sculptor.
 * 
 * The PutVoxel class inherits from the FiguraGeometrica class and provides
 * functionality to place a voxel in a Sculptor object. A voxel is a small
 * cube-shaped unit that can be used to create three-dimensional objects.
 */
class PutVoxel : public FiguraGeometrica {
    private:
        int x;    /**< The x-coordinate of the voxel. */
        int y;    /**< The y-coordinate of the voxel. */
        int z;    /**< The z-coordinate of the voxel. */
        float r;  /**< The red component of the voxel color. */
        float g;  /**< The green component of the voxel color. */
        float b;  /**< The blue component of the voxel color. */
        float a;  /**< The alpha (transparency) component of the voxel color. */
    
    public:
        /**
         * @brief Constructs a PutVoxel object with the specified parameters.
         * @param x The x-coordinate of the voxel.
         * @param y The y-coordinate of the voxel.
         * @param z The z-coordinate of the voxel.
         * @param r The red component of the voxel color.
         * @param g The green component of the voxel color.
         * @param b The blue component of the voxel color.
         * @param a The alpha (transparency) component of the voxel color.
         */
        PutVoxel(int x, int y, int z, float r, float g, float b, float a);
        
        /**
         * @brief Destroys the PutVoxel object.
         * 
         * This is the destructor of the PutVoxel class. It is responsible for
         * releasing any resources held by the object. 
         * Marcos — In which case there's none.
         */
        ~PutVoxel();
        
        /**
         * @brief Draws the voxel in the specified Sculptor object.
         * @param Sculptor The Sculptor object where the voxel will be drawn.
         * 
         * The Draw function is used to place the voxel with the specified
         * coordinates and color in the Sculptor object.
         * Marcos — It writes on the voxels grid of the Sculptor, v.
         */
        void Draw(Sculptor& Sculptor);
};