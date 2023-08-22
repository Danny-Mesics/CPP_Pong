#pragma once
#include "GameDefines.h"
#include "raylib.h"

class Paddle
{
public:
	Paddle();
	Paddle(int x);
	~Paddle();

	float m_x, y;
	float width, height;
	int speed;

	void Draw();

	void Update();

	

protected:
	void stayInBounds();

	


};

