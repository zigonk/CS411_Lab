#ifndef __UTILS_H__
#define __UTILS_H__

#include <math.h>

#define PI 3.14159265

class Utils
{
public:
  static const double translateL[3][3];
  static const double translateR[3][3];
  static const double translateU[3][3];
  static const double translateD[3][3];
  static const double scaleUp[3][3];
  static const double scaleDown[3][3];
  static const double rotateL[3][3];
  static const double rotateR[3][3];
};

#endif