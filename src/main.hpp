#ifndef MAIN_HPP
#define MAIN_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <cmath>

#include "init.hpp"
#include "Environment.hpp"
#include "control.h"


Environment* env = new Environment(1491,1497,51);

#endif
