#include "utils.h"

double get_opposite(game_t *game, double hypotenuse)
{
    return (sin(game->player->angleofview) * hypotenuse);
}

double get_adjacent(game_t *game, double hypotenuse)
{
    return (cos(game->player->angleofview) * hypotenuse);
}

double degree_to_rad(double degree)
{
    return (degree * (M_PI / 180));
}