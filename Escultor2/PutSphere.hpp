#include "FiguraGeometrica.hpp"
#include "Sculptor.hpp"

/*WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment.*/
/**
 * @class PutSphere
 * @brief Represents a sphere that is placed in a Sculptor.
 * 
 * The PutSphere class inherits from the FiguraGeometrica class and provides
 * functionality to place a sphere in a Sculptor object. A sphere is a three-dimensional
 * geometric shape that is perfectly round in shape, like a ball.
 * 
 * This class assumes that the Sculptor class, defined in Sculptor.hpp, is available.
 * The Sculptor class represents a 3D image drawer that uses voxels as building blocks
 * for primitive shapes. The PutSphere class draws the sphere in the Sculptor object.
 */
class PutSphere : public FiguraGeometrica {
    private:
        int x;    /**< The x-coordinate of the sphere center. */
        int y;    /**< The y-coordinate of the sphere center. */
        int z;    /**< The z-coordinate of the sphere center. */
        int raio; /**< The radius of the sphere. */
        float r;  /**< The red component of the sphere color. */
        float g;  /**< The green component of the sphere color. */
        float b;  /**< The blue component of the sphere color. */
        float a;  /**< The alpha (transparency) component of the sphere color. */
    
    public:
        /**
         * @brief Constructs a PutSphere object with the specified parameters.
         * @param x The x-coordinate of the sphere center.
         * @param y The y-coordinate of the sphere center.
         * @param z The z-coordinate of the sphere center.
         * @param raio The radius of the sphere.
         * @param r The red component of the sphere color.
         * @param g The green component of the sphere color.
         * @param b The blue component of the sphere color.
         * @param a The alpha (transparency) component of the sphere color.
         */
        PutSphere(int x, int y, int z, int raio, float r, float g, float b, float a);
        
        /**
         * @brief Destroys the PutSphere object.
         * 
         * This is the destructor of the PutSphere class. It is responsible for
         * releasing any resources held by the object.
         * 
         * @note Since PutSphere doesn't own any resources directly, this destructor
         * doesn't perform any specific cleanup.
         */
        ~PutSphere();
        
        /**
         * @brief Draws the sphere in the specified Sculptor object.
         * @param Sculptor The Sculptor object where the sphere will be drawn.
         * 
         * The Draw function is used to place the sphere with the specified
         * center, radius, and color in the Sculptor object. It modifies the
         * voxels grid of the Sculptor.
         */
        void Draw(Sculptor& Sculptor);
};
