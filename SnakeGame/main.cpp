#include <GLUT/glut.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include "Snake.h"
#include "Music.h"

//SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

Mix_Music* pBackgroundMusicAudio = NULL;

bool initSDL()
{
	// Initialise SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialise! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
		return false;
	}
	return true;
}

float yCameraPosition = 13.0f;

//l = light
GLfloat lAmb[] = { 0.5, 0.5, 0.5, 1 };
GLfloat lDiff[] = { 1, 1, 1, 1 };
GLfloat lPos[] = { 0, 3, 0 };

//create the snake
Snake* snake = new Snake(0, 0, 1);

void drawBoard(void)
{
	glColor3ub(54, 158, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glEnd();
	glLineWidth(1);
	glColor3ub(90, 80, 20);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-5 - 0.5, -0.51, -6.5);
	glVertex3f(-5 - 0.5, -0.51, 6.5);
	glVertex3f(6 - 0.5, -0.51, 6.5);
	glVertex3f(6 - 0.5, -0.51, -6.5);
	glEnd();
	glColor3ub(30, 2, 63);
};

void draw(void)
{
	snake->update();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt
	(
		0, yCameraPosition, -9,
		0, 0, 0,
		0, 1, 0
	);
	drawBoard();
	snake->draw();
	glutSwapBuffers();
};

void windowDisplay(int width, int height)
{
	if(height == 0)
	{
		height = 1;
	};
	float ratio = width*1.0f / height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(50, ratio, 1, 200);
	glMatrixMode(GL_MODELVIEW);
};

void keyEvents(unsigned char key, int xCoordinate, int yCoordinate)
{
	switch (key) 
	{
	case 27:
		exit(0);
		break;
	}
}

void movement(int key, int xCoordinate, int yCoordinate) 
{
	switch(key)
	{
	case GLUT_KEY_F1:
		exit(0);
		break;
	case GLUT_KEY_LEFT:
		std::cout << "Press Left" << std::endl;
		snake->move(Snake::DIRECTION_LEFT);
		break;
	case GLUT_KEY_RIGHT:
		std::cout << "Pressed Right" << std::endl;
		snake->move(Snake::DIRECTION_RIGHT);
		break;
	case GLUT_KEY_UP:
		std::cout << "Pressed Up" << std::endl;
		snake->move(Snake::DIRECTION_UP);
		break;
	case GLUT_KEY_DOWN:
		std::cout << "Press Down" << std::endl;
		snake->move(Snake::DIRECTION_DOWN);
		break;
	}
};

void initaliseGL(void)
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lDiff);
	glLightfv(GL_LIGHT1, GL_POSITION, lPos);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
}

void scrollWindow(int button, int direction, int xCoorinate, int yCoordinate)
{
	switch (button)
	{
	case 3:
		yCameraPosition -= 0.5;
		break;
	case 4:
		yCameraPosition += 0.5;
		break;
	};
};

int main(int argc, char **argv)
{
	initaliseGL();
	initSDL();
	pBackgroundMusicAudio = loadMusic("Music/MusicLoopTest.wav");

	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitWindowPosition(-1, -1);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	Mix_PlayMusic(pBackgroundMusicAudio, -1);
	glutCreateWindow("Snake Game");
	
	
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutReshapeFunc(windowDisplay);
	glutKeyboardFunc(keyEvents);
	glutSpecialFunc(movement);
	glutMouseFunc(scrollWindow);

	glutMainLoop();

	Mix_HaltMusic();

	snake->DeleteAudio();
	Mix_FreeMusic(pBackgroundMusicAudio);
	pBackgroundMusicAudio = NULL;
	SDL_Quit();
	return 1;
};