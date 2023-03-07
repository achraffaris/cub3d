#include "core.h"

int     valid_movement(game_t *g, int x, int y)
{
    x = ceil((double)x / MAP_CELL_SIZE) - 1;
    y = ceil((double)y / MAP_CELL_SIZE) - 1;
    if (x >= 0 && y >= 0 && g->map[y][x] == '0')
        return (1);
    return(0);
}

void    turn_player(game_t *g, int key_code)
{
    if (key_code == RIGHT)
        g->player->rotation_angle += degree_to_rad(-1 * ROTATION_SPEED);
    else
        g->player->rotation_angle += degree_to_rad(1 * ROTATION_SPEED);
}