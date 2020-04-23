#include "geometry.h"

Line::Line(Point start, Point end, Method method)
{
  switch (method)
  {
  case DDA:
    DrawByDDA(start, end);
    break;
  case BRESENHAM:
    DrawByBrensenham(start, end);
    break;
  default:
    DrawByDefault(start, end);
    break;
  }
}

Line::~Line()
{
  delete[] PointSet;
}

bool Line::LineNormalize(Point &start, Point &end)
{
  // Normalize line to y = mx + b with 0 <= abs(m) <= 1
  int dx = end.x - start.x;
  int dy = end.y - start.y;
  bool isSwap = false;
  // Swap x y when abs(m) > 1
  if (abs(dy) > abs(dx))
  {
    swap(end.x, end.y);
    swap(start.x, start.y);
    isSwap = true;
  }
  // Draw from low x to high x
  if (start.x > end.x)
    swap(start, end);
  return isSwap;
}

void Line::DrawByDDA(Point start, Point end)
{
  int dx = end.x - start.x;
  int dy = end.y - start.y;
  n_points = max(abs(dx), abs(dy));
  PointSet = new Point[n_points];
  float Xinc = dx / (float) n_points;
  float Yinc = dy / (float) n_points;
  n_points += 1;
  float X = start.x;
  float Y = start.y;
  for (int i = 0; i < n_points; ++i)
  {
    PointSet[i] = Point(round(X), round(Y));
    X += Xinc;
    Y += Yinc;
  }
}

void Line::DrawByBrensenham(Point start, Point end)
{
  bool isSwap = LineNormalize(start, end);
  int dx = end.x - start.x;
  int dy = end.y - start.y;
  int Yinc = 1;
  if (dy < 0)
  {
    Yinc = -1;
    dy = -dy;
  }
  int P = 2*dy - dx;
  int X = start.x;
  int Y = start.y;
  int C1 = 2*dy;
  int C2 = 2*(dy - dx);
  n_points = abs(dx) + 1;
  PointSet = new Point[n_points];
  for (int i = 0; i < n_points; ++i)
  {
    if (isSwap)
      PointSet[i] = Point(Y, X);
    else
      PointSet[i] = Point(X, Y);
    if (P >= 0)
    {
      P += C2;
      Y += 1;
    }
    else P += C1;
    X += 1;
  }
}

void Line::DrawByPointSet()
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

void Line::DrawByDefault(Point start, Point end)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glBegin(GL_LINES);
    glVertex2d(start.x, start.y);
    glVertex2d(end.x, end.y);
  glEnd();
}
