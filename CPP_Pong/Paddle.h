#pragma once
#include "GameDefines.h"
#include "raylib.h"

class Paddle
{
public:
	Paddle();
	Paddle(int x_position, KeyboardKey up, KeyboardKey down);
	~Paddle();

	float x, y;
	float width, height;
	int speed;

	void Draw();

	virtual void Update();

	KeyboardKey controls[2];

protected:
	void StayInBounds();

	


};

