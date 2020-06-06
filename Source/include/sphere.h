#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "3dshape.h"

class Sphere: public RotateShape {
private:
  float radius;
public:
  Sphere() = default;
  Sphere(Point center, float radius, int step = 100);
};

#endif