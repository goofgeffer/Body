#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "BODY");

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

        if (IsKeyDown(KEY_RIGHT)) {
            characterPosition.x += 2.0f;
        }

        if (IsKeyDown(KEY_LEFT)) {
            characterPosition.x -= 2.0f;
        }

        if (IsKeyDown(KEY_UP)) {
            characterPosition.y -= 2.0f;
        }

        if (IsKeyDown(KEY_DOWN)) {
            characterPosition.y += 2.0f;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Life is only limited.", 50, 200, 20, LIGHTGRAY);

            DrawCircleV(characterPosition, 25, GREEN);
        
        EndDrawing();
    }
    return 0;
}