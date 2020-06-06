#include "cylinder.h"
#include "sphere.h"
#include "cone.h"
#include "paraboloid.h"
#include "hyperboloid.h"
#include "torus.h"
#include "disk.h"
#include "cube.h"

GLuint texture[1];
float refreshMills = 10;
float curAngle = 0;

int loadGLTextures() // Load Bitmaps And Convert To Textures
{
  /* load an image file directly as a new OpenGL texture */
  texture[0] = SOIL_load_OGL_texture(
      "../static/template.bmp",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y);
  if (texture[0] == 0)
    return false;
  // Typical Texture Generation Using Data From The Bitmap
  glBindTexture(GL_TEXTURE_2D, texture[0]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  return true;
}


void initGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);              // Set background color to black and opaque
  glClearDepth(1.0f);                                // Set background depth to farthest
  glEnable(GL_DEPTH_TEST);                           // Enable depth testing for z-culling
  glFrontFace(GL_CW);
  glEnable(GL_CULL_FACE);
  glEnable(GL_TEXTURE_2D);
  glDepthFunc(GL_LEQUAL);                            // Set the type of depth-test
  glShadeModel(GL_SMOOTH);                           // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  curAngle += 1;
  glColor3f(1.0f, 1.0f, 1.0f);
  Cube cube = Cube(Point(-60, 15), 15);
  cube.draw(curAngle);
  Sphere s = Sphere(Point(-10, 15), 15);
  s.draw(360, curAngle);
  Cylinder c = Cylinder(Point(40, 0), 30, 15);
  c.draw(360, curAngle);
  Cone cone = Cone(Point(90, 0), 30, 15);
  cone.draw(360, curAngle);
  // Row 2
  Disk d = Disk(Point(-60, -50), 15);
  d.draw(360, curAngle);
  Torus t = Torus(Point(-10, -50), 15, 5);
  t.draw(360, curAngle);
  Paraboloid p = Paraboloid(Point(40,-50), 20, -10);
  p.draw(360, curAngle);
  Hyperboloid h = Hyperboloid(Point(90, -50), 20);
  h.draw(360, curAngle);

  glutSwapBuffers();
  glMatrixMode(GL_MODELVIEW);                         // To operate on model-view matrix
}
/* Called back when timer expired [NEW] */
void timer(int value)
{
  glutPostRedisplay();                   // Post re-paint request to activate display()
  glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}
/* Handler for window re-size event. Called back when the window first appears and
 whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height)
{ // GLsizei for non-negative integer
  // Compute aspect ratio of the new window
  GLfloat nRange = 100.0f;
  if (height == 0)
    height = 1; // To prevent divide by 0
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);
  // Set the aspect ratio of the clipping volume to match the viewport
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
  if (width <= height)
    glOrtho (-nRange, nRange, -nRange * height / width, nRange * height / width, -nRange, nRange);
  else
    glOrtho (-nRange * width / height, nRange * width / height, -nRange, nRange, -nRange, nRange);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();            // Reset
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char **argv)
{
  glutInit(&argc, argv);            // Initialize GLUT
  glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
  glutInitWindowSize(640, 480);     // Set the window's initial width & height
  glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
  glutCreateWindow("Window");       // Create window with the given title
  glutDisplayFunc(display);         // Register callback handler for window re-paint event
  glutReshapeFunc(reshape);         // Register callback handler for window re-size event
  initGL();                         // Our own OpenGL initialization
  glutTimerFunc(0, timer, 0);       // First timer call immediately [NEW]
  loadGLTextures();
  glutMainLoop();                   // Enter the infinite event-processing loop
  return 0;
}