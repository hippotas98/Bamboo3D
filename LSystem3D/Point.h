#pragma
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

namespace zero
{
    class Point
    {
        public:
        GLint x, y, z;
        Point() {x = y = z = 0;}
        Point(GLint x, GLint y, GLint z)
        {
            this->x = x; this->y = y; this->z = z;
        }
        Point(GLint x, GLint y)
        {
            this->x = x; this->y = y; this->z = 0;
        }
        void setxy(GLint x2, GLint y2)
        {
            x = x2;
            y = y2;
        }
        Point& operator=(const Point &rPoint)
        {
            x = rPoint.x;
            y = rPoint.y;
            z = rPoint.z;

            return *this;
        }
    };
}
