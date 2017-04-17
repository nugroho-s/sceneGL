#include "stdafx.h"
#include <GL/glut.h>
#include <iostream>
#include <math.h>


#define light_blue 76, 159, 247
#define dark_blue 41, 109, 219
#define red 255,0,0

#define ymaks 800
#define xmaks 1200
#define PI 3.14159265359;
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



void drawBackground(){
	int jarak = 50;
	glBegin(GL_TRIANGLES);
	int j = 0;
	for (int i = 0; i<xmaks; i += (jarak)){
		if (j % 2){
			glColor3ub(light_blue);
			glVertex2f(i, 800);
			glVertex2f(xmaks / 2, ymaks / 2);
			glColor3ub(dark_blue);
			glVertex2f(i + jarak, 800);
		}
		else {
			glColor3ub(dark_blue);
			glVertex2f(i, 800);
			glColor3ub(light_blue);
			glVertex2f(i + jarak, 800);
			glVertex2f(xmaks / 2, ymaks / 2);
		}
		j++;
	}
	for (int i = 800; i>0; i -= (jarak)){
		if (j % 2){
			glColor3ub(light_blue);
			glVertex2f(1200, i);
			glVertex2f(xmaks / 2, ymaks / 2);
			glColor3ub(dark_blue);
			glVertex2f(1200, i - jarak);
		}
		else{
			glColor3ub(dark_blue);
			glVertex2f(1200, i);
			glColor3ub(light_blue);
			glVertex2f(1200, i - jarak);
			glVertex2f(xmaks / 2, ymaks / 2);
		}
		j++;
	}
	for (int i = xmaks; i>0; i -= (jarak)){
		if (j % 2){
			glColor3ub(light_blue);
			glVertex2f(i, 0);
			glVertex2f(xmaks / 2, ymaks / 2);
			glColor3ub(dark_blue);
			glVertex2f(i - jarak, 0);
		}
		else {
			glColor3ub(dark_blue);
			glVertex2f(i, 0);
			glColor3ub(light_blue);
			glVertex2f(i - jarak, 0);
			glVertex2f(xmaks / 2, ymaks / 2);
		}
		j++;
	}
	for (int i = 0; i<ymaks; i += (jarak)){
		if (j % 2){
			glColor3ub(light_blue);
			glVertex2f(0, i);
			glVertex2f(xmaks / 2, ymaks / 2);
			glColor3ub(dark_blue);
			glVertex2f(0, i + jarak);
		}
		else {
			glColor3ub(dark_blue);
			glVertex2f(0, i);
			glColor3ub(light_blue);
			glVertex2f(0, i + jarak);
			glVertex2f(xmaks / 2, ymaks / 2);
		}
		j++;
	}
	glEnd();
}
void matahari(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 40;

	GLfloat rluar = radius+40;
	GLfloat rdalam = radius+10;

	GLfloat twicePi = 2.0f * PI;
	x = xmaks / 2;
	y = ymaks / 2;

	glColor3ub(246,210, 52);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		if (i % 2 == 0){
			glVertex2f(
				x + (rluar* cos(i *  twicePi / triangleAmount)),
				y + (rluar * sin(i * twicePi / triangleAmount))
				);
		}
		else{
			glVertex2f(
				x + (rdalam* cos(i *  twicePi / triangleAmount)),
				y + (rdalam * sin(i * twicePi / triangleAmount))
				);
		}
	}
	glEnd();

	float a = 2*PI;

	cout << "Nilai Cosinus" <<endl<< cos(a);

	glColor3ub(235, 196, 17);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
			);
	}
	glEnd();
}

// Menggambarkan keseluruhan komponen
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(76, 159, 247);
	drawBackground();
	matahari(xmaks / 2, ymaks / 2, 100);
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
