

class Fruit 
{
public:
	Fruit(int positionX, int positionZ) 
	{
		xCoordinate = positionX;
		zCoordinate = positionZ;
		angle = 0.0f;
	};

	Fruit() {};
	~Fruit() {};

	void draw();

	//getters
	float getXPosition() { return xCoordinate; };
	float getZPosition() { return zCoordinate; };
	float getAnglePosition() { return angle; };

	//setters
	float setXPosition(float positionX) { xCoordinate = positionX; return xCoordinate; };
	float setZPosition(float positionZ) { zCoordinate = positionZ; return zCoordinate; };
protected:
private:
	float xCoordinate, zCoordinate, angle;
};

