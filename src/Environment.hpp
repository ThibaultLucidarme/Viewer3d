#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <vector>
#include <cmath>
#include "Slice.hpp"

class Environment
{
public:
    Environment(int max_x, int max_y, int max_z);
    ~Environment();

    int getAngle(int);
    void setAngle(int, int);
    int getSize(int);
    int getSlice(int);
    void setSlice(int, int);
    GLubyte** getImage(int, int);

    void loadRandom();


protected:
private:

    GLubyte*** data_xy, ***data_xz, ***data_yz;

    int size_x, size_y, size_z;
    int slice_x, slice_y, slice_z;
    int alpha_x, alpha_z, alpha_y;
};

#endif // ENVIRONMENT_HPP
