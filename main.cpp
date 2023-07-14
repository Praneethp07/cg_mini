#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif
#include <string>
#include "apple.hpp"
// # include "elipse.hpp"
#include "monkey.hpp"
#define SPACEBAR 32
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "crocodile.hpp"
unsigned int intro, moral;
int scene = 0;
bool appleMove = false;
bool appleDown = false;
bool displayCloudS1 = true;
bool displayCloudS2 = true;
bool crocMaleFemale = true;
bool crocMonkey = true;
bool crocMonkeyS3 = true;
bool monkeyDown = false;
bool moveMonkeyCroc = false;
bool displayCloudS3 = true;
bool displayCloudS4 = true;
bool displayCloudS5 = false;
bool dialogsDone = false;
bool crocMonkeyS4 = true;
bool crocMonkeyS5 = true;
bool displayMoralS5 = false;
char *maleLine;
char *maleLine2 = " ";
char *femaleLine;
char *femaleLine2 = " ";
char *monkeyLine;
char *monkeyLine2;
char *line = "Click to continue";
int maleCounter = 0;
int femaleCounter = 0;
int monkeyCounter = 0;
void idle();
void idle2();
void moveCroc();
void keyboard();
void timer(int value);
void idle3();
void idle4(int);
void moveCrocMonkey();
float xpos = 2870, ypos = 2900, cXpos = 915, axpos = 1500, mypos = 2600, mxpos = 3400, b1xpos, b2xpos;
void idle5();

