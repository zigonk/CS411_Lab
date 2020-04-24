#include "geometry.h"

char *fileName;

void drawLineTimeComparing(char *fileName, int n_tries)
{
  freopen(fileName, "r", stdin);
  Point start, end;
  cin >> start >> end;
  high_resolution_clock::time_point t1, t2;
  duration<double, std::milli> time_span;
  // Draw by Default
  t1 = high_resolution_clock::now();

  for (int i = 0; i < n_tries; ++i)
    Line::DrawOnly(start, end);

  t2 = high_resolution_clock::now();
  time_span = t2 - t1;
  cout << "Draw by Default: " << time_span.count() << " milliseconds." << endl;

  // t1 = high_resolution_clock::now();

  // for (int i = 0; i < n_tries; ++i)
  // {
  //   Line l = Line(start, end, DDA);
  //   l.DrawByPointSet();
  // }

  // t2 = high_resolution_clock::now();
  // time_span = t2 - t1;
  // cout << "Draw by DDA: " << time_span.count() << " milliseconds." << endl;

  // t1 = high_resolution_clock::now();

  // for (int i = 0; i < n_tries; ++i)
  // {
  //   Line l = Line(start, end, BRESENHAM);
  //   l.DrawByPointSet();
  // }

  // t2 = high_resolution_clock::now();
  // time_span = t2 - t1;
  // cout << "Draw by Bresenham: " << time_span.count() << " milliseconds." << endl;
  fclose(stdin);
}

void drawLineAccuracyComparing(char *fileName, Method method1, Method method2)
{
  freopen(fileName, "r", stdin);
  Point start, end;
  cin >> start >> end;
  Line l1 = Line(start, end, method1);
  Line l2 = Line(start, end, method2);
  cout << "L1 distance: " << L1_distance(l1, l2) << endl;
  cout << "L2 distance: " << L2_distance(l1, l2) << endl;
}

void drawObjectsFromFile(char *fileName)
{
  freopen(fileName, "r", stdin);
  int obj_type;
  while (cin >> obj_type)
  {
    switch (obj_type)
    {
    case -1:
    {
      Point start, end;
      Method method = DEFAULT;
      cin >> start >> end;
      Line l = Line(start, end, method);
      break;
    }
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
    case 2:
    {
      Point center;
      int radius;
      cin >> center >> radius;
      Circle c = Circle(center, radius);
      c.DrawByPointSet();
      break;
    }
    case 3:
    {
      Point center;
      int major, minor;
      cin >> center >> major >> minor;
      Ellipse e = Ellipse(center, major, minor);
      e.DrawByPointSet();
      break;
    }
    case 4:
    {
      Point center;
      int focal_length;
      cin >> center >> focal_length;
      Parabola p = Parabola(center, focal_length);
      p.DrawByPointSet();
      break;
    }
    default:
      break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1 * Config::SLEEP_TIME));
  }
}

void renderObjects(void)
{
  drawObjectsFromFile(fileName);
  glFlush();
  // drawLineTimeComparing(fileName, 2000);
  // drawLineAccuracyComparing(fileName, DEFAULT, BRESENHAM);
  // glutSwapBuffers();
}

void init()
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glColor3f(1, 1, 1);
  glLoadIdentity();
  gluOrtho2D(0.0, Config::WIDTH, 0.0, Config::HEIGHT);
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
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(Config::WIDTH, Config::HEIGHT);
  glutCreateWindow("Visualize");
  init();
  glutDisplayFunc(renderObjects);
  glutMainLoop();
  return 0;
}