#include "utils.h"

Point Utils::rotateY(Point p, float angle)
{
  float x = p.x*cos(angle) - p.z*sin(angle);
  float z = p.x*sin(angle) + p.z*cos(angle);
  return Point(x, p.y, z);
}

void Utils::drawQuadsWithTexture(Point p1, Point p2, Point p3, Point p4, Point textureLocation, float textureXstep, float textureYstep)
{
  glBegin(GL_QUADS);
  // Top-left
  glTexCoord2f(textureLocation.x, textureLocation.y);
  glVertex3f(p1.x, p1.y, p1.z);
  // Top-right
  glTexCoord2f(textureLocation.x + textureXstep, textureLocation.y);
  glVertex3f(p2.x, p2.y, p2.z);
  // Bottom-right
  glTexCoord2f(textureLocation.x + textureXstep, textureLocation.y + textureYstep);
  glVertex3f(p3.x, p3.y, p3.z);
  // Bottom-left
  glTexCoord2f(textureLocation.x, textureLocation.y + textureYstep);
  glVertex3f(p4.x, p4.y, p4.z);
  glEnd();
}

void Utils::moveMatrixToCenter(Point center)
{
  glTranslatef(center.x, center.y, center.z);
}