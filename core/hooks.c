#include "../cub3d.h"

int    key_press(int key_code, t_game *g)
{
    if (key_code == ESC)
        exit(0);
    else if (key_code == NORTH && valid_movement(g, g->player->pos.x, g->player->pos.y - PLAYER_SPEED))
        g->player->pos.y -= PLAYER_SPEED; 
    else if (key_code == EST && valid_movement(g, g->player->pos.x + PLAYER_SPEED, g->player->pos.y))
        g->player->pos.x += PLAYER_SPEED;
    else if (key_code == SUD && valid_movement(g, g->player->pos.x, g->player->pos.y + PLAYER_SPEED))
        g->player->pos.y += PLAYER_SPEED;
    else if (key_code == WEST && valid_movement(g, g->player->pos.x - PLAYER_SPEED, g->player->pos.y))
        g->player->pos.x -= PLAYER_SPEED;
    else if (key_code == LEFT || key_code == RIGHT)
        turn_player(g, key_code);
    render_2d(g);
    g->player->rotation_angle = normalize_angle(g->player->rotation_angle);
    return (0);
}