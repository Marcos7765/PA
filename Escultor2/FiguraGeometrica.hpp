#ifndef FGEO_H
#define FGEO_H
#include "Sculptor.hpp"

/* WARNING: THAT'S A CHATGPT DOCUMENTATION. Trying it out as the classes implement
the same functionality i've documented in the earlier part of the assignment. */

/**
 * @class FiguraGeometrica
 * @brief Abstract base class for geometric figures.
 * 
 * The FiguraGeometrica class provides an interface for drawing geometric figures
 * in a Sculptor object. It serves as an abstract base class for specific geometric
 * figure classes.
 */
class FiguraGeometrica {
    public:
        /**
         * @brief Pure virtual function for drawing the geometric figure.
         * @param Sculptor The Sculptor object where the figure will be drawn.
         * 
         * The Draw function is a pure virtual function that must be overridden
         * by derived classes. It is used to draw the specific geometric figure
         * in the Sculptor object.
         */
        virtual void Draw(Sculptor& Sculptor) = 0;
};

#endif