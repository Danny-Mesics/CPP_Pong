
#include "raylib.h"
#include "glm/glm/glm.hpp"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "GameDefines.h"
#include "Game.h"



int main(int argc, char* argv[])
{

    Game game;

    game.startup();
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        game.update();

        // Draw
        //----------------------------------------------------------------------------------
        game.draw();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}