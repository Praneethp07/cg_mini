#ifndef CROCODILE_H
#define CROCODILE_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include "elipse.hpp"
#include "circle.hpp"
Ellipse ellipse;
class Crocodile
{
private:
    Circle circle;
    void drawtext(float x, float y, char *s)
    {
        glColor3f(0, 0, 0);
        glRasterPos2f(x, y);
        for (int i = 0; s[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
    }

public:
    void draw(int xpos, int ypos, int rotAngle, float scale)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glRotatef(rotAngle, 0, 0, 1);
        glScalef(scale, scale, scale);
        ellipse.setColor(0, 0.5, 0);
        ellipse.draw(200, 1600, 200, 600, 7, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1600, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1820, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1380, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(350, 1700, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(350, 1500, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(70, 1700, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(70, 1500, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(150, 2040, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(150, 1230, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(200, 2100, 150, 450, 8, false, 0, 360);
        //ellipse.setColor(0,0,0);
        // ellipse.draw(200,1300,100,450,7,true,330,370);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(70, 2300, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(150, 2520, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(250, 2520, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(150, 2520, 30, 30, 8, false, 0, 360);
        circle.setColor(0, 0, 0);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(250, 2520, 30, 30, 8, false, 0, 360);
        circle.draw(20, 60, 2300, 6, false, 0, 360);
        circle.setColor(0, 0, 0);
        circle.draw(20, 200, 2300, 6, false, 0, 360);
        // circle.setColor(0,0.2,0);
        //circle.draw(20,200,1300,6,false,0,360);
        ellipse.setColor(0, 0.5, 0);
        ellipse.draw(250, 888, 70, 151, 8, true, 110, 270, 15);
        ellipse.draw(260, 555, 100, 201, 8, true, 300, 420, 15);
        glFlush();
        glPopMatrix();
    }

    void draw(int xpos, int ypos, int rotAngle)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glRotatef(rotAngle, 0, 0, 1);
        ellipse.setColor(0, 0.5, 0);
        ellipse.draw(200, 1600, 200, 600, 7, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1600, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1820, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1380, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(350, 1700, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(350, 1500, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(70, 1700, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(70, 1500, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(150, 2040, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(150, 1230, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(200, 2100, 150, 450, 8, false, 0, 360);
        //ellipse.setColor(0,0,0);
        // ellipse.draw(200,1300,100,450,7,true,330,370);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(70, 2300, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(150, 2520, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(250, 2520, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(150, 2520, 30, 30, 8, false, 0, 360);
        circle.setColor(0, 0, 0);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(250, 2520, 30, 30, 8, false, 0, 360);
        circle.draw(20, 60, 2300, 6, false, 0, 360);
        circle.setColor(0, 0, 0);
        circle.draw(20, 200, 2300, 6, false, 0, 360);
        // circle.setColor(0,0.2,0);
        //circle.draw(20,200,1300,6,false,0,360);
        ellipse.setColor(0, 0.5, 0);
        ellipse.draw(250, 888, 70, 151, 8, true, 110, 270, 15);
        ellipse.draw(260, 555, 100, 201, 8, true, 300, 420, 15);
        glFlush();
        glPopMatrix();
    }

    void draw(int xpos, int ypos, int rotAngle, float scale, int dummy)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glRotatef(rotAngle, 0, 0, 1);
        glScalef(scale, -scale, scale);
        ellipse.setColor(0, 0.5, 0);
        ellipse.draw(200, 1600, 200, 600, 7, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1600, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1820, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 1380, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(350, 1700, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(350, 1500, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(70, 1700, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(70, 1500, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(150, 2040, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(150, 1230, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(200, 2100, 150, 450, 8, false, 0, 360);
        //ellipse.setColor(0,0,0);
        // ellipse.draw(200,1300,100,450,7,true,330,370);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(70, 2300, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(150, 2520, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(250, 2520, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(150, 2520, 30, 30, 8, false, 0, 360);
        circle.setColor(0, 0, 0);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(250, 2520, 30, 30, 8, false, 0, 360);
        circle.draw(20, 60, 2300, 6, false, 0, 360);
        circle.setColor(0, 0, 0);
        circle.draw(20, 200, 2300, 6, false, 0, 360);
        // circle.setColor(0,0.2,0);
        //circle.draw(20,200,1300,6,false,0,360);
        ellipse.setColor(0, 0.5, 0);
        ellipse.draw(250, 888, 70, 151, 8, true, 110, 270, 15);
        ellipse.draw(260, 555, 100, 201, 8, true, 300, 420, 15);
        glFlush();
        glPopMatrix();
    }

    void cloud(int xpos, int ypos, char *line1, char *line2)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        Circle circle;
        circle.setColor(1, 1, 1);
        circle.draw(80, 60, 80, 1, false, 0, 360);
        circle.draw(100, 150, 200, 1, false, 0, 360);
        Ellipse ellipse;
        ellipse.setColor(1, 1, 1);
        ellipse.draw(680, 400, 700, 200, 1, false, 0, 360);
        drawtext(50, 420, line1);
        drawtext(50, 330, line2);
        glPopMatrix();
    }
};
#endif /*CROCODILE_H*/
