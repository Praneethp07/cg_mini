#ifndef MONKEY_H
#define MONKEY_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "circle.hpp"
#include "line.hpp"
#include "elipse.hpp"
#include "Triangle.hpp"
Circle circle;
Ellipse elipse;
class Monkey
{

private:
    void drawFace()
    {

        circle.setColor(1, 0.5, 0);
        circle.draw(250, 650, 2000, 3, false, 0, 360);
        circle.setColor(0.9, 0.71, 0.63);
        circle.draw(200, 650, 2000, 2, false, 180, 360);
        circle.draw(100, 550, 2000, 2, false, 0, 180);
        circle.draw(100, 750, 2000, 2, false, 0, 180);
    }
    void drawEyes()
    {
        circle.setColor(0, 0, 0);
        circle.draw(30, 580, 2000, 1, false, 0, 360);
        circle.draw(30, 720, 2000, 1, false, 0, 360);
    }
    void drawNose()
    {
        circle.setColor(1, 0, 0);
        circle.draw(20, 650, 1940, 1, false, 0, 360);
    }
    void drawMouth()
    {
        circle.setColor(1, 1, 1);
        // circle.draw(50,250,1900,1,false,180,360);
        circle.draw(60, 650, 1890, 1, false, 180, 360);
    }
    void drawEars()
    {
        circle.setColor(1, 0.5, 0);
        circle.draw(40, 450, 2150, 4, false, 40, 240);
        circle.setColor(0.9, 0.71, 0.63);
        circle.draw(70, 450, 2150, 4, false, 40, 240);
        circle.setColor(1, 0.5, 0);
        circle.draw(40, 850, 2150, 4, false, 280, 500);
        circle.setColor(0.9, 0.71, 0.63);
        circle.draw(70, 850, 2150, 4, false, 280, 500);
    }
    void drawBody()
    {
        elipse.setColor(1, 0.5, 0);
        elipse.draw(650, 1500, 200, 400, 5, false, 0, 360);
        elipse.setColor(0.9, 0.71, 0.63);
        elipse.draw(650, 1530, 130, 330, 4, false, 0, 360);
    }

    void drawHands()
    {
        circle.setColor(1, 0.5, 0);
        circle.draw(500, 600, 2050, 3, true, 300, 360);
        circle.setColor(1, 0.5, 0);
        circle.draw(500, 700, 2050, 3, true, 180, 240);
    }

    void drawLegs()
    {
        circle.setColor(1, 0.5, 0);
        circle.draw(600, 250, 870, 3, true, 350, 390);
        circle.draw(600, 1050, 870, 3, true, 150, 190);
        elipse.setColor(1, 0.5, 0);
        elipse.draw(380, 750, 100, 25, 3, false, 0, 360);
        elipse.draw(930, 750, 100, 25, 3, false, 0, 360);
    }
    void drawTail()
    {
        circle.draw(300, 830, 1000, 3, true, 350, 450);
    }

public:
    void drawMonkey(int xpos, int ypos, float scale)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glScalef(scale, scale, scale);
        drawFace();
        drawEyes();
        drawNose();
        drawMouth();
        drawEars();
        drawBody();
        drawHands();
        drawLegs();
        drawTail();
        glPopMatrix();
    }

    void drawMonkey(int xpos, int ypos, float scale, int rotAngle)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, -100);
        glRotatef(rotAngle, 0, 0, 1);
        glScalef(scale, scale, scale);
        drawFace();
        drawEyes();
        drawNose();
        drawMouth();
        drawEars();
        drawBody();
        drawHands();
        drawLegs();
        drawTail();
        glPopMatrix();
    }
};
#endif /*MONKEY_H*/
