
#include <GL/glut.h>
#include <stdio.h>
// Função callback chamada para fazer o desenho
void Desenha(char action)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é vermelha
     //         R     G     B
     glColor3f(1.0f, 0.0f, 0.0f);

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_QUADS);
               glVertex2i(0,15);
               glVertex2i(0,0);
               // Especifica que a cor corrente é azul
               //glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(15,0);
               glVertex2i(15,15);               
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
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

char action = "n"; 
void Keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:             // ESCAPE key
	  exit (0);
	  break;

  case 'r':
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
     Inicializa();
     glutKeyboardFunc (Keyboard);
     glutMainLoop();
}
