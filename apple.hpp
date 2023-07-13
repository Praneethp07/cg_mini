#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "elipse.hpp"
#include "line.hpp"

class Apple
{

public:
    void draw(int xpos, int ypos, float scale)
    {
        Ellipse ellipse;
        Line line;
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glScalef(scale, scale, scale);
        ellipse.setColor(1, 0, 0);
        ellipse.draw(600, 600, 50, 70, 1, false, 0, 360);
        ellipse.draw(625, 600, 50, 70, 1, false, 0, 360);
        line.setColor(0.3, 0.3, 0.3);
        line.draw(625, 635, 625, 745, 1, 3);
        glPopMatrix();
    }

    void draw(int xpos, int ypos, float scale, int flag)
    {
        Ellipse ellipse;
        Line line;
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glScalef(scale, scale, scale);
        ellipse.setColor(1, 0, 0);
        ellipse.draw(600, 600, 50, 70, 1, false, 0, 360);
        ellipse.draw(625, 600, 50, 70, 1, false, 0, 360);
        line.setColor(0, 0, 0);
        line.draw(625, 635, 625, 745, 1, 5);
        glPopMatrix();
    }
};