#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


GLfloat angleCube = 0.0f;

void tail(double x,double y, double z){
    
    glBegin(GL_TRIANGLES);
    glVertex3d(x, y, z);
    glVertex3d(x, -y, z);
    glVertex3d(-x, 0, z);
    glVertex3d(x, y, -z);
    glVertex3d(x, -y, -z);
    glVertex3d(-x, 0, -z);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3d(x, y, z);
    glVertex3d(x, -y, z);
    glVertex3d(x, -y, -z);
    glVertex3d(x, y, -z);
    glVertex3d(x, y, z);
    glVertex3d(-x, 0, z);
    glVertex3d(-x, 0, -z);
    glVertex3d(x, y, -z);
    glVertex3d(x, -y, z);
    glVertex3d(-x, 0, z);
    glVertex3d(-x, 0, -z);
    glVertex3d(x, -y, z);
    glEnd();

}

void bait(){
    
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
          // Top face (y = 1.0f)
          // Define vertices in counter-clockwise (CCW) order with normal pointing out
          glColor3f(0.0f, 1.0f, 0.0f);     // Green
          glVertex3f( 1.0f, 1.0f, -1.0f);
          glVertex3f(-1.0f, 1.0f, -1.0f);
          glVertex3f(-1.0f, 1.0f,  1.0f);
          glVertex3f( 1.0f, 1.0f,  1.0f);
     
          // Bottom face (y = -1.0f)
          glColor3f(1.0f, 0.5f, 0.0f);     // Orange
          glVertex3f( 1.0f, -1.0f,  1.0f);
          glVertex3f(-1.0f, -1.0f,  1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f( 1.0f, -1.0f, -1.0f);
     
          // Front face  (z = 1.0f)
          glColor3f(1.0f, 0.0f, 0.0f);     // Red
          glVertex3f( 1.0f,  1.0f, 1.0f);
          glVertex3f(-1.0f,  1.0f, 1.0f);
          glVertex3f(-1.0f, -1.0f, 1.0f);
          glVertex3f( 1.0f, -1.0f, 1.0f);
     
          // Back face (z = -1.0f)
          glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
          glVertex3f( 1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f,  1.0f, -1.0f);
          glVertex3f( 1.0f,  1.0f, -1.0f);
     
          // Left face (x = -1.0f)
          glColor3f(0.0f, 0.0f, 1.0f);     // Blue
          glVertex3f(-1.0f,  1.0f,  1.0f);
          glVertex3f(-1.0f,  1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f,  1.0f);
     
          // Right face (x = 1.0f)
          glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
          glVertex3f(1.0f,  1.0f, -1.0f);
          glVertex3f(1.0f,  1.0f,  1.0f);
          glVertex3f(1.0f, -1.0f,  1.0f);
          glVertex3f(1.0f, -1.0f, -1.0f);
       glEnd();  // End of drawing color-cube

    
}

void initGL() {
    glClearColor(3.0/255, 248/255.0, 252.0/255, 1.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
double anglex = 0;
double angley=0;
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glTranslated(0, 0, -30);
    glRotated(angley,0,1,0);
    glRotated(anglex, 1, 0, 0);
    
    glColor3d(40.0/255, 176.0/255, 255.0/255);
    glScaled(3, 1, 1);
    glutSolidSphere(5, 30, 30);
    glScaled(1/3.0, 1.0, 1.0);
    glTranslated(15, 0, 0);
    glColor3d(0, 0, 1);
    tail(2.5,2,2);
    glTranslated(-15, 0, 0);
    
    glTranslated(0, 5, 0);
    tail(1.5, 1, 1);
    
    glTranslated(0, -10, 0);
    tail(1.5, 1, 1);
    
    glTranslated(-10, 7, 2);
    glutSolidSphere(1, 30, 30);
    
    glTranslated(0, 0, -4);
    glutSolidSphere(1, 30, 30);
    
    
    glTranslated(-15, 0, 0);
    
    
    glTranslated(1, 1, 0);
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);
    bait();
    angleCube -= 0.15f;
    glutSwapBuffers();
}
void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}
void reshape(GLsizei width, GLsizei height) {
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
    glViewport(0, 0, width, height);
 
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(60.0, aspect, 0.1, 100.0);
}

void specialinput(int key, int x, int y){
    if (key == GLUT_KEY_LEFT)
        angley--;
    else if (key == GLUT_KEY_RIGHT)
        angley++;
    else if (key == GLUT_KEY_UP)
        anglex--;
    else if (key == GLUT_KEY_DOWN)
        anglex++;
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("20101208");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialinput);
    initGL();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
