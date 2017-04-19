//#include "stdafx.h"
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "time.h"

#define light_blue 76, 159, 247
#define dark_blue 41, 109, 219
#define red 255,0,0
#define yellow 255,255,0
#define green 0,255,0

#define ymaks 800
#define xmaks 1200
#define PI 3.14159265359;


typedef struct {
	int x;
	int y;
} point;

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
	return (int)(-0.0003*(pow(x, 2)) + 0.36*x + 600);
};

int rainbowX(int y){
	return sqrt(y);
};

void drawTree(int awal, int batas){
	glBegin(GL_LINES);
	for(int x = awal;x < batas;x++){
		glColor3ub(139,69,19);
		glVertex2f(x,10);
		glVertex2f(x,360);
	}
	glEnd();
}
// 
// /*
// * width and height are the overall width and height we have to work with, displace is
// * the maximum deviation value. This stops the terrain from going out of bounds if we choose
// */
//
// point* terrain(width, height, displace, roughness){
// 		srand(time(NULL));
//     point points[]
//         // Gives us a power of 2 based on our width
//     float power = Math.pow(2, Math.ceil(Math.log(width) / (Math.log(2))));
//
//     // Set the initial left point
//     points[0] = height/2 + (Math.random()*displace*2) - displace;
//     // set the initial right point
//     points[power] = height/2 + (Math.random()*displace*2) - displace;
//     displace *= roughness;
//
//     // Increase the number of segments
//     for(var i = 1; i < power; i *=2){
//         // Iterate through each segment calculating the center point
//         for(var j = (power/i)/2; j < power; j+= power/i){
//             points[j] = ((points[j - (power / i) / 2] + points[j + (power / i) / 2]) / 2);
//             points[j] += (Math.random()*displace*2) - displace
//         }
//         // reduce our random range
//         displace *= roughness;
//     }
//     return points;
// }
//
// void angularPrism(bool solid){
//     // back endcap
//     glBegin(solid ? GL_TRIANGLES : GL_LINES);
//     glVertex3f(1, 0, 0);
//     glVertex3f(0, 0, 0);
//     glVertex3f(0, 1, 0);
//     glEnd();
//
//     // front endcap
//     glBegin(solid ? GL_TRIANGLES : GL_LINES);
//     glVertex3f(1, 0, 1);
//     glVertex3f(0, 0, 1);
//     glVertex3f(0, 1, 1);
//     glEnd();
//
//     // bottom
//     glBegin(solid ? GL_QUADS : GL_LINES);
//     glVertex3f(0, 0, 0);
//     glVertex3f(1, 0, 0);
//     glVertex3f(1, 0, 1);
//     glVertex3f(0, 0, 1);
//     glEnd();
//
//     // back
//     glBegin(solid ? GL_QUADS : GL_LINES);
//     glVertex3f(0, 0, 0);
//     glVertex3f(0, 1, 0);
//     glVertex3f(0, 1, 1);
//     glVertex3f(0, 0, 1);
//     glEnd();
//
//     // top
//     glBegin(solid ? GL_QUADS : GL_LINES);
//     glVertex3f(0, 1, 0);
//     glVertex3f(1, 0, 0);
//     glVertex3f(1, 0, 1);
//     glVertex3f(0, 1, 1);
//     glEnd();
// }

void drawRainbow(int range){
	glBegin(GL_LINES);
	int y;
	for (int x = 0; x<xmaks; x++){
		y = rainbowY(x);
		// red to yellow
		glColor3ub(255, 0, 0);
		glVertex2f(x, y);
		glColor3ub(255, 255, 0);
		glVertex2f(x, y - range);
		// yellow to green
		glVertex2f(x, y - range);
		glColor3ub(0, 255, 0);
		glVertex2f(x, y - (2 * range));
		// green to blue
		glVertex2f(x, y - (2 * range));
		glColor3ub(0, 0, 255);
		glVertex2f(x, y - (3 * range));
		// blue to purple
		glVertex2f(x, y - (3 * range));
		glColor3ub(128, 0, 128);
		glVertex2f(x, y - (4 * range));
	}
	// int x;
	// for (int y=0;y<ymaks;y++){
	// 	x = rainbowX(y);
	// 	glVertex2f(x+(xmaks/2),y);
	// 	glVertex2f((xmaks/2)-x,y);
	// }
	glEnd();
}

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

	GLfloat rluar = radius + 40;
	GLfloat rdalam = radius + 10;

	GLfloat twicePi = 2.0f * PI;
	x = xmaks / 2;
	y = ymaks / 2;

	glColor3ub(246, 210, 52);

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

	//float a = 2 * PI;

	//cout << "Nilai Cosinus" << endl << cos(a);



	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(225, 181, 24);
	glVertex2f(x, y); // center of circle
	glColor3ub(253, 237, 0);
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
	drawRainbow(15);
	matahari(xmaks / 2, ymaks / 2, 100);
	//radialGradientCircle(50,20);
	angularPrism(false);
	drawTree(150, 300);
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
