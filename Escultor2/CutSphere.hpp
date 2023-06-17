#include "FiguraGeometrica.hpp"

/* WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment. */

/**
 * @class CutSphere
 * @brief Represents a sphere that is cut from a Sculptor.
 * 
 * The CutSphere class inherits from the FiguraGeometrica class and provides
 * functionality to cut a sphere from a Sculptor object. A sphere is a three-dimensional
 * geometric shape consisting of all the points that are equidistant from a center point.
 */
class CutSphere : public FiguraGeometrica {
    private:
        int x;     /**< The x-coordinate of the center of the sphere. */
        int y;     /**< The y-coordinate of the center of the sphere. */
        int z;     /**< The z-coordinate of the center of the sphere. */
        int raio;  /**< The radius of the sphere. */
    
    public:
        /**
         * @brief Constructs a CutSphere object with the specified parameters.
         * @param x The x-coordinate of the center of the sphere.
         * @param y The y-coordinate of the center of the sphere.
         * @param z The z-coordinate of the center of the sphere.
         * @param raio The radius of the sphere.
         */
        CutSphere(int x, int y, int z, int raio);
        
        /**
         * @brief Destroys the CutSphere object.
         * 
         * This is the destructor of the CutSphere class. It is responsible for
         * releasing any resources held by the object.
         * 
         * @note Since CutSphere doesn't own any resources directly, this destructor
         * doesn't perform any specific cleanup.
         */
        ~CutSphere();
        
        /**
         * @brief Cuts the sphere from the specified Sculptor object.
         * @param Sculptor The Sculptor object from which to cut the sphere.
         * 
         * The Draw function is used to cut the sphere with the specified center
         * and radius from the Sculptor object. It modifies the voxels grid of the Sculptor.
         */
        void Draw(Sculptor& Sculptor);
};
