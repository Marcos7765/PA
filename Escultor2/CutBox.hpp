#include "FiguraGeometrica.hpp"
#include "Sculptor.hpp"

/* WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment. */

/**
 * @class CutBox
 * @brief Represents a box that is cut from a Sculptor.
 * 
 * The CutBox class inherits from the FiguraGeometrica class and provides
 * functionality to cut a box from a Sculptor object. A box is a three-dimensional
 * geometric shape with parallel faces and right angles.
 */
class CutBox : public FiguraGeometrica {
    private:
        int x0;    /**< The x-coordinate of the first corner of the box. */
        int y0;    /**< The y-coordinate of the first corner of the box. */
        int z0;    /**< The z-coordinate of the first corner of the box. */
        int x1;    /**< The x-coordinate of the second corner of the box. */
        int y1;    /**< The y-coordinate of the second corner of the box. */
        int z1;    /**< The z-coordinate of the second corner of the box. */
    
    public:
        /**
         * @brief Constructs a CutBox object with the specified parameters.
         * @param x0 The x-coordinate of the first corner of the box.
         * @param x1 The x-coordinate of the second corner of the box.
         * @param y0 The y-coordinate of the first corner of the box.
         * @param y1 The y-coordinate of the second corner of the box.
         * @param z0 The z-coordinate of the first corner of the box.
         * @param z1 The z-coordinate of the second corner of the box.
         */
        CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
        
        /**
         * @brief Destroys the CutBox object.
         * 
         * This is the destructor of the CutBox class. It is responsible for
         * releasing any resources held by the object.
         * 
         * @note Since CutBox doesn't own any resources directly, this destructor
         * doesn't perform any specific cleanup.
         */
        ~CutBox();
        
        /**
         * @brief Cuts the box from the specified Sculptor object.
         * @param Sculptor The Sculptor object from which to cut the box.
         * 
         * The Draw function is used to cut the box with the specified corners
         * from the Sculptor object. It modifies the voxels grid of the Sculptor.
         */
        void Draw(Sculptor& Sculptor);
};
