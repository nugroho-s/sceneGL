#include <GL/glut.h>
#include <iostream>
#include <cmath>

#define light_blue 76, 159, 247
#define dark_blue 41, 109, 219
#define red 255,0,0
#define yellow 255,255,0
#define green 0,255,0

#define ymaks 800
#define xmaks 1200

using namespace std;

//draw triangles
/* mode
t: GL_TRIANGLES
s: GL_TRIANGLE_STRIP
f: GL_TRIANGLE_FAN
*/
void drawTriangles(int* arr, int len, char mode){
	if (mode == 't')
		glBegin(GL_TRIANGLES);
	else if (mode == 's')
		glBegin(GL_TRIANGLE_STRIP);
	else if (mode == 'f')
		glBegin(GL_TRIANGLE_FAN);
	int j = 0;
	for (int i = 0; i<len; i++){
		//cout << arr[j] << "," << arr[j+1]<< endl;
		glVertex2f(arr[j], ymaks - arr[j + 1]);
		j += 2;
	}
	glEnd();
};

// returns ordinat for a given absis
int rainbowY(int x){
	return (int)(-0.0003*(pow(x,2))+0.36*x+600);
};

int rainbowX(int y){
	return sqrt(y);
};

void drawRainbow(int range){
	glBegin(GL_LINES);
	int y;
	for (int x=0;x<xmaks;x++){
		y = rainbowY(x);
		// red to yellow
		glColor3ub(255,0,0);
		glVertex2f(x,y);
		glColor3ub(255,255,0);
		glVertex2f(x,y-range);
		// yellow to green
		glVertex2f(x,y-range);
		glColor3ub(0,255,0);
		glVertex2f(x,y-(2*range));
		// green to blue
		glVertex2f(x,y-(2*range));
		glColor3ub(0,0,255);
		glVertex2f(x,y-(3*range));
		// blue to purple
		glVertex2f(x,y-(3*range));
		glColor3ub(128,0,128);
		glVertex2f(x,y-(4*range));
	}
	// int x;
	// for (int y=0;y<ymaks;y++){
	// 	x = rainbowX(y);
	// 	glVertex2f(x+(xmaks/2),y);
	// 	glVertex2f((xmaks/2)-x,y);
	// }
	glEnd();
};

void drawBackground(){
    int jarak = 50;
    glBegin(GL_TRIANGLES);
	int j=0;
    for (int i=0;i<xmaks;i+=(jarak)){
		if (j%2){
			glColor3ub(light_blue);
			glVertex2f(i,800);
			glVertex2f(xmaks/2,ymaks/2);
			glColor3ub(dark_blue);
	        glVertex2f(i+jarak,800);
		} else {
			glColor3ub(dark_blue);
			glVertex2f(i,800);
			glColor3ub(light_blue);
	        glVertex2f(i+jarak,800);
	        glVertex2f(xmaks/2,ymaks/2);
		}
		j++;
    }
    for (int i=800;i>0;i-=(jarak)){
		if (j%2){
			glColor3ub(light_blue);
			glVertex2f(1200,i);
			glVertex2f(xmaks/2,ymaks/2);
			glColor3ub(dark_blue);
	        glVertex2f(1200,i-jarak);
		} else{
			glColor3ub(dark_blue);
			glVertex2f(1200,i);
			glColor3ub(light_blue);
	        glVertex2f(1200,i-jarak);
	        glVertex2f(xmaks/2,ymaks/2);
		}
		j++;
    }
    for (int i=xmaks;i>0;i-=(jarak)){
		if (j%2){
			glColor3ub(light_blue);
			glVertex2f(i,0);
			glVertex2f(xmaks/2,ymaks/2);
			glColor3ub(dark_blue);
	        glVertex2f(i-jarak,0);
		} else {
			glColor3ub(dark_blue);
			glVertex2f(i,0);
			glColor3ub(light_blue);
	        glVertex2f(i-jarak,0);
	        glVertex2f(xmaks/2,ymaks/2);
		}
		j++;
    }
    for (int i=0;i<ymaks;i+=(jarak)){
		if (j%2){
			glColor3ub(light_blue);
			glVertex2f(0,i);
			glVertex2f(xmaks/2,ymaks/2);
			glColor3ub(dark_blue);
	        glVertex2f(0,i+jarak);
		} else {
			glColor3ub(dark_blue);
			glVertex2f(0,i);
			glColor3ub(light_blue);
	        glVertex2f(0,i+jarak);
	        glVertex2f(xmaks/2,ymaks/2);
		}
		j++;
    }
    glEnd();
}

// Menggambarkan keseluruhan komponen
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(76, 159, 247);
	drawBackground();
	drawRainbow(15);
	glFlush();
}

//Inisialisasi OpenGL
void Initialize() {
	glClearColor(0.2578125, 0.32421875, 0.953125, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1200, 0, 800, -2, 2);
	glEnable(GL_COLOR_MATERIAL);
}



int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("sceneGL");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
