#include "geometry.h"

Geometry::~Geometry()
{
  delete[] PointSet;
}

bool comp(Point a, Point b)
{
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int L1_distance(Geometry &g1, Geometry &g2)
{
  sort(g1.PointSet, g1.PointSet + g1.n_points, comp);
  sort(g2.PointSet, g2.PointSet + g2.n_points, comp);
  int res = 0;
  for (int i = 0; i < min(g1.n_points, g2.n_points); ++i)
  {
    Point p1 = g1.PointSet[i];
    Point p2 = g2.PointSet[i];
    // cout << p1 << " " << p2 << endl;
    res += abs(p1.x - p2.x) + abs(p1.y - p2.y);
  }
  return res;
}
int L2_distance(Geometry &g1, Geometry &g2)
{
  sort(g1.PointSet, g1.PointSet + g1.n_points, comp);
  sort(g2.PointSet, g2.PointSet + g2.n_points, comp);
  float res = 0;
  for (int i = 0; i < min(g1.n_points, g2.n_points); ++i)
  {
    Point p1 = g1.PointSet[i];
    Point p2 = g2.PointSet[i];
    // cout << p1 << " " << p2 << endl;
    res += pow((p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2);
  }
  return sqrt(res);
}

void Geometry::DrawByPointSet()
{
  glBegin(GL_POINTS);
  for (int i = 0; i < n_points; ++i)
  {
    if (PointSet[i].x > Config::WIDTH or PointSet[i].x < 0)
      continue;
    if (PointSet[i].y > Config::HEIGHT or PointSet[i].y < 0)
      continue;
    glVertex2i(PointSet[i].x, PointSet[i].y);
  }
  glEnd();
  glutSwapBuffers();
}