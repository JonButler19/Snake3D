#include <vector>
#include <iostream>
#include <GLUT/glut.h>

#include "Block.h"
using namespace std;

void Block::cubeComp() 
{ 
	cube = glGenLists(1);
	glNewList(cube, GL_COMPILE);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(0.5, 0.5, 0.5); //back face
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glNormal3f(0, 0, -1);
	glVertex3f(0.5, 0.5, -0.5); //front face
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glNormal3f(0, -1, 0); //bottom face
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glNormal3f(0, 1, 0); //top face
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glNormal3f(-1, 0, 0); //right face
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glNormal3f(1, 0, 0); //left face
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	glEndList();
};

void Block::draw() //draw the cube
{
	cubeComp();
	glPushMatrix();
	glTranslatef(-xCoordinate, yCoordinate, zCoordinate);
	if (red > 1 || green > 1 || blue > 1) 
	{
		glColor3ub(red, green, blue);
	}
	else 
	{
		glColor3f(red, green, blue);
	}
	glCallList(cube);
	glPopMatrix();
};