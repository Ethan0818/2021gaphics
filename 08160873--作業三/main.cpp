#include <GL/glut.h>
float angle=0;
void hand(){
    glPushMatrix();
        glScalef(0.5,0.1,0.2);
        glColor3ub(185,67,194);
        glutSolidCube(1);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3ub(68,68,183); glutSolidCube(0.75);
    glPushMatrix();//右半邊
        glTranslatef(0.375,0.25,0);//整個移到右上角掛著
        glRotatef(0.055*-angle, 0, 0, 1);//對中心轉動
        glTranslatef(0.25,0,0);//把關節移到中心
    hand();//細長的手臂
    glPushMatrix();
     glTranslatef(0.25,0,0);
     glRotatef(0.055*angle, 0, 0, 1);
     glTranslatef(0.25,0,0);
     hand();//下手臂跟手軸
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();//左半邊
     glTranslatef(-0.375,0.25,0);//整個移到左上角掛著
     glRotatef(0.055*-angle, 0, 0, 1);//對中心轉動
     glTranslatef(-0.25,0,0);//把關節移到中心
    hand();//細長的藍色手臂
    glPushMatrix();
     glTranslatef(-0.25,0,0);//往左拉過去
     glRotatef(0.055*-angle, 0, 0, 1);
     glTranslatef(-0.25,0,0);
     hand();//下手臂跟手軸
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.375,-0.375,-0.375);//整個移到左上角掛著
        glTranslatef(-0.25,0,0);//把關節移到中心
        hand();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.375,-0.375,0.375);//整個移到左上角掛著
        glTranslatef(+0.25,0,0);//把關節移到中心
        hand();
    glPopMatrix();


    glutSwapBuffers();
    angle++;
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("08160873");

    glutDisplayFunc( display);
    glutIdleFunc(display);
    glutMainLoop();
}
