#ifndef __HYPERBOLOID_H_
#define __HYPERBOLOID_H__

#include "3dshape.h"

class Hyperboloid: public RotateShape
{
public:
  Hyperboloid() = default;
  Hyperboloid(Point center, float height, float a = 10, float b = 10, int step = 100);
};

#endif