#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "CPU.h"



Game::~Game() {
	delete ball;
	delete player1;
	delete player2;
};

void Game::startup() {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "My Pong Game!");

	SetTargetFPS(60);
	BeginDrawing();
	while (isChosen == false) {
		welcomeMessage();
	}
	
	ball = new Ball;
	player1 = new Paddle(10, KEY_W, KEY_S);
	/*player1->initialiseControls();*/
	if (isMultiplayer)
	{
		player2 = new Paddle(WINDOW_WIDTH - 30, KEY_UP, KEY_DOWN);
		/*player2->initialiseControls();*/
	}
	else if (!isMultiplayer)
		player2 = new CPU(ball);
}



void Game::update(){
	ball->Update();
	player1->Update();
	player2->Update();

	if (CheckCollisionCircleRec(Vector2{ ball->x, ball->y }, ball->radius, Rectangle{ player1->m_x, player1->y, player1->width, player1->height })) {
		ball->speed_x = -ball->speed_x;
	}
	if (CheckCollisionCircleRec(Vector2{ ball->x, ball->y }, ball->radius, Rectangle{ player2->m_x, player2->y, player2->width, player2->height })) {
		ball->speed_x = -ball->speed_x;
	}
}
void Game::draw(){
	BeginDrawing();

	ClearBackground(BLACK);

	DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);
	ball->Draw();
	player1->Draw();
	player2->Draw();
	DrawText(TextFormat("%i", ball->player1_score), WINDOW_WIDTH / 4 - 20, 20, 80, WHITE);
	DrawText(TextFormat("%i", ball->player2_score), 3 * WINDOW_WIDTH / 4 - 20, 20, 80, WHITE);

	EndDrawing();
}

void Game::welcomeMessage() {
	ClearBackground(BLACK);
	DrawText(TextFormat("Welcome to my little build of Pong"), WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2, 20, WHITE);
	DrawText(TextFormat("Would you like to play local multiplayer or vs the CPU?"), WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2 + 40, 20, WHITE);
	DrawText(TextFormat("Press 'M' for multiplayer. Press 'S' for CPU match."), WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2 + 65, 20, WHITE);
	EndDrawing();
	if (IsKeyPressed(KEY_M) == true)
	{
		isMultiplayer = true;
		isChosen = true;
	}
	else if (IsKeyPressed(KEY_S) == true)
	{
		isMultiplayer = false;
		isChosen = true;
	}
}
	 	 
