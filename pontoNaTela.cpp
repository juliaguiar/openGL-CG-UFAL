#include <gl/glut.h>

int xf, yf;
GLfloat win;
GLint view_w, view_h;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     glClear(GL_COLOR_BUFFER_BIT);
     // Desenha um retângulo preenchido com a cor corrente
     glBegin(GL_POINTS);
	 	glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2i(xf, yf);
	 glEnd();
     glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    xf=100;
    yf=100;
    win=250.0f;
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{ 
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;                   

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}

           
// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
         if (state == GLUT_DOWN) {
                  // Troca o tamanho do retângulo, que vai do centro da 
                  // janela até a posição onde o usuário clicou com o mouse
                  xf = ( (2 * win * x) / view_w) - win;
                  yf = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
         }
    glutPostRedisplay();
}

                      
// Programa Principal 
int main(void)
{
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(350,300);
     glutInitWindowPosition(100,100);
     glutCreateWindow("Ponto na Tela");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutMouseFunc(GerenciaMouse);     
     Inicializa();
     glutMainLoop();
}
