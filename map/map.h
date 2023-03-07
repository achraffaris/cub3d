#ifndef MAP_H
#define MAP_H

#include "../cub3d.h"

void        render_2d(game_t *g);
void        render_line(game_t *g, double angle);
void	    put_pixel(image_t *image, int x, int y, int color);
image_t     *create_new_image(void *mlx, int color, int block_dimensions);

#endif