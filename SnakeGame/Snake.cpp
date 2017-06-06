#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <GLUT/glut.h>

#include"Snake.h"
#include"Music.h"

//creates fruit
Fruit* fruit = new Fruit(1, 1);

Mix_Chunk* pEatAudio = NULL;

enum Direction
{
	//direction the snake will move
	DIRECTION_LEFT, DIRECTION_RIGHT, DIRECTION_UP, DIRECTION_DOWN
};

void Snake::draw() //goes through a loop and keeps calling the draw()
{
	for(int i = 0; i <= snakeBlockBody.size() - 1; i++)
	{
		fruit->draw();
		Block* tmp = snakeBlockBody.at(i);
		tmp->draw();
	}
};

void Snake::move(Direction direction) //handle movement for the snake
{
	Block* snkHead = snakeBlockBody.at(0);
	if(direction == DIRECTION_LEFT && currentDir != DIRECTION_RIGHT)
	{
		moveSnake();
		snkHead->setXPosition(snkHead->getXPosition() - 1.0f);
		currentDir = direction;
		isUpdated = true;
	}
	else if (direction == DIRECTION_RIGHT && currentDir != DIRECTION_LEFT)
	{
		moveSnake();
		snkHead->setXPosition(snkHead->getXPosition() + 1.0f);
		currentDir = direction;
		isUpdated = true;
	}
	else if (direction == DIRECTION_UP && currentDir != DIRECTION_DOWN)
	{
		moveSnake();
		snkHead->setZPosition(snkHead->getZPosition() + 1.0f);
		currentDir = direction;
		isUpdated = true;
	}
	else if (direction == DIRECTION_DOWN && currentDir != DIRECTION_UP)
	{
		moveSnake();
		snkHead->setZPosition(snkHead->getZPosition() - 1.0f);
		currentDir = direction;
		isUpdated = true;
	}
};

void Snake::moveSnake()
{
	// sets the snakes body movement using its previous position
	for (int i = snakeBlockBody.size() - 1; i >= 1; i--)
	{
		Block* tmp = snakeBlockBody.at(i);
		Block* prevBlock = snakeBlockBody.at(i - 1);
		tmp->setXPosition(prevBlock->getXPosition());
		tmp->setZPosition(prevBlock->getZPosition());
			
	}
};

void Snake::update()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	if(!isUpdated)
		move(currentDir);
	isUpdated = false;
	collDetect();
};

void Snake::collDetect()
{
	pEatAudio = loadChunk("Music/EatSound.wav");

	float xCoordinate = snakeBlockBody.at(0)->getXPosition();
	float zCoordinate = snakeBlockBody.at(0)->getZPosition();
	//checking collision for the snake and fruit
	if(fruit->getXPosition() == xCoordinate && fruit->getZPosition() == zCoordinate)
	{
		points++;
		std::cout << "Points = " << points << std::endl;
		bool repeat = false;
		do 
		{
			repeat = false;
			fruit->setXPosition(rand() % 11 - 5);
			fruit->setZPosition(rand() % 11 - 5);
			for(int i = 0; i <= snakeBlockBody.size() - 1; i++)
			{
				xCoordinate = snakeBlockBody.at(i)->getXPosition();
				zCoordinate = snakeBlockBody.at(i)->getZPosition();
				if(fruit->getXPosition() == xCoordinate && fruit->getZPosition() == zCoordinate)
					repeat = true;	
				Mix_PlayChannel(-1, pEatAudio, 0);
			}
		} while (repeat);
		addBlock();
	}
	for(int i = 1; i <= snakeBlockBody.size() - 1; i++)
	{
		if(snakeBlockBody.at(i)->getXPosition() == snakeBlockBody.at(0)->getXPosition() && snakeBlockBody.at(i)->getZPosition() == snakeBlockBody.at(0)->getZPosition())
		{
			//collision has happened!
			std::cout << "collision" << std::endl;
			snakeBlockBody.at(i)->setColour(1, 0, 0);
		}
	}
};

void Snake::addBlock()
{
	//adds a block onto the snakes body
	Block* newBlock = new Block(-100, 0, -100);
	snakeBlockBody.push_back(newBlock);
};

void Snake::DeleteAudio() 
{
	Mix_FreeChunk(pEatAudio);
	pEatAudio = NULL;
}