void drawtext(float x, float y, char *s,bool flag,bool big)
{
    if(flag)
        glColor3f(0, 0, 0);
    else
    {
        glColor3f(1,1,1);
    }

    glRasterPos2f(x, y);
    if(big)
    {
        for (int i = 0; s[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
    else
    {
        for (int i = 0; s[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
    }
}

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 5000, 0, 5000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
}

void displayIntro()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, intro);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void displayMoral()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, moral);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}
void sky(){
  glPushMatrix();
  glTranslatef(2500,3300,100);
  glScalef(5000,3500,10);
  glColor3f(0.49, 0.93, 0.99);
  glutSolidCube(1.0);
  glPopMatrix();
}
void grass(int i){
    glPushMatrix();
    if(i == 1){
      glTranslatef(0,400,0);
    }else if(i==2){
      glTranslatef(0,700,5);
    }
    else if(i==3){
      glTranslatef(0,500,5);
    }
    else if(i==4){
      glTranslatef(0,500,100);
    }
    else if(i==5){
      glTranslatef(0,500,0);
    }
    int disp=0;
    for(int i=0;i<100;i++){
    glColor3f(0.31, 1, 0.11);
    glBegin(GL_TRIANGLES);
    glVertex2f(50+disp, 1550);   // Vertex 1 (top)
    glVertex2f(0+disp, 1180); // Vertex 2 (bottom-left)
    glVertex2f(100+disp, 1180);  // Vertex 3 (bottom-right)
    glEnd();
    disp+=50;
    }
    disp=0;
    for(int i=0;i<100;i++){
    glColor3f(0.07, 0.78, 0.04);
    glBegin(GL_TRIANGLES);
    glVertex2f(50+disp, 1680);   // Vertex 1 (top)
    glVertex2f(0+disp, 1310); // Vertex 2 (bottom-left)
    glVertex2f(100+disp, 1310);  // Vertex 3 (bottom-right)
    glEnd();
    disp+=50;
    }
    glPopMatrix();


}
void river()
{
    glColor4f(0, 0,1,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 1200);
    glVertex2f(5000, 1200);
    glVertex2f(5000, 0);
    glEnd();
}
void rocks(float x,float y){
  glPushMatrix();
  glColor3f(0.68, 0.66, 0.64);
  if(x == 0){
    glTranslatef(300,y+200,0);
  }else{
    glTranslatef(x+1000,y+200,0);
  }
  glScalef(300,200,0);
  glutSolidSphere(1.0,40,40);
  glPopMatrix();
  glPushMatrix();
  glColor3f(0.68, 0.66, 0.64);
  if(x == 0){
    glTranslatef(1500,y-60+200,0);
  }else{
    glTranslatef(x+500+1500,y-60+200,0);
  }
  glScalef(200,100,0);
  glutSolidSphere(1.0,40,40);
  glPopMatrix();
}
void river2(){
  glPushMatrix();
  glTranslatef(2500,500,-5);
  glScalef(5000,1500,100);
  glColor3f(0.08, 0.5, 0.85);
  glutSolidCube(1.0);
  glPopMatrix();
}
void river3(){
  glBegin(GL_POLYGON);
  glColor3f(0.08, 0.5, 0.85);
  glVertex3f(0, 2000, 10);
  glVertex3f(5000, 2000, 10);
  glVertex3f(5000,0, 10);
  glVertex3f(0, 0, 10);
  glEnd();

}
void grassGround(int i){

  grass(i);
  if(i==1){
  glPushMatrix();
  glTranslatef(2500,1400,-6);
  glScalef(5000,500,100);
  glColor3f(0.54, 0.34, 0.11);
  glutSolidCube(1.0);
  glPopMatrix();
}
  else if(i==3 || i == 2){
    glBegin(GL_POLYGON);
    glColor3f(0.54, 0.35, 0.12);
    glVertex3f(0, 2000, 10);
    glVertex3f(5000, 2000, 10);
    glVertex3f(5000,1500, 10);
    glVertex3f(0, 1500, 10);
    glEnd();
  }
}

void Tree(){
glPushMatrix();
glColor3f(0.31, 0.13, 0.01);
glutSolidCube(1.0);
glTranslatef(2000,2000,6);
glScalef(500,2000,100);
glPopMatrix();
}

void leaves(){
  glPushMatrix();
  glTranslatef(4000,4200,-6);
  glScalef(1400,1400,100);
  glColor3f(0.18, 0.75, 0.1);
  glutSolidSphere(0.5f,40,40);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(3600,3800,-6);
  glScalef(1400,1400,100);
  glColor3f(0.18, 0.75, 0.1);
  glutSolidSphere(0.5f,40,40);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(3300,3000,-6);
  glScalef(1400,1400,100);
  glColor3f(0.18, 0.75, 0.1);
  glutSolidSphere(0.5f,40,40);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(4600,2800,-6);
  glScalef(1200,1000,100);
  glColor3f(0.18, 0.75, 0.1);
  glutSolidSphere(0.5f,40,40);
  glPopMatrix();
}
void Tree1(){
  leaves();
  glPushMatrix();
  glTranslatef(4000,3600,0);
  glScalef(500,500,-10);
  glColor3f(0.18, 0.75, 0.1);
  glutSolidSphere(2.1f,40,40);
  glPopMatrix();
}

void treeTrunk(int i){
    if(i == 1){
      glColor3f(0.4, 0.2, 0.0);
      glRectf(3800, 1700, 4100, 2595);
      glEnd();
    }else{
      glPushMatrix();
      glColor3f(0.4, 0.2, 0.0);
      glTranslatef(0,500,10);
      glRectf(3800, 1400, 4100, 2595);
      glEnd();
      glPopMatrix();
    }

}

void displayScene1()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rocks(1000,1400);
    rocks(0,1400);
    rocks(2900,1400);
    Tree1();
    treeTrunk(1);
      sky();
    grassGround(1);
    river2();
    Crocodile crocodile;
    crocodile.draw(cXpos, 450, 280);
    Monkey monkey;
    monkey.drawMonkey(3400, 2600, 0.5);
    Apple apple;
    glDisable(GL_TEXTURE_2D);
    apple.draw(3600, 2800, 1);
    apple.draw(3600, 3900, 1);
    apple.draw(3400, 2800, 1);
    apple.draw(3400, 3800, 1);
    apple.draw(3000, 3800, 1);
    apple.draw(2600, 3100, 1);
    apple.draw(xpos, ypos, 1, 0);
    if (displayCloudS1)
    {
        if (crocMonkey)
        {
            switch (monkeyCounter)
            {
            case 0:
                monkeyLine = "Hello Mr Croc";
                monkeyLine2 = " ";
                break;
            case 1:
                monkeyLine = "How are you??";
                monkeyLine2 = " ";
                break;
            case 2:
                monkeyLine = "Good to hear that";
                monkeyLine2 = " ";
                break;
            case 3:
                monkeyLine = "Sure, take as many as you want";
                monkeyLine2 = " ";
                line = "Press D to drop the Apples";
                appleDown = true;
                break;
            case 4:
                monkeyLine = "Yes they are the best in this region";
                monkeyLine2 = " ";
                break;
            case 5:
                monkeyLine = "Sure convey my good wishes to her!!";
                monkeyLine2 = "Goodbye!!";
                line = "Press SpaceBar to move to the next scene";
                dialogsDone = true;
            }
            crocodile.cloud(3900, 3600, monkeyLine, monkeyLine2);
        }
        else
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "Hello Mr Monkey";
                maleLine2 = " ";
                break;
            case 1:
                maleLine = "Im fine..thank you";
                maleLine2 = " ";
                break;
            case 2:
                maleLine = "Those apples look very delicious!";
                maleLine2 = "Can I please have a few??";
                break;
            case 3:
                maleLine = "They are the most delicious apples";
                maleLine2 = " I have ever tasted";
                line = "Click to continue";
                break;
            case 4:
                maleLine = "Can you please give some apples for my wife";
                maleLine2 = "She would love it";
                break;
            }
            crocodile.cloud(2300, 800, maleLine, maleLine2);
        }

    }
    drawtext(1300, 3800, line,true,false);
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}
void sky1(){
  glBegin(GL_POLYGON);
  glColor3f(0.49, 0.93, 0.99);
  glVertex3f(0, 5000, 10);
  glVertex3f(5000, 5000, 10);
  glVertex3f(5000, 2000, 10);
  glVertex3f(0, 2000, 10);
  glEnd();
}
void displayScene2()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    sky1();
    grassGround(2);
    //river
    rocks(0,1700);
    rocks(3000,7800);
    rocks(1000,1700);
    rocks(2000,1700);
    river3();
    Crocodile crocodile;
    Apple apple;
    glDisable(GL_TEXTURE_2D);
    crocodile.draw(cXpos, 1000, 270, 0.8);
    if (displayCloudS2)
    {
        crocodile.draw(5000, 1000, 270, 0.8, 1);
        apple.draw(axpos, 260, 1);
        if (crocMaleFemale)
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "Hello Mrs Croc!";
                maleLine2 = " ";
                break;
            case 1:
                maleLine = "How was your day";
                maleLine2 = " ";
                break;
            case 2:
                maleLine = "I have some\n apples for you";
                maleLine2 = " ";
                appleMove = true;
                break;
            case 3:
                maleLine = "I knew you would like them";
                maleLine2 = "They are the best in the region";
                break;
            case 4:
                maleLine = "A monkey on the river bank gave it to me";
                maleLine2 = " ";
                break;
            case 5:
                maleLine = "His heart?? I cannot do that!!";
                maleLine2 = " ";
                break;
            case 6:
                maleLine = "Okay..I will get him here";
                maleLine2 = " ";
                line = "Press SpaceBar to move to the next scene";
                dialogsDone = true;
                break;
            }
            crocodile.cloud(1700, 1000, maleLine, maleLine2);
        }
        else
        {
            switch (femaleCounter)
            {
            case 0:
                femaleLine = "Hello Mr Croc!";
                femaleLine2 = " ";
                break;
            case 1:
                femaleLine = "Nothing special Mr Croc...what about you";
                break;
            case 2:
                femaleLine = "Wow apples!!";
                femaleLine2 = "Thank you so much";
                break;
            case 3:
                femaleLine = "They are so delicious";
                femaleLine2 = "Who gave them to you??";
                break;
            case 4:
                femaleLine = "A monkey?? Imagine how tasty he would be";
                femaleLine2 = "Get me his heart..I have a craving for it";
                break;
            case 5:
                femaleLine = "Can you not do a simple favour for your wife??";
                femaleLine2 = " ";
                break;
            }
            crocodile.cloud(2900, 1000, femaleLine, femaleLine2);
        }
    }
    drawtext(1700, 4000, line,true,false);
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void treetop(){
  Circle circle;
  circle.setColor(0.11, 0.62, 0.04);
  circle.draw(900,4000,3900,10,false,0,360);
  circle.draw(600,3500,3300,10,false,0,360);
  circle.draw(700,3900,4000,10,false,0,360);
  circle.draw(600,4500,3300,10,false,0,360);
}

