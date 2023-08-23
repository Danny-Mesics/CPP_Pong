#include "CPU.h"
#include "Ball.h"

CPU::CPU(Ball* ball) : Paddle(), ball{ ball } {}

void CPU::Update()
{  
	if (y + height / 2 > ball->y)
		y = y - speed;
	if (y + height / 2 <= ball->y)
		y = y + speed;

	stayInBounds();
}

