#include <raylib.h>
#include <stdio.h>

#include "data.h"

void player(Data *data)
{
    int dir_map[4][4] = {
        {0, 1, 0, 2}, {0, 1, 0, 2}, {0, 1, 0, 2}, {0, 1, 0, 2}};

    if (IsKeyDown(KEY_LEFT))
        data->player_direction = 0;

    if (IsKeyDown(KEY_DOWN))
        data->player_direction = 1;

    if (IsKeyDown(KEY_UP))
        data->player_direction = 2;

    if (IsKeyDown(KEY_RIGHT))
        data->player_direction = 3;

    data->player_frame_count++;
    if (data->player_frame_count > 30)
    {
        data->player_current_frame++;
        data->player_current_frame %= 4;

        data->player_frame_count = 0;
    }

    int x = data->player_direction * 16;
    int y = dir_map[data->player_direction][data->player_current_frame] * 16;

    Rectangle rec = {x, y, 16, 16};
    DrawTextureRec(data->player_texture, rec, data->player_position, WHITE);
}

////////////////////////////////////////////////////////////////

void init(Data *data)
{
    InitWindow(800, 480, "in stars, we met");
    SetTargetFPS(60);

    data->player_position = (Vector2){20, 20};
    data->player_direction = 0;
    data->player_texture = LoadTexture("src/assets/player.png");
    data->player_current_frame = 0;
    data->player_frame_count = 0;
}

void update(Data *data)
{
    BeginDrawing();
    ClearBackground(BLACK);

    player(data);

    if (IsKeyPressed(KEY_A))
    {
        data->count++;
        printf("%d\n", data->count);
    }

    EndDrawing();
}
