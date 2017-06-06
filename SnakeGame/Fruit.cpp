#include <vector>
#include <GLUT/glut.h>
#include "Fruit.h"

using namespace std;

void Fruit::draw()
{
	angle += 2.0f;
	glPushMatrix();
	glTranslatef(-xCoordinate, 0, zCoordinate);
	glRotatef(angle, 0, 1, 0);
	float gc = 0.5;
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0 - gc, 0 - gc, 0 - gc);
	glVertex3f(1 - gc, 0 - gc, 0 - gc);
	glVertex3f(0.5 - gc, 0 - gc, 1 - gc);
	glTexCoord2f(0.5, 1); glVertex3f(0.5 - gc, 1 - gc, 0.5 - gc);
	glTexCoord2f(0, 0); glVertex3f(0 - gc, 0 - gc, 0 - gc);
	glTexCoord2f(1, 0); glVertex3f(1 - gc, 0 - gc, 0 - gc);
	glTexCoord2f(0.5, 1); glVertex3f(0.5 - gc, 1 - gc, 0.5 - gc);
	glTexCoord2f(1, 0); glVertex3f(0 - gc, 0 - gc, 0 - gc);
	glTexCoord2f(0, 0); glVertex3f(0.5 - gc, 0 - gc, 1 - gc);
	glTexCoord2f(0.5, 1); glVertex3f(0.5 - gc, 1 - gc, 0.5 - gc);
	glTexCoord2f(0, 0); glVertex3f(1 - gc, 0 - gc, 0 - gc);
	glTexCoord2f(1, 0); glVertex3f(0.5 - gc, 0 - gc, 1 - gc);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
};