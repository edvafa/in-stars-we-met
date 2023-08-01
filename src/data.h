#include <raylib.h>

typedef struct Data
{
    char *player_name;
    Vector2 player_position;
    int player_direction;
    Texture2D player_texture;
    int player_current_frame;
    int player_frame_count;

    int count;
} Data;