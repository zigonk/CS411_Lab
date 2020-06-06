#ifndef __3D_SHAPE__
#define __3D_SHAPE__

#include "generic.h"
#include "utils.h"

class RotateShape
{
protected:
  Point center;
  vector<Line> ApproxLine;
public:
  void draw(int sector = 100, float angle = 0, float xrot = 0, float yrot = 1, float z = 0);
};

class FlatShape
{
protected:
  Point center;
  vector<Point> CornerList;
public:
  void draw(float angle = 0, float xrot = 0, float yrot = 1, float zrot = 0);
};

#endif