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
namespace zero {
    class Color32
    {
        public:
        GLubyte r, g, b, a=255;
        Color32(GLubyte r, GLubyte g, GLubyte b):
        r(r), g(g), b(b) {};
        Color32(GLubyte r, GLubyte g, GLubyte b, GLubyte a): r(r), g(g), b(b), a(a) {};

    };
}
