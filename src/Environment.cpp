#include "Environment.hpp"

Environment::Environment(int max_x, int max_y, int max_z):size_x(max_x),size_y(max_y),
    size_z(max_z),slice_x(0), slice_y(0), slice_z(0), alpha_x(0), alpha_z(0), alpha_y(0)

{
    /****** data_yz[1491][1497][51] *******/
    data_yz = new GLubyte**[size_x];
    for (int i = 0; i < size_x; ++i)
    {
        data_yz[i] = new GLubyte*[size_y];
        for (int j = 0; j < size_y; ++j)
            data_yz[i][j] = new GLubyte[size_z];
    }

    /****** data_yz[1497][1491][51] *******/
    data_xz = new GLubyte**[size_y];
    for (int i = 0; i < size_y; ++i)
    {
        data_xz[i] = new GLubyte*[size_x];
        for (int j = 0; j < size_x; ++j)
            data_xz[i][j] = new GLubyte[size_z];
    }

    /****** data_yz[51][1491][1497] *******/
    data_xy = new GLubyte**[size_z];
    for (int i = 0; i < size_z; ++i)
    {
        data_xy[i] = new GLubyte*[size_x];
        for (int j = 0; j < size_x; ++j)
            data_xy[i][j] = new GLubyte[size_y];
    }


    loadRandom();

}

Environment::~Environment()
{
//*
    for (int i = 0; i < size_x; ++i)
    {
        for (int j = 0; j < size_y; ++j)
            delete [] data_yz[i][j];
        delete [] data_yz[i];
    }
    delete [] data_yz;

    for (int i = 0; i < size_y; ++i)
    {
        for (int j = 0; j < size_x; ++j)
            delete [] data_xz[i][j];
        delete [] data_xz[i];
    }
    delete [] data_xz;

    for (int i = 0; i < size_z; ++i)
    {
        for (int j = 0; j < size_x; ++j)
            delete [] data_xy[i][j];
        delete [] data_xy[i];
    }
    delete [] data_xy;
// */

}

int Environment::getAngle(int a)
{
    int angle;

    switch(a)
    {
    case 1:
        angle=alpha_x;
        break;
    case 2:
        angle=alpha_y;
        break;
    case 3:
        angle=alpha_z;
        break;
    }

    return angle;

}

int Environment::getSize(int dim)
{

    int size;

    switch(dim)
    {
    case 1:
        size=size_x;
        break;
    case 2:
        size=size_y;
        break;
    case 3:
        size=size_z;
        break;
    }

    return size;


}

int Environment::getSlice(int dim)
{
    int slice;

    switch(dim)
    {
    case 1:
        slice=slice_x;
        break;
    case 2:
        slice=slice_y;
        break;
    case 3:
        slice=slice_z;
        break;
    }

    return slice;

}

void Environment::setSlice(int s, int dim)
{

    switch(dim)
    {
    case 1:
        slice_x= s;
        break;
    case 2:
        slice_y=s;
        break;
    case 3:
        slice_z=s;
        break;
    }

}

GLubyte** Environment::getImage(int s, int dim)
{
    GLubyte** slice;

    switch(dim)
    {
    case 1:
        slice=data_yz[s];
        break;
    case 2:
        slice=data_xz[s];
        break;
    case 3:
        slice=data_xy[s];
        break;
    }

    return slice;

}

void Environment::setAngle(int a, int dim)
{

    switch(dim)
    {
    case 1:
        alpha_x=a;
        break;
    case 2:
        alpha_y=a;
        break;
    case 3:
        alpha_z=a;
        break;
    }

}

void Environment::loadRandom()
{
    for (int i = 0; i < size_x; ++i)
        for (int j = 0; j < size_y; ++j)
            for (int k = 0; k < size_z; ++k)
            {
                int val = (sqrt(i*i+j*j+k*k)<30)?255:0;
                data_yz[i][j][k]=val;
                data_xy[k][i][j]=val;
                data_xz[j][i][k]=val;
            }
}


