#include "cub3d.h"
#include <math.h>
#include <stdio.h>

int     valid_movement(game_t *game, int x, int y)
{
    int future_x = ceil((double)x / MAP_CELL_SIZE);
    int future_y = ceil((double)y / MAP_CELL_SIZE);
    x = future_x - 1;
    y = future_y - 1;
    printf("col x = %d, y = %d map = %c\n", x, y, game->map[y][x]);
    if (x >= 0 && y >= 0 && game->map[y][x] == '0')
        return (1);
    return(0);
}

void    turn_player(game_t *game, int key_code)
{
    if (key_code == RIGHT)
        game->player->angleofview += 1 * 3;
    else
        game->player->angleofview -= 1 * 3;
    game->player->x_end_line = cos(game->player->angleofview) * 30;
    game->player->y_end_line = sin(game->player->angleofview) * 30;
}

void    render_line(game_t *game)
{
    int x;
    int y;

    x = game->player->x;
    y = game->player->y;

    while (x <= game->player->x_end_line + game->player->x)
    {
        mlx_pixel_put(game->mlx, game->win, x, y, 0xBBB);
        x++;
        y++;
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
    printf("player x = %d, player y = %d\n", game->player->x, game->player->y);
    return (0);
}