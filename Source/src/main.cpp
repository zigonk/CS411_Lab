#include "geometry.h"

const int WIDTH = 500;
const int HEIGHT = 500;

char *fileName;

void drawObjectsFromFile(char *fileName)
{
  freopen(fileName, "r", stdin);
  int obj_type;
  while (cin >> obj_type)
  {
    switch (obj_type)
    {
    case 0:
    {
      Point start, end;
      Method method = DDA;
      cin >> start >> end;
      Line l = Line(start, end, method);
      l.DrawByPointSet();
      break;
    }
    case 1:
    {
      Point start, end;
      Method method = BRESENHAM;
      cin >> start >> end;
      Line l = Line(start, end, method);
      l.DrawByPointSet();
      break;
    }
    default:
      break;
    }
    system("read -p 'Press Enter to continue...' var");
  }
}

void renderObjects(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  drawObjectsFromFile(fileName);
  glutSwapBuffers();

}

void init()
{
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    cout << "Please pass path of input file";
    return 0;
  }
  fileName = argv[1];
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("Visualize");
  init();
  glutDisplayFunc(renderObjects);
  glutMainLoop();
  return 0;
}