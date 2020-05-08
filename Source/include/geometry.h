#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <GL/glut.h>
#include <unistd.h>
#include <chrono>
#include <config.h>
#include <thread>
#include <queue>

using namespace std;
using namespace std::chrono;

const int sym_x[4] = {-1,  1, -1, 1};
const int sym_y[4] = { 1, -1, -1, 1};

#define PI 3.14159265

enum Method {
  DDA,
  BRESENHAM,
  MID_POINT,
  DEFAULT
};

enum ColorPreset
{
  RED,
  GREEN,
  BLUE,
};

class Color
{
public:
  float r, g, b;
  Color() = default;
  Color(float r, float g, float b);
  Color(ColorPreset preset);
  friend bool operator != (const Color &a, const Color &b);
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
  friend int L1_distance(Geometry &g1, Geometry &g2);
  friend int L2_distance(Geometry &g1, Geometry &g2);
};

class Line: public Geometry
{
private:
  void DrawByDDA(Point start, Point end);
  void DrawByBrensenham(Point start, Point end);
  void DrawByDefault(Point start, Point end);
public:
  Line() = default;
  Line(Point start, Point end, Method method);
  static void DrawOnly(Point start, Point end);
  static bool LineNormalize(Point &start, Point &end);
};

class Rectangle:public Geometry
{
public:
  static void DrawOnly(Point start, Point end);
};

class Circle: public Geometry
{
private:
  void DrawByMidPoint(Point center, int radius);
  void Add8SymmetricPoint(int x, int y, int index);
public:
  Circle() = default;
  Circle(Point center, int radius);
};

class Ellipse: public Geometry
{
private:
  void DrawByMidPoint(Point center, int major, int minor);
  void Add4SymetricPoint(int x, int y, int index);
public:
  Ellipse() = default;
  Ellipse(Point center, int major, int minor);
};

class Parabola: public Geometry
{
private:
  void DrawByMidPoint(Point center, int focal_length);
  void AddYSymetricPoint(int x, int y, int index);
public:
  Parabola() = default;
  Parabola(Point center, int focal_length);
};

class Hyperbola: public Geometry
{
private:
  void DrawByMidPoint(Point center, int major, int minor);
  void Add4SymetricPoint(int x, int y, int index);
public:
  Hyperbola() = default;
  Hyperbola(Point center, int major, int minor);
};

class RegularPolygon
{
public:
  static void drawOnly(Point center, int radius, int numberOfEdges);
};

#endif