#ifndef __MENU_MANAGER_H__
#define __MENU_MANAGER_H__

#include "geometry.h"

enum Shape
{
  CIRCLE,
  ELLIPSE,
  RECTANGLE,
  POLYGON,
};

enum Action
{
  DRAW,
  FILL,
  NONE
};

class MenuManager
{
private:
  static Shape currentDrawingShape;
  static Color currentSelectedColor;
  static Action currentAction;
  static void handleDrawMenu(int shape_type);
  static void handleColorMenu(int color_preset);
  static void handleMainMenu(int action);
public:
  static void createMenu();
  static Shape getShape();
  static Color getColor();
  static Action getAction();
};


#endif