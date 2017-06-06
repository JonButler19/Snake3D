#include <vector>
#include "Block.h"

#include "Fruit.h"

class Snake
{
public:
	enum Direction 
	{
		//direction the snake will move
		DIRECTION_LEFT, DIRECTION_RIGHT, DIRECTION_UP, DIRECTION_DOWN
	};

	std::vector<Block*> snakeBlockBody; // the snakes body (block array)
	
	Snake(float startPositionX, float startPositionZ, int bCounter)
	{
		for (float i = 0; i < bCounter; i++)
		{
			Block* tmp = new Block(startPositionX + i, 0, startPositionZ);
			if (i == 0)
			{
				tmp->setColour(0, 1, 0); //setting the head clour
				snakeBlockBody.push_back(tmp);
			};
			isUpdated = false;
			currentDir = DIRECTION_RIGHT;
			points = 0;
		};
	};
		Snake() {};
		~Snake() {};

		void draw();
		void move(Direction direction);
		void moveSnake();
		void update();
		void collDetect();
		void addBlock();
		void DeleteAudio();

		Direction getDirection() { return currentDir; };
protected:
private:
	Direction currentDir;
	bool isUpdated;
	int points;
};