void displayScene3(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    treetop();
    rocks(-500,1500);
    rocks(3500,1500);
    treeTrunk(3);
    sky1();
    grassGround(3);
    river3();
    Monkey monkey;
    monkey.drawMonkey(mxpos, mypos, 0.5);
    Crocodile crocodile;
    crocodile.draw(cXpos, 575, 280);
    Apple apple;
    glDisable(GL_TEXTURE_2D);
    apple.draw(3600, 2800, 1);
    apple.draw(3600, 3900, 1);
    apple.draw(3400, 2800, 1);
    apple.draw(3400, 3800, 1);
    apple.draw(3000, 3800, 1);
    apple.draw(2600, 3100, 1);

    if (displayCloudS3)
    {
        if (crocMonkeyS3)
        {
            xpos = 3900;
            ypos = 3600;
            switch (monkeyCounter)
            {
            case 0:
                monkeyLine = "Hello Mr Croc!!";
                monkeyLine2 = " ";
                break;
            case 1:
                monkeyLine = "Im fine...thank you";
                monkeyLine2 = "Want more apples??";
                break;
            case 2:
                monkeyLine = "But how will i cross the river??";
                monkeyLine2 = " ";
                break;
            case 3:
                monkeyLine = "Well, i cannot disrespect";
                monkeyLine2 = "Mrs Croc's hospitality..";
                break;
            case 4:
                monkeyLine = "All right, I will come";
                monkeyLine2 = " ";
                break;
            case 5:
                monkeyLine = "Lets go Mr Croc!!";
                monkeyLine2 = " ";
                line = "Press Space Bar to Continue";
                displayCloudS3 = false;
                moveMonkeyCroc = true;
                //xpos = 2500;
                //ypos = 1300;
                break;
            }
            crocodile.cloud(xpos, ypos, monkeyLine, monkeyLine2);
        }
        else
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "Hello Dear friend!!";
                maleLine2 = "How are you??";
                break;
            case 1:
                maleLine = "Actually I came here to";
                maleLine2 = "Invite you home for dinner";
                break;
            case 2:
                maleLine = "No worries...";
                maleLine2 = "You can cross the river on my back";
                break;
            case 3:
                maleLine = "Please do agree my friend";
                maleLine2 = " ";
                break;
            case 4:
                maleLine = "Great! Hop On";
                maleLine2 = " ";
                monkeyDown = true;
                break;
            }
            crocodile.cloud(3000, 1000, maleLine, maleLine2);
        }
    }
    drawtext(1300, 3800, line,true,false);
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void birds(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(180,180,10);
    glBegin(GL_TRIANGLES);

    // Draw bird's body
    glColor3f(0.2f, 0.4f, 0.6f); // Set color for body
    glVertex2f(-0.2f, 0.0f);     // Left vertex of body
    glVertex2f(0.0f, 0.2f);      // Top vertex of body
    glVertex2f(0.2f, 0.0f);      // Right vertex of body

    // Draw bird's head
    glColor3f(0.8f, 0.2f, 0.2f); // Set color for head
    glVertex2f(0.0f, 0.2f);      // Top vertex of head
    glVertex2f(0.2f, 0.0f);      // Right vertex of head
    glVertex2f(0.4f, 0.1f);      // Right vertex of beak

    glEnd();

    glBegin(GL_LINES);

    // Draw bird's legs
    glColor3f(0.0f, 0.0f, 0.0f); // Set color for legs
    glVertex2f(0.1f, -0.1f);     // Left leg
    glVertex2f(0.1f, -0.3f);

    glVertex2f(0.3f, -0.1f);     // Right leg
    glVertex2f(0.3f, -0.3f);

    glEnd();

    glPopMatrix();
}

