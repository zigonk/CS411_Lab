#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <GL/glut.h>

using namespace std;

const int sym_x[4] = {-1,  1, -1, 1};
const int sym_y[4] = { 1, -1, -1, 1};

enum Method {
  DDA,
  BRESENHAM,
  MID_POINT,
  DEFAULT
};

class Point
{
private:
public:
  int x, y;
  Point() = default;
  Point(int x, int y);
  friend ostream & operator << (ostream &out, const Point& p);
  friend istream & operator >> (istream &in, Point& p);
};

class Geometry
{
protected:
  Point* PointSet;
  int n_points = 0;
public:
  ~Geometry();
  void DrawByPointSet();
};

class Line: public Geometry
{
private:
  Point* PointSet;
  int n_points = 0;
  void DrawByDDA(Point start, Point end);
  void DrawByBrensenham(Point start, Point end);
  void DrawByDefault(Point start, Point end);
public:
  Line() = default;
  Line(Point start, Point end, Method method);
  ~Line();
  void DrawByPointSet();
  static bool LineNormalize(Point &start, Point &end);
};

class Circle: public Geometry
{
private:
  Point *PointSet;
  int n_points = 0;
  void DrawByMidPoint(Point center, int radius);
  void Add8SymmetricPoint(int x, int y, int index);
public:
  Circle() = default;
  Circle(Point center, int radius);
  ~Circle();
};

#endif