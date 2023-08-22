//#include "Game.h"
//#include "Ball.h"
//#include "Paddle.h"
//#include "CPU.h"
//
//
//Game::Game() {}
//Game::~Game() {};
//
//void Game::startup() {
//	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "My Pong Game!");
//
//	SetTargetFPS(60);
//
//	initialiseBall();
//	initialiseP1();
//	initialiseP2();
//}
//
//void Game::initialiseBall(){
//	Ball ball;
//}
//void Game::initialiseP1(){
//	Paddle p1(10);
//}
//void Game::initialiseP2(){
//	if (isMultiplayer)
//		Paddle p2(WINDOW_WIDTH - 30);
//	else
//		Paddle p2;
//}
//
//
//
//void Game::update(){
//	ball.Update();
//	p1.Update();
//	p2.Update(ball.y);
//}
//void Game::draw(){
//	BeginDrawing();
//
//	ClearBackground(BLACK);
//
//	DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);
//	ball.Draw();
//	p1.Draw();
//	p2.Draw();
//
//	EndDrawing();
//}
//
//void Game::welcomeMessage() {
//	
//}
//	 	 
