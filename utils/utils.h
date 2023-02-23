#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

#define ESC 53
#define CLOSE 0
#define ON_DESTROY 17

#define NORTH 13
#define SUD 1
#define WEST 0
#define EST 2

#define LEFT 124
#define RIGHT 123

#define MAP_CELL_SIZE 32

typedef struct image_s
{
    void    *instance;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}   image_t;

typedef struct player_s
{
    int x;
    int y;
    int direction;
}   player_t;

typedef struct game_s
{
    void            *mlx; // mlx instance
    void            *win; // mlx windows

    char            **map; // valid 2d map 
    
    int             map_height; // len of previous map
    int             map_width;  // len of max line in the map

    int             win_height; // map_height * cell_size 
    int             win_width;

    int             floor_color; // use encode_color(int r, int g, int b);
    int             ceiling_color; // same

    char            *wall_east; // texture path
    char            *wall_sud;  // same
    char            *wall_west; // same
    char            *wall_nord; // same

    image_t         *wall_img; // useful for rendering 2d map
    image_t         *floor_img;  // same
    image_t         *player_img; // same

    player_t        *player; // actor
}   game_t;


void	    put_pixel(image_t *image, int x, int y, int color);
int         encode_color(int t, int r, int g, int b);
image_t     *create_new_image(void *mlx, int color, int block_dimensions);
void        render_2d_map(game_t *game);
void        render_player(game_t *game);
int         key_press(int key_code, game_t *game);

#endif