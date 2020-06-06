#ifndef __GENERIC_H__
#define __GENERIC_H__

#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159

class Point
{
public:
  float x, y, z;
  Point() = default;
  Point(float x, float y, float z = 0.0);
};

class Line
{
public:
  Point start, end;
  Line() = default;
  Line(Point start, Point end);
};

#endif