
#include <GL/glut.h>
#include <stdio.h>
// Função callback chamada para fazer o desenho
int tx = 0;
int ty = 0;
int tz = 0;
int scale = 0;
int rx = 0;
int ry = 0;
int rz = 0;
char action = 'n';
GLfloat spin = 0;
void quadrado(void){
    glBegin(GL_QUADS);
               glVertex2i(0,15);
               glVertex2i(0,0);
               // Especifica que a cor corrente é azul
               //glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(15,0);
               glVertex2i(15,15);               
     glEnd();
}
void Desenha(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
     //glMatrixMode(GL_MODELVIEW);
    glPushMatrix(); 
     //glLoadIdentity();

     glColor3f(1.0f, 0.0f, 0.0f);


    quadrado();

    glPopMatrix();
     // Desenha um quadrado preenchido com a cor corrente
     
     // Executa os comandos OpenGL
     glFlush();
    glutSwapBuffers();

}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 100.0f, 0.0f, 100.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 100.0f*w/h, 0.0f, 100.0f);
}

// Programa Principal 
void direcional(int key, int x, int y){
     switch (key)
  {
    case  GLUT_KEY_UP:
        printf("up");
       if (action == 'r')
          ry+= 1;
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          glRotatef(spin,rx,ry,rz);

       if (action == 't')
          ty+= 1;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           glTranslatef(tx,ty,tz);

    case  GLUT_KEY_DOWN:
       if (action == 'r')
          ry-= 1;
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          glRotatef(spin,rx,ry,rz);
       if (action == 't')
          ty-= 1;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           glTranslatef(tx,ty,tz);
    case  GLUT_KEY_LEFT:
       if (action == 'r')
          rx-= 1;
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          glRotatef(spin,rx,ry,rz);
       if (action == 't')
          tx-= 1;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           glTranslatef(tx,ty,tz);
    case  GLUT_KEY_RIGHT:
       if (action == 'r')
          rx+= 1;
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          glRotatef(spin,rx,ry,rz);
       if (action == 't')
          tx+= 1;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           glTranslatef(tx,ty,tz);
    }
    glutPostRedisplay();    
}
 
void Keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:             // ESCAPE key
	  exit (0);
	  break;

  case 'r':
      printf("rotate");
      action = 'r';
	  //rotate();
	  break;

  case 't':
      action = 't';
	  //translate();
	  break;

  case 'v':
      action = 'v';
	  //velocidade();
	  break;
  
  }
}



int main(int argc, char** argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Quadrado");

     
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutSpecialFunc(direcional);
     glutKeyboardFunc (Keyboard);
     
     
    Inicializa();
     glutMainLoop();
}
