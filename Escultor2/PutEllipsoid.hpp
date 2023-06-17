#include "FiguraGeometrica.hpp"
#include "Sculptor.hpp"

/* WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment. */

/**
 * @class PutEllipsoid
 * @brief Represents an ellipsoid that is placed in a Sculptor.
 * 
 * The PutEllipsoid class inherits from the FiguraGeometrica class and provides
 * functionality to place an ellipsoid in a Sculptor object. An ellipsoid is a
 * three-dimensional geometric shape that resembles a stretched or squashed sphere.
 */
class PutEllipsoid : public FiguraGeometrica {
    private:
        int x;    /**< The x-coordinate of the ellipsoid center. */
        int y;    /**< The y-coordinate of the ellipsoid center. */
        int z;    /**< The z-coordinate of the ellipsoid center. */
        int rx;   /**< The radius along the x-axis of the ellipsoid. */
        int ry;   /**< The radius along the y-axis of the ellipsoid. */
        int rz;   /**< The radius along the z-axis of the ellipsoid. */
        float r;  /**< The red component of the ellipsoid color. */
        float g;  /**< The green component of the ellipsoid color. */
        float b;  /**< The blue component of the ellipsoid color. */
        float a;  /**< The alpha (transparency) component of the ellipsoid color. */
    
    public:
        /**
         * @brief Constructs a PutEllipsoid object with the specified parameters.
         * @param x The x-coordinate of the ellipsoid center.
         * @param y The y-coordinate of the ellipsoid center.
         * @param z The z-coordinate of the ellipsoid center.
         * @param rx The radius along the x-axis of the ellipsoid.
         * @param ry The radius along the y-axis of the ellipsoid.
         * @param rz The radius along the z-axis of the ellipsoid.
         * @param r The red component of the ellipsoid color.
         * @param g The green component of the ellipsoid color.
         * @param b The blue component of the ellipsoid color.
         * @param a The alpha (transparency) component of the ellipsoid color.
         */
        PutEllipsoid(int x, int y, int z, int rx, int ry, int rz, float r, float g, float b, float a);
        
        /**
         * @brief Destroys the PutEllipsoid object.
         * 
         * This is the destructor of the PutEllipsoid class. It is responsible for
         * releasing any resources held by the object.
         * 
         * @note Since PutEllipsoid doesn't own any resources directly, this destructor
         * doesn't perform any specific cleanup.
         */
        ~PutEllipsoid();
        
        /**
         * @brief Draws the ellipsoid in the specified Sculptor object.
         * @param Sculptor The Sculptor object where the ellipsoid will be drawn.
         * 
         * The Draw function is used to place the ellipsoid with the specified
         * center, radii, and color in the Sculptor object. It modifies the
         * voxels grid of the Sculptor.
         */
        void Draw(Sculptor& Sculptor);
};
