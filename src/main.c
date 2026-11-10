#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "BODY");

    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) {
            ballPosition.x += 2.0f;
        }

        if (IsKeyDown(KEY_LEFT)) {
            ballPosition.x -= 2.0f;
        }

        if (IsKeyDown(KEY_UP)) {
            ballPosition.y -= 2.0f;
        }

        if (IsKeyDown(KEY_DOWN)) {
            ballPosition.y += 2.0f;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Life is only limited.", 50, 200, 20, LIGHTGRAY);

            DrawCircleV(ballPosition, 25, MAROON);
        
        EndDrawing();
    }
    return 0;
}