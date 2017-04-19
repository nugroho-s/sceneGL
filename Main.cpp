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
#define dark_green 1, 127, 5
#define light_green 0, 224, 7
#define cloud_gray 195, 204, 196

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

void drawCloudSphere(int x, int y){
	int triangleAmount = 40;
	int i;
	GLfloat twicePi = 2.0f * PI;
	int radius = 50;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(cloud_gray);
	x+=(int)radius-(0.1*radius);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
			);
	}
	glEnd();
}

void drawCloud(int x, int y){
	int triangleAmount = 40;
	int i;
	GLfloat twicePi = 2.0f * PI;
	glColor3ub(cloud_gray);
	glBegin(GL_QUADS);
	glVertex2f(x+50,(y-50));
	glVertex2f(x+50,(y+50));
	glVertex2f((x+150),(y+50));
	glVertex2f((x+150),(y-50));
	glEnd();
	drawCloudSphere(x,y);
	drawCloudSphere(x+100,y);
	drawCloudSphere(x+25,y+25);
	drawCloudSphere(x+60,y+20);
	drawCloudSphere(x+35,y-10);
	drawCloudSphere(x+70,y-20);
};

// returns ordinat for a given absis
int rainbowY(int x){
	return (int)(-0.00035*(pow(x, 2)) + 0.36*x + 600);
};

int rainbowX(int y){
	return sqrt(y);
};

void drawTree(int awal, int batas){
	int height = 600;
	int x[] = {
		awal,800,
		awal,height,
		batas,800,
		batas,800,
		batas,height,
		awal,height
	};
	glColor3ub(139,69,19);
	drawTriangles(x,6,'t');
	int leaves[] = {
		awal-50,height,
		batas+50,height,
		((batas-awal)/2)+awal,height-100
	};
	glBegin(GL_TRIANGLES);
	glColor3ub(dark_green);
	glVertex2f(awal-50,ymaks-height);
	glColor3ub(light_green);
	glVertex2f(((batas-awal)/2)+awal,ymaks-(height-200));
	glVertex2f(batas+50,ymaks-height);
	glEnd();
	// for(int x = awal;x < batas;x++){
	//
	// 	glVertex2f(x,0);
	// 	glVertex2f(x,360);
	// }
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
//

// returns ordinat for a given absis
int mountainY1(int x){
	return (int)(-0.0004*(pow(x, 2)) + 0.6*x + 30);
};
int mountainY2(int x){
	return (int)(-0.0005*(pow(x, 2)) + 0.75*x);
};
int mountainY3(int x){
	return (int)(-0.0005*(pow(x, 2)) + 0.5*x + 100);
};

void drawAv(int range, int type) {
	int xend;
	int xbegin;
	glBegin(GL_LINES);
	int y;

	switch (type) {
		case 1 :  xbegin = 0; xend = xmaks;
				break;
		case 2 :  xbegin = -400;
				break;
		case 3 :  xbegin= -400; xend = xmaks + xbegin + 200;
				break;
	}

	for (int x = xbegin; x<xend; x++){
		switch (type) {
			case 1 :  y = mountainY1(x);
				  break;
			case 2 :  y = mountainY2(x);
				  break;
			case 3 :  y = mountainY3(x);
				  break;
		}
		// yellow to green
		glVertex2f(x, y - (2 * range));
		glColor3ub(dark_green);
		glVertex2f(x, y - (3 * range));

		glVertex2f(x, y - range);
		glColor3ub(light_green);
		glVertex2f(x, y - (2 * range));

// <<<<<<< HEAD
// 		glVertex2f(x, y - (2 * range));
// 		glColor3ub(light_green);
// 		glVertex2f(x, y - (3 * range));
// =======
//
// >>>>>>> c4585b4d69dd13614450d184bcb823eefce7ba07
	}
	glEnd();
}


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
	matahari(xmaks, ymaks, 100);
	//radialGradientCircle(50,20);
	// angularPrism(false);
	//draw mountain
  drawAv(80 ,1 );
	//drawAv(50 ,2 );
	drawAv(100 ,3 );
	drawTree(150, 300);
	drawTree(150, 200);
	drawTree(250, 300);
	drawTree(350, 400);
	drawCloud(350,700);
	drawCloud(750,600);
	drawCloud(50,550);
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
