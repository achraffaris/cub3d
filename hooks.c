#include "cub3d.h"
#include <math.h>
#include <stdio.h>

int     valid_movement(game_t *game, int x, int y)
{
    int future_x = floor(x / MAP_CELL_SIZE);
    int future_y = floor(y / MAP_CELL_SIZE);
    x = future_x;
    y = future_y;
    if (x >= 0 && y >= 0 && game->map[y][x] == '0')
        return (1);
    return(0);
}

void    turn_player(game_t *game, int key_code)
{
    if (key_code == RIGHT)
        game->player->angleofview += -1 * game->player->rotation_speed;
    else
        game->player->angleofview += 1 * game->player->rotation_speed;
}

void    render_line(game_t *game)
{
    int x;
    int y;
    int lh = 0;
    x = game->player->x;
    y = game->player->y;

    while (lh <= 100)
    {
        mlx_pixel_put(game->mlx, game->win, game->player->x + x, game->player->y + y, 0xBBB);
        x = get_adjacent(game, lh);
        y = get_opposite(game, lh);
        lh++;
    }
}


int    key_press(int key_code, game_t *game)
{
    if (key_code == ESC)
        exit(0);
    else if (key_code == NORTH && valid_movement(game, game->player->x, game->player->y - PLAYER_SPEED))
        game->player->y -= PLAYER_SPEED; 
    else if (key_code == EST && valid_movement(game, game->player->x + PLAYER_SPEED, game->player->y))
        game->player->x += PLAYER_SPEED;
    else if (key_code == SUD && valid_movement(game, game->player->x, game->player->y + PLAYER_SPEED))
        game->player->y += PLAYER_SPEED;
    else if (key_code == WEST && valid_movement(game, game->player->x - PLAYER_SPEED, game->player->y))
        game->player->x -= PLAYER_SPEED;
    else if (key_code == LEFT || key_code == RIGHT)
        turn_player(game, key_code);
    render_2d_map(game);
    render_line(game);
    render_player(game);
    return (0);
}