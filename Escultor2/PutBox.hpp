#include "FiguraGeometrica.hpp"
#include "Sculptor.hpp"

/* WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment. */

/**
 * @class PutBox
 * @brief Represents a box that is placed in a Sculptor.
 * 
 * The PutBox class inherits from the FiguraGeometrica class and provides
 * functionality to place a box in a Sculptor object. A box is a rectangular
 * prism with six rectangular faces.
 */
class PutBox : public FiguraGeometrica {
    private:
        int x0;   /**< The minimum x-coordinate of the box. */
        int x1;   /**< The maximum x-coordinate of the box. */
        int y0;   /**< The minimum y-coordinate of the box. */
        int y1;   /**< The maximum y-coordinate of the box. */
        int z0;   /**< The minimum z-coordinate of the box. */
        int z1;   /**< The maximum z-coordinate of the box. */
        float r;  /**< The red component of the box color. */
        float g;  /**< The green component of the box color. */
        float b;  /**< The blue component of the box color. */
        float a;  /**< The alpha (transparency) component of the box color. */
    
    public:
        /**
         * @brief Constructs a PutBox object with the specified parameters.
         * @param x0 The minimum x-coordinate of the box.
         * @param x1 The maximum x-coordinate of the box.
         * @param y0 The minimum y-coordinate of the box.
         * @param y1 The maximum y-coordinate of the box.
         * @param z0 The minimum z-coordinate of the box.
         * @param z1 The maximum z-coordinate of the box.
         * @param r The red component of the box color.
         * @param g The green component of the box color.
         * @param b The blue component of the box color.
         * @param a The alpha (transparency) component of the box color.
         */
        PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
        
        /**
         * @brief Destroys the PutBox object.
         * 
         * This is the destructor of the PutBox class. It is responsible for
         * releasing any resources held by the object.
         * 
         * @note Since PutBox doesn't own any resources directly, this destructor
         * doesn't perform any specific cleanup.
         */
        ~PutBox();
        
        /**
         * @brief Draws the box in the specified Sculptor object.
         * @param Sculptor The Sculptor object where the box will be drawn.
         * 
         * The Draw function is used to place the box with the specified
         * coordinates and color in the Sculptor object. It modifies the
         * voxels grid of the Sculptor.
         */
        void Draw(Sculptor& Sculptor);
};
