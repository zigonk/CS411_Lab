#ifndef __UTILS_H__
#define __UTILS_H__

#include "generic.h"

class Utils
{
public:
  static Point rotateY(Point p, float angle);
  static void drawQuadsWithTexture(Point p1, Point p2, Point p3, Point p4, Point textureLocation, float textureXstep, float textureYstep);
  static void moveMatrixToCenter(Point center);
};

#endif