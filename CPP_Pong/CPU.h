#pragma once
#include "Paddle.h"
class Ball;

class CPU : public Paddle
{
protected:
	Ball* ball;
public:
	CPU(Ball* ball);
	void Update() override;
};

