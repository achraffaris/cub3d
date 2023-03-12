#include "../cub3d.h"

void	put_pixel(image_t *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

image_t *create_new_image(void *mlx, int color, int block_dimensions)
{
    image_t *image;
    int i;
    int j;

    i = 0;
    j = 0;
    image = malloc(sizeof(image_t));
    image->instance = mlx_new_image(mlx, block_dimensions, block_dimensions);
    image->addr = mlx_get_data_addr(image->instance,
                    &image->bits_per_pixel,
                    &image->line_length,
                    &image->endian);
    while (i < block_dimensions)
    {
        while (j < block_dimensions)
            put_pixel(image, i, j++, color);
        i++;
        j = 0;
    }
    return (image);
}

void    render_map(t_game *g)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < g->map_height)
    {
        while (j++ < g->map_width)
        {
            if (g->map[i][j] && g->map[i][j] == '1')
                mlx_put_image_to_window(g->mlx,
                    g->win,
                    g->wall_img->instance,
                    j * MAP_CELL_SIZE,
                    i * MAP_CELL_SIZE);
            else if (g->map[i][j] && g->map[i][j] == '0')
                mlx_put_image_to_window(g->mlx, g->win, g->floor_img->instance, j * MAP_CELL_SIZE, i * MAP_CELL_SIZE);
        }
        j = 0;
        i++;
    }
}

void    render_line(t_game *g, double angle)
{
    int x;
    int y;
    int i;
    
    i = 0;
    x = g->player->pos.x;
    y = g->player->pos.y;
    
    int distance = find_horizontal_intersection(g, angle);
    if (distance < 0)
        distance *= -1;
    printf("distance = %d angle = %f \n", distance, angle);
    while (i <= distance)
    {
        x = get_adjacent(angle, i);
        y = get_opposite(angle, i);
        mlx_pixel_put(g->mlx, g->win, g->player->pos.x + x, g->player->pos.y + y, 0xE96479);
        i++;
    }
}

void    render_player(t_game *g)
{
    mlx_put_image_to_window(g->mlx,
        g->win,
        g->player_img->instance,
        g->player->pos.x - (MAP_PLAYER_SIZE / 2),
        g->player->pos.y - (MAP_PLAYER_SIZE / 2));
}

void    render_2d(t_game *g)
{
    mlx_clear_window(g->mlx, g->win);
    render_map(g);
    render_player(g);
    render_line(g, g->player->rotation_angle);
}