#include "cube.h"

Cube::Cube(Point center, float size)
{
  this->center = center;
  this->size = size;
}

void Cube::draw(float angle, float xrot, float yrot, float zrot)
{
  glLoadIdentity();
  Utils::moveMatrixToCenter(center);
  glRotatef(-30, 1, 0, 0);
  glRotatef(angle, xrot, yrot, zrot);
  float hs = size / 2;
  Point p1, p2, p3, p4, p5, p6, p7, p8, textureLocation = Point(0, 0);
  p1 = Point(-hs, hs, -hs);
  p2 = Point(hs, hs, -hs);
  p3 = Point(hs, -hs, -hs);
  p4 = Point(-hs, -hs, -hs);

  p5 = Point(-hs, hs, hs);
  p6 = Point(hs, hs, hs);
  p7 = Point(hs, -hs, hs);
  p8 = Point(-hs, -hs, hs);
  // Front face
  Utils::drawQuadsWithTexture(p1, p2, p3, p4, textureLocation, 1, 1);
  // Back face
  Utils::drawQuadsWithTexture(p8, p7, p6, p5, textureLocation, 1, 1);
  // Top face
  Utils::drawQuadsWithTexture(p1, p5, p6, p2, textureLocation, 1, 1);
  // Bottom face
  Utils::drawQuadsWithTexture(p3, p7, p8, p4, textureLocation, 1, 1);
  // Left face
  Utils::drawQuadsWithTexture(p4, p8, p5, p1, textureLocation, 1, 1);
  // Right face
  Utils::drawQuadsWithTexture(p2, p6, p7, p3, textureLocation, 1, 1);
}