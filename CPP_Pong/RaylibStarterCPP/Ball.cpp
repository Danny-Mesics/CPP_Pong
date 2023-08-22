#include "Ball.h"

Ball::Ball() : x{ WINDOW_WIDTH / 2 }, y{ WINDOW_HEIGHT / 2 }, speed_x{ 7 }, 
				speed_y{ 7 }, radius{ 20 } {}

Ball::~Ball() {};

void Ball::Update() {
	x += speed_x;
	y += speed_y;

	if (y + radius >= WINDOW_HEIGHT || y - radius <= 0) {
		speed_y = -speed_y;
	}
	if (x + radius >= WINDOW_WIDTH)
	{
		player1_score++;
		resetBall();
	}
	if (x - radius <= 0)
	{
		player2_score++;
		resetBall();
	}
	
}

void Ball::resetBall() {
	x = WINDOW_WIDTH / 2;
	y = WINDOW_HEIGHT / 2;

	speed_x *= speedChoices[GetRandomValue(0, 1)];
	speed_y *= speedChoices[GetRandomValue(0, 1)];

}