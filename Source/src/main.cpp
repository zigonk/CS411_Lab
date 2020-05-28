#include <bits/stdc++.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

using namespace std;

double angleCube = 1.0;
double anglePyramid = 1.0;
double refreshMills = 1.0;
double xrot = 0.0;
double yrot = 0.0;
double zrot = 0.0;
GLuint texture[1];

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
  glEnable(GL_TEXTURE_2D);
  return true;
}

int drawGLScene(GLvoid) // Here's Where We Do All The Drawing
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
  glLoadIdentity();                                   // Reset The View
  glTranslatef(0.0f, 0.0f, -5.0f);
  glRotatef(xrot, 1.0f, 0.0f, 0.0f);
  glRotatef(yrot, 0.0f, 1.0f, 0.0f);
  glRotatef(zrot, 0.0f, 0.0f, 1.0f);
  glBindTexture(GL_TEXTURE_3D, texture[0]); // Map your texture here
  glBegin(GL_QUADS);
  // Front Face
  glTexCoord3f(0.0f, 0.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  // Back Face
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  // Top Face
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  // Bottom Face
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  // Right face
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  // Left Face
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glEnd();
  xrot += 0.3f;
  yrot += 0.2f;
  zrot += 0.4f;
  return true;
}

void initGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);              // Set background color to black and opaque
  glClearDepth(1.0f);                                // Set background depth to farthest
  glEnable(GL_DEPTH_TEST);                           // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);                            // Set the type of depth-test
  glShadeModel(GL_SMOOTH);                           // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

void display()
{
  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);                         // To operate on model-view matrix
  // // Render a color-cube consisting of 6 quads with different colors
  // glLoadIdentity();                       // Reset the model-view matrix
  // glTranslatef(1.5f, 0.0f, -7.0f);        // Move right and into the screen
  // glRotatef(angleCube, 1.0f, 1.0f, 1.0f); // Rotate about (1,1,1)-axis [NEW]
  // glBegin(GL_QUADS);                      // Begin drawing the color cube with 6 quads
  // // Top face (y = 1.0f)
  // // Define vertices in counter-clockwise (CCW) order with normal pointing out
  // glColor3f(0.0f, 1.0f, 0.0f); // Green
  // glVertex3f(1.0f, 1.0f, -1.0f);
  // glVertex3f(-1.0f, 1.0f, -1.0f);
  // glVertex3f(-1.0f, 1.0f, 1.0f);
  // glVertex3f(1.0f, 1.0f, 1.0f);
  // // Bottom face (y = -1.0f)
  // glColor3f(1.0f, 0.5f, 0.0f); // Orange
  // glVertex3f(1.0f, -1.0f, 1.0f);
  // glVertex3f(-1.0f, -1.0f, 1.0f);
  // glVertex3f(-1.0f, -1.0f, -1.0f);
  // glVertex3f(1.0f, -1.0f, -1.0f);
  // // Front face (z = 1.0f)
  // glColor3f(1.0f, 0.0f, 0.0f); // Red
  // glVertex3f(1.0f, 1.0f, 1.0f);
  // glVertex3f(-1.0f, 1.0f, 1.0f);
  // glVertex3f(-1.0f, -1.0f, 1.0f);
  // glVertex3f(1.0f, -1.0f, 1.0f);
  // // Back face (z = -1.0f)
  // glColor3f(1.0f, 1.0f, 0.0f); // Yellow
  // glVertex3f(1.0f, -1.0f, -1.0f);
  // glVertex3f(-1.0f, -1.0f, -1.0f);
  // glVertex3f(-1.0f, 1.0f, -1.0f);
  // glVertex3f(1.0f, 1.0f, -1.0f);
  // // Left face (x = -1.0f)
  // glColor3f(0.0f, 0.0f, 1.0f); // Blue
  // glVertex3f(-1.0f, 1.0f, 1.0f);
  // glVertex3f(-1.0f, 1.0f, -1.0f);
  // glVertex3f(-1.0f, -1.0f, -1.0f);
  // glVertex3f(-1.0f, -1.0f, 1.0f);
  // // Right face (x = 1.0f)
  // glColor3f(1.0f, 0.0f, 1.0f); // Magenta
  // glVertex3f(1.0f, 1.0f, -1.0f);
  // glVertex3f(1.0f, 1.0f, 1.0f);
  // glVertex3f(1.0f, -1.0f, 1.0f);
  // glVertex3f(1.0f, -1.0f, -1.0f);
  // glEnd(); // End of drawing color-cube
  // // Render a pyramid consists of 4 triangles
  // glLoadIdentity();                          // Reset the model-view matrix
  // glTranslatef(-1.5f, 0.0f, -6.0f);          // Move left and into the screen
  // glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f); // Rotate about the (1,1,0)-axis [NEW]
  // glBegin(GL_TRIANGLES);                     // Begin drawing the pyramid with 4 triangles
  // // Front
  // glColor3f(1.0f, 0.0f, 0.0f); // Red
  // glVertex3f(0.0f, 1.0f, 0.0f);
  // glColor3f(0.0f, 1.0f, 0.0f); // Green
  // glVertex3f(-1.0f, -1.0f, 1.0f);
  // glColor3f(0.0f, 0.0f, 1.0f); // Blue
  // glVertex3f(1.0f, -1.0f, 1.0f);
  // // Right
  // glColor3f(1.0f, 0.0f, 0.0f); // Red
  // glVertex3f(0.0f, 1.0f, 0.0f);
  // glColor3f(0.0f, 0.0f, 1.0f); // Blue
  // glVertex3f(1.0f, -1.0f, 1.0f);
  // glColor3f(0.0f, 1.0f, 0.0f); // Green
  // glVertex3f(1.0f, -1.0f, -1.0f);
  // // Back
  // glColor3f(1.0f, 0.0f, 0.0f); // Red
  // glVertex3f(0.0f, 1.0f, 0.0f);
  // glColor3f(0.0f, 1.0f, 0.0f); // Green
  // glVertex3f(1.0f, -1.0f, -1.0f);
  // glColor3f(0.0f, 0.0f, 1.0f); // Blue
  // glVertex3f(-1.0f, -1.0f, -1.0f);
  // // Left
  // glColor3f(1.0f, 0.0f, 0.0f); // Red
  // glVertex3f(0.0f, 1.0f, 0.0f);
  // glColor3f(0.0f, 0.0f, 1.0f); // Blue
  // glVertex3f(-1.0f, -1.0f, -1.0f);
  // glColor3f(0.0f, 1.0f, 0.0f); // Green
  // glVertex3f(-1.0f, -1.0f, 1.0f);
  // glEnd(); // Done drawing the pyramid
  drawGLScene();
  glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
  // Update the rotational angle after each refresh [NEW]
  anglePyramid += 0.2f;
  angleCube -= 0.15f;
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
  if (height == 0)
    height = 1; // To prevent divide by 0
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);
  // Set the aspect ratio of the clipping volume to match the viewport
  glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
  glLoadIdentity();            // Reset
  // Enable perspective projection with fovy, aspect, zNear and zFar
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
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