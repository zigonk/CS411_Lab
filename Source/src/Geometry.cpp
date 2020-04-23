#include "geometry.h"

Geometry::~Geometry()
{
  delete[] PointSet;
}

void Geometry::DrawByPointSet()
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glBegin(GL_POINTS);
  for (int i = 0; i < n_points; ++i)
  {
    glColor3f(1, 1, 1);
    glVertex2i(PointSet[i].x, PointSet[i].y);
  }
  glEnd();
}