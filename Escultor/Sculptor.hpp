#include "Voxel.hpp"
/** @brief  OFF file 3D image drawer class.
 *  @details It uses [Voxels](https://en.wikipedia.org/wiki/Voxel)
 * as the building blocks of the primitive shapes.
*/
class Sculptor {
private:
  /// @brief Voxel matrix.
  Voxel ***v; // 3D matrix
  ///@{ @brief Max size of the given grid's dimension.
  int nx,ny,nz; // Dimensions
  ///@}
  ///@{ @brief Current specific color value according to the [RGBA model](https://en.wikipedia.org/wiki/RGBA_color_model).
  float r,g,b,a; // Current drawing color
  ///@}
public:
  /// @brief Class constructor, allocates the voxel
  /// grid to the choosen size.
  /// @param _nx Max size of the first dimension i.e. x axis.
  /// @param _ny Max size of the second dimension i.e. y axis.
  /// @param _nz Max size of the third dimension i.e. z axis.
  Sculptor(int _nx, int _ny, int _nz);
  /// Default class destructor.
  ~Sculptor();
  /// @brief Sets the RGBA values that any next put voxel will be.
  /// @param r Red value.
  /// @param g Green value.
  /// @param b Blue value.
  /// @param a Alpha value.
  void setColor(float r, float g, float b, float a);
  /// @brief Puts a voxel in the given coordinates.
  void putVoxel(int x, int y, int z);
  /// @brief Removes a voxel in the given coordinate.
  void cutVoxel(int x, int y, int z);
  /// @brief Places a full box with opposing vertices \f$ v_0 = (x_0 ,y_0 ,z_0) \f$ and \f$ v_1 = (x_1 ,y_1 ,z_1) \f$.
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /// @brief Erases a full box with opposing vertices \f$ v_0 = (x_0 ,y_0 ,z_0) \f$ and \f$ v_1 = (x_1 ,y_1 ,z_1) \f$.
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /// @brief Places a full sphere centered in \f$(x_\text{center} ,y_\text{center} ,z_\text{center}) \f$ and radius \f$ R=\text{radius}\f$
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /// @brief Erases a full sphere centered in \f$(x_\text{center} ,y_\text{center} ,z_\text{center}) \f$ and radius \f$ R=\text{radius}\f$
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /// @brief Places a full ellipsoid centered in \f$(x_\text{center} ,y_\text{center} ,z_\text{center}) \f$ and radii \f$ R_x =\text{rx} \f$,\f$ R_y =\text{ry} \f$,\f$ R_z =\text{rz} \f$
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /// @brief Erases a full ellipsoid centered in \f$(x_\text{center} ,y_\text{center} ,z_\text{center}) \f$ and radii \f$ R_x =\text{rx} \f$,\f$ R_y =\text{ry} \f$,\f$ R_z =\text{rz} \f$
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /// @brief Writes all visible voxels draw into an OFF file.
  /// @param filename Name of the destination file.
  void writeOFF(const char* filename);
};