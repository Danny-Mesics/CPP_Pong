#pragma once
#include "GameDefines.h"
#include "raylib.h"

class Paddle
{
public:
	Paddle();
	Paddle(int x, KeyboardKey up, KeyboardKey down);
	~Paddle();

	float m_x, y;
	float width, height;
	int speed;

	void Draw();

	virtual void Update();

	KeyboardKey controls[2];

	//void initialiseControls();

protected:
	void stayInBounds();

	


};

