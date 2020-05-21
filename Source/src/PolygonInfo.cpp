#include "geometry.h"

double calcAreaTP(Point p1, Point p2)
{
  return (1.0 * (int(p2.y) + int(p1.y)) * (int(p2.x) - int(p1.x)))/2;
}

double calcTriangleArea(Point p1, Point p2, Point p3)
{
  double res = 0;
  res += calcAreaTP(p1, p2);
  res += calcAreaTP(p2, p3);
  res += calcAreaTP(p3, p1);
  return abs(res);
}


void PolygonInfo::AddVertex(Point vertex)
{
  vertices.push_back(vertex);
}


bool PolygonInfo::IsInside(Point point)
{
  calcArea();
  int n_points = vertices.size();
  double sum_area = 0;
  for (int i = 0; i < n_points; ++i)
    sum_area += calcTriangleArea(point, vertices[i], vertices[(i + 1) % n_points]);
  return (sum_area == area);
}

void PolygonInfo::calcArea()
{
  int n_points = vertices.size();
  area = 0;
  for (int i = 0; i < n_points; ++i)
    area += calcAreaTP(vertices[i], vertices[(i + 1) % n_points]);
  area = abs(area);
}

void PolygonInfo::Draw()
{
  int n_points = vertices.size();
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < n_points; ++i)
    glVertex2i(int(vertices[i].x), int(vertices[i].y));
  glEnd();
}

void mulAffineMatrix(PolygonInfo &pInfo, const double mat[3][3])
{
  for (int i = 0; i < pInfo.vertices.size(); ++i)
  {
    pInfo.vertices[i].x = pInfo.vertices[i].x * mat[0][0] + pInfo.vertices[i].y * mat[1][0] + mat[2][0];
    pInfo.vertices[i].y = pInfo.vertices[i].x * mat[0][1] + pInfo.vertices[i].y * mat[1][1] + mat[2][1];
  }
}

Point PolygonInfo::moveCenterTo(double x, double y)
{
  double maxX = -1e8, maxY = -1e8, minX = 1e8, minY = 1e8;
  Point center = Point(0, 0);
  for (int i = 0; i < vertices.size(); ++i)
  {
    center.x += vertices[i].x;
    center.y += vertices[i].y;
  }
  center.x /= vertices.size();
  center.y /= vertices.size();
  for (int i = 0; i < vertices.size(); ++i)
  {
    vertices[i].x -= center.x - x;
    vertices[i].y -= center.y - y;
  }
  return center;
}

void PolygonInfo::Transform(int key, bool isSpecial)
{
  if (isSpecial)
  {
    switch (key)
    {
    case GLUT_KEY_LEFT:
      mulAffineMatrix(*this, Utils::translateL);
      break;
    case GLUT_KEY_RIGHT:
      mulAffineMatrix(*this, Utils::translateR);
      break;
    case GLUT_KEY_UP:
      mulAffineMatrix(*this, Utils::translateU);
      break;
    case GLUT_KEY_DOWN:
      mulAffineMatrix(*this, Utils::translateD);
    break;
    default:
      break;
    }
  }
  else {
    Point center = moveCenterTo(0, 0);
    switch (key)
    {
    case '+':
    {
      mulAffineMatrix(*this, Utils::scaleUp);
      break;
    }
    case '-':
    {
      Point center = moveCenterTo(0, 0);
      mulAffineMatrix(*this, Utils::scaleDown);
      moveCenterTo(0, 0);
      moveCenterTo(center.x, center.y);
      break;
    }
    case 'l':
      mulAffineMatrix(*this, Utils::rotateL);
      break;
    case 'r':
      mulAffineMatrix(*this, Utils::rotateR);
      break;
    default:
      break;
    }
    moveCenterTo(0, 0);
    moveCenterTo(center.x, center.y);
  }
}