void displayScene4()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    sky1();
    birds(100,4200);
    birds(200,4200);
    birds(1000,4200);
    birds(1100,4300);
    birds(2300,4000);
    birds(1500,4100);
    birds(2500,4200);
    birds(2800,4300);
    birds(3500,4200);
    birds(3800,4300);
    birds(3000,4000);
    birds(4500,4100);
    river3();
    Crocodile crocodile;
    Monkey monkey;
    crocodile.draw(cXpos, 1000, 270);
    monkey.drawMonkey(mxpos, 300, 0.6);
    if (displayCloudS4)
    {
        if (crocMonkeyS4)
        {
            switch (monkeyCounter)
            {
            case 0:
                monkeyLine = "Mr Croc how far is your home";
                monkeyLine2 = " ";

                break;
            case 1:
                monkeyLine = "Okay..";
                monkeyLine2 = " ";
                break;
            case 2:
                monkeyLine = "Tell me the truth Mr.Croc";
                monkeyLine2 = "What are your intentions ";
                break;
            case 3:
                monkeyLine = "But Mr.Croc";
                monkeyLine2 = "I left my heart at home";
                break;
            case 4:
                monkeyLine = "Okay!!";
                monkeyLine2 = "";
                line = "";
                dialogsDone = true;
                displayCloudS4 = false;
                break;
            }
            crocodile.cloud(b1xpos, 1600, monkeyLine, monkeyLine2);
        }
        else
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "Dont worry dear friend....";
                maleLine2 = "Its just a few minutes from here";
                break;
            case 1:
                crocMonkeyS4 = true;
                maleCounter = 3;
                glutPostRedisplay();
                break;
            case 3:
                maleLine = "To tell the truth";
                maleLine2 = "My wife wants to eat your heart.";
                break;
            case 4:
                maleLine = "oh NOOO!!";
                maleLine2 = "Let's go back to your home ";
                break;
            }
            crocodile.cloud(b2xpos, 1000, maleLine, maleLine2);
        }
    }
    drawtext(1700, 4000, line,true,false);
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void displayScene5()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    treetop();
    treeTrunk(5);
    rocks(0,1500);
    rocks(2900,1500);
    sky1();
    grassGround(3);
    river3();
    Monkey monkey;
    monkey.drawMonkey(mxpos, mypos, 0.5);
    Crocodile crocodile;
    crocodile.draw(cXpos, 575, 280);
    Apple apple;
    if (displayCloudS5)
    {
        if (crocMonkeyS5)
        {
            switch (monkeyCounter)
            {
            case 0:
                monkeyLine = "You dumb creature!!";
                monkeyLine2 = " ";
                line = "Click to continue";
                break;
            case 1:
                monkeyLine = "How can a creature";
                monkeyLine2 = "Live without its heart??";
                break;
            case 2:
                monkeyLine = "You have lost ";
                monkeyLine2 = "My trust you stupid creature";
                break;
            case 3:
                monkeyLine = "Get away from my sight";
                monkeyLine2 = "you ungrateful creature";
                line = "Press Space Bar to Continue";
                displayCloudS5 = false;
                break;
            }
            crocodile.cloud(3800, 3500, monkeyLine, monkeyLine2);
        }
        else
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "You tricked me!!";
                maleLine2 = " ";
                break;
            case 1:
                maleLine = "What shall I tell";
                maleLine2 = "my wife now??";
                break;
            case 2:
                maleLine = "You proved too clever";
                maleLine2 = "for my cunning";
                break;
            }
            crocodile.cloud(2300, 1000, maleLine, maleLine2);
        }
    }
    drawtext(1300, 3800, line,true,false);
    if(displayMoralS5==true)
    {
        elipse.setColor(0,0.5,0.5);
        elipse.draw(2500,2500,2000,1000,-10,false,0,360);
        drawtext(1300,2500,"Friendship is beautiful.Treasure it....dont misuse it",false,true);
        glutTimerFunc(5000,timer,0);
        glutDisplayFunc(displayMoral);

    }
    glDisable(GL_TEXTURE_2D);
    apple.draw(3600, 2800, 1);
    apple.draw(3600, 3900, 1);
    apple.draw(3400, 2800, 1);
    apple.draw(3400, 3800, 1);
    apple.draw(3000, 3800, 1);
    apple.draw(2600, 3100, 1);
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void moveCroc()
{
    if (cXpos <= 5000)
    {
        cXpos += 30;
       glutPostRedisplay();
    }
    else
    {
        glutIdleFunc(NULL);
        dialogsDone = false;
        cXpos = 0;
        monkeyCounter = 0;
        maleCounter = 0;
        if (scene == 1)
        {
            scene++;
            line = "Click to continue";
            glutDisplayFunc(displayScene2);
            glutPostRedisplay();
        }
        else
        {
            scene++;
            mxpos=6000;
            cXpos = 6000;
            displayMoralS5 = true;
            line = " ";
            glutPostRedisplay();

        }

        glutIdleFunc(idle2);
    }
}

