#include "geometry.h"

Parabola::Parabola(Point center, int focal_length)
{
  DrawByMidPoint(center, focal_length);
}

void Parabola::AddYSymetricPoint(int x, int y, int index)
{
  PointSet[index].x = x;
  PointSet[index].y = y;
  index++;
  PointSet[index].x = -x;
  PointSet[index].y = y;
}

void Parabola::DrawByMidPoint(Point center, int focal_length)
{
  bool isReversed = false;
  if (focal_length < 0)
  {
    isReversed = true;
    focal_length *= -1;
  }
  int P = 1 - 2 * focal_length;
  int X = 0;
  int Y = 0;
  n_points = Config::MAX_POINTS * 2 + 1;
  PointSet = new Point[n_points];
  PointSet[0].x = X;
  PointSet[0].y = Y;
  int i = 1;
  //  dy / dx > 1
  for (; i < 4 * focal_length + 1; i += 2)
  {
    X += 1;
    if (P > 0)
    {
      Y += 1;
      P -= 4 * focal_length;
    }
    P += 2 * X + 1;
    AddYSymetricPoint(X, Y, i);
  }

  // dy / dx < 1
  P = (X + 1 / 2) * (X + 1 / 2) - 4 * focal_length * Y;
  for (; i < n_points; i += 2)
  {
    if (P < 0)
    {
      X += 1;
      P += 2 * X + 1;
    }
    P -= 4 * focal_length;
    Y += 1;
    AddYSymetricPoint(X, Y, i);
  }
  // move to center
  for (int i = 0; i < n_points; i++)
  {
    PointSet[i].x += center.x;
    if (isReversed)
      PointSet[i].y *= -1;
    PointSet[i].y += center.y;
  }
}