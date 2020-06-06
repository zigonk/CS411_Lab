#ifndef __TORUS_H__
#define __TORUS_H__

#include "3dshape.h"

class Torus: public RotateShape {
private:
  float ringRadius, tubeRadius;
public:
  Torus() = default;
  Torus(Point center, float ringRadius, float tubeRadius, int step = 100);
};

#endif