void moveCrocScene2()
{
    if (cXpos <= 5000)
    {

        cXpos += 30;
        glutPostRedisplay();
    }
    else
    {
        glutIdleFunc(NULL);
        scene += 1;
        maleCounter = 0;
        femaleCounter = 0;
        monkeyCounter = 0;
        line = "Click to continue";
        glutDisplayFunc(displayScene3);
        cXpos = 915;
        glutPostRedisplay();
    }
}

void moveCrocMonkey()
{
    if (cXpos <= 5000 && mxpos <= 5000)
    {

        cXpos += 30;
        mxpos += 30;
        glutPostRedisplay();
    }
    else
    {

        glutIdleFunc(NULL);
        scene += 1;
        maleCounter = 0;
        femaleCounter = 0;
        monkeyCounter = 0;
        dialogsDone = false;
        line = "Click to continue";
        glutDisplayFunc(displayScene4);
        glutTimerFunc(50, idle4, 0);
        cXpos = 0;
        mxpos = 1200;
        b1xpos = 1800;
        b2xpos = 2100;
        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q')
        exit(0);
    if (scene == 0)
    {
        if (key == SPACEBAR)
        {
            scene += 1;
            line = "Click to continue";
            glutDisplayFunc(displayScene1);
            glutPostRedisplay();
        }
    }
    else if (scene == 1)
    {
        if (key == 'd' | key == 'D')
        {
            glutIdleFunc(idle);
        }
        if (appleDown)
        {
            if (key == SPACEBAR)
            {
                displayCloudS1 = false;
                monkeyCounter = 0;
                maleCounter = 0;
                xpos = 6000;
                glutIdleFunc(moveCroc);
                glutPostRedisplay();
            }
        }
    }
    else if (scene == 2)
    {
        if (appleMove == false)
            if (key == SPACEBAR)
            {
                displayCloudS2 = false;
                glutIdleFunc(moveCrocScene2);
                glutPostRedisplay();
            }
    }
    else if (scene == 3)
    {

        if (moveMonkeyCroc)
        {
            if (key == SPACEBAR)
            {
                glutIdleFunc(idle3);
                glutPostRedisplay();
                //glutIdleFunc(moveCrocMonkey);
            }
        }
    }
    else if (scene == 5)
    {
        if (key == SPACEBAR)
        {
            glutIdleFunc(moveCroc);
        }
    }
    else if (scene == 6)
    {
        if (key == 27)
            exit(0);
    }
}
void wait(int value)
{
    ypos = 2900;
    line = "Click to continue";
    glutPostRedisplay();
}

void idle()
{
    if (appleDown)
    {
        if (ypos >= 300)
        {
            ypos -= 30;
            glutPostRedisplay();
        }
        else
        {
            appleDown = true;
            glutIdleFunc(NULL);
            glutTimerFunc(1000, wait, 0);
        }
    }
}
void disappearApple(int value)
{
    axpos = 6000;
    glutPostRedisplay();
}
void idle2()
{

    if (appleMove)
    {
        if (axpos <= 2300)
        {

            axpos += 30;
            glutPostRedisplay();
        }
        else
        {
            appleMove = false;
            glutTimerFunc(1000, disappearApple, 0);
            glutIdleFunc(NULL);
        }
    }
}

void idle3()
{
    if (monkeyDown)
    {
        if (mypos >= 200)
        {
            mypos -= 60;
            mxpos -= 30;
            glutPostRedisplay();
        }
        else
        {

            monkeyDown = false;
            glutPostRedisplay();
            glutIdleFunc(moveCrocMonkey);
        }
    }
}

void idle4(int value)
{
    if (mxpos <= 6000 && cXpos <= 6000)
    {
        mxpos += 10;
        cXpos += 10;
        b1xpos += 10;
        b2xpos += 10;
        glutPostRedisplay();
        glutTimerFunc(50, idle4, 0);
    }
    else
    {
        monkeyCounter = 0;
        maleCounter = 0;
        femaleCounter = 0;
        cXpos = 0;
        mxpos = 1200;
        scene += 1;
        line = "Click to move monkey";
        glutDisplayFunc(displayScene5);
        glutPostRedisplay();
    }
}

void idle5()
{
    if (!monkeyDown)
    {
        if (mypos <= 2600 && mxpos <= 3400)
        {
            mypos += 60;
            mxpos += 60;
            glutPostRedisplay();
        }
        else
        {

            monkeyDown = true;
            displayCloudS5 = true;
            glutPostRedisplay();
            glutIdleFunc(NULL);
        }
    }
}

void mouse(int button, int state, int x, int y)
{

    if (scene == 1)
    {
        if (!dialogsDone)
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                if (crocMonkey)
                {
                    crocMonkey = false;
                    monkeyCounter++;
                }
                else
                {
                    crocMonkey = true;
                    maleCounter++;
                }

                glutPostRedisplay();
            }
        }
    }

    else if (scene == 2)
    {
        if (!dialogsDone)
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                if (crocMaleFemale)
                {
                    crocMaleFemale = false;
                    maleCounter++;
                }
                else
                {
                    crocMaleFemale = true;
                    femaleCounter++;
                }

                glutPostRedisplay();
            }
        }
    }

    else if (scene == 3)
    {

        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {

            //glutIdleFunc(idle3);
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (crocMonkeyS3)
            {
                crocMonkeyS3 = false;
                monkeyCounter++;
            }
            else
            {
                crocMonkeyS3 = true;
                maleCounter++;
            }
            glutPostRedisplay();
        }
    }
    else if (scene == 4)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (crocMonkeyS4)
            {
                crocMonkeyS4 = false;
                monkeyCounter++;
            }
            else
            {
                crocMonkeyS4 = true;
                maleCounter++;
            }
            glutPostRedisplay();
        }
    }
    else if (scene == 5)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (monkeyDown)
            {
                if (crocMonkeyS5)
                {
                    crocMonkeyS5 = false;
                    monkeyCounter++;
                }
                else
                {
                    crocMonkeyS5 = true;
                    maleCounter++;
                }
                glutPostRedisplay();
            }
            else
                glutIdleFunc(idle5);
        }
    }
}

