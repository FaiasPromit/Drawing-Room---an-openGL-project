#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

double Txval=0,Tyval=0,Tzval=0, arodure=60;
double eyex = 5;
double eyey = 5;
double eyez = 5;
double centerx = 5;
double centery = 0;
double centerz = 0;
double upx = 0;
double upy = 1;
double upz = 0;
double myval = 0;
double windowHeight=900, windowWidth=1800;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;
double far_id =200.0;
double near_id = 30.0;

GLfloat eyeX = 16;
GLfloat eyeY = 5;
GLfloat eyeZ = 20;

GLfloat lookX = 16;
GLfloat lookY = 5;
GLfloat lookZ = 0;

GLfloat upX = 0;
GLfloat upY = 1;
GLfloat upZ = 0;

GLfloat scaleX = 1;
GLfloat scaleY = 1;
GLfloat scaleZ = 1;



GLfloat cube_coordinate[8][3] =
{
    {0.0,0.0,0.0},
    {0.0,2.0,0.0},
    {2.0,2.0,0.0},
    {2.0,0.0,0.0},

    {0.0,0.0,-2.0},
    {0.0,2.0,-2.0},
    {2.0,2.0,-2.0},
    {2.0,0.0,-2.0}


};
static GLubyte cude_indices[6][4] =
{
    {0,3,2,1},
    {3,7,6,2},
    {7,4,5,6},
    {4,0,1,5},

    {1,2,6,5},
    {7,4,0,3}

};


void draw_house_cube(GLfloat c1,GLfloat c2,GLfloat c3 )
{
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        glColor3f(c1, c2, c3);
        glVertex3fv(&cube_coordinate[cude_indices[i][0]][0]);
        glVertex3fv(&cube_coordinate[cude_indices[i][1]][0]);
        glVertex3fv(&cube_coordinate[cude_indices[i][2]][0]);
        glVertex3fv(&cube_coordinate[cude_indices[i][3]][0]);
    }
    glEnd();
}

void draw_room()
{
    glPushMatrix();
    glScalef(20,0.01,8);
    draw_house_cube(0.3, 0.3, 0.3);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.01,6,8);
    draw_house_cube(0, 0.6, 0.9);
    glPopMatrix();
//
    glPushMatrix();
    glTranslatef(0,0,-16);
    glScalef(20,6,0.01);
    draw_house_cube(0, 0.6, 0.6);
    glPopMatrix();
//
    glPushMatrix();
    glTranslatef(40,0,0);
    glScalef(0.01,6,8);
    draw_house_cube(0, 0.6, 0.9);
    glPopMatrix();

}

void draw_sofa()
{
    glPushMatrix();
    glScalef(0.5,1,2.2);
    draw_house_cube(1, .8, .79);
    glPopMatrix();

    glPushMatrix();
    glScalef(1,0.8,0.4);
    glTranslatef(0,0,1);
    draw_house_cube(1, 0.6, 0.6);
    glPopMatrix();

    glPushMatrix();
    glScalef(1,0.8,0.4);
    glTranslatef(0,0,-11);
    draw_house_cube(1, 0.6, 0.6);
    glPopMatrix();


    glPushMatrix();
    glScalef(1,0.5,2.2);
    glTranslatef(1,0,0);
    draw_house_cube(1, 0.6, 0.3);
    glPopMatrix();
}

void draw_sofa_table()
{
    // table
    glPushMatrix();
        glPushMatrix();
        glTranslatef(0,1,0);
        glScalef(1,0.3,1);
        draw_house_cube(0, 0, 0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.5,0,-2);
        glRotatef(-90,0,1,0);
        glScalef(1,0.5,0.2);
        draw_house_cube(0.1, 0.2, 0.1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0,-2);
        glRotatef(-90,0,1,0);
        glScalef(1,0.5,0.2);
        draw_house_cube(0.1, 0.2, 0.1);
    glPopMatrix();
}

