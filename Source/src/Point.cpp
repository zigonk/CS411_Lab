#include "geometry.h"

Point::Point(int x, int y)
{
  this->x = x;
  this->y = y;
}

ostream & operator << (ostream &out, const Point& p)
{
  out << p.x  << " " << p.y;
}

istream & operator >> (istream &in, Point& p)
{
  in >> p.x >> p.y;
  return in;
}