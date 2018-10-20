//
//  main.m
//  Transformacoes1
//
//  Created by Marcelo Costa on 15/12/12.
//  Copyright (c) 2012 Universidade Federal de Alagoas - UFAL. All rights reserved.
//

//#import <Cocoa/Cocoa.h>
#include <windows.h>
#include <gl/glut.h> 

int ang = 0;

void init (void)
{
	
    /* selecionar cor de fundo (preto) */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    
    glMatrixMode (GL_PROJECTION); //Projecao 2D
    
    glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0); //Definindo os limites da Porta de Visao (ViewPort)
    
}

void display(void)
{
    /* Limpar todos os pixels  */
    glClear (GL_COLOR_BUFFER_BIT);
    
    glColor3f (1.0, 1.0, .0);
    glBegin(GL_POLYGON);
        glVertex3f (249.0f, 250.0f, -1.0f);
        glVertex3f (251.0f, 250.0f, -1.0f);
        glVertex3f (249.0f, 100.0f, -1.0f);
        glVertex3f (251.0f, 100.0f, -1.0f);
    glEnd();
    
    glPushMatrix();
    glTranslatef(250, 250, 0);
    glRotatef (ang, 0, 0, 1);
    
    /* Desenhar um polígono branco  */
    //glPushMatrix();
    glColor3f (1.0, 1.0, 1.0);
    //glRotatef (ang, 250.0f, 250.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        //glVertex2f (250.0f, 250.0f);
        glVertex2f (0.0f, 0.0f);
        //glVertex2f (230.0f, 200.0f);
        glVertex2f (-20.0f, -50.0f);
        //glVertex2f (270.0f, 200.0f);
        glVertex2f (20.0f, -50.0f);
    glEnd();
    //glPopMatrix();
    
    /* Desenhar um polígono vermelho */
    //glPushMatrix();
    glColor3f (1.0, 0.0, 0.0);
    //glRotatef (ang, 250.0f, 250.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        //glVertex2f (250.0f, 250.0f);
        glVertex2f (0.0f, 0.0f);
        //glVertex2f (300.0f, 230.0f);
        glVertex2f (50.0f, -20.0f);
        //glVertex2f (300.0f, 270.0f);
        glVertex2f (50.0f, 20.0f);
    glEnd();
    //glPopMatrix();
    
    /* Desenhar um polígono verde */
    //glPushMatrix();
    glColor3f (0.0, 1.0, 0.0);
    //glRotatef (ang, 250.0f, 250.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        //glVertex2f (250.0f, 250.0f);
        glVertex2f (0.0f, 0.0f);
        //glVertex2f (230.0f, 300.0f);
        glVertex2f (-20.0f, 50.0f);
        //glVertex2f (270.0f, 300.0f);
        glVertex2f (20.0f, 50.0f);
    glEnd();
    //glPopMatrix();
    
    /* Desenhar um polígono vermelho */
    //glPushMatrix();
    glColor3f (0.0, 0.0, 1.0);
    //glRotatef (ang, 250.0f, 250.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        //glVertex2f (250.0f, 250.0f);
        glVertex2f (0.0f, 0.0f);
        //glVertex2f (200.0f, 270.0f);
        glVertex2f (-50.0f, 20.0f);
        //glVertex2f (200.0f, 230.0f);
        glVertex2f (-50.0f, -20.0f);
    glEnd();
    
    glPopMatrix();
    
    
    /* Não esperar! */
    glFlush ();
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'A': 
            case 'a':// 
                     ang -= 20.0f;
                     break;
            case 'S':
            case 's':// 
                     ang += 20.0f;
                     break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    
	glutInit(&argc, argv);
    
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 400);
	glutInitWindowPosition (200, 200);
	glutCreateWindow ("Flor de Abril");
    
	init ();
    
	glutDisplayFunc(display);
	
	glutKeyboardFunc(GerenciaTeclado);
    
	glutMainLoop();
    
	/* C ANSI requer que main retorne um inteiro */
	return 0;
    
}
