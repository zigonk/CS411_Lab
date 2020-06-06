#ifndef __PARABOLOID_H__
#define __PARABOLOID_H__

#include "3dshape.h"

class Paraboloid: public RotateShape
{
public:
  Paraboloid() = default;
  Paraboloid(Point center, float height, float a = -20, int step = 100);
};

#endif