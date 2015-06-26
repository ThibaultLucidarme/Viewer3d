#include "control.h"

void setControls(void)
{
    glutIdleFunc(idle);
    glutReshapeFunc(resize);
}

 void idle(void)
{
    glutPostRedisplay();
}


 void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    gluPerspective(70,ar,0.1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
