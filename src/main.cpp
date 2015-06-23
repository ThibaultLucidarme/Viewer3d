
#include "main.hpp"
#include <iostream>

static void key(unsigned char key, int x, int y)
{
    int tmp;
    int step = 10;
    switch (key)
    {

    case 'a':
        tmp = env->getSlice(1);
        if (tmp+step < env->getSize(1) )
            env->setSlice(tmp+step,1);
        break;
    case 'z':
        tmp = env->getSlice(1);
        if (tmp-step >= 0)
            env->setSlice(tmp-step,1);
        break;

    case 'q':
        tmp = env->getSlice(2);
        if (tmp+step < env->getSize(2) )
            env->setSlice(tmp+step,2);
        break;
    case 's':
        tmp = env->getSlice(2);
        if (tmp-step >= 0)
            env->setSlice(tmp-step,2);
        break;

    case 'w':
        tmp = env->getSlice(3);
        if (tmp+1 < env->getSize(3) )
            env->setSlice(tmp+1,3);
        break;
    case 'x':
        tmp = env->getSlice(3);
        if (tmp-1 >= 0)
            env->setSlice(tmp-1,3);
        break;


    case 'p':
        tmp = env->getAngle(2);
        env->setAngle(tmp+step,2);
        break;
    case 'o':
        tmp = env->getAngle(2);
        env->setAngle(tmp-step,2);
        break;
    case 'i':
        env->setAngle(0,2);
        break;

    case 'm':
        tmp = env->getAngle(3);
        env->setAngle(tmp+step,3);
        break;
    case 'l':
        tmp = env->getAngle(3);
        env->setAngle(tmp-step,3);
        break;
    case 'k':
        env->setAngle(0,3);
        break;
    }


    glutPostRedisplay();
}

static void display(void)
{
    // set camera
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    //gluLookAt(3*cos(alpha*0.1),3,3*sin(alpha*0.1),
    gluLookAt(1.5,1.5,1.5,
              0,0,0,
              0,0,1);

    glRotated(env->getAngle(1),1,0,0);
    glRotated(env->getAngle(2),0,1,0);
    glRotated(env->getAngle(3),0,0,1);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    static GLuint texXY, texXZ, texYZ;

    /**** YZ plane ****/

    double abs = env->getSlice(1)/env->getSize(1)*2-1;
/*
    glGenTextures(1, &texYZ);
    glBindTexture(GL_TEXTURE_2D, texYZ);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, env->getSize(2),env->getSize(3),
                 0, GL_RGBA, GL_UNSIGNED_BYTE,env->getImage(abs,1));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texYZ);

 // */
    glColor3d(1,0,0);
    glPushMatrix();

    glTranslatef(abs,0,0);
    glBegin(GL_QUADS);
    glVertex3f(0,1,-1);
    glVertex3f(0,1,1);
    glVertex3f(0,-1,1);
    glVertex3f(0,-1,-1);
    glEnd();

    glPopMatrix();

    glFlush();
    glDisable(GL_TEXTURE_2D);

    /**** XZ plane ****/

    glColor3d(0,1,0);
    glPushMatrix();
    double ord = env->getSlice(2)/env->getSize(2)*2-1;
    glTranslatef(0,ord,0);
    //glutSolidCube(1);
    glBegin(GL_QUADS);
    glVertex3f(1,0,-1);
    glVertex3f(1,0,1);
    glVertex3f(-1,0,1);
    glVertex3f(-1,0,-1);
    glEnd();
    glPopMatrix();

    glColor3d(0,0,1);
    glPushMatrix();
    double cot = env->getSlice(3)/env->getSize(3)*2-1;
    glTranslatef(0,0,cot);
    //glutSolidCube(1);
    glBegin(GL_QUADS);
    glVertex3f(1,-1,0);
    glVertex3f(1,1,0);
    glVertex3f(-1,1,0);
    glVertex3f(-1,-1,0);
    glEnd();
    glPopMatrix();

    //dessinerRepere();

    int abs2, ord2, cot2;
    if ( abs2!=abs || ord2!=ord || cot2!=cot )
    {
        abs2 = (abs2!=abs)?abs:abs2;
        ord2 = (ord2!=ord)?ord:ord2;
        cot2 = (cot2!=cot)?cot:cot2;

        std::cout<<"graphics coords updated :"<< abs<<" "<<ord<<" "<<cot<<std::endl;
    }

    glutSwapBuffers();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    init(&argc, argv);
    setControls();

    glutDisplayFunc(display);
    glutKeyboardFunc(key);

    glutMainLoop();

    return EXIT_SUCCESS;
}
