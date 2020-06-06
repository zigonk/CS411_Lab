#ifndef __DISK_H__
#define __DISK_H__

#include "3dshape.h"

class Disk: public RotateShape
{
public:
  Disk() = default;
  Disk(Point center, float radius);
};

#endif