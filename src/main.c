#include "data.h"

#include <dlfcn.h>
#include <raylib.h>
#include <stddef.h>
#include <stdio.h>

void *handle;
void (*init)(Data *);
void (*update)(Data *);

void reload_game()
{
    if (handle != NULL)
        dlclose(handle);
    handle = dlopen("lib.so", RTLD_NOW);

    init = dlsym(handle, "init");
    update = dlsym(handle, "update");

    puts("LIB reloaded!");
}

int main(int argc, char **argv)
{
    reload_game();

    struct Data data = {.player_position = {20, 20}, .player_velocity = 2.0f};
    init(&data);
    while (!WindowShouldClose())
    {
        update(&data);

        if (IsKeyPressed(KEY_R))
            reload_game();
    }

    dlclose(handle);
    CloseWindow();
    return 0;
}