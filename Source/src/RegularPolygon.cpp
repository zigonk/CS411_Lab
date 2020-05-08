#include "geometry.h"

void RegularPolygon::drawOnly(Point center, int radius, int numberOfEdges)
{
  float angle = 0;
  float step = 360/numberOfEdges;
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < numberOfEdges; ++i)
  {
    int x = radius * cos(angle * PI / 180);
    int y = radius * sin(angle * PI / 180);
    glVertex2i(x + center.x, y + center.y);
    angle += step;
  }
  glEnd();
  glFlush();
}