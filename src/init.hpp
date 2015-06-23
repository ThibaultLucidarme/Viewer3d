#ifndef init_hpp
#define init_hpp

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


void init(int* argc, char** argv);

#endif
