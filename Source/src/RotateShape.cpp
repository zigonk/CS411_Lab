#include "3dshape.h"

void RotateShape::draw(int sector, float angle, float xrot, float yrot, float zrot)
{
  glLoadIdentity();
  Utils::moveMatrixToCenter(center);
  glRotatef(-30, 1, 0, 0);
  glRotatef(angle, xrot, yrot, zrot);
  float anglePerSector = 2 * PI / sector;
  Point textureLocation = Point(0.1, 0.1);
  float textureXstep = 0.8 / sector;
  float textureYstep = 0.8 / ApproxLine.size();
  for (int i = 0; i < ApproxLine.size(); ++i)
  {
    Line currentLine = ApproxLine[i];
    textureLocation.x = 0.1;
    for (int j = 0; j < sector; ++j)
    {
      Line nxLine;
      nxLine.start = Utils::rotateY(currentLine.start, anglePerSector);
      nxLine.end = Utils::rotateY(currentLine.end, anglePerSector);
      Utils::drawQuadsWithTexture(currentLine.start, nxLine.start, nxLine.end, currentLine.end, textureLocation, textureXstep, textureYstep);
      textureLocation.x += textureXstep;
      currentLine = nxLine;
    }
    // Utils::drawQuadsWithTexture(currentLine.start, ApproxLine[i].start, ApproxLine[i].end, currentLine.end, textureLocation, textureXstep, textureYstep);
    textureLocation.y += textureYstep;
  }
}