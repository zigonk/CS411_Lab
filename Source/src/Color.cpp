#include "geometry.h"

Color::Color(float r, float g, float b)
{
  this -> r = r;
  this -> g = g;
  this -> b = b;
}

Color::Color(ColorPreset preset)
{
  switch (preset)
  {
  case RED:
    this -> r = 1;
    this -> g = 0;
    this -> b = 0;
    break;
  case GREEN:
    this -> r = 0;
    this -> g = 1;
    this -> b = 0;
    break;
  case BLUE:
    this -> r = 0;
    this -> g = 0;
    this -> b = 1;
    break;
  default:
    break;
  }
}

bool operator != (const Color&a, const Color &b)
{
  return a.r != b.r || a.g != b.g || a.b != b.b;
}