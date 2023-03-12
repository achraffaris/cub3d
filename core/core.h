#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define ESC 53
#define CLOSE 0
#define ON_DESTROY 17
#define LEFT 124
#define RIGHT 123
#define NORTH 13
#define SUD 1
#define WEST 0
#define EST 2

#define COL_THICKNESS 1
#define ANGLE_OF_VUE 60 * (M_PI / 180)

#define MAP_CELL_SIZE 32
#define MAP_PLAYER_SIZE 8

#define PLAYER_SPEED 8
#define ROTATION_SPEED 8

#define MINIMAP_SIZE 0.1


typedef struct point_s
{
    int     x;
    int     y;
}   point_t;

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
    point_t     pos;
    double      rotation_angle;
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

    int             player_direction; // which direction the player is looking at

    int             floor_color; // use encode_color(int r, int g, int b);
    int             ceiling_color; // same

    
    image_t         *wall_img; // useful for rendering 2d map
    image_t         *floor_img;  // same
    image_t         *player_img; // same

    char            *wall_east; // texture path
    char            *wall_sud;  // same
    char            *wall_west; // same
    char            *wall_nord; // same


    player_t        *player; // actor
}   t_game;

int         key_press(int key_code, t_game *g);

double      get_opposite(double angle, double hypotenuse);
double      get_adjacent(double angle, double hypotenuse);
double      degree_to_rad(double degree);
double      get_hypoteneuse(double angle, double adjacent);


//                  Movements
int         valid_movement(t_game *g, int x, int y);
void        turn_player(t_game *g, int key_code);

#endif