void draw_all_sofa_set()
{
    glPushMatrix();
        glTranslatef(3,0,-2);
        draw_sofa();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(7,0,-10);
        glPushMatrix();
            glRotatef(-90,0,1,0);
            glScalef(1,1,0.6);
            draw_sofa();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(14,0,-7);
        glPushMatrix();
            glRotatef(-180,0,1,0);

            draw_sofa();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(10,0,0);
        glPushMatrix();
            glRotatef(-270,0,1,0);
            glScalef(1,1,0.6);
            draw_sofa();
        glPopMatrix();
    glPopMatrix();

}

void draw_almira()
{
    glPushMatrix();
        //glTranslatef(3,0,-2);
        glScalef(0.5,2,2);
        draw_house_cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0,-2);
        glScalef(0.4,2,0.05);
        draw_house_cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1,2,-0.9);
        glScalef(0.1,0.5,0.1);
        draw_house_cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1,2,-2.2);
        glScalef(0.1,0.5,0.1);
        draw_house_cube(0,0,0);
    glPopMatrix();



}

void draw_ac()
{
    glPushMatrix();
        //glTranslatef(3,7,2);
        glScalef(4.5,.5,1);
        draw_house_cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,.3,0.2);
        glScalef(4.5,.02,.4);
        draw_house_cube(0,0,0);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(0,.4,0.2);
        glScalef(4.5,.02,.4);
        draw_house_cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,.1,0.2);
        glScalef(4.5,.02,.4);
        draw_house_cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(8,.5,0.3);
        glScalef(.2,.2,.2);
        draw_house_cube(0,0,0);
    glPopMatrix();

}

void draw_circle()
{
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    for(int i=0; i<1000; ++i)
    {
        glVertex2f(0,0);
        glVertex2f(5*cos(2*3.14159*i/1000.0),5*sin(2*3.14159*i/1000.0));
    }
    glEnd();

    glTranslatef(0,0,.05);
    glBegin(GL_POINTS);
    glColor3f(0,1,0);
    for(int i=0; i<1000; ++i)
    {
        //glVertex2f(0,0);
        glVertex2f(4.5*cos(2*3.14159*i/1000.0),4.5*sin(2*3.14159*i/1000.0));
        glVertex2f(4.49*cos(2*3.14159*i/1000.0),4.49*sin(2*3.14159*i/1000.0));
        glVertex2f(4.48*cos(2*3.14159*i/1000.0),4.48*sin(2*3.14159*i/1000.0));
    }
    glEnd();

//    glBegin(GL_LINES);
//    glColor3f(0,0,1);
//    for(int i=0; i<1000; ++i)
//    {
//        glVertex2f(0,0);
//        glVertex2f(5*cos(2*3.14159*i/1000.0),5*sin(2*3.14159*i/1000.0));
//    }
//    glEnd();

}

void draw_stairs()
{
    glScalef(3.5,1.4,1);
    glPushMatrix();
//        glTranslatef(8,.5,0.3);
        glScalef(.3,.5,2);
        draw_house_cube(.52,.52,0.52);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(.3,0,0);
        glScalef(.3,.8,2);
        draw_house_cube(.54,.54,0.54);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(.6,0,0);
        glScalef(.3,1.1,2);
        draw_house_cube(.56,.56,0.56);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(.9,0,0);
        glScalef(.3,1.4,2);
        draw_house_cube(.58,.58,0.58);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.2,0,0);
        glScalef(.3,1.7,2);
        draw_house_cube(.6,.6,0.6);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.5,0,0);
        glScalef(.3,2,2);
        draw_house_cube(.62,.62,0.62);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.9,3.3,-1.5);
        glScalef(.1,1.3,.9);
        draw_house_cube(.488,.294,0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.8,5,-1.5);
        glScalef(.1,.1,.1);
        draw_house_cube(.2,.2,.2);
    glPopMatrix();


}

