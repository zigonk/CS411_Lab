#include "geometry.h"
#include "menu_manager.h"
#include "draw_manager.h"

bool firstRender = true;

void renderObjects(void)
{
  if (firstRender)
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    firstRender = false;
  }
  if (MenuManager::getAction() == TRANSFROM)
    DrawManager::redraw();
  DrawManager::execute();
}

void init()
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glColor3f(1, 1, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  gluOrtho2D(0.0, Config::WIDTH, 0.0, Config::HEIGHT);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(Config::WIDTH, Config::HEIGHT);
  glutCreateWindow("Visualize");
  MenuManager::createMenu();
  init();
  glutDisplayFunc(renderObjects);
  glutMouseFunc(DrawManager::handleClick);
  glutKeyboardFunc(DrawManager::handleKeyboard);
  glutSpecialFunc(DrawManager::handleSpecialKey);
  glutMainLoop();
  return 0;
}