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
    glPushMatrix();//�k�b��
        glTranslatef(0.375,0.25,0);//��Ӳ���k�W������
        glRotatef(0.055*-angle, 0, 0, 1);//�襤�����
        glTranslatef(0.25,0,0);//�����`���줤��
    hand();//�Ӫ������u
    glPushMatrix();
     glTranslatef(0.25,0,0);
     glRotatef(0.055*angle, 0, 0, 1);
     glTranslatef(0.25,0,0);
     hand();//�U���u���b
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();//���b��
     glTranslatef(-0.375,0.25,0);//��Ӳ��쥪�W������
     glRotatef(0.055*-angle, 0, 0, 1);//�襤�����
     glTranslatef(-0.25,0,0);//�����`���줤��
    hand();//�Ӫ����Ŧ���u
    glPushMatrix();
     glTranslatef(-0.25,0,0);//�����ԹL�h
     glRotatef(0.055*-angle, 0, 0, 1);
     glTranslatef(-0.25,0,0);
     hand();//�U���u���b
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.375,-0.375,-0.375);//��Ӳ��쥪�W������
        glTranslatef(-0.25,0,0);//�����`���줤��
        hand();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.375,-0.375,0.375);//��Ӳ��쥪�W������
        glTranslatef(+0.25,0,0);//�����`���줤��
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
