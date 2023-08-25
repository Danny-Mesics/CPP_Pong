
#include "raylib.h"
#include "raygui.h"
#include "GameDefines.h"
#include "Game.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS




int main(int argc, char* argv[])
{

    Game game;
    game.Startup();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        game.Update();

        // Draw
        //----------------------------------------------------------------------------------
        game.Draw();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}