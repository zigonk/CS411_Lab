#include "draw_manager.h"

Point DrawManager::start = Point(-1, -1);
Point DrawManager::end = Point(0, 0);
int DrawManager::button = 0;
int DrawManager::state = GLUT_UP;
int DrawManager::x = 0;
int DrawManager::y = 0;
bool DrawManager::isClick = false;

void DrawManager::drawCircle()
{
  if (button != GLUT_LEFT_BUTTON)
    return;
  switch (state)
  {
  case GLUT_DOWN:
    start = Point(x, y);
    break;
  case GLUT_UP:
  {
    end = Point(x, y);
    if (end.y < start.y)
      swap(end.y, start.y);
    if (end.x < start.x)
      swap(end.x, start.x);
    int radius = min(end.x - start.x, end.y - start.y);
    radius /= 2;
    if (radius == 0)
      break;
    Point center = Point(start.x + radius, start.y + radius);
    Circle c = Circle(center, radius);
    c.DrawByPointSet();
    resetValue();
    break;
  }
  default:
    break;
  }
}

void DrawManager::drawEllipse()
{
  if (button != GLUT_LEFT_BUTTON)
    return;
  switch (state)
  {
  case GLUT_DOWN:
    start = Point(x, y);
    break;
  case GLUT_UP:
  {
    end = Point(x, y);
    if (end.y < start.y)
      swap(end.y, start.y);
    if (end.x < start.x)
      swap(end.x, start.x);
    if (end.x == start.x && end.y == start.y)
      break;
    Point center = Point((start.x + end.x) / 2, (start.y + end.y) / 2);
    Ellipse e = Ellipse(center, end.x - center.x, end.y - center.y);
    e.DrawByPointSet();
    resetValue();
    break;
  }
  default:
    break;
  }
}

void DrawManager::drawRectangle()
{
  if (button != GLUT_LEFT_BUTTON)
    return;
  switch (state)
  {
  case GLUT_DOWN:
    start = Point(x, y);
    break;
  case GLUT_UP:
  {
    end = Point(x, y);
    cout << start << " " << end << endl;
    Rectangle::DrawOnly(start, end);
    resetValue();
    break;
  }
  default:
    break;
  }
}

void DrawManager::drawPolygon()
{
  switch (button)
  {
  case GLUT_LEFT_BUTTON:
  {
    if (state == GLUT_UP)
    {
      if (start.x == -1)
      {
        start = Point(x, y);
        glutDetachMenu(GLUT_RIGHT_BUTTON);
      }
      else
      {
        Point currentPoint = Point(x, y);
        Line::DrawOnly(end, currentPoint);
      }
      end = Point(x, y);
    }
    break;
  }
  case GLUT_RIGHT_BUTTON:
    if (state == GLUT_UP && start.x != -1)
    {
      cout << "1" << endl;
      Line::DrawOnly(end, start);
      resetValue();
      glutAttachMenu(GLUT_RIGHT_BUTTON);
    }
    break;
  default:
    break;
  }
}

void DrawManager::handleDraw()
{
  switch (MenuManager::getShape())
  {
  case CIRCLE:
    drawCircle();
    break;
  case ELLIPSE:
    drawEllipse();
    break;
  case RECTANGLE:
    drawRectangle();
    break;
  case POLYGON:
    drawPolygon();
    break;
  default:
    break;
  }
  glutSwapBuffers();
}

Color getColorAtPixel(int x, int y)
{
  float pixel[3];
  glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixel);
  return Color(pixel[0], pixel[1], pixel[2]);
}

void putPixel(int x, int y)
{
  // cout << "add pixel" << endl;
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  // cout << "finish" << endl;
}

void floodFill(int x, int y, const Color &c, Color a[][Config::WIDTH])
{
  queue<Point> q;
  bool check[Config::HEIGHT][Config::WIDTH];
  memset(check, 0, sizeof check);
  q.push(Point(x, y));
  while (!q.empty())
  {
    Point u = q.front();
    q.pop();
    int x = u.x, y = u.y;
    if (x < 0 or x >= Config::WIDTH)
      continue;
    if (y < 0 or y >= Config::HEIGHT)
      continue;
    if (check[y][x])
      continue;
    if (a[y][x] != c)
      continue;
    check[y][x] = true;
    putPixel(x, y);
    q.push(Point(x + 1, y));
    q.push(Point(x - 1, y));
    q.push(Point(x, y + 1));
    q.push(Point(x, y - 1));
  }
}

void getCurrentFrame(Color a[][Config::WIDTH])
{
  float pixel[Config::HEIGHT * Config::WIDTH * 3];
  glReadPixels(0, 0, Config::HEIGHT, Config::WIDTH, GL_RGB, GL_FLOAT, pixel);
  for (int j = 0; j < Config::HEIGHT; j++)
    for (int i = 0; i < Config::WIDTH; i++)
    {
      int pos = j * Config::WIDTH + i;
      a[j][i] = Color(pixel[pos * 3 + 0], pixel[pos * 3 + 1], pixel[pos * 3 + 2]);
    }
}

void DrawManager::handleFill()
{
  if (button != GLUT_LEFT_BUTTON)
    return;
  if (state != GLUT_DOWN)
    return;
  Color a[Config::HEIGHT][Config::WIDTH];
  getCurrentFrame(a);
  Color c = a[y][x];
  floodFill(x, y, c, a);
  glutSwapBuffers();
}

void DrawManager::handleClick(int btn, int state, int x, int y)
{
  if (DrawManager::state == state)
    return;
  DrawManager::button = btn;
  DrawManager::state = state;
  DrawManager::x = x;
  DrawManager::y = Config::WIDTH - y;
  DrawManager::isClick = true;
  glutPostRedisplay();
}

void DrawManager::resetValue()
{
  start = Point(-1, -1);
  end = Point(0, 0);
  button = 0;
  state = GLUT_UP;
  x = 0;
  y = 0;
}

void DrawManager::execute()
{
  if (!isClick)
    return;
  isClick = false;
  switch (MenuManager::getAction())
  {
  case DRAW:
  {
    Color c = MenuManager::getColor();
    glColor3f(c.r, c.g, c.b);
    handleDraw();
    break;
  }
  case FILL:
  {
    Color c = MenuManager::getColor();
    glColor3f(c.r, c.g, c.b);
    handleFill();
    break;
  }
  default:
    break;
  }
}