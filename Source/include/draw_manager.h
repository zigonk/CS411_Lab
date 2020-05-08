#ifndef __DRAW_MANAGER_H__
#define __DRAW_MANAGER_H__

#include "menu_manager.h"
#include "geometry.h"

class DrawManager
{
  static int button, state, x, y;
  static bool isClick;
private:
  static Point start, end;
  static void drawCircle();
  static void drawEllipse();
  static void drawRectangle();
  static void drawPolygon();
  static void drawRegularPolygon(int numberOfEdges);
  static void handleDraw();
  static void handleFill();
  static void resetValue();
public:
  static void handleClick(int button, int state, int x, int y);
  static void execute();
};

#endif