void draw_tv()
{
    glScalef(1.7,.8,1);
    glPushMatrix();
//        dglTranslatef(8,.5,0.3);
    glScalef(3,2,.2);
    draw_house_cube(.1,.1,.1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.5,0.5,0.01);
    glScalef(2.5,1.6,.01);
    draw_house_cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(.6,.6,0.02);
    glScalef(2.3,1.5,.01);
    draw_house_cube(.1,.1,.1);
    glPopMatrix();

}

void draw_every()
{
    draw_room();
    glPushMatrix();
    glTranslatef(0,0,-3);
    draw_all_sofa_set();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.5,0,-6.5);
    draw_sofa_table();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-5);
    draw_almira();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(23,8,-15);
    draw_ac();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(32.6,0,-10);
    draw_stairs();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(24.6,0.1,-7);
    glRotatef(-90,1,0,0);
    draw_circle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,5,-14.9);
//    glRotatef(-90,1,0,0);
    draw_tv();
    glPopMatrix();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-15,15, -15, 15, near_id, far_id);

    //gluPerspective(60,1,5,100);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, upX,upY,upZ);

    glViewport(0, 0, windowHeight, windowWidth);
    //glRotatef(30, 0, 0, 1 );
    glScalef(scaleX,scaleY,scaleZ);
    glRotatef( alpha,axis_x, axis_y, 0.0 );
    glRotatef( theta, axis_x, axis_y, 0.0 );



    draw_every();


    glFlush();
    glutSwapBuffers();
}

double aY = 90, aP = 90, aR = 90;

void pitch() // x axis , y er about ,  o p
{
    lookX = 400.0*(cos(aP*3.1416/180.0));
}

void yaw() // y axis, x axis about y u
{
    lookY = 400.0*(cos(aY*3.1416/180.0));
//    printf("%lf\n" , aY);
}


void roll() // z axis h j
{
    upX = 10*(cos(aR*3.1416/180.0));
    upY = 10*(sin(aR*3.1416/180.0));
    //printf("%lf %faR\n" , aR,cos(aR*3.1416/180.0));
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'R':
    case 'r':
        bRotate = !bRotate;
        axis_x=0.0;
        axis_y=1.0;
        break;
    case 'T':
    case 't':
        bRotate = !bRotate;
        axis_x=1.0;
        axis_y=0.0;
        break;

    case 'o':
        if(aP>=180)
            break;
        aP+=1;
        pitch();
        glutPostRedisplay();
        break;
    case 'p':
        aP-=1;
        if(aP<=0)
            break;
        pitch();
        glutPostRedisplay();
        break;

    case 'y':

          // aY -= 360.0*floor(aY/360.0);
        if(aY >= 180.0 )break;
        aY+=1;

        yaw();
        glutPostRedisplay();
        break;
    case 'u':
        if( aY <=0)break;
        aY-=1;

           // aY += 360.0*floor(aY/360.0);
        yaw();
        glutPostRedisplay();
        break;


     case 'h':

          // aY -= 360.0*floor(aY/360.0);
        if(aR >= 270.0 )
            break;
        aR+=1;

        roll();
        glutPostRedisplay();
        break;
    case 'j':
        if( aR <= -90.0)
            break;
        aR-=1;

           // aY += 360.0*floor(aY/360.0);
        roll();
        glutPostRedisplay();
        break;




    case 'f':
        eyeZ++;
        lookZ++;
        break;
    case 'g':
        eyeZ--;
        lookZ--;
        break;
    case 'w':
        eyeY++;
        lookY++;
        break;
    case 's':
        eyeY--;
        lookY--;
        break;

    case 'd':
        eyeX++;
        lookX++;
        break;
    case 'a':
        eyeX--;
        lookX--;
        break;

    case 'z':
        scaleX+=0.3;
        scaleY+=0.3;
        scaleZ+=0.3;
        break;
    case 'x':
        scaleX-=0.3;
        scaleY-=0.3;
        scaleZ-=0.3;
        break;



    case 27:	// Escape key
        exit(1);

    }
}


void animate()
{
    if (bRotate == true)
    {
        theta += 0.2;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.2;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }
    glutPostRedisplay();

}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(500,500);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Traingle-Demo");
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}

