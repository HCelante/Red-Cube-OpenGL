#include <stdio.h>
#include <GL/glut.h>

char comando = 't';
double translacaoX = 0, translacaoY = 0, rotacaoX = 10, rotacaoY = 0, key;
// funcao de inicializacao
int init()
{
   glClearColor(0, 0, 0, 0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentitY();
   gluOrtho2D(0, 100, 0, 100);
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentitY();
   glTranslatef(translacaoX, translacaoY, 0); // translada para a posicao alterada
   glTranslatef(5, 5, 0);
   glRotatef(rotacaoY, 0.0, 0.0, 1);
   glTranslatef(-5, -5, 0);
   glBegin(GL_POLYGON); // desenha o quadrado
   glColor3f(1, 0, 0);
   glVertex2i(0, 0);
   glColor3f(1, 0, 0);
   glVertex2i(10, 0);
   glColor3f(1, 0, 0);
   glVertex2i(10, 10);
   glColor3f(1, 0, 0);
   glVertex2i(0, 10);
   glEnd();
   glFlush();
}
void teclasChar(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 'R':
   case 'r':
      comando = 'r';
      break;
   case 'T':
   case 't':
      comando = 't';
      break;
   }
   glutPostRedisplay();
}

void teclasEspeciais(int key)
{
   if (comando == 't')
   {
      if (key == GLUT_KEY_DOWN)
      {
         translacaoY -= 1;
      }
      else if (key == GLUT_KEY_LEFT)
      {
         translacaoX -= 1;
      }
      else if (key == GLUT_KEY_UP)
      {
         translacaoY += 1;
      }
      else if (key == GLUT_KEY_RIGHT)
      {
         translacaoX += 1;
      }

   }
   else if (comando == 'r')
   {
      if (key == GLUT_KEY_DOWN)
      {
         rotacaoY -= rotacaoX;
      }
      else if (key == GLUT_KEY_RIGHT)
      {
         rotacaoY -= rotacaoX;
      }
      else if (key == GLUT_KEY_LEFT)
      {
         rotacaoY += rotacaoX;
      }
      else if (key == GLUT_KEY_UP)
      {
         rotacaoY += rotacaoX;
      }


   }
   glutPostRedisplay();
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

   glutInitWindowSize(500, 500);
   //glutInitWindowPosition(600, 0);

   glutCreateWindow("Atividade 1 \n- Por Higor Celante");
   glutDisplayFunc(display);
   init();
   glutteclasChar(teclasChar);
   glutSpecialFunc(teclasEspeciais);
   glutMainLoop();
}
