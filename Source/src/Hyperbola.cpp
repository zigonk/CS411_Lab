#include "geometry.h"

Hyperbola::Hyperbola(Point center, int major, int minor)
{
  DrawByMidPoint(center, major, minor);
}

void Hyperbola::Add4SymetricPoint(int x, int y, int index)
{
  for (int i = 0; i < 4; ++i)
  {
    int x_ = x * sym_x[i];
    int y_ = y * sym_y[i];
    PointSet[index + i] = Point(x_, y_);
  }
}

void Hyperbola::DrawByMidPoint(Point center, int major, int minor)
{
  int X = major;
  int Y = 0;
  n_points = Config::MAX_POINTS * 4 + 2;
  PointSet = new Point[n_points];
  PointSet[0] = Point(major,  0);
  PointSet[1] = Point(-major, 0);
  int i = 2;
  int C1 = pow(major, 2) - pow(minor, 2);
  if (C1 <= 0)
    C1 = n_points;
  else
    C1 = ceil(pow(minor, 2)/sqrt(C1) + 1) * 4 + 2;
  int P = pow(minor, 2) * pow(X + 1.0 / 2, 2) - pow(major, 2) * pow(Y + 1, 2) - pow(major, 2) * pow(minor, 2);
  for (; i < C1; i += 4)
  {
    Y++;
    if (P <= 0)
    {
      X++;
      P += pow(minor, 2) * (2 * X);
    }
    P -= pow(major, 2) * (2 * Y + 1);
    Add4SymetricPoint(X, Y, i);
  }
  P = pow(minor, 2) * pow((X + 1), 2) - pow(major, 2) * pow(Y + 1.0 / 2, 2) - pow(major, 2) * pow(minor, 2);
  for (; i < n_points; i += 4)
  {
    X++;
    if (P >= 0)
    {
      Y++;
      P -= pow(major, 2) * (2 * Y);
    }
    P += pow(minor, 2) * (2 * X + 1);
    Add4SymetricPoint(X, Y, i);
  }
  // move to center
  for (int i = 0; i < n_points; ++i)
  {
    PointSet[i].x += center.x;
    PointSet[i].y += center.y;
  }
}