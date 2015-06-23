#ifndef CONTROL_HPP
#define CONTROL_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void setControls(void);
void idle(void);
void resize(int width, int height);

#endif
