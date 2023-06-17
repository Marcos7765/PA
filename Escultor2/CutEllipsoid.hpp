#include "FiguraGeometrica.hpp"
#include "Sculptor.hpp"

/* WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment. */

/**
 * @class CutEllipsoid
 * @brief Represents an ellipsoid that is cut from a Sculptor.
 * 
 * The CutEllipsoid class inherits from the FiguraGeometrica class and provides
 * functionality to cut an ellipsoid from a Sculptor object. An ellipsoid is a
 * three-dimensional geometric shape that resembles a stretched sphere.
 */
class CutEllipsoid : public FiguraGeometrica {
    private:
        int x;     /**< The x-coordinate of the center of the ellipsoid. */
        int y;     /**< The y-coordinate of the center of the ellipsoid. */
        int z;     /**< The z-coordinate of the center of the ellipsoid. */
        int rx;    /**< The radius along the x-axis of the ellipsoid. */
        int ry;    /**< The radius along the y-axis of the ellipsoid. */
        int rz;    /**< The radius along the z-axis of the ellipsoid. */
    
    public:
        /**
         * @brief Constructs a CutEllipsoid object with the specified parameters.
         * @param x The x-coordinate of the center of the ellipsoid.
         * @param y The y-coordinate of the center of the ellipsoid.
         * @param z The z-coordinate of the center of the ellipsoid.
         * @param rx The radius along the x-axis of the ellipsoid.
         * @param ry The radius along the y-axis of the ellipsoid.
         * @param rz The radius along the z-axis of the ellipsoid.
         */
        CutEllipsoid(int x, int y, int z, int rx, int ry, int rz);
        
        /**
         * @brief Destroys the CutEllipsoid object.
         * 
         * This is the destructor of the CutEllipsoid class. It is responsible for
         * releasing any resources held by the object.
         * 
         * @note Since CutEllipsoid doesn't own any resources directly, this destructor
         * doesn't perform any specific cleanup.
         */
        ~CutEllipsoid();
        
        /**
         * @brief Cuts the ellipsoid from the specified Sculptor object.
         * @param Sculptor The Sculptor object from which to cut the ellipsoid.
         * 
         * The Draw function is used to cut the ellipsoid with the specified center,
         * radii along each axis from the Sculptor object. It modifies the voxels grid of the Sculptor.
         */
        void Draw(Sculptor& Sculptor);
};