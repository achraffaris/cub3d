#include "../cub3d.h"


void	put_pixel(image_t *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int encode_color(int t, int r, int g, int b)
{
    int encoded_color;

    encoded_color = t << 24 | r << 16 | g << 8 | b;
    return (encoded_color);
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
        {
            put_pixel(image, i, j, color);
            j++;
        }
        i++;
        j = 0;
    }
    return (image);
}

void    render_2d_map(game_t *game)
{
    
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < game->map_height)
    {
        while (j < game->map_width)
        {
            if (game->map[i][j] && game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx,
                    game->win,
                    game->wall_img->instance,
                    j * MAP_CELL_SIZE,
                    i * MAP_CELL_SIZE);
            else if (game->map[i][j] && game->map[i][j] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->floor_img->instance, j * MAP_CELL_SIZE, i * MAP_CELL_SIZE);
            j++;
        }
        j = 0;
        i++;
    }
}

void    render_player(game_t *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->player_img->instance, game->player->x, game->player->y);
}
