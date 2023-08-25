#pragma once
#include "raylib.h"
#include "GameDefines.h"

class Ball
{
public:
	Ball();
	~Ball();

	float x, y;
	int speedX, speedY;
	int radius;

	void Draw() {
		DrawCircle(x, y, radius, WHITE);
	}

	void Update();

	void ResetBall();

	int player1Score = 0;
	int player2Score = 0;

private:
	int speedChoices[2] = { -1, 1 };
};

