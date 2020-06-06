#include "torus.h"

Torus::Torus(Point center, float ringRadius, float tubeRadius, int step)
{
  this -> center = center;
  float anglePerStep = 2 * PI / step;
  float currentAngle = 2 * PI;
  Point start = Point(0.0f, tubeRadius);
  for (int i = 1; i < step; ++i)
  {
    currentAngle -= anglePerStep;
    Point end = Point(cos(currentAngle) * tubeRadius, sin(currentAngle) * tubeRadius);
    ApproxLine.push_back(Line(Point(start.x + ringRadius, start.y), Point(end.x + ringRadius, end.y)));
    start = end;
  }
}