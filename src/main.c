#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "BODY");

    Image robot_character = LoadImage("assets/robot.png");

    // Note: Textures must be loaded after window is initialized
    Texture2D texture = LoadTextureFromImage(robot_character);

    UnloadImage(robot_character); // Don't need robot_character anymore

    Vector2 characterPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

    SetTargetFPS(60);

    HideCursor(); // Hide the cursor by default

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_H)) {
            if (IsCursorHidden()) {
                ShowCursor();
            } else {
                HideCursor();
            }
        }

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            characterPosition.x += 2.0f;
        }

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            characterPosition.x -= 2.0f;
        }

        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            characterPosition.y -= 2.0f;
        }

        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            characterPosition.y += 2.0f;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Little Body Test", 50, 200, 20, LIGHTGRAY);

            DrawTextureV(texture, characterPosition, WHITE);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}