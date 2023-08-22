#pragma once
#include "raylib.h"
#include "GameDefines.h"

class Ball
{
public:
	Ball();
	~Ball();

	float x, y;
	int speed_x, speed_y;
	int radius;

	void Draw() {
		DrawCircle(x, y, radius, WHITE);
	}

	void Update();
};

