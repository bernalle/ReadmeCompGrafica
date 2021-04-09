// Aula Assíncrona 21/01 - Tutorial OpenGL Hands on 1

#include <GL/glew.h>
#include <GL/freeglut.h>

// glew.h deve vir antes do freeglut.h

//CallBack de desenho (display)
void desenhaMinhaCena(){
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(0.0, 0.0, 0.0);
    //glColor3f(1.0, 0.0, 0.0);
    //glColor3f(0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    //glColor3f(1.0, 1.0, 0.0);
    //glColor3f(1.0, 0.0, 1.0);
    //glColor3f(0.0, 1.0, 1.0);
    //glColor3f(0.6, 0.6, 0.6);
    //glColor3f(1.0, 1.0, 1.0);
    //Desenha um POLYGON por seus vértices
    glBegin(GL_POLYGON);
        //NOVIDADE: antes os valores eram -0.5, 0.5
        glVertex3f(20, 20, 0);
        glVertex3f(80, 20, 0);
        glVertex3f(80, 80, 0);
        glVertex3f(20, 80, 0);
    glEnd();
    glFlush();
}

/*
    NOVIDADE: uma função que vamos chamar dentro do "main"
    Inicia algumas variáveis de estado do OpenGl 
*/

void inicializa(){
    //define qual é a cor do fundo 
    glClearColor(1, 1, 1, 1); // Branco

    //desenho preenchido vs. contorno
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

// NOVIDADE: CallBack para o evento "reshape"
void redimensionada(int width, int height){
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// NOVIDADE: CallBack de "Keyboard"
void teclaPressionada(unsigned char key, int x, int y){
    //vê qual tecla foi pressionada
    switch (key){
        case 27:        // Tecla "ESC"
            exit(0);    // Sai da aplicação
            break;
        default:
            break;
    }
}

// Função Principal
int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitContextVersion(1,1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);

    glutCreateWindow("-- Hands On 1 --");

    //Rgistra CallBack para alguns eventos
    glutDisplayFunc(desenhaMinhaCena);
    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(teclaPressionada);

    /*
    configura valor incial de algumas váriaveis
    de estado do OpenGL 
    */

    inicializa();

    glutMainLoop();
    return 0;
}