void timer(int value)
{
    glutPostRedisplay();
}
void processMenu(int option)
{
    switch (option)
    {
    case 1:
        scene = 0;
        appleMove = false;
        appleDown = false;
        displayCloudS1 = true;
        displayCloudS2 = true;
        crocMaleFemale = true;
        crocMonkey = true;
        crocMonkeyS3 = true;
        monkeyDown = false;
        moveMonkeyCroc = false;
        displayCloudS3 = true;
        displayCloudS4 = true;
        displayCloudS5 = false;
        dialogsDone = false;
        crocMonkeyS4 = true;
        crocMonkeyS5 = true;
        maleLine2 = " ";
        femaleLine2 = " ";
        maleCounter = 0;
        femaleCounter = 0;
        monkeyCounter = 0;
        xpos = 2870;
        ypos = 2900;
        cXpos = 915;
        axpos = 1500;
        mypos = 2600;
        mxpos = 3400;
        glutDisplayFunc(displayIntro);
        glutPostRedisplay();
        break;
    case 2:
        exit(0);
        break;
    }
}
void menu(void)
{

    int menu;

    // create the menu and
    // tell glut that "processMenuEvents" will
    // handle the events
    menu = glutCreateMenu(processMenu);

    //add entries to our menu
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Exit", 2);

    // attach the menu to the right button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("A Clever Monkey");
    // glutFullScreen();
    glutDisplayFunc(displayIntro);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(500, timer, 0);
    glEnable(GL_DEPTH_TEST);
    init();
    menu();
    glutMainLoop();
}
