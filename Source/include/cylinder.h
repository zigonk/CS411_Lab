#ifndef __CYLINDER_H__
#define __CYLINDER_H__

#include "3dshape.h"

class Cylinder: public RotateShape {
private:
  float height, radius;
public:
  Cylinder() = default;
  Cylinder(Point center, float height, float radius);
};

#endif