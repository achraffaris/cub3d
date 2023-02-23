#include "cub3d.h"


int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    char    *dup;
    int     i;

    i = 0;
    if (!str)
        return (NULL);
    dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
    while (str[i])
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char    **createMap(void)
{
    char    **map;
    int i = 0;
    map = malloc(sizeof(char *) * 25);
    map[i] = ft_strdup("11111111111111111111111111111111111111111111111"); i++;
    map[i] = ft_strdup("10000000000000000000000000000000001000000000001"); i++;
    map[i] = ft_strdup("10000000000001111000000000000000001000000100001"); i++;
    map[i] = ft_strdup("10000000000001011000000000000000001000000100001"); i++;
    map[i] = ft_strdup("10000000000001001000000000000000001000000100001"); i++;
    map[i] = ft_strdup("10000000000001011000000000000000001000000100001"); i++;
    map[i] = ft_strdup("10000000000000000000000000100000001000000100001"); i++;
    map[i] = ft_strdup("10000000000001000000000000100000001000000100001"); i++;
    map[i] = ft_strdup("10010000000001000000000000100000001000000100001"); i++;
    map[i] = ft_strdup("10010000000001001100000000100000000000000100001"); i++;
    map[i] = ft_strdup("10010000000001001100000000100000000000000100001"); i++;
    map[i] = ft_strdup("10010000000001001100000000100000000000000100001"); i++;
    map[i] = ft_strdup("10010000000001001100000000100000000000000100001"); i++;
    map[i] = ft_strdup("10010000000001001100000000100000000000000100001"); i++;
    map[i] = ft_strdup("10010000000001001100000000000000000000000100001"); i++;
    map[i] = ft_strdup("10010000000001000000000000000000000000000100001"); i++;
    map[i] = ft_strdup("10010000000001000000000000000000000000000100001"); i++;
    map[i] = ft_strdup("10010000000000000000000000011100000000000100001"); i++;
    map[i] = ft_strdup("10010000000000000000000000011100000000000100001"); i++;
    map[i] = ft_strdup("10010000000000000000000000011100000000000100001"); i++;
    map[i] = ft_strdup("10010000000000000000000000011100000000000100001"); i++;
    map[i] = ft_strdup("10000000000000000000000000011100000000000100001"); i++;
    map[i] = ft_strdup("10000000000000000000000000000000000000000000001"); i++;
    map[i] = ft_strdup("11111111111111111111111111111111111111111111111"); i++;

    map[i] = NULL;
    return (map);
}

int mapSize(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

int lineSize(char **map)
{
    int max;
    int i;

    i = 0;
    max = ft_strlen(map[i]);
    while (map[i])
    {
        if (ft_strlen(map[i]) > max)
            max = ft_strlen(map[i]);
        i++;
    }
    return (max);
}

player_t    *player_init(game_t *game)
{
    player_t *p;

    p = malloc(sizeof(player_t));
    p->direction = NORTH;
    p->y = game->win_height / 2;
    p->x = game->win_width / 2;
    return (p);
}


game_t  *game_init()
{
    game_t *game = malloc(sizeof(game_t));

    game->mlx = mlx_init();
    game->map = createMap();
    game->map_height = mapSize(game->map);
    game->map_width = lineSize(game->map);
    game->win_height = game->map_height * MAP_CELL_SIZE;
    game->win_width = game->map_width * MAP_CELL_SIZE;
    game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "Cub3d");
    // 
    game->wall_img = create_new_image(game->mlx, 0x1E90FF, MAP_CELL_SIZE);
    game->floor_img = create_new_image(game->mlx, 0xF5F5F5, MAP_CELL_SIZE);
    game->player_img = create_new_image(game->mlx, 0xBBB, MAP_CELL_SIZE / 3);
    game->player = player_init(game);
    // 
    return (game);
}

int main()
{
    game_t  *g;

    g = game_init();
    render_2d_map(g);
    render_player(g);
    mlx_hook(g->win, 2, 0, key_press, g);
    mlx_hook(g->win, 3, 0, key_press, g);
    mlx_loop(g->mlx);
    return (0);
}