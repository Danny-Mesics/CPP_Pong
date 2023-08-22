#include "Paddle.h"

//default constructor for the CPU paddle
Paddle::Paddle() : m_x{ WINDOW_WIDTH - 30 }, y{ (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2) }, width{ PADDLE_WIDTH },
height{ PADDLE_HEIGHT }, speed{ 5 } {}

//x parameter used to destinguish player1 and player2 positions.
Paddle::Paddle(int x) : y { (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2) }, width{ PADDLE_WIDTH },
height{ PADDLE_HEIGHT }, speed{ 5 } {
	m_x = x;
}
Paddle::~Paddle() {};

void Paddle::Draw() {
	DrawRectangle(m_x, y, width, height, WHITE);
}

void Paddle::Update() {
	if (IsKeyDown(KEY_W) == true)
		y -= speed;
	if (IsKeyDown(KEY_S) == true)
		y += speed;

	stayInBounds();
}

void Paddle::stayInBounds() {
	if (y <= 0)
		y = 0;
	if (y + height >= WINDOW_HEIGHT)
		y = WINDOW_HEIGHT - height;
}