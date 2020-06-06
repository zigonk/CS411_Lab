#ifndef __CONE_H__
#define __CONE_H__

#include "3dshape.h"

class Cone: public RotateShape
{
public:
  Cone() = default;
  Cone(Point center, float height, float radius);
};

#endif