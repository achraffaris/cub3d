#include "cub3d.h"

double      setup_player_direction(game_t *g)
{
    if (g->player_direction == SUD)
        return (degree_to_rad(90));
    else if (g->player_direction == WEST)
        return (degree_to_rad(180));
    else if (g->player_direction == EST)
        return (degree_to_rad(0));
    return (degree_to_rad(270));
}

int     is_player(char c)
{
    if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
        return (1);
    return (0);
}

void    set_player_pos(game_t *g, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (g->map[i])
    {
        while (g->map[i][j])
        {
            if (is_player(g->map[i][j]))
            {
                *x = j * MAP_CELL_SIZE;
                *y = i * MAP_CELL_SIZE;
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

player_t    *player_init(game_t *g)
{
    player_t *p;

    p = malloc(sizeof(player_t));
    p->rotation_angle = setup_player_direction(g);
    set_player_pos(g, &p->pos.x, &p->pos.y);
    return (p);
}

game_t  *game_init(game_t *g)
{
    g->mlx = mlx_init();
    g->win_height = g->map_height * MAP_CELL_SIZE;
    g->win_width = g->map_width * MAP_CELL_SIZE;
    g->win = mlx_new_window(g->mlx, g->win_width, g->win_height, "Cub3d");
    g->wall_img = create_new_image(g->mlx, 0xccc, MAP_CELL_SIZE);
    g->floor_img = create_new_image(g->mlx, g->floor_color, MAP_CELL_SIZE);
    g->player_img = create_new_image(g->mlx, 0xE96479, MAP_PLAYER_SIZE);
    g->player = player_init(g);
    return (g);
}

int main(int ac, char **av)
{
    int     fd;
    game_t  *g;

    fd = primary_checks(ac, av[1]);
    g = malloc(sizeof(game_t));
    init_config_data(&g);
    parse_file(fd, &g);
    game_init(g);
    render_2d(g);
    mlx_hook(g->win, 2, 0, key_press, g);
    mlx_loop(g->mlx);
    return (0);
}
