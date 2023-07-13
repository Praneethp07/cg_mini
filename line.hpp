#ifndef LINE_H
#define LINE_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
class Line
{
private:
    float color[3];

public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }
    void draw(int x1, int y1, int x2, int y2, int depthIndex, int width)
    {
        glColor3fv(color);
        glLineWidth(width);
        glBegin(GL_LINES);
        glVertex3f(x1, y1, depthIndex);
        glVertex3f(x2, y2, depthIndex);
        glEnd();
    }
};
#endif /*LINE_H*/