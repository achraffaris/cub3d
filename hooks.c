#include "cub3d.h"
#include <math.h>

int     valid_movement(game_t *game, int x, int y)
{
    if (game->map[(int)floor(y / MAP_CELL_SIZE)][(int)floor(x / MAP_CELL_SIZE)] == '1')
        return (0);
    return(1);
}

int    key_press(int key_code, game_t *game)
{
    if (key_code == ESC)
        exit(0);
    else if (key_code == NORTH && valid_movement(game, game->player->x, game->player->y - 2))
        game->player->y -= 4; 
    else if (key_code == EST && valid_movement(game, game->player->x + 2, game->player->y))
        game->player->x += 4;
    else if (key_code == SUD && valid_movement(game, game->player->x, game->player->y + 2))
        game->player->y += 4;
    else if (key_code == WEST && valid_movement(game, game->player->x - 2, game->player->y))
        game->player->x -= 4;
    render_2d_map(game);
    render_player(game);
    return (0);
}