#include "CPU.h"
#include "Ball.h"

CPU::CPU(Ball* ball) : Paddle(), ball{ ball } {}

void CPU::Update()
{  

	//CPU Tracks the Y axis of the ball and trys to stay in line with it
	if (y + height / 2 > ball->y)
		y = y - speed;
	if (y + height / 2 <= ball->y)
		y = y + speed;

	StayInBounds();
}

