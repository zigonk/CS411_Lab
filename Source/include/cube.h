#ifndef __CUBE_H__
#define __CUBE_H__

#include "3dshape.h"

class Cube: public FlatShape
{
private:
  float size;
public:
  Cube() = default;
  Cube(Point center, float size);
  void draw(float angle = 0, float xrot = 0, float yrot = 1, float zrot = 0);
};

#endif