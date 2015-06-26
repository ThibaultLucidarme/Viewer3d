#include "Slice.hpp"

Slice::Slice(int x, int y):size_x(x),size_y(y)
{
    data = new GLubyte**[x];
    for (int i = 0; i < x; ++i)
    {
        data[i] = new GLubyte*[y];
        for (int j = 0; j < y; ++j)
            data[i][j] = new GLubyte[4];
    }
}

Slice::~Slice()
{
    for (int i = 0; i < size_x; ++i)
    {
        for (int j = 0; j < size_y; ++j)
            delete [] data[i][j];

        delete [] data[i];
    }

    delete [] data;
}

GLubyte Slice::setData(int i, int j, int k, int val)
{
    GLubyte d = NULL;
    if(i<size_x && j<size_y && k<4)
        data[i][j][k] = val;

    return d;
}

GLubyte*** Slice::getData(void)
{
    return data;
}
