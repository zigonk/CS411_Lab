#include "disk.h"

Disk::Disk(Point center, float radius)
{
  this -> center = center;
  ApproxLine.push_back(Line(Point(0, 0), Point(radius, 0)));
}