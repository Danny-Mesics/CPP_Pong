#include "Ball.h"

Ball::Ball() : x{ WINDOW_WIDTH / 2 }, y{ WINDOW_HEIGHT / 2 }, speedX{ 7 }, 
				speedY{ 7 }, radius{ 20 } {}

Ball::~Ball() {};

void Ball::Update() {

	x += speedX;
	y += speedY;

	//checks for collision with top and bottom of the window
	//inverts on the Y axis
	if (y + radius >= WINDOW_HEIGHT || y - radius <= 0) {
		speedY = -speedY;
	}

	//Increments the score of the respective player when ball contacts edge of window
	if (x + radius >= WINDOW_WIDTH)
	{
		player1Score++;
		ResetBall();
	}
	if (x - radius <= 0)
	{
		player2Score++;
		ResetBall();
	}
	
}

void Ball::ResetBall() {
	x = WINDOW_WIDTH / 2;
	y = WINDOW_HEIGHT / 2;

	speedX *= speedChoices[GetRandomValue(0, 1)];
	speedY *= speedChoices[GetRandomValue(0, 1)];

}