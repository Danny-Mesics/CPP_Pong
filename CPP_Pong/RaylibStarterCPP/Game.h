#pragma once
#include "raylib.h"
#include "GameDefines.h"

class Ball;
class Paddle;
class CPU;

class Game
{
public:
	~Game();

	void startup();

	void update();
	void draw();

	void welcomeMessage();

	

private:
	Ball* ball;
	Paddle* player1;
	Paddle* player2;

	bool isMultiplayer;
	bool isChosen = false;
	
	
};

