#ifndef SLICE_HPP
#define SLICE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Slice
{
public:
    Slice(int , int );
    ~Slice();

    GLubyte setData(int, int, int, int);
    GLubyte*** getData(void);
protected:
private:

    GLubyte*** data;
    int size_x, size_y;

};

#endif // SLICE_HPP
