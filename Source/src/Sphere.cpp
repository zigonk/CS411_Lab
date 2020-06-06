#include "sphere.h"

Sphere::Sphere(Point center, float radius, int step)
{
  this -> center = center;
  float anglePerStep = PI / step;
  float currentAngle = PI / 2;
  Point start = Point(0.0f, radius);
  for (int i = 1; i < step; ++i)
  {
    currentAngle -= anglePerStep;
    if (currentAngle < 0)
      currentAngle += 2 * PI;
    Point end = Point(cos(currentAngle)*radius, sin(currentAngle)*radius);
    ApproxLine.push_back(Line(start, end));
    start = end;
  }
}