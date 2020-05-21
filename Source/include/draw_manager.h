#ifndef __DRAW_MANAGER_H__
#define __DRAW_MANAGER_H__

#include "menu_manager.h"
#include "geometry.h"

class DrawManager
{
private:
  static int button, state, x, y;
  static int key;
  static bool isClick, isSpecial;
  static vector<PolygonInfo> PolygonList;
  static int selectedPolygon;
  static Point start, end;
  static void drawCircle();
  static void drawEllipse();
  static void drawRectangle();
  static void drawPolygon();
  static void drawRegularPolygon(int numberOfEdges);
  static void handleDraw();
  static void handleFill();
  static void resetValue();
  static void handleSelectShape();
public:
  static void handleClick(int button, int state, int x, int y);
  static void handleKeyboard(unsigned char key, int x, int y);
  static void handleSpecialKey(int key, int x, int y);
  static void execute();
  static void redraw();
};

#endif