#include "Paddle.h"

//default constructor for the CPU paddle
Paddle::Paddle() : x { WINDOW_WIDTH - 30 }, y { (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2) }, width{ PADDLE_WIDTH },
height{ PADDLE_HEIGHT }, speed{ 5 } {}

//x parameter used to destinguish player1 and player2's positions + Control inputs.
Paddle::Paddle(int x_position, KeyboardKey up, KeyboardKey down) : y { (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2) }, width{ PADDLE_WIDTH },
height{ PADDLE_HEIGHT }, speed{ 5 } {
	x = x_position;
	controls[0] = up;
	controls[1] = down; 
}
Paddle::~Paddle() {};

void Paddle::Draw() {
	DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::Update() {
	if (IsKeyDown(controls[0]) == true)
		y -= speed;
	if (IsKeyDown(controls[1]) == true)
		y += speed;

	StayInBounds();
}



void Paddle::StayInBounds() {
	if (y <= 0)
		y = 0;
	if (y + height >= WINDOW_HEIGHT)
		y = WINDOW_HEIGHT - height;
}

