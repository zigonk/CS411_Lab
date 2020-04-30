#include "geometry.h"

Circle::Circle(Point center, int radius)
{
  DrawByMidPoint(center, radius);
}

void Circle::Add8SymmetricPoint(int x, int y, int index)
{
  for (int i = 0; i < 4; ++i)
  {
    int x_ = x * sym_x[i];
    int y_ = y * sym_y[i];
    PointSet[index + i].x = x_;
    PointSet[index + i].y = y_;
  }
  swap(x, y);
  index += 4;
  for (int i = 0; i < 4; ++i)
  {
    int x_ = x * sym_x[i];
    int y_ = y * sym_y[i];
    PointSet[index + i].x = x_;
    PointSet[index + i].y = y_;
  }
}

void Circle::DrawByMidPoint(Point center, int radius)
{
  n_points = ceil(1.0 * radius / sqrt(2)) * 8;
  PointSet = new Point[n_points];
  Add8SymmetricPoint(0, radius, 0);
  int P = 1 - radius;
  int X = 0;
  int Y = radius;
  for (int i = 8; i < n_points; i += 8)
  {
    if (P >= 0)
    {
      P -= 2*(Y - 1);
      Y -= 1;
    }
    P += 2*(X + 1) + 1;
    X += 1;
    Add8SymmetricPoint(X, Y, i);
  }
  for (int i = 0; i < n_points; i++)
  {
    PointSet[i].x += center.x;
    PointSet[i].y += center.y;
  }
}