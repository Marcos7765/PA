#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxel.hpp"
/** @brief  OFF file 3D image drawer class.
 *  @details It uses [Voxels](https://en.wikipedia.org/wiki/Voxel)
 * as the building blocks of the primitive shapes.
*/
class Sculptor {
public:
  /// @brief Voxel matrix.
  Voxel ***v; // 3D matrix
  ///@{ @brief Max size of the given grid's dimension.
  int nx,ny,nz; // Dimensions
  ///@}
  /// @brief Class constructor, allocates the voxel
  /// grid to the choosen size.
  /// @param _nx Max size of the first dimension i.e. x axis.
  /// @param _ny Max size of the second dimension i.e. y axis.
  /// @param _nz Max size of the third dimension i.e. z axis.
  Sculptor(int _nx, int _ny, int _nz);
  /// Default class destructor.
  ~Sculptor();
  /// @brief Writes all visible voxels draw into an OFF file.
  /// @param filename Name of the destination file.
  void writeOFF(const char* filename);
};
#endif