#include "raylib.h"

int main()
{
    InitWindow(800, 480, "in stars, we met");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}