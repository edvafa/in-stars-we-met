#include <raylib.h>
#include <stdio.h>

#include "data.h"

void init(Data *data)
{
    InitWindow(800, 480, "in stars, we met");
    SetTargetFPS(60);
}

void update(Data *data)
{
    BeginDrawing();
    ClearBackground(BLACK);

    if (IsKeyDown(KEY_RIGHT))
        data->player_position.x += data->player_velocity;
    if (IsKeyDown(KEY_LEFT))
        data->player_position.x -= data->player_velocity;
    if (IsKeyDown(KEY_UP))
        data->player_position.y -= data->player_velocity;
    if (IsKeyDown(KEY_DOWN))
        data->player_position.y += data->player_velocity;

    if (IsKeyPressed(KEY_A))
    {
        data->count++;
        printf("%d\n", data->count);
    }

    DrawCircleV(data->player_position, 10, RED);

    EndDrawing();
}
