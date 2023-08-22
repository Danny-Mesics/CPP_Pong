
#include "raylib.h"
#include "glm/glm/glm.hpp"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "GameDefines.h"
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "CPU.h"

Ball ball;
Paddle p1(10);
CPU p2;


int main(int argc, char* argv[])
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "My Pong Game!");

    SetTargetFPS(60);

   /* Game game;

    game.startup();*/
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        ball.Update();
        p1.Update();
        p2.Update(ball.y);

        //Checking for Collisions
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ p1.m_x, p1.y, p1.width, p1.height })) {
            ball.speed_x = -ball.speed_x;
        }
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ p2.m_x, p2.y, p2.width, p2.height })) {
            ball.speed_x = -ball.speed_x;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        /*game.draw();*/
        BeginDrawing();

        ClearBackground(BLACK);

        DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);
        ball.Draw();
        p1.Draw();
        p2.Draw();
        DrawText(TextFormat("%i",ball.player1_score), WINDOW_WIDTH / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", ball.player2_score), 3 * WINDOW_WIDTH / 4 - 20, 20, 80, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}