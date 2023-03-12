#include "parser.h"

void    init_config_data(t_game **g)
{
    t_game  *aux;

    aux = *g;
    aux->wall_east = NULL;
    aux->wall_sud = NULL;
    aux->wall_west = NULL;
    aux->wall_nord = NULL;
    aux->floor_color = -1;
    aux->ceiling_color = -1;
    aux->map_height = 0;
    aux->map_width = 0;
    aux->player_direction = -1;
}
