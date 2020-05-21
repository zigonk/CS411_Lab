#include "menu_manager.h"

  Shape MenuManager::currentDrawingShape = CIRCLE;
  Color MenuManager::currentSelectedColor = RED;
  Action MenuManager::currentAction = NONE;

void MenuManager::handleDrawMenu(int shape_type)
{
  currentAction = DRAW;
  currentDrawingShape = static_cast<Shape>(shape_type);
}

void MenuManager::handleColorMenu(int color_preset)
{
  ColorPreset preset = static_cast<ColorPreset>(color_preset);
  currentSelectedColor = Color(preset);
}

void MenuManager::handleMainMenu(int action)
{
  Action act = static_cast<Action>(action);
  currentAction = act;
}

void MenuManager::createMenu()
{
  int drawMenu = glutCreateMenu(MenuManager::handleDrawMenu);
  // glutAddMenuEntry("Circle", CIRCLE);
  // glutAddMenuEntry("Ellipse", ELLIPSE);
  // glutAddMenuEntry("Rectangle", RECTANGLE);
  glutAddMenuEntry("Polygon", POLYGON);
  // glutAddMenuEntry("Right Triangle", RIGHT_TRIANGLE);
  // glutAddMenuEntry("Regular Hexagon", REGULAR_HEXAGON);
  // glutAddMenuEntry("Regular Pentagon", REGULAR_PENTAGON);
  int colorMenu = glutCreateMenu(MenuManager::handleColorMenu);
  glutAddMenuEntry("Red", RED);
  glutAddMenuEntry("Green", GREEN);
  glutAddMenuEntry("Blue", BLUE);
  int mainMenu = glutCreateMenu(MenuManager::handleMainMenu);
  glutAddSubMenu("Draw", drawMenu);
  glutAddSubMenu("Choose color", colorMenu);
  glutAddMenuEntry("Transform", TRANSFROM);
  glutAddMenuEntry("Fill color", FILL);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

Color MenuManager::getColor()
{
  return MenuManager::currentSelectedColor;
}

Shape MenuManager::getShape()
{
  return MenuManager::currentDrawingShape;
}

Action MenuManager::getAction()
{
  return MenuManager::currentAction;
}
