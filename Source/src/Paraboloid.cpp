#include "paraboloid.h"

Paraboloid::Paraboloid(Point center, float height, float a, int step)
{
  this -> center = center;
  float Ystep = height / step;
  float Y = 0, X = 0;
  for (int i = 0; i < step; ++i)
  {
    float nY = Y - Ystep;
    float nX = sqrt(a * nY);
    ApproxLine.push_back(Line(Point(X, Y + height), Point(nX, nY + height)));
    X = nX;
    Y = nY;
  }
  ApproxLine.push_back(Line(Point(X, Y + height), Point(0, 0)));
}