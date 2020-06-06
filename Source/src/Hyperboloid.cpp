#include "hyperboloid.h"

Hyperboloid::Hyperboloid(Point center, float height, float a, float b, int step)
{
  this -> center = center;
  float Ystep = height / step;
  float Y = height / 2, X = a * sqrt(1 + Y * Y / (b * b));
  ApproxLine.push_back(Line(Point(0, Y + height / 2), Point(X, Y + height / 2)));
  for (int i = 0; i < step; ++i)
  {
    float nY = Y - Ystep;
    float nX = a * sqrt(1 + nY * nY / (b * b));
    ApproxLine.push_back(Line(Point(X, Y + height / 2), Point(nX, nY + height / 2)));
    X = nX;
    Y = nY;
  }
  ApproxLine.push_back(Line(Point(X, Y + height / 2), Point(0, 0)));
}