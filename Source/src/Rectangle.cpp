#include "geometry.h"

void Rectangle::DrawOnly(Point start, Point end)
{
  glRecti(start.x, start.y, end.x, end.y);
  glFlush();
}