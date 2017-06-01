#include <GLUT/glut.h>

class Block 
{
public:

	GLuint cube;
	//this is the colour of the block
	float blockColourRed = 47; float blockColourGreen = 181; float blockColourBlue = 243;

	Block(float positionX, float positionY, float positionZ, float blockSize = 1.0f) {
		xCoordinate = positionX;
		yCoordinate = positionY;
		zCoordinate = positionZ;
		size = blockSize;
		red = blockColourRed; green = blockColourGreen; blue = blockColourBlue; //rgb colors are set to their default (initialized at the top)
	};

	~Block() {};

	//setters
	void setXPosition(float positionX) { xCoordinate = positionX; }; //getter and setter functions for x, y and z
	void setYPosition(float positionY) { yCoordinate = positionY; };
	void setZPosition(float positionZ) { zCoordinate = positionZ; };

	//getters
	float getXPosition() { return xCoordinate; };
	float getYPosition() { return yCoordinate; };
	float getZPosition() { return zCoordinate; };

	void setColour(float pRed, float pGreen, float pBlue) { red = pRed; green = pGreen; blue = pBlue; }; //... and color
	void cubeComp();
	void draw();
private:
	float xCoordinate, yCoordinate, zCoordinate, size, red, green, blue;
};
