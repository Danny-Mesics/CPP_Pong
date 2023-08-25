#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "CPU.h"



Game::~Game() {
	delete ball;
	delete player1;
	delete player2;
};

void Game::Startup() {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "My Pong Game!");

	SetTargetFPS(60);
	BeginDrawing();

	// Allows the player to decide on CPU or
	// local multiplayer match before instantiating anything
	while (isChosen == false) {
		WelcomeMessage();
	}
	
	ball = new Ball;
	player1 = new Paddle(10, KEY_W, KEY_S);
	

	if (isMultiplayer)
	{
		player2 = new Paddle(WINDOW_WIDTH - 30, KEY_UP, KEY_DOWN);
	}
	else if (!isMultiplayer)
		player2 = new CPU(ball);
}



void Game::Update(){
	ball->Update();
	player1->Update();
	player2->Update();

	// Checks for collision between the Ball and a Paddle, inverting the X Axis.
	if (CheckCollisionCircleRec(Vector2{ ball->x, ball->y }, ball->radius, Rectangle{ player1->x, player1->y, player1->width, player1->height })) {
		ball->speedX = -ball->speedX;
	}
	if (CheckCollisionCircleRec(Vector2{ ball->x, ball->y }, ball->radius, Rectangle{ player2->x, player2->y, player2->width, player2->height })) {
		ball->speedX = -ball->speedX;
	}
}
void Game::Draw(){
	BeginDrawing();

	ClearBackground(BLACK);

	DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);
	ball->Draw();
	player1->Draw();
	player2->Draw();
	DrawText(TextFormat("%i", ball->player1Score), WINDOW_WIDTH / 4 - 20, 20, 80, WHITE);
	DrawText(TextFormat("%i", ball->player2Score), 3 * WINDOW_WIDTH / 4 - 20, 20, 80, WHITE);

	EndDrawing();
}

void Game::WelcomeMessage() {
	ClearBackground(BLACK);
	DrawText(TextFormat("Welcome to my little build of Pong"), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 4, 20, WHITE);
	DrawText(TextFormat("Would you like to play local multiplayer or vs the CPU?"), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 4 + 60, 20, WHITE);
	DrawText(TextFormat("Press 'M' for multiplayer. Press 'S' for CPU match."), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 4 + 80, 20, WHITE);
	DrawText(TextFormat("Player 1 Controls: Up - > 'W'"), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 2 + 100, 20, WHITE);
	DrawText(TextFormat("Up - > 'W'"), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 2 + 120, 20, WHITE);
	DrawText(TextFormat("Down - > 'S'"), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 2 + 140, 20, WHITE);
	DrawText(TextFormat("Player 2 Controls:"), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 2 + 160, 20, WHITE);
	DrawText(TextFormat("Up - > 'Up arrow'"), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 2 + 180, 20, WHITE);
	DrawText(TextFormat("Down - > 'Down Arrow'"), WINDOW_WIDTH / 8, WINDOW_HEIGHT / 2 + 200, 20, WHITE);
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
	 	 
